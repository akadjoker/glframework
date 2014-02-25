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
class TwistFilter extends RenderFilter
{
private var radius:Float = 0.5;
private var angle:Float = 5;
private var offsetx:Float = 0.5;
private var offsety:Float=0.5;
	
private var radiusUniform:GLUniformLocation;
private var angleUniform:GLUniformLocation;
private var offsetUniform:GLUniformLocation;
	
		
	
	override public function getFragment():String 
	{
		return Filter.twistFilter;
	}
	override public function getUnifom() 
	{
			radiusUniform = GL.getUniformLocation (shader, "radius");
			angleUniform = GL.getUniformLocation (shader, "angle");
			offsetUniform = GL.getUniformLocation (shader, "offset");
			
	}
	override public function setUnifom() 
	{
		GL.uniform1f (radiusUniform, radius);
		GL.uniform1f (angleUniform, angle);
		GL.uniform2f(offsetUniform, offsetx, offsety);
	}
	public function setRadius(v:Float)
	{
		radius = v;
	}
	
	public function setAngle(v:Float)
	{
		angle = v;
	}
	public function setOffset(x:Float,y:Float)
	{
		offsetx = x;
		offsety = y;
	}	
	
}