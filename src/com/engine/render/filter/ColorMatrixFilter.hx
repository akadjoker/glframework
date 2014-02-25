package com.engine.render.filter;


import flash.geom.Matrix;
import flash.geom.Matrix3D;
import flash.geom.Vector3D;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;

/**
 * ...
 * @author djoker
 */
class ColorMatrixFilter extends RenderFilter
{
private var matrix:Matrix3D;
private var matrixUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.colormatrixFilter;
	}
	override public function getUnifom() 
	{
		    matrix = new Matrix3D([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
			matrixUniform = GL.getUniformLocation (shader, "matrix");
	}
	override public function setUnifom() 
	{
		GL.uniformMatrix3D(matrixUniform, false,matrix);
	}
	 public function setTransformation(x:Float,y:Float,rotation:Float,Scale:Float) 
	{
		matrix.identity();
		matrix.appendTranslation(x, y, 0);
		matrix.appendRotation(rotation, new Vector3D(0, 0, 1));
		matrix.appendScale(Scale, Scale, 0);
	}
	
	 public function setMatrix2D(mat:Matrix) 
	{
	
	}
		
		
	
}