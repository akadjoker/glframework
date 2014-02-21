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
class TesteBatch extends Screen
{

 var tex :Texture;
 var batch:SpriteBatch;


 var player:Entity;

   var particles : Array<Particle>;

	
	override public function show()
	{
	
		tex = new Texture("assets/texture.png",true);
         batch = new SpriteBatch(500);
        particles = [];
        for(i in 0...200)
         addParticle();
		 
	
		 var caption:TextField = new TextField();
		 caption.x =  game.gameWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test 200 sprites with  SpriteBatch ";
		 game.addChild(caption);
		 
		 player = new  Entity(200,200, tex);


	}

	override public function render(dt:Float) 
	{ 
  
		  //player.rotation += dt * 0.1;
		  player.skewX += dt * 0.1;
		  
 
		  
		  batch.Begin();

      for(p in particles)
      {
         p.move(dt);
	
        batch.drawImage(p);
      }
	  
	  batch.drawEntity(player);
	  
      batch.End();
	

	}

		
		

public function addParticle()
{
	var particle:Particle = new Particle(tex);
	particle.Init();
	particle.blendMode = BlendMode.NORMAL;
    particles.push(particle);
}
public function addParticle2(x:Float,y:Float)
{
	var particle:Particle = new Particle(tex);
	particle.Init();
	particle.x = x;
	particle.y = y;
	particle.blendMode = BlendMode.NORMAL;
    particles.push(particle);
}

override public function mouseDown(mousex:Float, mousey:Float) 
{
	addParticle2(mousex, mousey);
}

	
	
}