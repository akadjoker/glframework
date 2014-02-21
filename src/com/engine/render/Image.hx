package com.engine.render;

import flash.geom.Rectangle;
import com.engine.render.BlendMode;
/**
 * ...
 * @author djoker
 */
class Image
{

public var width:Float;
public var height:Float;

public var x:Float;
public var y:Float;
public var red:Float;
public var green:Float;
public var blue:Float;
public var alpha:Float;

public var angle:Float;
public var scaleX:Float;
public var scaleY:Float;
public var originX:Float;
public var originY:Float;
public var texture:Texture;
public var blendMode:Int;
public var clip:Clip;
public var flipX:Bool;
public var flipY:Bool;

	public function new(Tex:Texture) 
	{
		clip = new Clip(0, 0, Tex.width, Tex.height);
		angle = 0;
		scaleX = 1;
		scaleY = 1;
		originX = 0;
		originY = 0;
		red = 1;
		green = 1;
		blue = 1;
		alpha = 1;
		x = 0;
		y = 0;	
		width = Tex.width;
        height = Tex.height;
		flipX = false;
		flipY = false;
		blendMode = BlendMode.NORMAL;
		red = 1;
		green = 1;
		blue = 1;
		alpha = 1;

		texture = Tex;
	}
	
}