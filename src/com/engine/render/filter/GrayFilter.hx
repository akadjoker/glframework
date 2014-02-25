package com.engine.render.filter;


import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;

/**
 * ...
 * @author djoker
 */
class GrayFilter extends RenderFilter
{

	private var gray:Float = 1;
	private var grayUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.grayFilter;
	}
	override public function getUnifom() 
	{
			grayUniform = GL.getUniformLocation (shader, "gray");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (grayUniform, gray);
	}
		public function setGray(f:Float)
	{
		gray = f;
		
	}
}