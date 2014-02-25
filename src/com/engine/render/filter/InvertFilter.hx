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
class InvertFilter extends RenderFilter
{

	private var invert:Float = 1;
	private var invertUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.invertFilter;
	}
	override public function getUnifom() 
	{
			invertUniform = GL.getUniformLocation (shader, "invert");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (invertUniform, invert);
	}
	public function setInvert(f:Float)
	{
		invert = f;
		
	}
	
}