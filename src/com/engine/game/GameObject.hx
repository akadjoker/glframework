package com.engine.game;


import flash.geom.Matrix;

/**
 * ...
 * @author djoker
 */
class GameObject extends Transform
{
    public var children:List<Transform>;
   
	public function new() 
	{
	super();
	children = new List<Transform>();
	}
	public function add(child:Transform)
	{
	this.children.add(child);
	}
	public function remove(child:Transform)
	{
	this.children.remove(child);
	}
		
	override public function dispose()
	{
		this.children = null;
		this.mTransformationMatrix = null;
		super.dispose();
		
	}
}