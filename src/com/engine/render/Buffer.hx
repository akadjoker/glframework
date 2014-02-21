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
		viewMatrix = Matrix.Identity();
	}
	public function getMatrix():Matrix
	{
		return this.viewMatrix;
	}
	public function combineMatrix(m:Matrix)
	{
		viewMatrix.Multiply4x4(viewMatrix, m);
	}
    public function update()
	{
	viewMatrix.set2Dtransformation( Math.round(position.x), Math.round(position.y), scale, rotation);
	}

	public function dispose()
	{
		
	}
	
}