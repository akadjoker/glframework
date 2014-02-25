package com.engine.render.filter;

import com.engine.game.Game;
import com.engine.render.filter.Filter;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLFramebuffer;
import openfl.gl.GLRenderbuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;


//*********************//TEST TEST TEST

import flash.geom.Matrix3D;
import flash.geom.Rectangle;
import openfl.gl.GLUniformLocation;
import openfl.utils.Float32Array;
import openfl.utils.UInt8Array;
import openfl.utils.UInt8Array;

/**
 * ...
 * @author djoker
 */
class NormalFilter extends RenderFilter
{
 

	override public function getFragment():String 
	{
		return Filter.normalFilter;
	}
	override public function getUnifom() 
	{
		
	}
	override public function setUnifom() 
	{
		
	}
	
}