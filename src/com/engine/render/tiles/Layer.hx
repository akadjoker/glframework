package com.engine.render.tiles;


import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;

import com.engine.render.TileMap;
import com.engine.render.filter.Filter;
import com.engine.render.Clip;
import com.engine.render.Block;

/**
 * ...
 * @author djoker
 */
class Layer
{
public var tilesIDs:Array<Int>;
public var tileWidth:Int;
public var tileHeight:Int;
public var name:String;
public var width:Int;
public var height:Int;
public var opacity:Float ;

public var parent:TileMap;

	private var capacity:Int;
	private var numVerts:Int;
	private var numIndices:Int; 
	private var vertices:Float32Array;
	private var indices:Int16Array;
	private var lastIndexCount:Int;
	private var drawing:Bool;
	private var currentBatchSize:Int;
	private var currentBlendMode:Int;

	public var vertexStrideSize:Int;
	
private var vertexBuffer:GLBuffer;
private var indexBuffer:GLBuffer;



		
    /**
	 * <alpha> opacity of the layes
	 * <w>Map width 
	 * <h>Map height
	 * <tw> tile width
	 * <th>tile height
	 */

	public function new(w:Int,h:Int,tw:Int,th:Int,alpha:Float,name:String) 
	{
	tilesIDs = [];
	this.width = w;
	this.height = h;
	this.tileWidth = tw;
	this.tileHeight = th;
	this.name = name;
	this.opacity = alpha;
	
	
	}
		
	public function getCell(x:Int, y:Int):Int
	{
			 return  tilesIDs[y * this.width + x];
			
	}
	
	public function build()
		{
	capacity = (this.width * this.height);
	vertexStrideSize =  9 * 4; 
    numVerts = capacity * vertexStrideSize;
    numIndices = capacity * 6;
    vertices = new Float32Array(numVerts);
    this.indices = new Int16Array(numIndices); 
    var length = Std.int(this.indices.length/6);
		
		for (i in 0...length) 
		{
			var index2 = i * 6;
			var index3 = i * 4;
			this.indices[index2 + 0] = index3 + 0;
			this.indices[index2 + 1] = index3 + 1;
			this.indices[index2 + 2] = index3 + 2;
			this.indices[index2 + 3] = index3 + 0;
			this.indices[index2 + 4] = index3 + 2;
			this.indices[index2 + 5] = index3 + 3;
		};
		


    currentBatchSize = 0;
  
		for (y in 0...height)
		{
			for (x in 0...width)
			{

					
				var id =  getCell(x, y);
				if (id >= 1)
				{
					//id = 1;
					var t:Clip = parent.getClip(id - 1);
			  	    var DrawX:Int =Math.round((x * tileWidth));
                    var DrawY:Int =Math.round((y * tileHeight));
					var dst:Clip = new Clip(DrawX,DrawY, tileWidth, tileHeight);
					addQuad(t,dst);
				}
			}
		}
		
		

    vertexBuffer = GL.createBuffer();
    indexBuffer = GL.createBuffer();


    //upload the index data
    GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
    GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, indices, GL.STATIC_DRAW);
    GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.STATIC_DRAW);
	
	vertices = null;
	indices = null;
}
		
public function addQuad(srcrect:Clip, dstrect:Clip)
{

var index:Int = currentBatchSize *  vertexStrideSize;

var widthTex:Int  = parent.image.width;
var heightTex:Int = parent.image.height;


         			

vertices[index++] = dstrect.x;
vertices[index++] = dstrect.y;
vertices[index++] = 0;
vertices[index++] = srcrect.x / widthTex; vertices[index++] = srcrect.y / heightTex;
vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = opacity;
	
vertices[index++] = (dstrect.x + dstrect.width);
vertices[index++] = dstrect.y;
vertices[index++] = 0;
vertices[index++] = (srcrect.x + srcrect.width) / widthTex;vertices[index++] = srcrect.y / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = opacity;

vertices[index++] =(dstrect.x + dstrect.width);
vertices[index++] =(dstrect.y + dstrect.height);
vertices[index++] = 0;
vertices[index++] = (srcrect.x + srcrect.width) / widthTex;vertices[index++] = (srcrect.y + srcrect.height) / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = opacity;

vertices[index++] = dstrect.x;  
vertices[index++] = (dstrect.y + dstrect.height);
vertices[index++] = 0;
vertices[index++] = srcrect.x / widthTex; vertices[index++] = (srcrect.y + srcrect.height) / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = opacity;


 
 
this.currentBatchSize++;
	 
}
public function render()
	{
     if (currentBatchSize == 0) return;
     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
     GL.vertexAttribPointer(Filter.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(Filter.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(Filter.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3+2) * 4);
   //  GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.STATIC_DRAW);
	 GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
     GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
    }
	
	
public function dispose():Void 
{
	   GL.deleteBuffer(indexBuffer);
	   GL.deleteBuffer(vertexBuffer);
	   tilesIDs = null;
}

public function toCSV(?w:Int):String 
{
	var counter:Int = 0;
		var csv:String = "";

		for (tile in tilesIDs) 
		{
			var tileGID = tile;

			if (counter >= width) 
			{
				// remove the last ","
				csv = csv.substr(0, csv.length - 1);

				// add a new line and reset counter
				csv += '\n';
				counter = 0;
			}

			csv += tileGID;
			csv += ',';

			counter++;
		}

		// remove the last ","
		csv = csv.substr(0, csv.length - 1);

		return csv;
	}
}