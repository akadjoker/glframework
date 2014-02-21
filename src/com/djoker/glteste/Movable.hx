package com.djoker.glteste;
import flash.display.Bitmap;

/**
 * ...
 * @author djoker
 */
class Movable extends Bitmap
{

   var dx:Float;
   var dy:Float;
   var da:Float;
 //  var x:Float;
 //  var y:Float;

   
	public function init() 
	{
		 
      x = 320;
      y = 240;
      this.rotation = 0;
      dx = Math.random()*200.0 - 100.0;
      dy = Math.random()*200.0 - 100.0;
      da = Math.random() * 360.2 - 180.1;
	  
	 
	
   
   //   red =1; Math.random();
   //   green = Math.random();
   //   blue = Math.random();
      alpha = Math.random();
	 

      scaleX =  Math.random() * 1.1 + 0.1;
	  scaleY =  Math.random() * 1.1 + 0.1;
	}







   public function move(dt:Float)
   {
      var rad = 30 * scaleX;

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

      this.rotation += da;


   }
}