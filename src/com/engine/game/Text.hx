package com.engine.game;

import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;

/**
 * ...
 * @author djoker
 */
class Text extends TextField
{

	public function new(x:Float = 10, y:Float = 10,caption:String,?size:Int=12, ?color:Int = 0xffffffff)
	{
	    super ();
		this.x = x;
		this.y = y;
		selectable = false;
		defaultTextFormat = new TextFormat ("_sans", size, color);
		text = caption;
	}
	
}