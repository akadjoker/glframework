package com.engine.game;
import com.engine.render.Clip;
import com.engine.render.Texture;
import com.engine.render.BlendMode;

import flash.geom.Matrix;
import flash.geom.Point;


/**
 * ...
 * @author djoker
 */
class Entity extends GameObject
{
public var flipx:Bool;
public var flipy:Bool;
public var image:Texture;
public var blendMode:Int;
public var clip:Clip;
public var name:String;
public var red:Float;
public var green:Float;
public var blue:Float;
public var alpha:Float;
public var depth:Float;

	public function new(x:Float,y:Float,image:Texture,?name:String='solid') 
	{
		super();
		flipx = false;
		flipy = true;
		this.image = image;
		this.blendMode = BlendMode.NORMAL;
		clip = new Clip(0, 0, image.width, image.height);
		this.pivotX = clip.width/2;
		this.pivotY = clip.height/2;
		this.x = x;
		this.y = y;
		this.depth = 0.0;
		this.name = name;
		red = 1;
		green = 1;
		blue = 1;
		alpha = 1;
	    

		
	
	}
	

	
}