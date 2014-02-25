package com.engine.render;

import com.engine.misc.Util;
import com.engine.math.Vector2;
import com.engine.game.Game;
import flash.display.DisplayObject;

import flash.geom.Matrix;
import flash.geom.Matrix3D;
import flash.geom.Point;


/**
 * ...
 * @author djoker
 */
class Buffer
{

	public var viewMatrix:Matrix3D;
	public var position:Vector2;//position of the matrix
	public var x:Float;
	public var y:Float;
	public var scale:Float;
	public var rotation:Float;
	public var scrollx:Float;///factor of scroll
	public var scrolly:Float;///factor of scroll
		
	public function new() 
	{
		position =new  Vector2(0, 0);
		rotation = 0;
		scale=1;
		viewMatrix = new  Matrix3D();
		scrollx = 1;
		scrolly = 1;
		x = 0;
		y = 0;
		update();
	}
	public function getMatrix():Matrix3D
	{
		return this.viewMatrix;
	}
	public function combineMatrix(m:Matrix3D)
	{
		viewMatrix.append(m);
	}
    public function update()
	{
	viewMatrix.identity();
	viewMatrix.appendScale(scale, scale, 0);
	viewMatrix.appendTranslation( Math.round(position.x-Game.camera.scrollX *scrollx), Math.round(position.y-Game.camera.scrollY *scrolly),0);
	}

	public function dispose()
	{
		viewMatrix = null;
		position = null;
	}
	
}