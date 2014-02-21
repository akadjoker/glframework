package com.djoker.glteste;


import flash.display.BitmapData;
import flash.display.Sprite;
import flash.geom.Matrix3D;
import flash.geom.Rectangle;
import flash.display.StageDisplayState;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.Lib;

import openfl.display.OpenGLView;
import openfl.display.FPS;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;
import openfl.utils.Float32Array;
import openfl.utils.UInt8Array;
import openfl.Assets;

import com.engine.render.Texture;
import com.engine.render.VertexBuffer;
import com.engine.render.SpriteBatch;

class Main extends Sprite {



private var imageUniform:GLUniformLocation;
private var modelViewMatrixUniform:GLUniformLocation;
private var projectionMatrixUniform:GLUniformLocation;
private var shaderProgram:GLProgram;
private var texCoordAttribute:Int;
private var texCoordBuffer:GLBuffer;
private var view:OpenGLView;
private var vertexAttribute:Int;
private var colorAttribute:Int;
private var vertexBuffer:GLBuffer;
private var layer:FPS;

private var tex:Texture;

private var buffer:VertexBuffer;
private var batch:SpriteBatch;

public function new () {

super ();
var _fullScreen:Bool=true;




if (OpenGLView.isSupported) {

view = new OpenGLView ();

tex =new Texture("assets/openfl.png",false);

initializeShaders ();

createBuffers ();


Lib.current.stage.addEventListener (MouseEvent.MOUSE_UP, stage_onMouseUp);



buffer = new VertexBuffer();



view.render = renderView;

addChild (view);
layer = new FPS(20, 20, 0x00ff00ff);
addChild(layer);

}

}


	
	private function stage_onMouseUp (event:MouseEvent):Void {
		#if DESKTOP
		Lib.exit ();
		#end
	}
private function createBuffers ():Void {

var vertices = [

tex.width, tex.height, 0,
0, tex.height, 0,
tex.width, 0, 0,
0, 0, 0

];

vertexBuffer = GL.createBuffer ();
GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast vertices), GL.STATIC_DRAW);
GL.bindBuffer (GL.ARRAY_BUFFER, null);

var texCoords = [

1, 1,
0, 1,
1, 0,
0, 0,

];

texCoordBuffer = GL.createBuffer ();
GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);	
GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast texCoords), GL.STATIC_DRAW);
GL.bindBuffer (GL.ARRAY_BUFFER, null);

}




private function initializeShaders ():Void {
/*
var vertexShaderSource =

"attribute vec3 aVertexPosition;
 attribute vec2 aTexCoord;
 attribute vec4 aColor;
	
varying vec2 vTexCoord;
varying vec4 vColor;

uniform mat4 uModelViewMatrix;
uniform mat4 uProjectionMatrix;
void main(void) 
{
vColor = aColor;
vTexCoord = aTexCoord;
gl_Position = uProjectionMatrix * uModelViewMatrix * vec4 (aVertexPosition, 1.0);
}";
*/
	var vertexShaderSource =

"attribute vec3 aVertexPosition;
attribute vec2 aTexCoord;
varying vec2 vTexCoord;
uniform mat4 uModelViewMatrix;
uniform mat4 uProjectionMatrix;
void main(void) {
vTexCoord = aTexCoord;
gl_Position = uProjectionMatrix * uModelViewMatrix * vec4 (aVertexPosition, 1.0);
}";


var vertexShader = GL.createShader (GL.VERTEX_SHADER);
GL.shaderSource (vertexShader, vertexShaderSource);
GL.compileShader (vertexShader);

if (GL.getShaderParameter (vertexShader, GL.COMPILE_STATUS) == 0) {

throw "Error compiling vertex shader";

}
/*
var fragmentShaderSource =

#if !desktop
"precision mediump float;" +
#end
"varying vec2 vTexCoord;
varying vec4 vColor;
uniform sampler2D uImage0;
void main(void)
{
	 vec4 texColor = texture2D(uImage0, vTexCoord);
  // gl_FragColor = vColor * texColor;
   gl_FragColor = texColor *vec4(1.0, 1.0, 1.0, 1.0);
  
//gl_FragColor = texture2D (uImage0, vTexCoord);
}";
*/
	var fragmentShaderSource =

#if !desktop
"precision mediump float;" +
#end
"varying vec2 vTexCoord;
uniform sampler2D uImage0;
void main(void)
{"
#if html5
+ "gl_FragColor = texture2D (uImage0, vTexCoord);" +
#else
+ "gl_FragColor = texture2D (uImage0, vTexCoord).gbar;" +
#end
"}";



var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
GL.shaderSource (fragmentShader, fragmentShaderSource);
GL.compileShader (fragmentShader);

if (GL.getShaderParameter (fragmentShader, GL.COMPILE_STATUS) == 0) {

throw "Error compiling fragment shader";

}

shaderProgram = GL.createProgram ();
GL.attachShader (shaderProgram, vertexShader);
GL.attachShader (shaderProgram, fragmentShader);
GL.linkProgram (shaderProgram);

if (GL.getProgramParameter (shaderProgram, GL.LINK_STATUS) == 0) {

throw "Unable to initialize the shader program.";

}
vertexAttribute = 0;
texCoordAttribute = 1;
colorAttribute = 2;

vertexAttribute = GL.getAttribLocation (shaderProgram, "aVertexPosition");
texCoordAttribute = GL.getAttribLocation (shaderProgram, "aTexCoord");
//colorAttribute = GL.getAttribLocation (shaderProgram, "aColor");
//GL.bindAttribLocation(shaderProgram, vertexAttribute, "aVertexPosition");
//GL.bindAttribLocation(shaderProgram,texCoordAttribute, "aTexCoord");
GL.bindAttribLocation(shaderProgram,colorAttribute, "aColor");

trace(colorAttribute);
projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");
imageUniform = GL.getUniformLocation (shaderProgram, "uImage0");

}



private function renderView (rect:Rectangle):Void {

	//var bound:Rectangle = Rectangle(0, 0, 480, 320);
	
GL.viewport (Std.int (rect.x), Std.int (rect.y), Std.int (rect.width), Std.int (rect.height));

GL.clearColor (0.0, 0.0, 0.4, 1.0);
GL.clear (GL.COLOR_BUFFER_BIT);

var positionX = 0;// (stage.stageWidth - bitmapData.width) / 2;
var positionY = 0;// (stage.stageHeight - bitmapData.height) / 2;

var projectionMatrix = Matrix3D.createOrtho (0, rect.width, rect.height, 0, 1000, -1000);
var modelViewMatrix = Matrix3D.create2D (positionX, positionY, 1, 0);


tex.Bind();

buffer.Begin(projectionMatrix, modelViewMatrix);





buffer.RenderNormal(100, 100, 400, 400);

buffer.RenderNormal(10, 10, 140, 140);


buffer.End();

/*
GL.useProgram (shaderProgram);
GL.enableVertexAttribArray (vertexAttribute);
GL.enableVertexAttribArray (texCoordAttribute);

GL.activeTexture (GL.TEXTURE0);
tex.Bind();

#if desktop
GL.enable (GL.TEXTURE_2D);
#end

GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
GL.vertexAttribPointer (vertexAttribute, 3, GL.FLOAT, false, 0, 0);
GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);
GL.vertexAttribPointer (texCoordAttribute, 2, GL.FLOAT, false, 0, 0);

GL.uniformMatrix3D (projectionMatrixUniform, false, projectionMatrix);
GL.uniformMatrix3D (modelViewMatrixUniform, false, modelViewMatrix);
GL.uniform1i (imageUniform, 0);

GL.drawArrays (GL.TRIANGLE_STRIP, 0, 4);

GL.bindBuffer (GL.ARRAY_BUFFER, null);
GL.bindTexture (GL.TEXTURE_2D, null);

#if desktop
GL.disable (GL.TEXTURE_2D);
#end

GL.disableVertexAttribArray (vertexAttribute);
GL.disableVertexAttribArray (texCoordAttribute);
GL.useProgram (null);
*/

}


}