package com.engine.misc;


import flash.Lib;
import flash.geom.Matrix;
import flash.geom.Matrix3D;
import flash.display.Bitmap;
import flash.display.BitmapData;


/**
 * ...
 * @author djoker
 */
 class Util
{
		 static public var DEG:Float = -180 / Math.PI;
		 static public  var  RAD:Float = Math.PI / -180;
		 static public var EPSILON:Float = 0.00000001;
		 
static public  function getTime():Int
{
	return Lib.getTimer();
}


	static public function randf(max:Float, min:Float ):Float
{	
     return Math.random() * (max - min) + min;
}
static public function randi(max:Int, min:Int ):Int
{
	return Std.int(Math.random() * (max - min) + min);
     
}

	public static inline function WithinEpsilon(a:Float, b:Float):Bool {
        var num:Float = a - b;
        return -1.401298E-45 <= num && num <= 1.401298E-45;
    }
	public static  function getColorValue(color:Int):Float
	{
		var h:Int = (color >> 16) & 0xFF;
		var s:Int = (color >> 8) & 0xFF;
		var v:Int = color & 0xFF;

		return Std.int(Math.max(h, Math.max(s, v))) / 255;
	}
	

 public static function deg2rad(deg:Float):Float
    {
        return deg / 180.0 * Math.PI;   
    }
	 public function rad2deg(rad:Float):Float
    {
        return rad / Math.PI * 180.0;            
    }

	
     
	inline static public function print(s:Dynamic)
	{
	//	flash.Lib.trace(s);
	}
	
	 static public function deepCopy<T>( arr : Array<T> ) : Array<T>
     {
         var r = new Array<T>();
         for( i in 0...arr.length )
             r.push(copy(arr[i]));
         return r;
     }

    static private function copy<T>( value : Dynamic) : T {
         if( Std.is( value, Array ) )
             return cast deepCopy( value );
         else
             return value;
     }
	 	function getExponantOfTwo(value:Int, max:Int):Int {
        var count:Int = 1;

        do {
            count *= 2;
        } while (count < value);

        if (count > max)
            count = max;

        return count;
    }
	
	inline static public function getNextPowerOfTwo(number:Int):Int
    {
        if (number > 0 && (number & (number - 1)) == 0) // see: http://goo.gl/D9kPj
            return number;
        else
        {
            var result:Int = 1;
            while (result < number) result <<= 1;
            return result;
        }
    }
	
		
	inline static public function getScaled(source:BitmapData, newWidth:Int, newHeight:Int):BitmapData 
	{
		var m:flash.geom.Matrix = new flash.geom.Matrix();
		m.scale(newWidth / source.width, newHeight / source.height);
	
		var bmp:BitmapData = new BitmapData(newWidth, newHeight, true,0);
	
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
	
	public static  function fillMatrix3DArrayTo(mat:Matrix3D,array:Array<Float>) 
	{
		for (index in 0...16) 
		{
		
         //   mat.rawData[index] = array[index];
        }
	}
	 public static function createOrtho(x0:Float, x1:Float,  y0:Float, y1:Float, zNear:Float, zFar:Float) :Matrix3D
   {
      var sx = 1.0 / (x1 - x0);
      var sy = 1.0 / (y1 - y0);
      var sz = 1.0 / (zFar - zNear);

      return new Matrix3D([
         2.0*sx,       0,          0,                 0,
         0,            2.0*sy,     0,                 0,
         0,            0,          -2.0*sz,           0,
         - (x0+x1)*sx, - (y0+y1)*sy, - (zNear+zFar)*sz,  1,
      ]);
   }
      public static function setMatrixOrtho(mat:Matrix3D,x0:Float, x1:Float,  y0:Float, y1:Float, zNear:Float, zFar:Float) 
   {
      var sx = 1.0 / (x1 - x0);
      var sy = 1.0 / (y1 - y0);
      var sz = 1.0 / (zFar - zNear);

      fillMatrix3DArrayTo(mat,[
         2.0*sx,       0,          0,                 0,
         0,            2.0*sy,     0,                 0,
         0,            0,          -2.0*sz,           0,
         - (x0+x1)*sx, - (y0+y1)*sy, - (zNear+zFar)*sz,  1,
      ]);
   }
	
	 public static function set2Dtransformation(mat:Matrix3D,x:Float, y:Float, scale:Float = 1, rotation:Float = 0) 
   {
      var theta = rotation * Math.PI / 180.0;
      var c = Math.cos(theta);
      var s = Math.sin(theta);
/*
	 fillMatrix3DArrayTo(mat,[
        c*scale,  -s*scale, 0,  0,
        s*scale,  c*scale , 0,  0,
        0,        0,        1,  0,
        x,        y,        0,  1
      ]);
	  */
   }
	
   public static function createMtrix2D(x:Float, y:Float, scale:Float = 1, rotation:Float = 0):Matrix3D 
   {
      var theta = rotation * Math.PI / 180.0;
      var c = Math.cos(theta);
      var s = Math.sin(theta);

	  var mat:Matrix3D = new Matrix3D([
        c*scale,  -s*scale, 0,  0,
        s*scale,  c*scale, 0,  0,
        0,        0,        1,  0,
       x,        y,        0,  1
      ]);/*
	  return Matrix.FromArray([
        c*scale,  -s*scale, 0,  0,
        s*scale,  c*scale, 0,  0,
        0,        0,        1,  0,
       x,        y,        0,  1
      ]);
	  */
	  return mat;
   }

}