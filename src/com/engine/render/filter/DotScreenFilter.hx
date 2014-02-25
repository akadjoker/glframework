package com.engine.render.filter;


import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;
import openfl.utils.Float32Array;

/**
 * ...
 * @author djoker
 */
class DotScreenFilter extends RenderFilter
{
private var scale:Float = 1;
private var angle:Float = 5;
	
private var scaleUniform:GLUniformLocation;
private var angleUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.dotscreenFilter;
	}
	override public function getUnifom() 
	{
	angleUniform = GL.getUniformLocation (shader, "angle");
	scaleUniform = GL.getUniformLocation (shader, "scale");
	}
	override public function setUnifom() 
	{
		GL.uniform1f (scaleUniform,scale);
		GL.uniform1f (angleUniform,angle);
	}

	public function setScale(v:Float)
	{
		scale = v;
	}
	
	public function setAngle(v:Float)
	{
		angle = v;
	}
	
}