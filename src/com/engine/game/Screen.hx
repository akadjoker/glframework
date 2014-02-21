package com.engine.game;

/**
 * ...
 * @author djoker
 */
class Screen extends GameObject
{

    public var game:Game = null;
	
	public function show() { }
	public function render(dt:Float) { }
	public function resize(width:Int, height:Int) {}
	
	public function mouseMove(mousex:Float, mousey:Float) { };
	public function mouseUp(mousex:Float, mousey:Float) { };
	public function mouseDown(mousex:Float, mousey:Float) { };
	public function keyDown(key:Int) { };
	public function keyUp(key:Int) { };
	
}