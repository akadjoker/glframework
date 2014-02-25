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

   var particles : Array<Particle>;
 
 var child:Entity;
 
 var player:Entity;
 var logo:Entity;
 var caption:TextField;

   var playerTex :Texture;
   var skew:Float = 0;
 
	
	override public function show()
	{
		
	
         batch = new SpriteBatch(500);
   
	
		  caption = new TextField();
		 caption.x =  game.gameWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test trasform sprites by parent ";
		 caption.selectable = false;
		 game.addChild(caption);
		 
		 tex = getTexture("assets/texture.png");
		    particles = [];
        for(i in 0...200)
        addParticle();

		logo = new Entity(this.width / 2, this.height / 2, getTexture("assets/hxlogo.png", true));
	    logo.blendMode = BlendMode.SCREEN;
	
		 player = new  Entity(300, 200, getTexture("assets/zazaka.png", true));
		 child = new  Entity(0, 0, getTexture("assets/zazaka.png", true));
		 child.blue = 0;

		 player.add(child);
		 
		 
		
	 
		
		 

		 
		 game.clarColor(0, 0, 0);


	}
	
	override public function update(dt:Float) 
	{ 

		
		caption.text = logo.getLocalToWorldMatrix().toString();
		
	}

	override public function render() 
	{ 
  
		  player.rotation += game.deltaTime * 2.1;
		  child.rotation -= game.deltaTime * 2.5;
		  player.skewX += game.deltaTime * 0.1;
		  
		skew +=game.deltaTime * 1;
 
		logo.skewX = Math.sin(skew)*1;
		logo.skewY = Math.cos(skew)*1;
		
		  
	batch.Begin();


  	  batch.drawEntity(logo);
	  batch.drawEntity(player,true);

	   		
      for(p in particles)
      {
         p.move(game.deltaTime);
	
        batch.drawImage(p);
      }

	  
      batch.End();
	

	}

		
		


public function addParticle()
{
	var particle:Particle = new Particle(tex);
	particle.Init();
	particle.blendMode = BlendMode.NORMAL;
    particles.push(particle);
}

override public function mouseDown(mousex:Float, mousey:Float) 
{

	player.x = mousex;
	player.y = mousey;
}

	
	
}