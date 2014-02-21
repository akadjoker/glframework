package com.djoker.glteste;

import com.engine.render.Clip;
import flash.display.Bitmap;
import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

import openfl.Assets;
import flash.Lib;
import com.engine.game.Screen;
import com.engine.game.Game;
import com.engine.render.SpriteBatch;
import com.engine.render.BatchPrimitives;
import com.engine.render.Texture;
import com.engine.render.TileMap;
import com.engine.misc.Util;

import com.engine.math.Vector2;
import com.engine.math.Vector3;



/**
 * ...
 * @author djoker
 */
class TesteBatchTiles extends Screen
{


 var batch:SpriteBatch;
 var primitives:BatchPrimitives;
 var tilemap:TileMap;
 var lastmouseX:Float;
 var lastmouseY:Float;
 var mouseX:Float;
 var mouseY:Float;
 var toutch:Bool;
 var distx:Float;
 var disty:Float;
 var Toutch:Vector3 ;
 var lastToutch:Vector3;
 var position:Vector3;
 var scroll:Int = 0;
	
	override public function show()
	{
	
       	
		primitives = new BatchPrimitives( 100);
		//tilemap = new TileMap(Assets.getText ("assets/scrol.tmx"));
		tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/sewers.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/desert.tmx"));
		
        batch = new SpriteBatch(  3000);
		//trace( "map : w" + tilemap.widthInTiles + " h:" + tilemap.heightInTiles);
		
			
		 
		 var caption:TextField = new TextField();
		 caption.x =  game.screenWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test  statics sprites ";
		 game.addChild(caption);
		 
		 Toutch = new Vector3(0, 0);
		 lastToutch = new Vector3(0, 0);
		 
		 position = new   Vector3(0, 0, 0);
		 

	}

	    public function renderTiles( x:Float , y:Float ,  sx:Int ,  sy:Int ,  width:Int ,  height:Int)
	     {
	    		
	    	      for (ty in 0...height) 
	    	      {
	    	      renderTile(x,y,sx,sy,width,ty);
	    	      }
	    		
	    
	     }
	public function renderTile( x:Float , y:Float ,  sx:Int ,  sy:Int ,  width:Int ,  ty:Int )
	{
			 var tw:Int = tilemap.tileWidth;
			var th:Int = tilemap.tileHeight;
			
	 			for ( tx in 0...width)
	 			{
	 				if ((sx+tx < 0) || (sy+ty < 0)) 
	 				{
	 					continue;
	 				}
	 				if ((sx+tx >= tilemap.widthInTiles) || (sy+ty >= tilemap.heightInTiles)) {
						continue;
					}
					
				var id =  tilemap.getCell(sx+tx, sy+ty);
				if (id >= 1)
				{
					var t:Clip = tilemap.getClip(id - 1);
					
					 var x:Float = x+(tx*tw);
			         var y:Float = y+(ty*(th));
					 batch.RenderTile(tilemap.image,x,y,tw,th,t, false, true,0);
				}		
					
				}
	}
	


	public function draw_orthogonal( sx:Float,  sy:Float,  sw:Float,  sh:Float,  dx:Float,  dy:Float)
	{
            var tw:Int = tilemap.tileWidth;
			var th:Int = tilemap.tileHeight;
				
	var mx, my:Int=0;
	var ystart:Int = Std.int(sy / th);
	var yend:Int = Std.int((sy + sh) / th);
	var xstart:Int = Std.int(sx / tw);
	var xend:Int = Std.int((sx + sw) / th);
	
	
	for (my in  ystart...yend) 
	{
		for (mx in xstart...xend)
		{
			
				
				var id =  tilemap.getCell(mx, my);
				if (id >= 1)
				{
					var t:Clip = tilemap.getClip(id - 1);
					
					var x:Float = mx*tw - sx + dx;
			        var y:Float = my*th - sy + dy;
					 batch.RenderTile(tilemap.image,x,y,tw,th,t, false, true,0);
				}				
		}
	}
}
	override public function render(dt:Float) 
	{ 
	
				var tw:Int = tilemap.tileWidth;
				var th:Int = tilemap.tileHeight;
				
		
		batch.Begin();	
		
	draw_orthogonal(scroll, 0, 480,320, 20, 20);
	//scroll++;
//	renderTiles(0,0, scroll,5, 22,22);
					
/*
		for (y in 0...tilemap.heightInTiles)
		{
			for (x in 0...tilemap.widthInTiles)
			{

					
				var id =  tilemap.getCell(x, y);
				if (id >= 1)
				{
					//id = 2;
					var t:Clip = tilemap.getClip(id - 1);
					//var t:Clip = tilemap.getClipNum(id - 1);
					
					
					   var DrawX:Int =Std.int(position.x+ (x * tw));
                       var DrawY:Int =Std.int(position.y+ (y * th));
					   
					 var dst:Clip = new Clip(DrawX, DrawY, tw, th);
					 
					// batch.RenderTile(tilemap.image,x*tw-0.5,y*th-0.5,tw,th,t, false, true,0);
             		batch.Blt(tilemap.image, dst,t, false, true,  0);	
					//batch.RenderClip(tilemap.image, x*tw,y*th, t, false, true,  0);	
				}
			}
		}
	*/

    batch.End();
		

	primitives.begin();
	primitives.renderMode(false);

	primitives.line(lastToutch.x, lastToutch.y, Toutch.x, Toutch.y, 1, 0, 0);
	
	primitives.render();
	primitives.end;

    }

	override public function keyDown(key:Int) 
	{
		if (key == 65) scroll--;
		if (key == 68) scroll++;
		
	}
		
	override public function mouseDown(mousex:Float, mousey:Float) 
	{
		toutch = true;
		lastToutch.x = mousex;
		lastToutch.y = mousey;
		//lastToutch=camera.unproject(lastToutch);
		
		
	}		
	override public function mouseMove(mousex:Float, mousey:Float) 
	{
		
		if (toutch==true)
		{
			
			Toutch.x = mousex;
			Toutch.y = mousey;
		//	Toutch=camera.unproject(Toutch);
	
			
		var dir:Vector3 = Vector3.Sub(Toutch, lastToutch);
		dir.normalize();
		
		//camera.position = Vector3.Add(camera.position, dir);
		position.x += (dir.x * game.deltaTime*1000);
		position.y += (dir.y * game.deltaTime*1000);
		
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}
	
	
}