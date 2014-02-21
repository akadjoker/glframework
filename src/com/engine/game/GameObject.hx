package com.engine.game;


import flash.geom.Matrix;

/**
 * ...
 * @author djoker
 */
class GameObject extends Transform
{
    public var children:Array<GameObject>;
   
	public function new() 
	{
	super();
	children = new Array<GameObject>();
	}
	public function add(child:GameObject)
	{
	child.parent=this	;
	this.children.push(child);
	}
	public function remove(child:GameObject)
	{
	child.parent = null;	
	this.children.remove(child);
	}
		
	override public function dispose()
	{
		this.children = null;
		this.mTransformationMatrix = null;
		super.dispose();
		
	}
}