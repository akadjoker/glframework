package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;
import com.engine.game.Game;
import flash.geom.Point;
import openfl.Assets;

import com.engine.misc.Util;
import com.engine.math.Vector3;
import com.engine.math.Matrix;

import flash.geom.Matrix3D;
import flash.geom.Vector3D;
	

/**
 * ...
 * @author djoker
 */

typedef Array2D = Array<Array<Int>>

class TileMap extends Buffer
{


	public var widthInTiles:Int;
	public var heightInTiles:Int;
	public var tileWidth:Int;
	public var tileHeight:Int;
	public var margin:Int=0;
	public var spacing:Int=0;
	public var tilesIDs:Array<Int>;
	public var columns:Int;
	public var image:Texture;
	private var isBuild:Bool;
	private var capacity:Int;
	private var numVerts:Int;
	private var numIndices:Int; 
	private var vertices:Float32Array;
	private var indices:Int16Array;
	private var lastIndexCount:Int;
	private var drawing:Bool;
	private var currentBatchSize:Int;
	private var currentBlendMode:Int;
	private var currentBaseTexture:Texture;



private var vertexBuffer:GLBuffer;
private var indexBuffer:GLBuffer;

private var invTexWidth:Float = 0;
private var invTexHeight:Float = 0;

public var shader:SpriteShader;
public var vertexStrideSize:Int;

		
	

public  function new (xml:String):Void 
		{
			super();
		var xml = Xml.parse(xml).firstElement();

		 widthInTiles = Std.parseInt(xml.get("width"));
		 heightInTiles = Std.parseInt(xml.get("height"));
		//this.orientation = xml.get("orientation");
		// tileWidth = Std.parseInt(xml.get("tilewidth"));
		// tileHeight = Std.parseInt(xml.get("tileheight"));
		var properties = new Map<String, String>();

		for (child in xml)
		{
		//	trace("node:" +child.toString());
			if (isValidElement(child)) 
			{
			//	trace(child.nodeName);
				if (child.nodeName == "tileset")
				{
					if (child.get("source") != null) 
					{
					   tilesfromGenericXml(getText(child.get("source")));
					} else 
					{
						tilesfromGenericXml(child.toString());
					}

					//tileset.setFirstGID(Std.parseInt(child.get("firstgid")));

					//this.tilesets.push(tileset);
				}

				else if (child.nodeName == "properties") 
				{
					for (property in child) 
					{
						if (!isValidElement(property))
							continue;
				//		properties.set(property.get("name"), property.get("value"));
					}
				}

				else if (child.nodeName == "layer") 
				{
					layerfromGenericXml(child);
				}

				else if (child.nodeName == "objectgroup") 
				{
				objectsfromGenericXml(child);

				
				}
			}
		}
		
		addClips();
	
	   capacity = (this.widthInTiles * this.heightInTiles);
	 

	     vertexStrideSize =  9 * 4; 
 
	   numVerts = capacity * vertexStrideSize *   4;
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
	currentBlendMode = BlendMode.NORMAL;
    invTexWidth  = 1.0 / image.texWidth;
    invTexHeight = 1.0 / image.texHeight;

	

    vertexBuffer = GL.createBuffer();
    indexBuffer = GL.createBuffer();


    //upload the index data
    GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
    GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, indices, GL.STATIC_DRAW);

	
    GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
	
	
	
	shader = new SpriteShader();
	isBuild = false;
	
				
		
		
		}
		
	
	public function build()
		{
		for (y in 0...heightInTiles)
		{
			for (x in 0...widthInTiles)
			{

					
				var id =  getCell(x, y);
				if (id >= 1)
				{
					//id = 1;
					var t:Clip = getClip(id - 1);
			  	       var DrawX:Int =Math.round((x * tileWidth));
                       var DrawY:Int =Math.round((y * tileHeight));
					 var dst:Clip = new Clip(Math.round(DrawX),Math.round( DrawY), tileWidth, tileHeight);
					 this.addQuad(t,dst);
				}
			}
		}
		isBuild = true;
		}

	
public function addQuad(srcrect:Clip, dstrect:Clip)
{

var index:Int = currentBatchSize *  vertexStrideSize;

var widthTex:Int  = image.width;
var heightTex:Int = image.height;


         			

vertices[index++] = dstrect.x;
vertices[index++] = dstrect.y;
vertices[index++] = 0;
vertices[index++] = srcrect.x / widthTex; vertices[index++] = srcrect.y / heightTex;
vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;
	
vertices[index++] = (dstrect.x + dstrect.width);
vertices[index++] = dstrect.y;
vertices[index++] = 0;
vertices[index++] = (srcrect.x + srcrect.width) / widthTex;vertices[index++] = srcrect.y / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;

vertices[index++] =(dstrect.x + dstrect.width);
vertices[index++] =(dstrect.y + dstrect.height);
vertices[index++] = 0;
vertices[index++] = (srcrect.x + srcrect.width) / widthTex;vertices[index++] = (srcrect.y + srcrect.height) / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;

vertices[index++] = dstrect.x;  
vertices[index++] = (dstrect.y + dstrect.height);
vertices[index++] = 0;
vertices[index++] = srcrect.x / widthTex; vertices[index++] = (srcrect.y + srcrect.height) / heightTex;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;


 
 
this.currentBatchSize++;
	 
}
public function render()
	{
	 this.update();
	 
	
	 
	 if (!isBuild)
	 {
		 build();
		 return;
	 }
	 shader.Enable();
     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(shader.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3+2) * 4);


	 
  if (currentBatchSize == 0) return;

			
	
   	GL.activeTexture(GL.TEXTURE0);
	image.Bind();
	BlendMode.setBlend(this.currentBlendMode);
	GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(Game.projMatrix.toArray()));
    GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(viewMatrix.toArray()));
   
    GL.uniform1i (shader.imageUniform, 0);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
	GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
    GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
    shader.Disable();
    }
	
	
public function renderDinamic(pointx:Float,pointy:Float)
	{
	 this.update();
	 isBuild = false;
	 currentBatchSize = 0;
	 shader.Enable();
     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(shader.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3 + 2) * 4);
	 
	 	var tw:Int = Math.ceil(tileWidth), th:Int = Math.ceil(tileHeight);

	

		// determine start and end tiles to draw (optimization)
		var startx = Math.floor( -pointx / tw ),
			starty = Math.floor( -pointy / th ),
			destx = startx + 1 + Math.ceil(Game.viewWidth  / tw ),
			desty = starty + 1 + Math.ceil(Game.viewHeight / th );

		// nothing will render if we're completely off screen
		if (startx > widthInTiles || starty > heightInTiles || destx < 0 || desty < 0)
			return;

		// clamp values to boundaries
		if (startx < 0) startx = 0;
		if (destx > widthInTiles) destx = widthInTiles;
		if (starty < 0) starty = 0;
		if (desty > heightInTiles) desty = heightInTiles;

		var wx:Float, sx:Float = (pointx + startx * tw ) ,
			wy:Float = (pointy + starty * th ) ,
			stepx:Float = tw ,
			stepy:Float = th ,
			tile:Int = 0;

		// adjust scale to fill gaps
		var scx = Math.ceil(stepx) / tileWidth;
		var scy = Math.ceil(stepy) / tileHeight;

		for (y in starty...desty)
		{
			wx = sx;
			for (x in startx...destx)
			{
				
				var id =  getCell(x%widthInTiles, y%heightInTiles);
				if (id >= 1)
				{
					var t:Clip = getClip(id - 1);
					this.addQuad(t,new Clip(Math.round(wx), Math.round(wy), tileWidth,tileHeight));
				}				
	  		wx += stepx;
			}
			wy += stepy;
		}

	 
  if (currentBatchSize == 0) return;
   	GL.activeTexture(GL.TEXTURE0);
	image.Bind();
	BlendMode.setBlend(this.currentBlendMode);
	GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(Game.projMatrix.toArray()));
    GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(viewMatrix.toArray()));
    GL.uniform1i (shader.imageUniform, 0);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
	GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
    GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
    currentBatchSize = 0;
    shader.Disable();
	}
	
	
			
		 public function getCell(x:Int, y:Int):Int
		{
			 return  tilesIDs[y * this.widthInTiles + x];
			
		}
		public function getClip(num:Int):Clip
		{
	
	
  
		//	return new Clip(this.tileWidth * (num % columns), this.tileHeight * Std.int(num / columns), this.tileWidth, this.tileHeight);
			return new Clip(
			this.margin + (this.tileWidth  + this.spacing) * num % columns,
			this.margin + (this.tileHeight + this.spacing) * Std.int(num / columns),
			this.tileWidth, this.tileHeight);
			
			

			
		}
   	  
		
		public function addClips()
		{
			/*
		}
		clips = [];
		var columns:Int =Std.int( image.width  / this.tileWidth );
		var rows:Int    =Std.int( image.height / this.tileHeight ); 
	
	
	for ( y in 0...rows)
	{
		for (x in 0...columns)
		{
		var rect:Clip = new Clip();
			rect.y = y * (tileHeight + spacing);
			rect.y += margin;
			rect.height = tileHeight;
			rect.x = x * (tileWidth + spacing);
			rect.x += margin;
			rect.width = tileWidth;
		    clips.push(rect);
		
			
		}
	}
	*/
 }
		
	public function loadFromString(str:String, columnSep:String = ",", rowSep:String = "\n")
	{
		var row:Array<String> = str.split(rowSep),
			rows:Int = row.length,
			col:Array<String>, cols:Int, x:Int, y:Int;
		for (y in 0...rows)
		{
			if (row[y] == '') continue;
			col = row[y].split(columnSep);
			cols = col.length;
			for (x in 0...cols)
			{
				if (col[x] == '') continue;
				//_map[y][x] = Std.parseInt(col[x]);
			}
		}
	}

	
		public  function objectfromGenericXml(xml:Xml) 
		{
		var gid:Int = xml.get("gid") != null ? Std.parseInt(xml.get("gid")) : 0;
		var name:String = xml.get("name");
		var type:String = xml.get("type");
		var x:Int = Std.parseInt(xml.get("x"));
		var y:Int = Std.parseInt(xml.get("y"));
		var width:Int = Std.parseInt(xml.get("width"));
		var height:Int = Std.parseInt(xml.get("height"));
		//var polygon:TiledPolygon = null;
		//var polyline:TiledPolyline = null;
		var properties:Map<String, String> = new Map<String, String>();
		
		for (child in xml) 
		{
			if (isValidElement(child)) 
			{
				if (child.nodeName == "properties")
				{
					for (property in child) 
					{
						if (isValidElement(property)) 
						{
							properties.set(property.get("name"), property.get("value"));
						}
					}
				}
				
				if (child.nodeName == "polygon" || child.nodeName == "polyline")
				{
					var origin:Point = new Point(x, y);
					var points:Array<Point> = new Array<Point>();
					
					var pointsAsString:String = child.get("points");
					
					var pointsAsStringArray:Array<String> = pointsAsString.split(" ");
					
					for (p in pointsAsStringArray) 
					{
						//var coords:Array<String> = p.split(",");
						//points.push(new Point(Std.parseInt(coords[0]), Std.parseInt(coords[1])));
					}
					
					if (child.nodeName == "polygon") 
					{
						//polygon = new TiledPolygon(origin, points);
					} else if (child.nodeName == "polyline") 
					{
					//	polyline = new TiledPolyline(origin, points);
					}
				}
			}
		}
		
	
	}
		public  function objectsfromGenericXml(xml:Xml)
		{
		var name = xml.get("name");
		var color = xml.get("color");
		var width = Std.parseInt(xml.get("width"));
		var height = Std.parseInt(xml.get("height"));
		var properties:Map<String, String> = new Map<String, String>();
		//var objects:Array<TiledObject> = new Array<TiledObject>();
		
		for (child in xml) {
			if (isValidElement(child))
			{
				if (child.nodeName == "properties") {
					for (property in child) {
						if (isValidElement(property)) 
						{
							properties.set(property.get("name"), property.get("value"));
						}
					}
				}
				
				if (child.nodeName == "object") 
				{
					objectfromGenericXml(child);
				}
			}
		}
		
		
	}

	
	public  function isValidElement(element:Xml):Bool
	{
		return Std.string(element.nodeType) == "element";
	}
	public function getText(assetPath:String):String 
	{
		return Assets.getText(assetPath);
	}
	
	public  function tilesfromGenericXml(content:String)
	{
		var xml = Xml.parse(content).firstElement();

		var name:String = xml.get("name");
		tileWidth = Std.parseInt(xml.get("tilewidth"));
		tileHeight = Std.parseInt(xml.get("tileheight"));
		spacing = xml.exists("spacing") ? Std.parseInt(xml.get("spacing")) : 0;
		margin = xml.exists("margin") ? Std.parseInt(xml.get("margin")) : 0;
		
		var properties:Map<String, String> = new Map<String, String>();
		//var propertyTiles:Map<Int, PropertyTile> = new Map<Int, PropertyTile>();
		//var terrainTypes:Array<TerrainType> = new Array<TerrainType>();
		//var image:TilesetImage = null;

		var tileOffsetX:Int = 0;
		var tileOffsetY:Int = 0;

		for (child in xml.elements()) 
		{
			if (isValidElement(child)) 
			{
				if (child.nodeName == "properties") 
				{
					for (property in child) {
						if (isValidElement(property)) 
						{
							trace("tileHeight set name:" + property.get("name") +" - Value : " + property.get("value"));
						//	properties.set(property.get("name"), property.get("value"));
						}
					}
				}

				if (child.nodeName == "tileoffset") 
				{
					tileOffsetX = Std.parseInt(child.get("x"));
					tileOffsetY = Std.parseInt(child.get("y"));
				}

				if (child.nodeName == "image")
				{
					var width = Std.parseInt(child.get("width"));
					var height = Std.parseInt(child.get("height"));
                   // trace("Tile set: Image: " + child.get("source"));
					this.image = new Texture("assets/" + child.get("source"));
					if (image!=null)
					{
					this.columns = Std.int(image.width / this.tileWidth);
					
					
					//trace("Columns:" + columns);
					}
					//image = new TilesetImage(child.get("source"), width, height);
				}

				if (child.nodeName == "terraintypes") 
				{
					for (element in child) 
					{

						if (isValidElement(element)) 
						{
							if (element.nodeName == "terrain") 
							{
						//		terrainTypes.push(new TerrainType(element.get("name"), Std.parseInt(element.get("tile"))));
							}
						}
					}
				}

			
				if (child.nodeName == "tile")
				{
					//trace("tile");
					var id:Int = Std.parseInt(child.get("id"));
					var properties:Map<String, String> = new Map<String, String>();

					for (element in child) 
					{

						if (isValidElement(element)) 
						{
							if (element.nodeName == "properties") 
							{
								for (property in element) {
									if (!isValidElement(property)) {
										continue;
									}

									//properties.set(property.get("name"), property.get("value"));
								}
							}
						}
					}

					//propertyTiles.set(id, new PropertyTile(id, properties));
				}
			}
		}

		//return new Tileset(name, tileWidth, tileHeight, spacing, properties, terrainTypes, image,
		//new Point(tileOffsetX, tileOffsetY));
	}	
	
	
	private  function csvToArray(input:String):Array<Int>
	{
		var result:Array<Int> = new Array<Int>();
		var rows:Array<String> = StringTools.trim(input).split("\n");
		var row:String;

		for (row in rows) {

			if (row == "") {
				continue;
			}

			var resultRow:Array<Int> = new Array<Int>();
			var entries:Array<String> = row.split(",");
			var entry:String;

			for (entry in entries) {

				if(entry != "") {
					result.push(Std.parseInt(entry));
				}
			}
		}
		return result;
	}
    
	
		public  function layerfromGenericXml(xml:Xml)
		{
		var name:String = xml.get("name");
		var width:Int = Std.parseInt(xml.get("width"));
		var height:Int = Std.parseInt(xml.get("height"));
		var opacity:Float = Std.parseFloat(xml.get("opacity") != null ?			xml.get("opacity") : "1.0");

	    tilesIDs= new Array<Int>();

		for (child in xml) 
		{
			if (isValidElement(child)) 
			{
				if (child.nodeName == "data") 
				{
					var encoding:String = "";
					if (child.exists("encoding"))
					{
						encoding = child.get("encoding");
					}
					var chunk:String = "";
					switch(encoding){
						case "base64":
							{
							chunk = child.firstChild().nodeValue;
							//trace("base64");
							}
						case "csv":
							{
							chunk = child.firstChild().nodeValue;
								//trace("csv");
							   tilesIDs = csvToArray(chunk);
				     	}
						default:
							{
							//trace("string tiles");
							for (tile in child) 
							{
								if (isValidElement(tile)) 
								{
									var gid = Std.parseInt(tile.get("gid"));
									tilesIDs.push(gid);
								}
							}
							}
					}
				}
			}
		}
	}
	public function toCSV(?width:Int):String 
	{
		if (width <= 0 || width == null) 
		{
			width = this.widthInTiles;
		}

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
		
override public function dispose():Void 
{
	   GL.deleteBuffer(indexBuffer);
		GL.deleteBuffer(vertexBuffer);
	super.dispose();
	
}
}