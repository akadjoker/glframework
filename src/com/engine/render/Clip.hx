package com.engine.render;

/**
 * ...
 * @author djoker
 */
class Clip
{

	public var x:Int;
	public var y:Int;
	public var width:Int;
	public var height:Int;
	
	
	
	public function new(?x:Int=0,?y:Int=0,?width:Int=0,?height:Int=0) 
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	public function set(x:Int,y:Int,width:Int,height:Int) 
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	
}