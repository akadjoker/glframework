package com.djoker.glteste;
 
import flash.display.BlendMode;
import flash.display.Sprite;
import flash.geom.ColorTransform;
import flash.geom.Rectangle;
import flash.geom.Matrix3D;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.events.MouseEvent;



import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;
import openfl.Assets;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.utils.ByteArray;
import flash.Lib;


	#if cpp

//import sys.io.File;
//import sys.io.FileOutput;
		#end


import com.engine.game.Game;

import flash.text.TextField;
import flash.text.TextFormat;



class Main extends Game {

   




override function begin() 
{

//	fixRatio(480, 320);
 
/*
var bmp:BitmapData = new BitmapData(32, 32, false);
bmp.draw(bitmapData, null, null, BlendMode.INVERT, new Rectangle(0, 0, 32, 32));
//bmp.draw(this.drawArea,null,null,null,null,true);

var b:ByteArray = bmp.encode("png");
var f:FileOutput = File.write("test.png");
f.writeString(b.toString());
//trace(b.toString());
f.close();
*/
//spr = new Bitmap(bitmapData);
//Lib.current.stage.addChild(spr);



//this.setScreen(new TesteBatch());
//this.setScreen(new TesteAtlas());
//this.setScreen(new TestneBatch());
//this.setScreen(new TesteCloud());
//this.setScreen(new TesteCloudTiles());
//this.setScreen(new TesteBatchTiles());
this.setScreen(new TesteTiles());
//this.setScreen(new TestePrimitives());
//this.setScreen(new TesteBitmap());
//this.setScreen(new TesteDraTiles());


}




	
 
}