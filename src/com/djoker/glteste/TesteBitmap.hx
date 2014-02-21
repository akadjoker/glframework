package com.djoker.glteste;

import openfl.Assets;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.utils.ByteArray;
import flash.Lib;



import com.engine.game.Screen;

/**
 * ...
 * @author djoker
 */
class TesteBitmap extends Screen
{

	var particles : Array<Movable>;
    var bitmapData:BitmapData;

   
  
public function addParticle()
{
	var particle:Movable = new Movable(bitmapData);
	particle.init();
    particles.push(particle);
	Lib.current.stage.addChild(particle);
}

	override public function show()
	{
		 bitmapData = Assets.getBitmapData("assets/zazaka.png");
		particles = [];
        for(i in 0...200)
         addParticle();
	}
	
	override public function render(dt:Float) 
	{
      for(p in particles)
      {
         p.move(dt);
      }

	}

}