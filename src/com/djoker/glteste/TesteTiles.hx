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
class TesteTiles extends Screen
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
	   
	   position = new Vector3(0, 0, 0);
	   
		
		primitives = new BatchPrimitives( 100);
		//tilemap = new TileMap(Assets.getText ("assets/scrol.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/sewers.tmx"));
		tilemap = new TileMap(Assets.getText ("assets/desert.tmx"));
		
       // batch = new SpriteBatch( camera, 3000);
		//trace( "map : w" + tilemap.widthInTiles + " h:" + tilemap.heightInTiles);
		
			
		 
	
		 Toutch = new Vector3(0, 0);
		 lastToutch = new Vector3(0, 0);
		 

	}
	
	
	override public function keyDown(key:Int) 
	{
		if (key == 65) scroll--;
		if (key == 68) scroll++;
		
	}

	override public function render(dt:Float) 
	{ 

	
	tilemap.render();
	//tilemap.renderDinamic(0,0);
	
	
		

	primitives.begin();

	primitives.line(lastToutch.x, lastToutch.y, Toutch.x, Toutch.y, 1, 0, 0);
	
	primitives.end;
	
    }

		
		
	override public function mouseDown(mousex:Float, mousey:Float) 
	{
		toutch = true;
		lastToutch.x = mousex;
		lastToutch.y = mousey;

		
	}		
	override public function mouseMove(mousex:Float, mousey:Float) 
	{
		
		if (toutch==true)
		{
			
			Toutch.x = mousex;
			Toutch.y = mousey;
	
			
		var dir:Vector3 = Vector3.Sub(Toutch, lastToutch);
		dir.normalize();
		
		//camera.position = Vector3.Add(camera.position, dir);
		tilemap.position.x += (dir.x * game.deltaTime*1000);
		tilemap.position.y += (dir.y * game.deltaTime*1000);
			
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}
	
	
}