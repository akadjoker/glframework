package com.engine.game;

import com.engine.math.Matrix;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.events.MouseEvent;
import flash.events.TouchEvent;
import flash.geom.Rectangle;
import flash.Lib;
import flash.ui.Multitouch;
import flash.ui.MultitouchInputMode;
import openfl.display.FPS;
import openfl.display.OpenGLView;
import openfl.gl.GL;




/**
 * ...
 * @author djoker
 * http://code-haxe.co.nf/
 */
class Game extends OpenGLView
{

	private var ready:Bool;
	public var deltaTime:Float;
    private var prevFrame:Int;
    private var nextFrame:Int; 
	private var mMultiTouch:Bool;
	private var screen:Screen = null;
	private var container:Sprite;
	static public var scrollX:Float = 0;
	static public var scrollY:Float = 0;
	static public var viewWidth:Int = 0;
	static public var viewHeight:Int = 0;
	public var screenWidth:Int = 0;
	public var screenHeight:Int = 0;
	public var gameWidth:Int=0;
	public var gameHeight:Int = 0;
	private var rescale:Bool = false;
	private var enableDepth:Bool;
	
public var red:Float;
public var green:Float;
public var blue:Float;

	
	static public var projMatrix:Matrix;

		


	public function fixRatio(w:Int, h:Int)
	{
		rescale = true;
		gameWidth = w;
		gameHeight = h;
	}

	public function new() 
	{
	super();
	ready = false;
    this.render = renderView;
	
	
    		
	
	
    
	
	
		screenWidth = Lib.current.stage.stageWidth;
		screenHeight = Lib.current.stage.stageHeight;
	    Game.viewWidth = screenHeight;
		Game.viewHeight = screenHeight;
		gameWidth = screenWidth;
	    gameHeight = screenHeight;
	
	

		Game.projMatrix=Matrix.OrthoOffCenterLH(0, gameWidth,gameHeight,0,  -1, 1);
	

	stage.addEventListener(Event.RESIZE, onResize);
	stage.addEventListener(Event.ADDED, focusGained);
	stage.addEventListener(Event.DEACTIVATE, focusLost);
	
	
	container = new Sprite();
	container.addEventListener(Event.ADDED_TO_STAGE, addedToStage);		
	stage.addChild(container);
	addChild(new FPS(10, 10, 0xff0ff));
	prevFrame = Lib.getTimer();
	
	

	
	}
	
	public function setDeph(v:Bool)
	{
		enableDepth = v;
		if (v == true)
		{
		 GL.disable(GL.DEPTH_TEST);
		} else
		{
		GL.enable(GL.DEPTH_TEST);
		GL.depthFunc(GL.FASTEST);
    	}
	}
	public function clarColor(r:Float, g:Float, b:Float)
	{
		red = r;
		green = g;
		blue = b;
	}
	
	public	function removeChild(child : DisplayObject)
	{
		container.removeChild(child);
	}
	
	public function addChild(child : DisplayObject) 
  {
	  container.addChild(child);
  }
		
	private function addedToStage(e:Event)
	{
  	
	mMultiTouch = Multitouch.supportsTouchEvents;
    if (mMultiTouch) Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;
  //  trace("Using multi-touch : " + mMultiTouch);
	
	
	
	Lib.current.stage.addEventListener (MouseEvent.MOUSE_DOWN, doMouseDown);
	Lib.current.stage.addEventListener (MouseEvent.MOUSE_MOVE, doMouseMove);
	Lib.current.stage.addEventListener (MouseEvent.MOUSE_UP, doMouseUp);
    Lib.current.stage.addEventListener (KeyboardEvent.KEY_DOWN, stage_onKeyDown);
	Lib.current.stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
		
	
	if (mMultiTouch)
	{
	Lib.current.stage.addEventListener(TouchEvent.TOUCH_BEGIN, doTouchDown);
    Lib.current.stage.addEventListener(TouchEvent.TOUCH_MOVE, doTouchMove);
    Lib.current.stage.addEventListener(TouchEvent.TOUCH_END, doTouchUp);
	}
	
			
 
 		  
		   //
    GL.disable(GL.CULL_FACE);
    GL.enable(GL.BLEND);
	GL.blendFunc(GL.SRC_ALPHA,GL.DST_ALPHA );
	GL.pixelStorei(GL.PACK_ALIGNMENT, 2);
//	GL.enable(GL.DEPTH_TEST);
    setDeph(true);
	clarColor(0, 1, 0.4);
	GL.clearColor(red, green, blue, 1);
	GL.depthMask(true);
	 
	  

		begin(); 
		ready = true; 
	
	}
	public function focusGained(e:Event) 
	{ 
		
	
	  
	
	}

	private function stage_onKeyDown (event:KeyboardEvent):Void 
	{

		keyDown(event.keyCode);
		if (screen != null) screen.keyDown(event.keyCode);
	}
	
	
	private function stage_onKeyUp (event:KeyboardEvent):Void
	{
	
		keyUp(event.keyCode);
		if (screen != null) screen.keyUp(event.keyCode);
	}
	
	private function doMouseDown (event:MouseEvent):Void 
	{
	mouseDown(event.localX, event.localY);
	if (screen != null) screen.mouseDown(event.localX, event.localY);
	}
	private function doMouseUp (event:MouseEvent):Void 
	{
	mouseUp(event.localX, event.localY);
	if (screen != null) screen.mouseUp(event.localX, event.localY);
	}
    private function doMouseMove (event:MouseEvent):Void 
	{
	mouseMove(event.localX, event.localY);
	if (screen != null) screen.mouseMove(event.localX, event.localY);

	}

	private function doTouchDown (event:TouchEvent):Void 
	{
	
	}
	private function doTouchUp (event:TouchEvent):Void 
	{
		
	}
    private function doTouchMove (event:TouchEvent):Void 
	{
		

	}

    private function focusLost(e:Event) {trace("end game"); ready = false; end(); }
	private function onResize(e:Event) 
	{
		screenWidth = Lib.current.stage.stageWidth;
		screenHeight = Lib.current.stage.stageHeight;
		
		resize(screenWidth,screenHeight);
	}
	
	public function begin() {  }
	public function end()   {  }
	public function resize(width:Int, height:Int) 
	{
    // trace("resize :" + width + "X" + height);
	if (screen != null) screen.resize(width, height);
	}
	public function update(dt:Float) 
	{
	if (screen != null) screen.render(dt);
	}
    public function keyDown(key:Int) { };
	public function keyUp(key:Int) { };

	public function mouseMove(mousex:Float, mousey:Float) { };
	public function mouseUp(mousex:Float, mousey:Float) { };
	public function mouseDown(mousex:Float, mousey:Float) { };
	
	public function setScreen ( screen:Screen) 
	{
		if (this.screen != null) this.screen.dispose();
		this.screen = screen;
		this.screen.game = this;
		if (this.screen != null)
		{
			this.screen.width  = screenWidth;
			this.screen.height = screenHeight;
			this.screen.show();
			this.screen.resize(Std.int(Game.viewWidth),Std.int(Game.viewHeight));
		}
	}
	
		
private function renderView(rect:Rectangle):Void 
{ 
	viewWidth   = Std.int(rect.width);
	viewHeight  = Std.int(rect.height);
	
	if (rescale==true)
	{
	var ar_origin:Float = (gameWidth   / gameHeight);
    var ar_new   :Float = (screenWidth /screenHeight);

    var scale_w:Float = (screenWidth / gameWidth);
    var scale_h:Float = (screenHeight / gameHeight);
    if (ar_new > ar_origin) 
	{
        scale_w = scale_h;
    } else {
        scale_h = scale_w;
    }

    var margin_x:Float = (screenWidth  - gameWidth * scale_w) / 2;
    var margin_y:Float = (screenHeight - gameHeight * scale_h) / 2;
	
	GL.viewport (Std.int (margin_x), Std.int (margin_y), Std.int (gameWidth*scale_w), Std.int (gameHeight*scale_h));
	Game.projMatrix=Matrix.OrthoOffCenterLH(0, gameWidth/ar_origin, gameHeight/ar_origin,0,  -1000, 1000);
	} else
	{
	GL.viewport (Std.int (rect.x), Std.int (rect.y), Std.int (rect.width), Std.int (rect.height));
 	Game.projMatrix=Matrix.OrthoOffCenterLH(0, gameWidth,gameHeight,0,  -1, 1);
	}
	


	
   
	nextFrame = Lib.getTimer();
    deltaTime = (nextFrame - prevFrame) * 0.001;
    GL.clearColor(red, green, blue, 1);
	
	if (enableDepth == true)
	{
	 GL.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
	} else
	{
	GL.clear(GL.COLOR_BUFFER_BIT );	
	}
  //  GL.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
    
 


	if (ready)
	{
	  update(deltaTime);
    }
	
	
 GL.bindBuffer (GL.ARRAY_BUFFER, null);	
 GL.useProgram (null);	
 GL.blendFunc(GL.SRC_ALPHA,GL.DST_ALPHA );
 prevFrame = nextFrame;
}
	
}