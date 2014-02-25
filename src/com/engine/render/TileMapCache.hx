package com.engine.render;

import flash.geom.Rectangle;
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
import com.engine.render.tiles.LayerCache;

/**
 * ...
 * @author djoker
 */
class TileMapCache extends Buffer
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
	public var viewBound:Rectangle;




private var invTexWidth:Float = 0;
private var invTexHeight:Float = 0;

public var shader:SpriteShader;


//layers

public var layers:Array<LayerCache>;

//blocks

 private var segmentWidth:Int;
 private var segmentHeight:Int	;
	
 
public function renderLayer(layer:Int)
{
     update();
	 if (layer >= layers.length) layer = layers.length;
	 shader.Enable();
	 shader.setTexture(image);
     GL.uniformMatrix3D(shader.modelViewMatrixUniform, false, viewMatrix);
     GL.uniformMatrix3D(shader.projectionMatrixUniform, false,Game.camera.projMatrix);
	 BlendMode.setBlend(currentBlendMode); 
	 layers[layer].renderSegments();
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
	 layers[l].renderSegments();
	 }

	 shader.Disable();
} 

public function renderAABB(batch:BatchPrimitives)
{
	
	 for (l in 0...layers.length)
	 {
	 layers[l].renderAABB(batch);
	 }
	 
	 batch.rect(viewBound.left, viewBound.top, viewBound.right, viewBound.bottom,1,1,0,1);

} 


 public  function new (xml:String,segmentWidth:Int,segmentHeight:Int):Void 
		{
		super();
		this.segmentWidth = segmentWidth;
		this.segmentHeight = segmentHeight;
		
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
		
	 viewBound = new  Rectangle(0, 0, Game.viewWidth, Game.viewHeight);

	 
	 buildBuffers();
		
	trace(" tock "+ (endTime-initTime)+" to load tilemap"); 	
	
	

}

public function setViewPort(x:Float, y:Float, width:Float, height:Float)
{
	viewBound = new Rectangle(x, y, width, height);
	
}

public function buildBuffers()
{
	shader = new SpriteShader();
	currentBlendMode = BlendMode.NORMAL;
	
	for (l in 0...layers.length)
	 {
	 layers[l].buildSegments(segmentWidth, segmentHeight);
	 }
}



	
			

		public function getClip(num:Int):Clip
		{
		//	return new Clip(this.tileWidth * (num % columns), this.tileHeight * Std.int(num / columns), this.tileWidth, this.tileHeight);
			return new Clip(
			this.margin + (this.tileWidth  + this.spacing) * num % columns,
			this.margin + (this.tileHeight + this.spacing) * Std.int(num / columns),
			this.tileWidth, this.tileHeight);
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

		var layer:LayerCache = new LayerCache(width, height, tileWidth, tileHeight, opacity, name);
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