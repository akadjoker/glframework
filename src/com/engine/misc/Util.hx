package com.engine.misc;




/**
 * ...
 * @author djoker
 */
 class Util
{
		 static public var DEG:Float = -180 / Math.PI;
		 static public  var  RAD:Float = Math.PI / -180;
		 static public var EPSILON:Float = 0.00000001;
		 
		
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

}