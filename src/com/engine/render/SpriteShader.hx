package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;

import flash.geom.Matrix3D;

import com.engine.render.filter.Filter;
import com.engine.game.Game;

/**
 * ...
 * @author djoker
 */
class SpriteShader
{
private var shaderProgram:GLProgram;
	

 public var projectionMatrixUniform:Dynamic;
 public var modelViewMatrixUniform:Dynamic;
 public var imageUniform:Dynamic;
 public var invertUniform:Dynamic;


	
	public function new() 
	{



 
var vertexShader = GL.createShader (GL.VERTEX_SHADER);
GL.shaderSource (vertexShader, Filter.textureVertexShader);
GL.compileShader (vertexShader);

if (GL.getShaderParameter (vertexShader, GL.COMPILE_STATUS) == 0) 
{

throw (GL.getShaderInfoLog(vertexShader));

}

var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
GL.shaderSource (fragmentShader, Filter.textureFragmentShader);
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

Filter.vertexAttribute = GL.getAttribLocation (shaderProgram, "aVertexPosition");
//GL.bindAttribLocation(shaderProgram,Filter.vertexAttribute,"aVertexPosition");
Filter.texCoordAttribute = GL.getAttribLocation (shaderProgram, "aTexCoord");
//GL.bindAttribLocation(shaderProgram,Filter.texCoordAttribute,"aTexCoord");
Filter.colorAttribute = GL.getAttribLocation (shaderProgram, "aColor");
//GL.bindAttribLocation(shaderProgram,Filter.colorAttribute,"aColor");
projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");
imageUniform = GL.getUniformLocation (shaderProgram, "uImage0");
//invertUniform = GL.getUniformLocation (shaderProgram, "invert");
//GL.uniform1f (invertUniform, 1);

 		
	}

	public function Enable()
	{
	   GL.useProgram (shaderProgram);
       GL.enableVertexAttribArray (Filter.vertexAttribute);
       GL.enableVertexAttribArray (Filter.texCoordAttribute);
	   GL.enableVertexAttribArray (Filter.colorAttribute);
	}
	public function Disable()
	{
       GL.disableVertexAttribArray (Filter.vertexAttribute);
       GL.disableVertexAttribArray (Filter.texCoordAttribute);
	   GL.disableVertexAttribArray (Filter.colorAttribute);
	   GL.useProgram (null);
	
	}
	public function dispose()
	{
		GL.deleteProgram(shaderProgram);

	}
	public function setTexture(tex:Texture)
	{
 	 tex.Bind();
     GL.uniform1i (imageUniform, 0);
	}
	public function setMatrix()
	{
    GL.uniformMatrix3D(projectionMatrixUniform, false,Game.camera.projMatrix);
    GL.uniformMatrix3D(modelViewMatrixUniform, false, Game.camera.viewMatrix);
	}
}