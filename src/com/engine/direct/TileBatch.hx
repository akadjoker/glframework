package com.engine.direct ;
import flash.display.BitmapData;
import flash.display.Bitmap;
import flash.display.InteractiveObject;
import flash.display.Sprite;
import flash.geom.Matrix;
import flash.events.Event;
import openfl.display.Tilesheet;
import flash.Vector;
import flash.Lib;
import flash.geom.Point;
import flash.geom.Rectangle;
import haxe.xml.Fast;

/**
 * ...
 * @author djoker
 */
class TileBatch extends Sprite
{
	private  var tilesheet: Tilesheet;
	private  var tileData:Array<Float>;
	private var sprites:Array<TileImage>;
	private var clips:Vector<SpriteClip>;
	private var sort:Bool;
	private var length:Int;
	private var maxSize:Int;
	private var numTile:Int;
	private var currentTime:Int;
	private var previousTime:Int;
	
	public function new(image:BitmapData) 
	{
		super();
		tilesheet = new Tilesheet(image);
		tileData = new Array<Float>();
		sprites = new  Array<TileImage>();
		clips = new Vector<SpriteClip>();
		length = 0;
		addEventListener( Event.ENTER_FRAME, onEnterFrame );
		sort = false;
		maxSize = 1000;
		numTile = 0;
		previousTime = Lib.getTimer ();
	}
		
		public  function parseXML (data:String):Void 
		{
		var frameIndex:Map <String,Int> = new Map <String,Int> ();
		
		var xml:Xml = Xml.parse (data);
		var spriteSheetNode:Xml = xml.firstElement ();
		
		for (behaviorNode in spriteSheetNode.elements ()) {
			
			var behaviorNodeFast:Fast = new Fast (behaviorNode);
			var behaviorFrames:Array <Int> = new Array <Int> ();
			
			var allFramesText:String = behaviorNodeFast.innerData;
			var framesText:Array <String> = allFramesText.split (";");
			
			for (frameText in framesText) {
				
				if (!frameIndex.exists (frameText)) {
				
					
					var components:Array < String > = frameText.split (",");
					
					addTileRect(new Rectangle(
					Std.parseInt (components[0]), 
					Std.parseInt (components[1]), 
					Std.parseInt (components[2]), 
					Std.parseInt (components[3])),
					new Point( 
					-Std.parseInt (components[4]), 
					-Std.parseInt (components[5])));
					
						
					var frame:SpriteClip = new SpriteClip (Std.parseInt (components[0]), Std.parseInt (components[1]), Std.parseInt (components[2]), Std.parseInt (components[3]), -Std.parseInt (components[4]), -Std.parseInt (components[5]));
				     clips.push(frame);
				}
				
			
				
			}
			
			
			
		}
		
	}
	public function getClip(index:Int):SpriteClip
	{
		return clips[index];
	}
	public function addTileRect(rectangle:Rectangle, centerPoint:Point = null):Int
	{
	numTile++;	
	return tilesheet.addTileRect(rectangle, centerPoint);	
	}
		
	
	
	private function sortObjects(a:TileImage, b:TileImage):Int 
	{
     if (a.Layer == b.Layer)
        return 0;
     if (a.Layer > b.Layer)
         return 1;
     else
         return -1;
    }
	public function clear():Void
	{
		length = 0;
		sprites.splice(0, sprites.length);
	}
	 public function kill():Void
	{
		var i:Int = 0;
		var basic:TileImage = null;
		
		while (i < length)
		{
			basic = sprites[i++];
			
			if ((basic != null) )
			{
				basic.kill();
			}
		}
		
	
	}

		public function add(Object:TileImage):TileImage
	{
		if (Object == null)
		{
			return null;
		}
		
		
		if (Util.indexOf(sprites, Object) >= 0)
		{
			sort = true;
			return Object;
		}
		
		// First, look for a null entry where we can add the object.
		var i:Int = 0;
		var l:Int = sprites.length;
		
		while (i < l)
		{
			if (sprites[i] == null)
			{
				sprites[i] = Object;
				
				if (i >= length)
				{
					length = i + 1;
				}
				sort = true;
				return Object;
			}
			i++;
		}
		
		// Failing that, expand the array (if we can) and add the object.
		if (maxSize > 0)
		{
			if (sprites.length >= maxSize)
			{
				sort = true;
				return Object;
			}
			else if (sprites.length * 2 <= maxSize)
			{
				Util.setLength(sprites, sprites.length * 2);
			}
			else
			{
				Util.setLength(sprites, maxSize);
			}
		}
		else
		{
			Util.setLength(sprites, sprites.length * 2);
		}
		
		sprites[i] = Object;
		sort = true;
		length = i + 1;
		
		return Object;
	}
	public function numObjects():Int
	{
		return length;
	}
	public function destroy():Void
	{
		if (sprites != null)
		{
			var i:Int = 0;
			var basic:TileImage = null;
			
			while (i < length)
			{
				basic = sprites[i++];
				
				if (basic != null)
				{
					basic.destroy();
				}
			}
			
			
			sprites = null;
		}
		
	
		
		
	}
	public function remove(obj:TileImage, Splice:Bool = false):TileImage
	
	{
		if (sprites == null)
		{
			return null;
		}
		
		var index:Int = Util.indexOf(sprites, obj);
		
		if ((index < 0) || (index >= sprites.length))
		{
			return null;
		}
		if (Splice)
		{
			sprites.splice(index, 1);
		}
		else
		{
			sprites[index] = null;
		}
		
		return obj;
	}
	public function dispose():Void
	{
		removeEventListener( Event.ENTER_FRAME, onEnterFrame );
	}
	
	public function render()
	{
		var currentTime = Lib.getTimer ();
		var deltaTime:Int = currentTime - previousTime;
		
		graphics.clear();
		var flags = Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA | Tilesheet.TILE_BLEND_NORMAL | Tilesheet.TILE_RGB;
	    var i:Int = 0;
		var basic:TileImage = null;
		while (i < sprites.length)
		{
			basic = sprites[i++];
			
			if ((basic != null) && basic.Visible)
			{
			basic.updateAnim(deltaTime / 100);
			basic.update();
			renderObject(tileData, basic);
			}
		}
		
		tilesheet.drawTiles(graphics,tileData, false, flags);
		tileData = [];
		if (sort)
		{
			sprites.sort(sortObjects);
			sort = false;
		
		}
		previousTime = currentTime;
	}
		
	private function onEnterFrame(e:Event):Void 
	{
		var currentTime = Lib.getTimer ();
		var deltaTime:Int = currentTime - previousTime;
		
		graphics.clear();
		var flags = Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA | Tilesheet.TILE_BLEND_NORMAL | Tilesheet.TILE_RGB;
	    var i:Int = 0;
		var basic:TileImage = null;
		while (i < sprites.length)
		{
			basic = sprites[i++];
			
			if ((basic != null) && basic.Visible)
			{
			basic.updateAnim(deltaTime / 100);
			basic.update();
			renderObject(tileData, basic);
			}
		}
		
		tilesheet.drawTiles(graphics,tileData, false, flags);
		tileData = [];
		if (sort)
		{
			sprites.sort(sortObjects);
			sort = false;
		
		}
		previousTime = currentTime;
	}
public  function renderObject(data:Array<Float>,obj:TileImage)
	{
	  	  var mTransformationMatrix:Matrix = obj.getMatrix();
		    data.push(mTransformationMatrix.tx);
		    data.push(mTransformationMatrix.ty);
	        data.push (obj.Graph);
			data.push(mTransformationMatrix.a); 
			data.push(mTransformationMatrix.b); 
			data.push(mTransformationMatrix.c); 
			data.push(mTransformationMatrix.d);
	    	data.push(obj.Red);
			data.push(obj.Green);
			data.push(obj.Blue);
			data.push(obj.Alpha);
	}
	public  function renderTile(data:Array<Float>, tile:Int, mX:Float, mY:Float,
	    mPivotX:Float,mPivotY:Float,
		mScaleX:Float, mScaleY:Float, 
		mSkewX:Float,mSkewY:Float,
		mRotation:Float,
		red:Float, green:Float, blue:Float, alpha:Float)
	{
		
		var mTransformationMatrix:Matrix = new Matrix();
		 mTransformationMatrix.identity();
	
               if (mSkewX == 0.0 && mSkewY == 0.0)
                {
                  
                    if (mRotation == 0.0)
                    {
					
                       Util.matrixsetTo(mTransformationMatrix,mScaleX, 0.0, 0.0, mScaleY, mX - mPivotX * mScaleX, mY - mPivotY * mScaleY);
                    }
                    else
                    {
                       		var cos = Math.cos(mRotation * Math.PI / -180);
			                var sin = Math.sin(mRotation * Math.PI / -180);
			
                        var a:Float   = mScaleX *  cos;
                        var b:Float   = mScaleX *  sin;
                        var c:Float   = mScaleY * -sin;
                        var d:Float   = mScaleY *  cos;
                        var tx:Float  = mX - mPivotX * a - mPivotY * c;
                        var ty:Float  = mY - mPivotX * b - mPivotY * d;
                        
                        Util.matrixsetTo(mTransformationMatrix,a, b, c, d, tx, ty);
                    }
                }
                else
                {
                    mTransformationMatrix.identity();
                    mTransformationMatrix.scale(mScaleX, mScaleY);
                    Util.skew(mTransformationMatrix, mSkewX, mSkewY);
                    mTransformationMatrix.rotate(mRotation);
                    mTransformationMatrix.translate(mX, mY);
                    
                    if (mPivotX != 0.0 || mPivotY != 0.0)
                    {
                        
                        mTransformationMatrix.tx = mX - mTransformationMatrix.a * mPivotX
                                                      - mTransformationMatrix.c * mPivotY;
                        mTransformationMatrix.ty = mY - mTransformationMatrix.b * mPivotX 
                                                      - mTransformationMatrix.d * mPivotY;
                    }
                }
            

            data.push(mTransformationMatrix.tx);
		    data.push(mTransformationMatrix.ty);
	        data.push (tile);
			data.push(mTransformationMatrix.a); // m00
			data.push(mTransformationMatrix.b); // m10
			data.push(mTransformationMatrix.c); // m01
			data.push(mTransformationMatrix.d); // m11
	

		
			data.push( red);
			data.push(green);
			data.push(blue);
			data.push(alpha);
	}
	
	public var numTiles(get, set) : Int;
	private inline function get_numTiles():Int {  return numTile;}
    private function set_numTiles( v : Int ):Int {numTile = v;return numTile;}

	
	
}