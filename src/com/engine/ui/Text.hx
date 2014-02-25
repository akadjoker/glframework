package com.engine.ui;

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
		width = caption.length * size;
		selectable = false;
		defaultTextFormat = new TextFormat ("arial", size, color);
		text = caption;
	}
	
}