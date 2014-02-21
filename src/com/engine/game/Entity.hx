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

	public function new(x:Float,y:Float,image:Texture,?name:String='solid') 
	{
		super();
		flipx = false;
		flipy = false;
		this.image = image;
		this.blendMode = BlendMode.NORMAL;
		clip = new Clip(0, 0, image.width, image.height);
		this.x = 100;
		this.y = y;
		this.name = name;
		

		
	    

		
	
	}
	

	
}