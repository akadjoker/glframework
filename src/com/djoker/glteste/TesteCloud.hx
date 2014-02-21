package com.djoker.glteste;

import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;
import openfl.Assets;

import com.engine.game.Screen;
import com.engine.game.Game;
import com.engine.render.SpriteCloud;
import com.engine.render.Texture;

import com.engine.render.TileMap;
import com.engine.misc.Util;


/**
 * ...
 * @author djoker
 */
class TesteCloud extends Screen
{

 var tex :Texture;
 var batch:SpriteCloud;

 var tilemap:TileMap;

	
	override public function show()
	{
	
		tex = new Texture("assets/texture.png");

        batch = new SpriteCloud(tex,500);
         for (i in 0...1000)
		 {
          var particle:Particle = new Particle(tex);
	      particle.Init();
		  particle.x = Util.randf(10, 630);
		  particle.y = Util.randf(10, 470);
          batch.addImage(particle);
		 }
		 

		 var caption:TextField = new TextField();
		 caption.x =  Game.viewWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test 1000 statics sprites ";
		 game.addChild(caption);
		 
		 
		 tilemap= new TileMap(Assets.getText ("assets/map.tmx"));

	}

	override public function render(dt:Float) 
	{ 

    batch.render();
    }

		
		
		


	
	
}