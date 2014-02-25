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
class SepiaFilter extends RenderFilter
{

	private var sepia:Float = 1;
	private var sepiaUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.sepiaFilter;
	}
	override public function getUnifom() 
	{
			sepiaUniform = GL.getUniformLocation (shader, "sepia");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (sepiaUniform, sepia);
	}
	public function setSepia(f:Float)
	{
		sepia = f;
		
	}
}