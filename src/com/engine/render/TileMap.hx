package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;

import flash.geom.Point;
import openfl.Assets;

import com.engine.misc.Util;
import com.engine.math.Vector3;


import flash.geom.Matrix3D;
import flash.geom.Vector3D;
import com.engine.render.filter.Filter;	
import com.engine.game.Game;
import com.engine.render.tiles.Layer;

/**
 * ...
 * @author djoker
 */

typedef Array2D = Array<Array<Int>>

class TileMap extends Buffer
{

	public var currentBlendMode:Int;

	public var widthInTiles:Int;
	public var heightInTiles:Int;

	public var tileWidth:Int;
	public var tileHeight:Int;
	public var margin:Int=0;
	public var spacing:Int=0;
	public var columns:Int;
	public var image:Texture;
	public var ortho:Bool;





private var invTexWidth:Float = 0;
private var invTexHeight:Float = 0;

public var shader:SpriteShader;


//layers

public var layers:Array<Layer>;

//blocks
 private var blocks:Array<Block>;
 private var segmentCols:Int ;
 private var segmentRows:Int ;
 private var numSegments:Int ;
 private var segmentWidth:Int;
 private var segmentHeight:Int	;
	

 public  function new (xml:String,?Build:Bool=true):Void 
		{
		super();
		
		var initTime:Int = Util.getTime();
		
		var xml = Xml.parse(xml).firstElement();

		 widthInTiles = Std.parseInt(xml.get("width"));
		 heightInTiles = Std.parseInt(xml.get("height"));
		if (xml.get("orientation") == "orthogonal")
		{
		ortho = true;
		} else {
	    ortho = false;
		}
		// tileWidth = Std.parseInt(xml.get("tilewidth"));
		// tileHeight = Std.parseInt(xml.get("tileheight"));
		var properties = new Map<String, String>();
		layers = [];

		for (child in xml)
		{
		if (isValidElement(child)) 
			{
				if (child.nodeName == "tileset")
				{
					if (child.get("source") != null) 
					{
					   tilesfromGenericXml(getText(child.get("source")));
					} else 
					{
						tilesfromGenericXml(child.toString());
					}
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
		
		var endTime:Int = Util.getTime();
		
		if (Build) buildBuffers();
		
	trace(" tock "+ (endTime-initTime)+" to load tilemap"); 	
	
	

}

public function buildBuffers()
{
	shader = new SpriteShader();
	currentBlendMode = BlendMode.NORMAL;
	
		for (l in 0...layers.length)
	 {
	 layers[l].build();
	 }
}

	/*	
public function buildSegments(segmentWidth:Int,segmentHeight:Int)
{
	
segmentCols = 0;
segmentRows = 0;
numSegments = 0;
this.segmentWidth = segmentWidth;
this.segmentHeight = segmentHeight;

 

	 blocks = new  Array<Block>();
		

			var tilesetCols:Int = Math.floor(image.width / tileWidth);
			var tilesetRows:Int = Math.floor(image.height / tileHeight);
			
			var viewWidthInTiles:Int  = Std.int(Game.viewWidth/ tileWidth);
			var viewHeightInTiles:Int = Std.int(Game.viewHeight/ tileHeight);
			
			var cols:Int = widthInTiles;
			var rows:Int = heightInTiles;
		
			
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

			
			var uvWidth:Float  = 1 / (image.width / tileHeight);
			var uvHeight:Float = 1 / (image.height / tileWidth);
		
			
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

					
					var tx:Int = x * tileWidth;
					var ty:Int = y * tileHeight;
					var u:Float = (tid % tilesetCols) * uvWidth;
					var v:Float = Math.floor(tid / tilesetCols) * uvHeight;
				
					
					
					segment.addVertex(tx + Util.EPSILON, 	ty + Util.EPSILON,	u,				v);
					segment.addVertex(tx + tileWidth,		ty + Util.EPSILON,	u + uvWidth,	v);
					segment.addVertex(tx + Util.EPSILON,	ty + tileHeight,	u,				v + uvHeight);
					segment.addVertex(tx + tileWidth,		ty + tileHeight,	u + uvWidth,	v + uvHeight);
					
					segment.indices.push(segment.index + 0);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 3);
					
					
					
					segment.index += 4;
						
				}
			}	
			
		shader = new  SpriteShader();
			
		for (i in 0...blocks.length)
		{
		 blocks[i].build();
		}
}


public function renderSegments(viewWidth:Int,viewHeight:Int)
{
	update();
	shader.Enable();
    shader.setTexture(image);
	BlendMode.setBlend(this.currentBlendMode);
	GL.uniformMatrix3D(shader.projectionMatrixUniform, false,Game.camera.projMatrix);
    GL.uniformMatrix3D(shader.modelViewMatrixUniform, false, viewMatrix);

 
   
   
            var minXSegment:Int = Math.floor((Game.camera.scrollX- position.x) / tileWidth / segmentWidth);
			var maxXSegment:Int = Math.floor((Game.camera.scrollX+ viewWidth - position.x ) / tileWidth / segmentWidth);
			
			var minYSegment:Int = Math.floor((Game.camera.scrollY-position.y) / tileHeight / segmentHeight);
			var maxYSegment:Int = Math.floor((Game.camera.scrollY + viewHeight-position.y) / tileHeight / segmentHeight);
			for ( sx in minXSegment...maxXSegment) 
			{
				for (sy in minYSegment...maxYSegment) 
				{
					var si:Int = sy * segmentCols + sx;
					if (si < 0 || si >= blocks.length) {
						continue;
					}
					blocks[si].render();
					
				}
			}
			
				
   
 
   shader.Disable();
}
	*/


	
			

		public function getClip(num:Int):Clip
		{
		//	return new Clip(this.tileWidth * (num % columns), this.tileHeight * Std.int(num / columns), this.tileWidth, this.tileHeight);
			return new Clip(
			this.margin + (this.tileWidth  + this.spacing) * num % columns,
			this.margin + (this.tileHeight + this.spacing) * Std.int(num / columns),
			this.tileWidth, this.tileHeight);
		}
   	  
		
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
				   
					this.image =new  Texture();
					this.image.load("assets/" + child.get("source"));
					if (image!=null)
					{
					this.columns = Std.int(image.width / this.tileWidth);
					
					
					//trace("Columns:" + columns);
					}
					
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

		var layer:Layer = new Layer(width, height, tileWidth, tileHeight, opacity, name);
		layer.parent = this;
	 

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
							layer.tilesIDs= csvToArray(chunk);
				     	}
						default:
							{
							for (tile in child) 
							{
								if (isValidElement(tile)) 
								{
									var gid = Std.parseInt(tile.get("gid"));
									layer.tilesIDs.push(gid);
								}
							}
							}
					}
				}
			}
		}
		
		layers.push(layer);
	}
	
public function renderLayer(layer:Int)
{
	this.update();
	 if (layer >= layers.length) layer = layers.length;
	 shader.Enable();
	 shader.setTexture(image);
     GL.uniformMatrix3D(shader.modelViewMatrixUniform, false, viewMatrix);
     GL.uniformMatrix3D(shader.projectionMatrixUniform, false,Game.camera.projMatrix);
	 BlendMode.setBlend(currentBlendMode); 
	 layers[layer].render();
}

public function render()
{
	this.update();
	
	 shader.Enable();
	 shader.setTexture(image);
     GL.uniformMatrix3D(shader.modelViewMatrixUniform, false, viewMatrix);
     GL.uniformMatrix3D(shader.projectionMatrixUniform, false,Game.camera.projMatrix);
	 BlendMode.setBlend(currentBlendMode); 
    
	 for (l in 0...layers.length)
	 {
	 layers[l].render();
	 }

}
		
override public function dispose():Void 
{
	 for (l in 0...layers.length)
	 {
	 layers[l].dispose();
	 }
	 layers = null;
	 shader.dispose();
	 super.dispose();
	
}
}