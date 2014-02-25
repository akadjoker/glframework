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
class TesteBatchTiles extends Screen
{



  var batch:BatchPrimitives;
 
 
 var Toutch:Vector2 ;
 var lastToutch:Vector2;
  var toutch:Bool=false;





 var blocks:Array<Block>;
 var shader:SpriteShader;
 var tilemap:TileMap;

 
 
 	        var segmentWidth:Int=5;
			var segmentHeight:Int = 5;
			var segmentCols:Int = 0;
			var segmentRows:Int = 0;
			var numSegments:Int = 0;
	
	override public function show()
	{
	

		batch = new  BatchPrimitives( 500);
	
	
		 Toutch = new Vector2(0, 0);
		 lastToutch = new Vector2(0, 0);
		
		 
		//tilemap = new TileMap(Assets.getText ("assets/scrol.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/map.tmx"));
		tilemap = new TileMap(Assets.getText ("assets/sewers.tmx"));
		//tilemap = new TileMap(Assets.getText ("assets/desert.tmx"));
		
      //  batch = new SpriteBatch(  1000);
		//trace( "map : w" + tilemap.widthInTiles + " h:" + tilemap.heightInTiles);
		
			
		 /*
		 var caption:TextField = new TextField();
		 caption.x =  game.screenWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Test  statics sprites ";
		 game.addChild(caption);
		 
*/
		 
		 
		 

	 blocks = new  Array<Block>();
		

			var tilesetCols:Int = Math.floor(tilemap.image.width / tilemap.tileWidth);
			var tilesetRows:Int = Math.floor(tilemap.image.height / tilemap.tileHeight);
			
			var viewWidthInTiles:Int  = Std.int(game.gameWidth/ tilemap.tileWidth);
			var viewHeightInTiles:Int = Std.int(game.gameHeight/ tilemap.tileHeight);
			
			var cols:Int = tilemap.widthInTiles;
			var rows:Int = tilemap.heightInTiles;
		
			
			segmentWidth = segmentWidth == -1 ? (cols < viewWidthInTiles * 2 ? cols : viewWidthInTiles) : segmentWidth;
			segmentHeight = segmentHeight == -1 ? (rows < viewHeightInTiles * 2 ? rows : viewHeightInTiles) : segmentHeight;
			segmentCols = Math.ceil(cols / segmentWidth);
			segmentRows = Math.ceil(rows / segmentHeight);
			
			for (y in 0...segmentCols)
			{
				for (x in 0...segmentRows) 
				{
					var sw:Int = x == segmentCols - 1 && cols % segmentWidth != 0 ? cols % segmentWidth : segmentWidth;
					var sh:Int = y == segmentRows - 1 && rows % segmentHeight != 0 ? rows % segmentHeight : segmentHeight;
					blocks.push(new Block(sw, sh));
					numSegments++;
				}
			}

			
			var uvWidth:Float  = 1 / (tilemap.image.width / tilemap.tileHeight);
			var uvHeight:Float = 1 / (tilemap.image.height / tilemap.tileWidth);
		
			
            var tid:Int = 0;
			var index:Int=0;
	
			for (y in 0...rows)
			{
				for (x in 0...cols) 
				{
	
					var segmentRow:Int = Std.int(y / segmentHeight);
					var segmentCol:Int = Std.int(x / segmentWidth);
					var segmentOffset:Int = segmentRow * segmentCols + segmentCol;
					var segment:Block = blocks[segmentOffset];
					
					tid = tilemap.getCell(x, y);
					if (tid == 0) 
					{
						continue;
					}
					tid -= 1;

					
					var tx:Int = x * tilemap.tileWidth;
					var ty:Int = y * tilemap.tileHeight;
					var u:Float = (tid % tilesetCols) * uvWidth;
					var v:Float = Math.floor(tid / tilesetCols) * uvHeight;
				
					
					
					segment.addVertex(tx + Util.EPSILON, 	ty + Util.EPSILON,	u,				v);
					segment.addVertex(tx + tilemap.tileWidth,		ty + Util.EPSILON,	u + uvWidth,	v);
					segment.addVertex(tx + Util.EPSILON,	ty + tilemap.tileHeight,	u,				v + uvHeight);
					segment.addVertex(tx + tilemap.tileWidth,		ty + tilemap.tileHeight,	u + uvWidth,	v + uvHeight);
					
					segment.indices.push(segment.index + 0);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 1);
					segment.indices.push(segment.index + 2);
					segment.indices.push(segment.index + 3);
					
					
					
					segment.index += 4;
						
				}
			}	
			
			shader = new  SpriteShader();
			
		for (i in 0...blocks.length)
		{
		 blocks[i].build();
		}

		
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
	override public function render(dt:Float) 
	{ 
	
		


   
   shader.Enable();
   shader.setTexture(tilemap.image);
   shader.setMatrix();
   
   
   var vWidth:Int = game.screenWidth;
   var vHeight:Int = game.screenHeight;
   var x:Float = 0;
   var y:Float = 0;
   
   
            var minXSegment:Int = Math.floor((0 ) / tilemap.tileWidth / segmentWidth);
			var maxXSegment:Int = Math.floor((0 + vWidth ) / tilemap.tileWidth / segmentWidth);
			var minYSegment:Int = Math.floor((0 ) / tilemap.tileHeight / segmentHeight);
			var maxYSegment:Int = Math.floor((0 + vHeight) / tilemap.tileHeight / segmentHeight);
			for ( sx in minXSegment...maxXSegment) 
			{
				for (sy in minYSegment...maxYSegment) 
				{
					var si:Int = sy * segmentCols + sx;
					if (si < 0 || si >= blocks.length) {
						continue;
					}
					blocks[si].render();
					
				}
			}
			
				
   
 
   shader.Disable();
	

	

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
		lastToutch.x = mousex;
		lastToutch.y = mousey;
	
		
	}		
	override public function mouseMove(mousex:Float, mousey:Float) 
	{
		
		if (toutch==true)
		{
			
			Toutch.x = mousex;
			Toutch.y = mousey;
	
			
		var dir:Vector2 = Vector2.Sub(Toutch, lastToutch);
		dir.normalize();
	
		batch.position.x += (dir.x * game.deltaTime*100);
		batch.position.y += (dir.y * game.deltaTime*100);
		
		}
	}
	override public function mouseUp(mousex:Float, mousey:Float) 
	{
		toutch = false;
	}
		


	
	
}