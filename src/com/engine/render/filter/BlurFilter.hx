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
class BlurFilter extends RenderFilter
{
private var blur:Float = 1/512;
	private var blurUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.blurXFilter;
	}
	override public function getUnifom() 
	{
			blurUniform = GL.getUniformLocation (shader, "blur");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (blurUniform, blur);
	}
	public function setBlur(v:Float)
	{
		blur = v / (1 / 7000);
	}
	
}