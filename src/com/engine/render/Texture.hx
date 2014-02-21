package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.utils.UInt8Array;

import flash.display.Bitmap;
import flash.geom.Matrix;
import flash.display.BitmapData;
import flash.Lib;

import openfl.Assets;

import com.engine.misc.Util;
import com.engine.misc.MatrixHelp;

/**
 * ...
 * @author djoker
 */
class Texture
{
    public var data:GLTexture;
	private var  bitmapData:BitmapData ;
	public var width:Int;	
	public var height:Int;
	public var texHeight:Int;
	public var texWidth:Int;
	
	public function Bind()
	{
     GL.bindTexture(GL.TEXTURE_2D, data);
	}

	public function new(url:String) 
	{
	

		
	       bitmapData = Assets.getBitmapData(url);
	//   bitmapData = flipBitmapData(bitmapData);
		  
	   
	   	    data = GL.createTexture ();	
	        GL.bindTexture(GL.TEXTURE_2D, data);
		
	
	
			
		this.width = bitmapData.width;
		this.height = bitmapData.height;

		this.texWidth =  Util.getNextPowerOfTwo(width);
		this.texHeight = Util.getNextPowerOfTwo(height);
	
	//	trace(this.texWidth +"<>"+ this.texHeight);
			
		 var isPot = (bitmapData.width == texWidth && bitmapData.height == texHeight);
		  
		
		//	trace(bitmapData.width + " x " + bitmapData.height);
		//	trace(texWidth + " x " + texHeight);
			
	GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
    GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
    GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
	GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST);

			
			if (!isPot)
			{
				var workingCanvas:BitmapData = MatrixHelp.getScaled(bitmapData, Std.int(texWidth / 2), Std.int(texHeight / 2));
				bitmapData = null;
										
			#if html5
			var pixelData = workingCanvas.getPixels(workingCanvas.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(workingCanvas));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, workingCanvas.width, workingCanvas.height, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
			
           
				
				
			} else
			{
													
			#if html5
			var pixelData = bitmapData.getPixels(bitmapData.rect).byteView;
			#else
			var pixelData = new UInt8Array(BitmapData.getRGBAPixels(bitmapData));
			#end
			GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, texWidth, texHeight, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
      		}

	
	
		


		  
       
			
			 //GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_NEAREST);
             //GL.generateMipmap(GL.TEXTURE_2D);
		    // GL.bindTexture(GL.TEXTURE_2D, null);
          
		 
	}
	
	
}