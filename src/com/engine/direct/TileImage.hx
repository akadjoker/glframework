package com.engine.direct;

import flash.display.BitmapData;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.geom.Matrix;
import flash.events.Event;

/**
 * ...
 * @author djoker
 */

typedef CallbackFunction = Void -> Void;

class TileImage
{
	
	public var width:Int;
    public var height:Int;
    public var originX:Int;
    public var originY:Int;
	
	 public var complete:Bool;
	 public var callbackFunc:CallbackFunction;  
     public var rate:Float;
     private var _frameCount:Int;
  	private var _anims:Map<String,Animation>;
	private var _anim:Animation;
	private var _index:Int;
	private var _frame:Int;
	private var _timer:Float;
	
	    public var x:Float;
        public var y:Float;
        public var PivotX:Float;
        public var PivotY:Float;
        public var ScaleX:Float;
        public var ScaleY:Float;
        public var SkewX:Float;
        public var SkewY:Float;
        public var Rotation:Float;
        public var Alpha:Float;
		public var Red:Float;
		public var Green:Float;
		public var Blue:Float;
        public var Visible:Bool;
        private var mName:String;
        private var mParent:TileImage;  
        private var mTransformationMatrix:Matrix;
		public var Layer:Int;
		public var Graph:Int;

   public var name(get, set) : String;		
   public function get_name():String { return mName; }
   public function set_name(value:String):String { mName = value; return mName; }
      		

	
	public function new(x:Float,y:Float,graph:Int) 
	{
		    this.x = this.y = PivotX = PivotY = Rotation = SkewX = SkewY = 0.0;
            ScaleX = ScaleY = Alpha=Red=Green=Blue = 1.0;            
            Visible  = true;
			Layer = 0;
			this.x = x;
			this.y = y;
			this.Graph = graph;
            mTransformationMatrix = new Matrix();
			complete = true;
		    rate = 1;
			callbackFunc = null;
			_anims = new Map<String,Animation>();
			originX = originY = 0;
		    width = height = 0;
			 
	}
	
	public function destroy():Void
	{
		
	}
	public function update():Void
	{
		//updateAnim();
	}
	public function kill():Void
	{
		
	}
		
	public function getMatrix():Matrix
	{
		
	
	      	 mTransformationMatrix.identity();

			 mTransformationMatrix.scale(ScaleX, ScaleY);
			 
				if (SkewX != 0.0 && SkewY != 0.0)
                {
                    Util.skew(mTransformationMatrix, SkewX, SkewY);
				}
                    mTransformationMatrix.rotate(Rotation);
                    mTransformationMatrix.translate(x, y);
                    
                    if (PivotX != 0.0 || PivotY != 0.0)
                    {
                        
                        mTransformationMatrix.tx = x - mTransformationMatrix.a * PivotX
                                                      - mTransformationMatrix.c * PivotY;
                        mTransformationMatrix.ty = y - mTransformationMatrix.b * PivotX 
                                                      - mTransformationMatrix.d * PivotY;
                    }
					
  
				
				return mTransformationMatrix;
	}
	
	public function add(name:String, frames:Array<Int>, frameRate:Float = 0, loop:Bool = true):Animation
	{
		if (_anims.get(name) != null) return null;
		for (i in 0...frames.length)
		{
		//	frames[i] %= _frameCount;
		//	if (frames[i] < 0) frames[i] += _frameCount;
		}
		var anim = new Animation(name, frames, frameRate, loop);
		_anims.set(name, anim);
		_frameCount = anim.frameCount;
		return anim;
	}
	public function addFrames(name:String, minf:Int,maxf:Int, frameRate:Float = 0, loop:Bool = true):Animation
	{
		if (_anims.get(name) != null) return null;
		var frames:Array<Int>= new Array<Int>();
		for (i in minf...maxf)
		{
			frames.push(i);
		}
		var anim = new Animation(name, frames, frameRate, loop);
		_anims.set(name, anim);
		_frameCount = anim.frameCount;
		return anim;
	}
	public function play(name:String = "", reset:Bool = false):Animation
	{
		if (!reset && _anim != null && _anim.name == name) return _anim;
		if (_anims.exists(name))
		{
			_anim = _anims.get(name);
			_timer = _index = 0;
			_frame = _anim.frames[0];
			complete = false;
		}
		else
		{
			_anim = null;
			_frame = _index = 0;
			complete = true;
		}
		
		return _anim;
	}
	public function updateAnim(elapsed:Float)
	{
		if (_anim != null && !complete)
		{
			_timer += (_anim.frameRate * elapsed) * rate;
			if (_timer >= 1)
			{
				while (_timer >= 1)
				{
					_timer --;
					_index ++;
					if (_index == _anim.frameCount)
					{
						if (_anim.loop)
						{
							_index = 0;
							if (callbackFunc != null) callbackFunc();
						}
						else
						{
							_index = _anim.frameCount - 1;
							complete = true;
							if (callbackFunc != null) callbackFunc();
							break;
						}
					}
				}
				if (_anim != null) _frame = Std.int(_anim.frames[_index]);
				Graph = _frame;
			}
		}
	}
	public var frame(get_frame, set_frame):Int;
	private function get_frame():Int { return _frame; }
	private function set_frame(value:Int):Int
	{
		_anim = null;
		value %= _frameCount;
		if (value < 0) value = _frameCount + value;
		if (_frame == value) return _frame;
		_frame = value;
		return _frame;
	}
	public var frameCount(get_frameCount, null):Int;
	private function get_frameCount():Int { return _frameCount; }
	public var currentAnim(get_currentAnim, null):String;
	private function get_currentAnim():String { return (_anim != null) ? _anim.name : ""; }
   /*
    public var visible(get, set) : Bool;
	private inline function get_visible():Bool {  return mVisible;}
    private function set_visible( v : Bool ):Bool {mVisible = v;return mVisible;}

	
	public var alpha(get, set) : Float;
	private inline function get_alpha():Float {  return mAlpha;}
    private function set_alpha( v : Float ):Float {mAlpha = v;return mAlpha;}

	public var red(get, set) : Float;
	private inline function get_red():Float {  return mRed;}
    private function set_red( v : Float ):Float {mRed = v;return mRed;}

    public var green(get, set) : Float;
	private inline function get_green():Float {  return mGreen;}
    private function set_green( v : Float ):Float {mGreen = v;return mGreen;}
	
	public var blue(get, set) : Float;
	private inline function get_blue():Float {  return mBlue;}
    private function set_blue( v : Float ):Float {mBlue = v;return mBlue;}
	
	
    public var x(get, set) : Float;
	private inline function get_x():Float {  return mX;}
    private function set_x( v : Float ):Float {mX = v;return mX;}

    public var y(get, set) : Float;
	private inline function get_y():Float {  return mY;}
    private function set_y( v : Float ):Float {mY = v;return mY;}

    public var layer(get, set) : Int;
	private inline function get_layer():Int {  return mLayer;}
    private function set_layer( v : Int ):Int {mLayer = v;return mLayer;}

	public var graph(get, set) : Int;
	private inline function get_graph():Int {  return mGraph;}
    private function set_graph( v : Int ):Int { mGraph = v; return mGraph; }
	
	public var PivotX(get, set) : Float;
	private inline function get_PivotX():Float {  return mPivotX;}
    private function set_PivotX( v : Float ):Float {mPivotX = v;return mPivotX;}

    public var PivotY(get, set) : Float;
	private inline function get_PivotY():Float {  return mPivotY;}
    private function set_PivotY( v : Float ):Float {mPivotY = v;return mPivotY;}

    public var SkewX(get, set) : Float;
	private inline function get_SkewX():Float {  return mSkewX;}
    private function set_SkewX( v : Float ):Float {mSkewX = v;return mSkewX;}

	public var SkewY(get, set) : Float;
	private inline function get_SkewY():Float {  return mSkewY;}
    private function set_SkewY( v : Float ):Float {mSkewY = v;return mSkewY;}

	public var Rotation(get, set) : Float;
	private inline function get_Rotation():Float {  return mRotation;}
    private function set_Rotation( v : Float ):Float {mRotation = v;return mRotation;}
*/
}