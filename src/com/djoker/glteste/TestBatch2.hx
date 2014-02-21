package com.djoker.glteste;

import com.engine.game.Screen;
import com.engine.game.Screen;
import com.engine.render.Batch;
import com.engine.render.Texture;
import com.engine.render.OrthoCamera;
/**
 * ...
 * @author djoker
 */
class TesteBatch2 extends Screen
{

	
 var tex :Texture;
 var batch:Batch;
 var camera:OrthoCamera;



   var particles : Array<Particle>;

	
	override public function show()
	{
	
		tex = new Texture("assets/texture.png");
        camera = new OrthoCamera(640,480);
        batch = new Batch(tex,camera,500);
        particles = [];
        for(i in 0...100)
         addParticle();

	}
	override public function hide() 
	{ }
	override public function render(dt:Float) 
	{ 
   camera.Update();
   batch.Begin();

     // for(p in particles)
    //  {
     //    p.move(dt);
     //   batch.drawImage(p);
    //  }
	
	 for(i in 0...particles.length)
      {
		  var p:Particle = particles[i];
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