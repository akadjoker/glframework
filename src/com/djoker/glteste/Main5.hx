package com.djoker.glteste;
 
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.geom.Matrix3D;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.events.MouseEvent;



import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;


import com.engine.render.SpriteBatch;
import com.engine.render.Texture;
import com.engine.render.OrthoCamera;
import com.engine.Game.Game;

import flash.text.TextField;
import flash.text.TextFormat;

class Main extends Sprite {

private var view:OpenGLView;
private var Tex :Texture;
private var tex2:Texture;

private var batch:SpriteBatch;
var camera:OrthoCamera;
 //http://djoker-games.co.nf/haxe/batch/index.html
 


   var particles : Array<Particle>;
   
   var stats:TextField;


public function addParticle()
{
	var particle:Particle = new Particle(tex2);
	particle.Init();
   particles.push(particle);
}
public function addParticle2(x:Float,y:Float)
{
	var particle:Particle = new Particle(tex2);
	particle.Init();
	particle.x = x;
	particle.y=y;
	
   particles.push(particle);
}

public function new() {
super();
if (OpenGLView.isSupported) 
{
	
view = new OpenGLView();


tex2 = new Texture("assets/texture.png", true);

camera= new OrthoCamera(stage.stageWidth,stage.stageHeight);

batch = new SpriteBatch(camera);

particles = [];
      for(i in 0...200)
         addParticle();

	
	GL.disable(GL.DEPTH_TEST);
    GL.disable(GL.CULL_FACE);

    GL.enable(GL.BLEND);
    GL.colorMask(true, true, true, true);
    GL.clearColor(0,0,0.4, 1);	





view.render = renderView;
addChild(view);
addChild(new FPS(10, 10, 0xff0ff));

stats = new TextField();
stats.text = "trace";
stats.x = 10;
stats.y = 20;
stats.width = 200;

stats.defaultTextFormat = new TextFormat ("_sans", 12, 0xff00ff);

addChild(stats);

stage.addEventListener (MouseEvent.MOUSE_DOWN, onMouseDown);



}
}
 
private function onMouseDown (event:MouseEvent):Void 
{
	    addParticle2(event.localX,event.localY); 	
}

	
 
 
private function renderView(rect:Rectangle):Void 
{
GL.viewport(Std.int(rect.x), Std.int(rect.y), Std.int(rect.width), Std.int(rect.height));
GL.clear(GL.COLOR_BUFFER_BIT);
 
camera.Update();


batch.Begin();

 for(p in particles)
      {
         p.move();
         batch.drawImage(p);
      }

batch.End();
//stats.text = Std.string("Bl:" + batch.numBlend +"- Tx:" + batch.numTex +" - Sp:");

	
}
}