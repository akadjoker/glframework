package com.engine.render;

import com.engine.misc.Util;
import com.engine.misc.MatrixHelp;
import com.engine.math.Matrix;
import com.engine.math.Vector2;
/**
 * ...
 * @author djoker
 */
class Buffer
{

	public var viewMatrix:Matrix;
	public var position:Vector2;
	public var scale:Float;
	public var rotation:Float;
		
	public function new() 
	{
		position =new  Vector2(0, 0);
		rotation = 0;
		scale=1;
		viewMatrix = Matrix.create2D(position.x, position.y, scale, rotation);
	}
	public function getMatrix():Matrix
	{
		return this.viewMatrix;
	}
	public function combineMatrix(m:Matrix)
	{
		viewMatrix = Matrix.MatrixMultiply4x4(this.viewMatrix, m);
	}
    public function update()
	{
	viewMatrix = Matrix.create2D( Math.round(position.x), Math.round(position.y), scale, rotation);
	//viewMatrix = Matrix.create2D( position.x, position.y, scale, rotation);
	}

	public function dispose()
	{
		
	}
	
}