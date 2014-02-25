package com.engine.render;

import com.engine.game.Game;
import com.engine.math.Vector2;
import com.engine.misc.Util;


import flash.geom.Matrix;
import flash.geom.Matrix3D;
import flash.geom.Point;




/**
 * ...
 * @author djoker
 */
class Camera 
{
	 public var projMatrix:Matrix3D;
	 public var viewMatrix:Matrix3D;
	 private var width:Float;
	 private var height:Float;
	 public  var scale:Float;
	 
	 public var position:Vector2;//this value move the world matrix
	 public var scrollX:Float;
	 public var scrollY:Float;
	
	

	public function new(width:Int,height:Int) 
	{
		projMatrix = Util.createOrtho(0, width, height, 0,  -1, 1);
		this.width = width;
		this.height = height;
		viewMatrix = new Matrix3D();
		scale = 1;
		position = new Vector2(0, 0);
		scrollX = 0;
		scrollY = 0;
	}


	public function update()
	{
		 viewMatrix.identity();
         viewMatrix.appendScale(scale, scale, 0);
		 viewMatrix.appendTranslation(Math.round(position.x),Math.round( position.y), 0);
		 
  
		
	}
	public function resize(width:Float, height:Float) 
	{
	this.width = width;
	this.height = height;
	projMatrix = Util.createOrtho(0, width, height, 0,  -1, 1);
	}
	 	
	
	
}