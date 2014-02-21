package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;

import flash.geom.Matrix3D;

/**
 * ...
 * @author djoker
 */
class SpriteShader
{
private var shaderProgram:GLProgram;
	
 public var vertexAttribute :Int;
 public var texCoordAttribute :Int;
 public var colorAttribute :Int;
 public var projectionMatrixUniform:Dynamic;
 public var modelViewMatrixUniform:Dynamic;
 public var imageUniform:Dynamic;


	
	public function new() 
	{


var vertexShaderSource =
"
attribute vec3 aVertexPosition;
attribute vec2 aTexCoord;
attribute vec4 aColor;

varying vec2 vTexCoord;
varying vec4 vColor;

uniform mat4 uModelViewMatrix;
uniform mat4 uProjectionMatrix;
void main(void) 
{
vTexCoord = aTexCoord;
vColor = aColor;
gl_Position = uProjectionMatrix * uModelViewMatrix *  vec4 (aVertexPosition, 1.0);

}";

 //gl_Position = vec4(outpos.x, yflip*outpos.y, outpos.z*2.0 - outpos.w, outpos.w);

 
var vertexShader = GL.createShader (GL.VERTEX_SHADER);
GL.shaderSource (vertexShader, vertexShaderSource);
GL.compileShader (vertexShader);

if (GL.getShaderParameter (vertexShader, GL.COMPILE_STATUS) == 0) 
{

throw (GL.getShaderInfoLog(vertexShader));

}

var fragmentShaderSource =

#if !desktop
"precision mediump float;" +
#end
"
varying vec2 vTexCoord;
varying vec4 vColor;
uniform sampler2D uImage0;

void main(void)
{
	gl_FragColor = texture2D (uImage0, vTexCoord) * vColor;

}";

var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
GL.shaderSource (fragmentShader, fragmentShaderSource);
GL.compileShader (fragmentShader);

if (GL.getShaderParameter (fragmentShader, GL.COMPILE_STATUS) == 0) {

 throw(GL.getShaderInfoLog(fragmentShader));

}

shaderProgram = GL.createProgram ();
GL.attachShader (shaderProgram, vertexShader);
GL.attachShader (shaderProgram, fragmentShader);
GL.linkProgram (shaderProgram);

if (GL.getProgramParameter (shaderProgram, GL.LINK_STATUS) == 0) {


throw "Unable to initialize the shader program.";
}

vertexAttribute = GL.getAttribLocation (shaderProgram, "aVertexPosition");
texCoordAttribute = GL.getAttribLocation (shaderProgram, "aTexCoord");
colorAttribute = GL.getAttribLocation (shaderProgram, "aColor");
projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");
imageUniform = GL.getUniformLocation (shaderProgram, "uImage0");
 		
	}

	public function Enable()
	{
	   GL.useProgram (shaderProgram);
       GL.enableVertexAttribArray (vertexAttribute);
       GL.enableVertexAttribArray (texCoordAttribute);
	   GL.enableVertexAttribArray (colorAttribute);
	}
	public function Disable()
	{
		GL.disableVertexAttribArray (vertexAttribute);
	    GL.disableVertexAttribArray (texCoordAttribute);
		GL.disableVertexAttribArray (colorAttribute);
		//GL.useProgram (null);
	}
}