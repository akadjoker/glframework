package com.djoker.glteste;

import com.engine.game.Screen;
import flash.geom.Rectangle;

import openfl.Assets;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.utils.ByteArray;
import flash.Lib;

import com.engine.direct.TileBatch;
import com.engine.direct.TileImage;


class MoveSprite extends TileImage
{
	var dx:Float;
   var dy:Float;
   var da:Float;


   
	public function init() 
	{
		 
      x = 320;
      y = 240;
      this.Rotation = 0;
      dx = Math.random()*200.0 - 100.0;
      dy = Math.random()*200.0 - 100.0;
      da = Math.random() * 10.2 - 12.1;
	  
	 
	
   
     Red = Math.random();
     Green = Math.random();
      Blue = Math.random();
      Alpha = Math.random();
	 

      ScaleX =  Math.random() * 1.1 + 0.1;
	  ScaleY =  Math.random() * 1.1 + 0.1;
	}



	override public function update():Void 
	{
		move(0.03);
	}


   public function move(dt:Float)
   {
      var rad = 30 * ScaleX;

      x+=dx*dt;
      if (x<rad)
      {
         x = rad;
         dx = -dx;
      }
      if (x>640-rad)
      {
         x = 640-rad;
         dx = -dx;
      }

      y+=dy*dt;
      if (y<rad)
      {
         y = rad;
         dy = -dy;
      }
      if (y>480-rad)
      {
         y = 480-rad;
         dy = -dy;
      }

      this.Rotation += da;


   }
}
	

/**
 * ...
 * @author djoker
 */
class TesteDraTiles extends Screen
{
    var bitmapData:BitmapData;
	var batch:TileBatch;
   
  
	override public function show()
	{
		 bitmapData = Assets.getBitmapData("assets/zazaka.png");
	     batch = new TileBatch(bitmapData);
		 batch.addTileRect(new Rectangle(0, 0, 64, 64));
		 for (i in 0...200) 
		 {
			 var  spr = new MoveSprite(0, 0, 0);
			 spr.init();
		 batch.add(spr);
		 }
		 Lib.current.stage.addChild(batch);
		  
	
	}
	
	override public function render(dt:Float) 
	{
    // batch.render();
	}

}