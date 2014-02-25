package com.engine.render.tiles;

import flash.geom.Rectangle;
import flash.geom.Vector3D;

import com.engine.render.BatchPrimitives;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;

import com.engine.game.Game;
import com.engine.render.TileMapCache;
import com.engine.render.filter.Filter;
import com.engine.render.Clip;
import com.engine.render.Block;
import com.engine.misc.Util;

/**
 * ...
 * @author djoker
 */
class LayerCache
{
public var tilesIDs:Array<Int>;
public var tileWidth:Int;
public var tileHeight:Int;
public var name:String;
public var width:Int;
public var height:Int;
public var opacity:Float ;
 
 public var parent:TileMapCache;
 private var blocks:Array<Block>;
 private var segmentCols:Int ;
 private var segmentRows:Int ;
 private var numSegments:Int ;
 private var segmentWidth:Int;
 private var segmentHeight:Int	;
 public  var drawBlocks:Int;

 

		
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

	
		
public function buildSegments(segmentWidth:Int,segmentHeight:Int)
{
	
segmentCols = 0;
segmentRows = 0;
numSegments = 0;
this.segmentWidth = Std.int(Game.viewWidth / tileWidth);
this.segmentHeight =  Std.int(Game.viewHeight / tileHeight);


 

	 blocks = new  Array<Block>();
		

			var tilesetCols:Int = Math.floor(parent.image.width / tileWidth);
			var tilesetRows:Int = Math.floor(parent.image.height / tileHeight);
			
			var viewWidthInTiles:Int  = Std.int(Game.viewWidth/ tileWidth);
			var viewHeightInTiles:Int = Std.int(Game.viewHeight/ tileHeight);
			
			
			var cols:Int = width;
			var rows:Int = height;
		
			
			segmentWidth = segmentWidth == -1 ? (cols < viewWidthInTiles * 2 ? cols : viewWidthInTiles) : segmentWidth;
			segmentHeight = segmentHeight == -1 ? (rows < viewHeightInTiles * 2 ? rows : viewHeightInTiles) : segmentHeight;
			segmentCols = Math.ceil(cols / segmentWidth);
			segmentRows = Math.ceil(rows / segmentHeight);
			
			for (y in 0...segmentCols)
			{
				for (x in 0...segmentRows) 
				{
					var sw:Int = x == segmentCols - 1 && cols % segmentWidth != 0 ? cols % segmentWidth : segmentWidth;
					var sh:Int = y == segmentRows - 1 && rows % segmentHeight != 0 ? rows % segmentHeight : segmentHeight;
					blocks.push(new Block(sw, sh));
					numSegments++;
				}
			}

			
			
            var tid:Int = 0;
			var index:Int=0;
	
			for (y in 0...rows)
			{
				for (x in 0...cols) 
				{
	
					var segmentRow:Int = Std.int(y / segmentHeight);
					var segmentCol:Int = Std.int(x / segmentWidth);
					var segmentOffset:Int = segmentRow * segmentCols + segmentCol;
					var segment:Block = blocks[segmentOffset];
					
					tid = getCell(x, y);
					if (tid == 0) 
					{
						continue;
					}
					tid -= 1;

					
					var tx:Int = Math.round(x * tileWidth);
					var ty:Int = Math.round(y * tileHeight);
					
					var widthTex:Int  = parent.image.width;
                    var heightTex:Int = parent.image.height;


				
					var clip:Clip = parent.getClip(tid);
						
					var u:Float =   clip.x / widthTex;
					var u2:Float = (clip.x + clip.width) / widthTex;
					var v:Float = clip.y / heightTex;
					var v2:Float=(clip.y + clip.height) / heightTex;
				
				
					
					
					
					segment.addVertex(tx + Util.EPSILON, 	ty + Util.EPSILON,	u,				v);
					segment.addVertex(tx + tileWidth,		ty + Util.EPSILON,	u2,	v);
					segment.addVertex(tx + Util.EPSILON,	ty + tileHeight,	u,				v2);
					segment.addVertex(tx + tileWidth,		ty + tileHeight,	u2,	v2);
					
					segment.indices.push(segment.index + 0);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 3);
					
					
					
					segment.index += 4;
						
				}
			}	
			
	
			
		for (i in 0...blocks.length)
		{
		 blocks[i].build();
		}
}
	public function getCell(x:Int, y:Int):Int
	{
			 return  tilesIDs[y * this.width + x];
			
	}
	public function setCell(x:Int, y:Int,v:Int)
	{
			   tilesIDs[y * this.width + x]=v;
			
	}

public function renderAABB(batch:BatchPrimitives)
{
for (i in 0...blocks.length)
	{
	 
		/*
		batch.line(blocks[i].vMin.x, blocks[i].vMin.y, blocks[i].vMax.x, blocks[i].vMin.y, 0, 1, 1, 1);
		batch.line(blocks[i].vMax.x, blocks[i].vMax.y, blocks[i].vMax.x, blocks[i].vMax.y, 0, 1, 1, 1);
		batch.line(blocks[i].vMin.x, blocks[i].vMin.y, blocks[i].vMin.x, blocks[i].vMax.y, 0, 1, 1, 1);
		batch.line(blocks[i].vMax.x, blocks[i].vMin.y, blocks[i].vMax.x, blocks[i].vMax.y, 0, 1, 1, 1);
*/
		
		batch.line(blocks[i].AMin.x, blocks[i].AMin.y, blocks[i].AMax.x, blocks[i].AMin.y, 0, 1, 1, 1);
		batch.line(blocks[i].AMax.x, blocks[i].AMax.y, blocks[i].AMax.x, blocks[i].AMax.y, 0, 1, 1, 1);
		batch.line(blocks[i].AMin.x, blocks[i].AMin.y, blocks[i].AMin.x, blocks[i].AMax.y, 0, 1, 1, 1);
		batch.line(blocks[i].AMax.x, blocks[i].AMin.y, blocks[i].AMax.x, blocks[i].AMax.y, 0, 1, 1, 1);

	}
		
	
} 	



public function renderSegments()
{
	drawBlocks = 0;
	for (i in 0...blocks.length)
	{
			blocks[i].AMin = parent.viewMatrix.transformVector(blocks[i].vMin);
		    blocks[i].AMax = parent.viewMatrix.transformVector(blocks[i].vMax);
			blocks[i].bound = new Rectangle(blocks[i].AMin.x, blocks[i].AMin.y, blocks[i].AMax.x - blocks[i].AMin.x, blocks[i].AMax.y - blocks[i].AMin.y);
			
			if (parent.viewBound.intersects(blocks[i].bound))
			{		
			    blocks[i].render();
     			drawBlocks++;
			}
	}
}

	
public function dispose():Void 
{
		   tilesIDs = null;
		   for (i in 0...blocks.length)
	        {		    
				blocks[i].dispose();
     		}
	
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