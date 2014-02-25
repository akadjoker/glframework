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
class ColorStepFilter extends RenderFilter
{
private var step:Float = 5;
	private var stepUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.colorStepFilter;
	}
	override public function getUnifom() 
	{
			stepUniform = GL.getUniformLocation (shader, "step");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (stepUniform, step);
	}
	
	public function setStep(f:Float)
	{
		step = f;
		
	}
	
}