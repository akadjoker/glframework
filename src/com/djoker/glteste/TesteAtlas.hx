package com.djoker.glteste;

import com.engine.game.Screen;
import com.engine.render.SpriteAtlas;
import com.engine.render.Texture;
import com.engine.render.OrthoCamera;

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
 var camera:OrthoCamera;



   var particles : Array<Particle>;

	
	override public function show()
	{
	
		tex = new Texture("assets/texture.png");
        camera = new OrthoCamera(640,480);
        batch = new SpriteAtlas(tex,camera,500);
        particles = [];
        for(i in 0...200)
         addParticle();
		 var caption:TextField = new TextField();
		 caption.x =  game.screnWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = " Test 200 sprites with SpriteAtlas";
		 game.addChild(caption);

	}

	override public function render(dt:Float) 
	{ 
   camera.Update();
   batch.Begin();

      for(p in particles)
      {
         p.move(dt);
	    batch.drawImage(p);
      }
      batch.End();
	}
	override public function resize(width:Int, height:Int) 
	{
	game.setViewPort(0, 0, width, height);
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