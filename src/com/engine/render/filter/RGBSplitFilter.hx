package com.engine.render.filter;


import flash.geom.Point;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;

/**
 * ...
 * @author djoker
 */
class RGBSplitFilter extends RenderFilter
{
    private var colordistance:Float = 10000;
	private var redUniform:GLUniformLocation;
	private var greenUniform:GLUniformLocation;
	private var blueUniform:GLUniformLocation;
	private var subtractUniform:GLUniformLocation;
	
	
	override public function getFragment():String 
	{
		return Filter.rgbsplitFilter;
	}
	override public function getUnifom() 
	{
			redUniform = GL.getUniformLocation (shader, "red");
			greenUniform = GL.getUniformLocation (shader, "green");
			blueUniform = GL.getUniformLocation (shader, "blue");
			subtractUniform= GL.getUniformLocation (shader, "distance");
			
	}
	override public function setUnifom() 
	{
		GL.uniform1f (subtractUniform,colordistance);
		GL.uniform2f (redUniform, 20,20);
		GL.uniform2f (greenUniform,-20,20);
		GL.uniform2f (blueUniform, 20,-20);
	}
		
	
}