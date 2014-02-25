package com.djoker.glteste;

import com.engine.game.Screen;

import com.engine.render.BatchPrimitives;
import com.engine.render.Texture;


import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

import com.engine.math.Vector2;
import com.engine.game.Game;


/**
 * ...
 * @author djoker
 */
class TestePrimitives extends Screen
{

 
 var batch:BatchPrimitives;
  var lastmouseX:Float;
 var lastmouseY:Float;
 var mouseX:Float;
 var mouseY:Float;
 var toutch:Bool;
 var Toutch:Vector2 ;
 var lastToutch:Vector2;
 var position:Vector2;




	
	override public function show()
	{
	
		
  
		batch = new  BatchPrimitives( 500);
		
	    Toutch = new Vector2(0, 0);
		 lastToutch = new Vector2(0, 0);
		 position = new   Vector2(0, 0);
	
		


	}

	override public function render() 
	{ 
   

	batch.begin();
	

	batch.line(10, 10, 100, 100, 1, 0, 1);
	batch.rect(100, 100, 90, 120, 1, 1, 1);
	batch.circle(100, 100, 12, 8, 1, 1, 1, 1);
	batch.ellipse(300, 90, 55, 15, 8, 1, 1, 1, 1);

	batch.fillrect(200, 200, 50, 50, 1, 0, 0, 1);
	batch.fillrect(280, 200, 50, 50, 0, 1, 1, 1);
	batch.fillcircle(200, 100, 8, 18, 1, 0, 1, 1);
	batch.fillellipse(300, 100, 55, 15, 8, 0, 1, 1, 1);

	batch.line(lastToutch.x, lastToutch.y, Toutch.x, Toutch.y, 1, 0, 0);
	
	batch.end();
	
    }

		
	override public function mouseDown(mousex:Float, mousey:Float) 
	{
		toutch = true;
		lastToutch.x = mousex;
		lastToutch.y = mousey;
		//lastToutch=camera.unproject(lastToutch);
		
		
	}		
	override public function mouseMove(mousex:Float, mousey:Float) 
	{
		
		if (toutch==true)
		{
			
			Toutch.x = mousex;
			Toutch.y = mousey;
		//	Toutch=camera.unproject(Toutch);
	
			
		var dir:Vector2 = Vector2.Sub(Toutch, lastToutch);
		dir.normalize();
		
		//camera.position = Vector3.Add(camera.position, dir);
		batch.position.x += (dir.x * game.deltaTime*100);
		batch.position.y += (dir.y * game.deltaTime*100);
		
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}
		


	
	
}