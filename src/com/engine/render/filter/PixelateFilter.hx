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
class PixelateFilter extends RenderFilter
{
	private var pixelSizeX:Float = 0.9;
    private var pixelSizeY:Float = 0.9;

	private var pixelSizeUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.pixelateFilter;
	}
	override public function getUnifom() 
	{
	pixelSizeUniform = GL.getUniformLocation (shader, "pixelSize");
	}
	override public function setUnifom() 
	{
		GL.uniform2f (pixelSizeUniform, pixelSizeX, pixelSizeY);
	}
	public function setPixelSize(x:Float,y:Float)
	{
	pixelSizeX = x;	
	pixelSizeY = y;
		
	}
	
}