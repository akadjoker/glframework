package com.djoker.glteste;


import com.engine.game.Entity;
import com.engine.game.Screen;
import com.engine.render.SpriteBatch;
import com.engine.render.Texture;
import com.engine.render.BlendMode;

import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

/**
 * ...
 * @author djoker
 */
class TestTrasform extends Screen
{

 var tex :Texture;
 var batch:SpriteBatch;


 
 var child:Entity;
 
 var player:Entity;
 var logo:Entity;


   var playerTex :Texture;
   var skew:Float = 0;
 
	
	override public function show()
	{
		
	   playerTex = new Texture("assets/zazaka.png", true);
	
         batch = new SpriteBatch(500);
   
	
		 var caption:TextField = new TextField();
		 caption.x =  game.gameWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test trasform sprites by parent ";
		 caption.selectable = false;
		 game.addChild(caption);

		logo = new Entity(this.width / 2, this.height / 2, new Texture("assets/hxlogo.png", true));
	    logo.blendMode = BlendMode.SCREEN;
	
		 player = new  Entity(300, 200, playerTex);
		 child = new  Entity(0, 0, playerTex);
		 child.blue = 0;

		 player.add(child);
		 

		 
		 game.clarColor(0, 0, 0);


	}

	override public function render(dt:Float) 
	{ 
  
		  player.rotation += dt * 2.1;
		  child.rotation -= dt * 2.5;
		  player.skewX += dt * 0.1;
		  
		skew += dt * 1;
 
		logo.skewX = Math.sin(skew)*1;
		logo.skewY = Math.cos(skew)*1;
		
		  
	batch.Begin();


  	  batch.drawEntity(logo);
	  batch.drawEntity(player);
	  batch.drawEntity(child);

	  
      batch.End();
	

	}

		
		



override public function mouseDown(mousex:Float, mousey:Float) 
{

	player.x = mousex;
	player.y = mousey;
}

	
	
}