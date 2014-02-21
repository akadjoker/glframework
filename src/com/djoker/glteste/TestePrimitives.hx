package com.djoker.glteste;

import com.engine.game.Screen;

import com.engine.render.BatchPrimitives;
import com.engine.render.Texture;


import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

/**
 * ...
 * @author djoker
 */
class TestePrimitives extends Screen
{

 
 var batch:BatchPrimitives;




	
	override public function show()
	{
	
		
  
		batch = new  BatchPrimitives( 500);
		

		


	}

	override public function render(dt:Float) 
	{ 
   

	batch.begin();
	

	batch.line(10, 10, 100, 100, 1, 0, 1);
	batch.rect(100, 100, 90, 120, 1, 1, 1);
	batch.circle(100, 100, 12, 8, 1, 1, 1, 1);
	batch.ellipse(300, 90, 55, 15, 8, 1, 1, 1, 1);

	batch.fillrect(200, 200, 50, 50, 1, 0, 0, 1);
	batch.fillrect(280, 200, 50, 50, 1, 0, 1, 1);
	batch.fillcircle(200, 100, 8, 18, 1, 1, 1, 1);
	batch.fillellipse(300, 100, 55, 15, 8, 1, 1, 1, 1);

	
	batch.end();
	
    }

		
		


	
	
}