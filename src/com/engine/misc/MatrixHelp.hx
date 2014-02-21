package com.engine.misc;

import flash.geom.Matrix;

import flash.display.Bitmap;
import flash.display.BitmapData;

/**
 * ...
 * @author djoker
 */
class MatrixHelp
{
	
		
	inline static public function getScaled(source:BitmapData, newWidth:Int, newHeight:Int):BitmapData 
	{
		var m:flash.geom.Matrix = new flash.geom.Matrix();
		m.scale(newWidth / source.width, newHeight / source.height);
	
		var bmp:BitmapData = new BitmapData(newWidth, newHeight, true);
	
		bmp.draw(source, m);
		return bmp;
	}
	
	inline static public function flipBitmapData(original:BitmapData, axis:String = "y"):BitmapData
{
     var flipped:BitmapData = new BitmapData(original.width, original.height, true, 0);
     var matrix:Matrix;
     if(axis == "x"){
          matrix = new Matrix( -1, 0, 0, 1, original.width, 0);
     } else {
          matrix = new Matrix( 1, 0, 0, -1, 0, original.height);
     }
     flipped.draw(original, matrix, null, null, null, true);
     return flipped;
}

public static function skew(matrix:Matrix, skewX:Float, skewY:Float)
        {
            var sinX:Float = Math.sin(skewX);
            var cosX:Float = Math.cos(skewX);
            var sinY:Float = Math.sin(skewY);
            var cosY:Float = Math.cos(skewY);
           
            setTo(matrix,matrix.a  * cosY - matrix.b  * sinX,
                         matrix.a  * sinY + matrix.b  * cosX,
                         matrix.c  * cosY - matrix.d  * sinX,
                         matrix.c  * sinY + matrix.d  * cosX,
                         matrix.tx * cosY - matrix.ty * sinX,
                         matrix.tx * sinY + matrix.ty * cosX);
        }
		   public static function setTo (matrix:Matrix, a:Float, b:Float, c:Float, d:Float, tx:Float, ty:Float):Void 
   {
		
		matrix.a = a;
		matrix.b = b;
		matrix.c = c;
		matrix.d = d;
		matrix.tx = tx;
		matrix.ty = ty;
		
	}
	
}