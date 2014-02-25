package com.djoker.glteste;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;


import flash.display.Bitmap;
import flash.events.Event;
import flash.text.TextField;
import flash.text.TextFormat;

import openfl.Assets;
import flash.Lib;

import com.engine.game.Screen;
import com.engine.game.Game;
import com.engine.misc.Util;
import com.engine.render.Clip;
import com.engine.math.Vector2;
import com.engine.render.BatchPrimitives;

import com.engine.render.Block;
import com.engine.render.SpriteShader;
import com.engine.render.SpriteBatch;
import com.engine.render.Texture;
import com.engine.render.TileMap;



/**
 * ...
 * @author djoker
 */
class TesteBlockTiles extends Screen
{



  var batch:BatchPrimitives;
 
 
 var Toutch:Vector2 ;
 var lastToutch:Vector2;
  var toutch:Bool=false;



 var shader:SpriteShader;
 var tilemap:TileMap;

 var caption:TextField;
 
 
	
	override public function show()
	{
	

		batch = new  BatchPrimitives( 500);
	
	
		 Toutch = new Vector2(0, 0);
		 lastToutch = new Vector2(0, 0);
		
		 
		//tilemap = new TileMap(Assets.getText ("assets/scrol.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/sewers.tmx"));
		//tilemap.buildSegments(10,10);
		tilemap = new TileMap(Assets.getText ("assets/desert.tmx"));
		
      //  batch = new SpriteBatch(  1000);
		//trace( "map : w" + tilemap.widthInTiles + " h:" + tilemap.heightInTiles);
		
			
		 
		  caption = new TextField();
		 caption.x =  game.screenWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test  statics sprites ";
		 game.addChild(caption);
		 

		 
		 
		 

		
		}

		
	

	/*

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
	*/
	override public function render() 
	{ 
	
	//tilemap.renderSegments(game.gameWidth, game.gameHeight);
	
	
	tilemap.render();


	

	batch.begin();


	batch.line(10, 10, 100, 100, 1, 0, 1);
	batch.rect(100, 100, 90, 120, 1, 1, 1);
	batch.circle(100, 100, 12, 8, 1, 1, 1, 1);
	batch.ellipse(300, 90, 55, 15, 8, 1, 1, 1, 1);

	batch.fillrect(200, 200, 50, 50, 1, 0, 0, 1);
	batch.fillrect(280, 200, 50, 50, 0, 1, 1, 1);
	batch.fillcircle(200, 100, 8, 18, 1, 0, 1, 1);
	batch.fillellipse(300, 100, 55, 15, 8, 0, 1, 1, 1);

	batch.line(lastToutch.x, lastToutch.y, Toutch.x, Toutch.y, 1, 0, 0);
	
	batch.end();
	
	
	
    }

		
override public function mouseDown(mousex:Float, mousey:Float) 
	{
		toutch = true;
		Toutch.x = mousex;
		Toutch.y = mousey;
		
		
	}		
	override public function mouseMove(mousex:Float, mousey:Float) 
	{
		
		if (toutch==true)
		{
     	 var dx = mousex - Toutch.x;
	     var dy = mousey - Toutch.y;
	     Game.camera.scrollX -= dx;
	     Game.camera.scrollY -= dy;
         Toutch.x = mousex;
		 Toutch.y = mousey;
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}


	
	
}