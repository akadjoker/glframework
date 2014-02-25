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
import com.engine.render.TileMapCache;
import com.engine.input.Keys;



/**
 * ...
 * @author djoker
 */
class TesteBlockTilesCache extends Screen
{



  var batch:BatchPrimitives;
 
 
 var Toutch:Vector2 ;
 var lastToutch:Vector2;
  var toutch:Bool=false;



 var shader:SpriteShader;
 var tilemap:TileMapCache;

 var caption:TextField;
 
 
	
	override public function show()
	{
	

		batch = new  BatchPrimitives( 500);
	
	
		 Toutch = new Vector2(0, 0);
		 lastToutch = new Vector2(0, 0);
		
		 
		//tilemap = new TileMap(Assets.getText ("assets/scrol.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		tilemap = new TileMapCache(Assets.getText ("assets/sewers.tmx"), 10, 10);
		
		//tilemap.buildSegments(10,10);
		//tilemap = new TileMapCache(Assets.getText ("assets/desert.tmx"),5,5);
		
      //  batch = new SpriteBatch(  1000);
		//trace( "map : w" + tilemap.widthInTiles + " h:" + tilemap.heightInTiles);
		
			
		 
		  caption = new TextField();
		 caption.x =  game.screenWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.selectable = false;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test  statics sprites ";
		 game.addChild(caption);
		 

		 
		 
		 

		
		}

		
	

	override public function render() 
	{ 
	

	//tilemap.renderSegments(game.gameWidth, game.gameHeight);
	
	// tilemap.renderLayer(800,800,0);
	tilemap.render();


	

	batch.begin();


	batch.line(10, 10, 100, 100, 1, 0, 1);
	batch.rect(100, 100, 90, 120, 1, 1, 1);
	batch.circle(100, 100, 12, 8, 1, 1, 1, 1);
	batch.ellipse(300, 90, 55, 15, 8, 1, 1, 1, 1);
 //   batch.rect(5, 5, game.screenWidth - 5, game.screenHeight - 5, 1, 0, 0);
	//batch.rect(5,5, game.gameWidth-5, game.gameHeight-5, 0, 1, 0);

	batch.fillrect(200, 200, 50, 50, 1, 0, 0, 1);
	batch.fillrect(280, 200, 50, 50, 0, 1, 1, 1);
	batch.fillcircle(200, 100, 8, 18, 1, 0, 1, 1);
	batch.fillellipse(300, 100, 55, 15, 8, 0, 1, 1, 1);

	batch.line(lastToutch.x, lastToutch.y, Toutch.x, Toutch.y, 1, 0, 0);
	
	tilemap.renderAABB(batch);
	
	batch.end();
	
	
	caption.text = "Scrolx:" +Game.camera.scrollX + "  Scroly:" + Game.camera.scrollY + "Blocks " +tilemap.layers[0].drawBlocks;
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
	     tilemap.position.x += dx;
	     tilemap.position.y += dy;
         Toutch.x = mousex;
		 Toutch.y = mousey;
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}
	
	override public function keyDown(key:Int) 
	{
		//trace(key);
		
		if (key == Keys.A)
		{
			Game.camera.scrollX -= 100 *  Game.dt;
		} else
			if (key == Keys.D)
		{
			Game.camera.scrollX += 100 *  Game.dt;
		} 
			
		if (key == Keys.W)
		{
			Game.camera.scrollY -= 100 *  Game.dt;
		} else
			if (key == Keys.S)
		{
			Game.camera.scrollY += 100 * Game.dt;
		}
	
	}
		


	
	
}