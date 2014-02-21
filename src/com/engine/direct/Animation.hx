package com.engine.direct ;


class Animation
{

	public function new(name:String, frames:Array<Int>, frameRate:Float = 0, loop:Bool = true)
	{
        this.name       = name;
        this.frames     = frames;
        this.frameRate  = frameRate;
        this.loop       = loop;
        this.frameCount = frames.length;
	}



	


	public var name(default, null):String;

	public var frames(default, null):Array<Int>;


	public var frameRate(default, null):Float;

	public var frameCount(default, null):Int;


	public var loop(default, null):Bool;

}