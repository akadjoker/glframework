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
class PrimitiveShader
{
private var shaderProgram:GLProgram;
	
 public var vertexAttribute :Int;
 public var colorAttribute :Int;
 public var projectionMatrixUniform:Dynamic;
 public var modelViewMatrixUniform:Dynamic;


	
	public function new() 
	{


var vertexShaderSource =
"
attribute vec3 aVertexPosition;
attribute vec4 aColor;

varying vec4 vColor;

uniform mat4 uModelViewMatrix;
uniform mat4 uProjectionMatrix;
void main(void) 
{
vColor = aColor;
gl_Position = uProjectionMatrix * uModelViewMatrix * vec4 (aVertexPosition, 1.0);
}";

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

varying vec4 vColor;
void main(void)
{
	gl_FragColor =  vColor;
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
colorAttribute = GL.getAttribLocation (shaderProgram, "aColor");
projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");

 		
	}

	public function Enable()
	{
	   GL.useProgram (shaderProgram);
       GL.enableVertexAttribArray (vertexAttribute);
	   GL.enableVertexAttribArray (colorAttribute);


	}
	public function Disable()
	{
		GL.disableVertexAttribArray (vertexAttribute);
		GL.disableVertexAttribArray (colorAttribute);
	}
}