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
		//tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		tilemap = new TileMap(Assets.getText ("assets/sewers.tmx"));
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



	

 public function renderMap(pointx:Float,pointy:Float)
	{
		
	

		var tw:Int = Math.ceil(tilemap.tileWidth), th:Int = Math.ceil(tilemap.tileHeight);

	

		// determine start and end tiles to draw (optimization)
		var startx = Math.floor( -pointx / tw ),
			starty = Math.floor( -pointy / th ),
			destx = startx + 1 + Math.ceil(Game.viewWidth  / tw ),
			desty = starty + 1 + Math.ceil(Game.viewHeight / th );

		// nothing will render if we're completely off screen
		if (startx > tilemap.widthInTiles || starty > tilemap.heightInTiles || destx < 0 || desty < 0)
			return;

		// clamp values to boundaries
		if (startx < 0) startx = 0;
		if (destx > tilemap.widthInTiles) destx = tilemap.widthInTiles;
		if (starty < 0) starty = 0;
		if (desty > tilemap.heightInTiles) desty = tilemap.heightInTiles;

		var wx:Float, sx:Float = (pointx + startx * tw ) ,
			wy:Float = (pointy + starty * th ) ,
			stepx:Float = tw ,
			stepy:Float = th ,
			tile:Int = 0;

		// adjust scale to fill gaps
		var scx = Math.ceil(stepx) / tilemap.tileWidth;
		var scy = Math.ceil(stepy) / tilemap.tileHeight;

		for (y in starty...desty)
		{
			wx = sx;
			for (x in startx...destx)
			{
				
				var id =  tilemap.getCell(x%tilemap.widthInTiles, y%tilemap.heightInTiles);
				if (id >= 1)
				{
					var t:Clip = tilemap.getClip(id - 1);
					
					
					 batch.RenderTile(tilemap.image,Math.round(wx),Math.round(wy), tilemap.tileWidth*scx,tilemap.tileHeight*scy, t, false, true, 0);
					 //batch.RenderTileScale(tilemap.image,Math.round(wx),Math.round(wy),tilemap.tileWidth,tilemap.tileHeight, scx, scy, t, false, true, 0);
				}				
	  		wx += stepx;
			}
			wy += stepy;
		}
	}
	
	override public function render(dt:Float) 
	{ 
	
				var tw:Int = tilemap.tileWidth;
				var th:Int = tilemap.tileHeight;
				
		
		batch.Begin();	
		
	//draw_orthogonal(scroll, 0, 480,320, 20, 20);
	renderMap(position.x, position.y);
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