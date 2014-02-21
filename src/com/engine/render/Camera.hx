package com.engine.render;

import flash.display.Sprite;
import flash.geom.Rectangle;




import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;

import com.engine.misc.Util;
import com.engine.math.Vector3;
import com.engine.math.Matrix;
import com.engine.game.Game;


/**
 * ...
 * @author djoker
 */
class Camera buffer
{

	public function new() 
	{
		super();
	}


	public function unproject(source:Vector3):Vector3
	{
		var world=Matrix.Identity();
		return Vector3.Unproject(source, Game.viewWidth, Game.viewHeight, world, this.viewMatrix, Game.projMatrix);
	}
	 	
	
	
}