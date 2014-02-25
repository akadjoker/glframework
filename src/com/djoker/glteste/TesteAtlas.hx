package com.djoker.glteste;

import com.engine.game.Screen;
import com.engine.render.SpriteAtlas;
import com.engine.render.Texture;

import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

/**
 * ...
 * @author djoker
 */
class TesteAtlas extends Screen
{

	
 var tex :Texture;
 var batch:SpriteAtlas;
 


   var particles : Array<Particle>;

	
	override public function show()
	{
	
		tex =getTexture("assets/texture.png");
		
        batch = new SpriteAtlas(tex,500);
        particles = [];
        for(i in 0...200)
         addParticle();
		 var caption:TextField = new TextField();
		 caption.x =  game.screenWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.selectable = false;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = " Test 200 sprites with SpriteAtlas";
		 game.addChild(caption);
		 game.clarColor(0, 0, 0);

	}

	override public function render() 
	{ 

   batch.Begin();

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
    particles.push(particle);
}
public function addParticle2(x:Float,y:Float)
{
	var particle:Particle = new Particle(tex);
	particle.Init();
	particle.x = x;
	particle.y=y;
    particles.push(particle);
}

override public function mouseDown(mousex:Float, mousey:Float) 
{
	addParticle2(mousex, mousey);
}

	
	
}