package com.engine.direct ;

import flash.geom.Matrix;
import flash.geom.Rectangle;
/**
 * ...
 * @author djoker
 */
class  Util
{
    	public static var EPSILON:Float = 0.00000001;
        public static var  WHITE:Int   = 0xffffff;
        public static var SILVER:Int  = 0xc0c0c0;
        public static var GRAY:Int    = 0x808080;
        public static var BLACK:Int   = 0x000000;
        public static var RED:Int     = 0xff0000;
        public static var MAROON:Int  = 0x800000;
        public static var YELLOW:Int  = 0xffff00;
        public static var OLIVE:Int   = 0x808000;
        public static var LIME:Int    = 0x00ff00;
        public static var GREEN:Int   = 0x008000;
        public static var AQUA:Int    = 0x00ffff;
        public static var TEAL:Int    = 0x008080;
        public static var BLUE:Int    = 0x0000ff;
        public static var NAVY:Int    = 0x000080;
        public static var FUCHSIA:Int = 0xff00ff;
        public static var PURPLE:Int  = 0x800080;
	
	
	public static function matrixsetTo(matrix:Matrix,aa : Float, ba : Float, ca : Float, da : Float, txa : Float, tya : Float) : Void
	{
		matrix.a = aa;
		matrix.b = ba;
		matrix.c = ca;
		matrix.d = da;
		matrix.tx = txa;
		matrix.ty = tya;
		
		
	}
public static function skew(matrix:Matrix, skewX:Float, skewY:Float):Void
        {
            var sinX:Float = Math.sin(skewX);
            var cosX:Float = Math.cos(skewX);
            var sinY:Float = Math.sin(skewY);
            var cosY:Float = Math.cos(skewY);
            
            matrixsetTo(matrix,matrix.a  * cosY - matrix.b  * sinX,
                         matrix.a  * sinY + matrix.b  * cosX,
                         matrix.c  * cosY - matrix.d  * sinX,
                         matrix.c  * sinY + matrix.d  * cosX,
                         matrix.tx * cosY - matrix.ty * sinX,
                         matrix.tx * sinY + matrix.ty * cosX);
        }
		
public static function isEquivalent(a:Float, b:Float, epsilon:Float=0.0001):Bool
        {
            return (a - epsilon < b) && (a + epsilon > b);
        }
        
public static function normalizeAngle(angle:Float):Float
        {
            // move into range [-180 deg, +180 deg]
            while (angle < -Math.PI) angle += Math.PI * 2.0;
            while (angle >  Math.PI) angle -= Math.PI * 2.0;
            return angle;
        }
		
        public static function getAlpha(color:Int):Int { return (color >> 24) & 0xff; }
        public static function getRed(color:Int):Int   { return (color >> 16) & 0xff; }
        public static function getGreen(color:Int):Int { return (color >>  8) & 0xff; }
        public static function getBlue(color:Int):Int  { return  color        & 0xff; }
        public static function rgb(red:Int, green:Int, blue:Int):Int
        {
            return (red << 16) | (green << 8) | blue;
        }
        public static function argb(alpha:Int, red:Int, green:Int, blue:Int):Int
        {
            return (alpha << 24) | (red << 16) | (green << 8) | blue;
        }		
		
		  public static function intersect(rect1:Rectangle, rect2:Rectangle, resultRect:Rectangle):Rectangle
        {
            if (resultRect == null) resultRect = new Rectangle();
            
            var left:Float   = rect1.x      > rect2.x      ? rect1.x      : rect2.x;
            var right:Float  = rect1.right  < rect2.right  ? rect1.right  : rect2.right;
            var top:Float    = rect1.y      > rect2.y      ? rect1.y      : rect2.y;
            var bottom:Float = rect1.bottom < rect2.bottom ? rect1.bottom : rect2.bottom;
            
            if (left > right || top > bottom)
                resultRect.setEmpty();
          //  else
             //   resultRect.setTo(left, top, right-left, bottom-top);
            
            return resultRect;
        }
        
 
        public static function fit(rectangle:Rectangle, into:Rectangle, resultRect:Rectangle):Rectangle
        {
           
            if (resultRect == null) resultRect = new Rectangle();
            
            var width:Float   = rectangle.width;
            var height:Float  = rectangle.height;
            var factorX:Float = into.width  / width;
            var factorY:Float = into.height / height;
            var factor:Float  = 1.0;

            
            width  *= factor;
            height *= factor;
            
          //  resultRect.setTo(
           //     into.x + (into.width  - width)  / 2,
            //    into.y + (into.height - height) / 2,
            //    width, height);
            
            return resultRect;
        }
        
    static public function setLength<T>(array:Array<T>, newLength:Int):Void
	{
		if (newLength < 0) return;
		var oldLength:Int = array.length;
		var diff:Int = newLength - oldLength;
		if (diff < 0)
		{
			#if flash
			untyped array.length = newLength;
			#else
			diff = -diff;
			for (i in 0...diff)
			{
				array.pop();
			}
			#end
		}
	}
    static public function indexOf<T>(array:Array<T>, whatToFind:T, fromIndex:Int = 0):Int
	{
		#if flash
		return untyped array.indexOf(whatToFind, fromIndex);
		#else
		var index:Int = -1;
		var len:Int = array.length;
		for (i in fromIndex...len)
		{
			if (array[i] == whatToFind)
			{
				index = i;
				break;
			}
		}
		return index;
		#end
	}
}