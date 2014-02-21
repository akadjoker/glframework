package com.engine.render;

import com.engine.game.Game;
import com.engine.math.Matrix;
import com.engine.math.Vector3;







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