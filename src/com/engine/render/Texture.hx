package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.utils.UInt8Array;

import flash.display.Bitmap;
import flash.utils.ByteArray;
import flash.geom.Matrix;
import flash.display.BitmapData;
import flash.Lib;

import openfl.Assets;

import com.engine.misc.Util;



	#if neko

import sys.io.File;
import sys.io.FileOutput;
		#end
		

/**
 * ...
 * @author djoker
 */
class Texture
{
    public var data:GLTexture;
	public var width:Int;	
	public var height:Int;
	public var texHeight:Int;
	public var texWidth:Int;
	public var name:String;
	private var exists:Bool;
	public var invTexWidth:Float;
	public var invTexHeight:Float;
	
	public function Bind()
	{
	 if (!exists) return;
     GL.bindTexture(GL.TEXTURE_2D, data);
	}

	public function setData(bitmapData:BitmapData, ?flip:Bool = false,?newname:String="bitmap" )
	{
		exists = false;
		if (bitmapData==null) return ;
		
		this.name = newname;
	
	if (flip)
	{
	bitmapData = Util.flipBitmapData(bitmapData);
	}
    data = GL.createTexture ();	
	GL.bindTexture(GL.TEXTURE_2D, data);
		
		this.width = bitmapData.width;
		this.height = bitmapData.height;

		this.texWidth =  Util.getNextPowerOfTwo(width);
		this.texHeight = Util.getNextPowerOfTwo(height);
	
		
			
		 var isPot = (bitmapData.width == texWidth && bitmapData.height == texHeight);

			
	GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
    GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
    GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
	GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST);

			
			if (!isPot)
			{
			var workingCanvas:BitmapData = Util.getScaled(bitmapData,texWidth, texHeight);
									
			#if html5
			var pixelData = workingCanvas.getPixels(workingCanvas.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(workingCanvas));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, workingCanvas.width, workingCanvas.height, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
			
		
#if neko
/*
  var b:ByteArray = workingCanvas.encode("png");
  var f:FileOutput = File.write("rescale.png");
  f.writeString(b.toString());
  f.close();
  */
#end
        
#if !html5
//workingCanvas.dispose();
#end
				
			} else
			{
													
			#if html5
			var pixelData = bitmapData.getPixels(bitmapData.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(bitmapData));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, texWidth, texHeight, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
      		}
			
	#if !html5
			//	bitmapData.dispose();
     #end

		     invTexWidth  = 1.0 / texWidth;
             invTexHeight = 1.0 /texHeight;
	
			exists = true;
	}
	public function load(url:String, ?flip:Bool = false ) 
	{
	name = url;
	var  bitmapData:BitmapData ;	
    bitmapData = Assets.getBitmapData(url);
	if (bitmapData==null) return ;
	
	if (flip)
	{
	bitmapData = Util.flipBitmapData(bitmapData);
	}
    data = GL.createTexture ();	
	GL.bindTexture(GL.TEXTURE_2D, data);
		
		this.width = bitmapData.width;
		this.height = bitmapData.height;

		this.texWidth =  Util.getNextPowerOfTwo(width);
		this.texHeight = Util.getNextPowerOfTwo(height);
	
		
			
		 var isPot = (bitmapData.width == texWidth && bitmapData.height == texHeight);
		  

			
	GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
    GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
    GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
	GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST);

			
			if (!isPot)
			{
			var workingCanvas:BitmapData = Util.getScaled(bitmapData,texWidth, texHeight);
			#if html5
			var pixelData = workingCanvas.getPixels(workingCanvas.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(workingCanvas));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, workingCanvas.width, workingCanvas.height, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
			
		
#if neko

  var b:ByteArray = workingCanvas.encode("png");
  var f:FileOutput = File.write("rescale.png");
  f.writeString(b.toString());
  f.close();
  
#end

#if !html5
//workingCanvas.dispose();
#end
				
				
			} else
			{
													
			#if html5
			var pixelData = bitmapData.getPixels(bitmapData.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(bitmapData));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, texWidth, texHeight, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
      		}

	
	#if !html5
			//	bitmapData.dispose();
     #end

		     invTexWidth  = 1.0 / texWidth;
             invTexHeight = 1.0 /texHeight;

       
			exists = true;
	
		
	}
	public function new() 
	{
		this.width =0;
		this.height = 0;
		this.texWidth = 0;
		this.texHeight = 0;
		exists = false;
			 //GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_NEAREST);
             //GL.generateMipmap(GL.TEXTURE_2D);
		    // GL.bindTexture(GL.TEXTURE_2D, null);
          
		 
	}
	
	public function dispose()
	{
		GL.deleteTexture(data);
	}
	
	
}