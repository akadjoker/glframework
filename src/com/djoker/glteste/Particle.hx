package com.djoker.glteste;
import com.engine.render.Image;

/**
 * ...
 * @author djoker
 */

class Particle extends Image
{

   var dx:Float;
   var dy:Float;
   var da:Float;


   public function Init()
   {
	 
      x = 320;
      y = 240;
      angle = 0;
      dx = Math.random()*200.0 - 100.0;
      dy = Math.random()*200.0 - 100.0;
      da = Math.random() * 0.2 - 0.1;
	  
	  var frame:Int =  Std.random(4*4);
	  var columns:Int = 4;
	  
	  var w:Int = 32;
	  var h:Int = 32;

	  
	  	//_rect.x = _rect.width * (frame % _columns);
		//_rect.y = _rect.height * Std.int(frame / columns);
		
			
	  	//var tx:Int = x * tileWidth;
		//var ty:Int = y * tileHeight;
		//var u:Number = (tid % columns) * uvWidth;
		//var v:Number = Math.floor(tid / columns) * uvHeight;
				
	//clip.width = 32;
	//clip.height = 32;
	
	//  clip.right  = 30  * (frame % columns);
	//  clip.bottom = 20  * Std.int(frame / columns);
	
	clip.set(w * (frame % columns), h * Std.int(frame / columns), w, h);
	
    
      red =1; Math.random();
      green = Math.random();
      blue = Math.random();
      alpha = Math.random();

      scaleX = 0.2;// Math.random() * 1.1 + 0.1;
	  scaleY = 0.2;// Math.random() * 1.1 + 0.1;
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

      angle += da;


   }
}