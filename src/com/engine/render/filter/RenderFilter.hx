package com.engine.render.filter;

import com.engine.game.Game;
import com.engine.render.filter.Filter;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLFramebuffer;
import openfl.gl.GLRenderbuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;


//*********************//TEST TEST TEST

import flash.geom.Matrix3D;
import flash.geom.Rectangle;
import openfl.gl.GLUniformLocation;
import openfl.utils.Float32Array;
import openfl.utils.UInt8Array;
import openfl.utils.UInt8Array;

/**
 * ...
 * @author djoker
 */
class RenderFilter
{
 
	//TESt
	private var modelViewMatrixUniform:GLUniformLocation;
	private var projectionMatrixUniform:GLUniformLocation;
	private var imageUniform:GLUniformLocation;
	public  var shader:GLProgram;
	private var texCoordAttribute:Int;
	private var texCoordBuffer:GLBuffer;
	private var vertexAttribute:Int;
	private var vertexBuffer:GLBuffer;
	//end test
	private var framebuffer:GLFramebuffer;
    private var texture : GLTexture;
	  public var width:Int;	
	  public var height:Int;
   

	public function new(width:Int,height:Int) 
	{
		
		
		this.width = width;
		this.height = height;

	    framebuffer = GL.createFramebuffer();
		GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
          
        texture = GL.createTexture();
		GL.bindTexture(GL.TEXTURE_2D, texture);
		
		           
	    GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
		
		//#if html5
	//	var pixelData = new UInt8Array(width * height *4);
		GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, width, height, 0, GL.RGBA, GL.UNSIGNED_BYTE, null);
	//	pixelData = null;
	//	#else
	//	GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, width, height, 0, GL.RGBA, GL.UNSIGNED_BYTE, null);
	//	#end
		//
				
				  
              
     
	
		GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
        GL.framebufferTexture2D(GL.FRAMEBUFFER, GL.COLOR_ATTACHMENT0, GL.TEXTURE_2D, texture, 0);
		GL.bindFramebuffer(GL.FRAMEBUFFER, null);
        
			   //////////////////////TESTESTESTESTE
var vertices = [
			width, height, 0,
			0, height, 0,
			width, 0, 0,
			0, 0, 0];
		
		vertexBuffer = GL.createBuffer ();
		GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
		GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast vertices), GL.STATIC_DRAW);

		
		var texCoords = [		
			1, 0, 
			0, 0, 
			1, 1, 
			0, 1,		
		];
		
		texCoordBuffer = GL.createBuffer ();
		GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);	
		GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast texCoords), GL.STATIC_DRAW);
		
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
		
		
		
		var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
		GL.shaderSource (fragmentShader, getFragment());
		GL.compileShader (fragmentShader);
		
		if (GL.getShaderParameter (fragmentShader, GL.COMPILE_STATUS) == 0) {
			
			throw "Error compiling fragment shader";
			
		}
		
		shader = GL.createProgram ();
		GL.attachShader (shader, vertexShader);
		GL.attachShader (shader, fragmentShader);
		GL.linkProgram (shader);
		
		if (GL.getProgramParameter (shader, GL.LINK_STATUS) == 0) {
			
			throw "Unable to initialize the shader program.";
			
		}
		
		vertexAttribute = GL.getAttribLocation (shader, "aVertexPosition");
		texCoordAttribute = GL.getAttribLocation (shader, "aTexCoord");
		projectionMatrixUniform = GL.getUniformLocation (shader, "uProjectionMatrix");
		modelViewMatrixUniform = GL.getUniformLocation (shader, "uModelViewMatrix");
		imageUniform = GL.getUniformLocation (shader, "uImage0");
		getUnifom();

		
	}
	public function getFragment():String
	{
		return "";
	}

	public function getUnifom()
	{
		
	}
	public function setUnifom()
	{
		
	}
	public function begin()
	{
		GL.colorMask(true, true, true, true); 
		GL.viewport(0, 0, width,height);
	    GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
	  //  GL.clearColor(0, 0, 0, 1);
	    GL.clear(GL.COLOR_BUFFER_BIT);
 	}
	public function end()
	{
	 GL.bindFramebuffer(GL.FRAMEBUFFER, null);
	}
	
	public function render()
	{
		GL.useProgram (shader);
		GL.enableVertexAttribArray (vertexAttribute);
		GL.enableVertexAttribArray (texCoordAttribute);
		GL.bindTexture (GL.TEXTURE_2D, texture);
		GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
		GL.vertexAttribPointer (vertexAttribute, 3, GL.FLOAT, false, 0, 0);
		GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);
		GL.vertexAttribPointer (texCoordAttribute, 2, GL.FLOAT, false, 0, 0);
		GL.uniformMatrix3D (projectionMatrixUniform, false, Game.camera.projMatrix);
		GL.uniformMatrix3D (modelViewMatrixUniform, false, Game.camera.viewMatrix);
		GL.uniform1i (imageUniform, 0);
		setUnifom();
		GL.drawArrays (GL.TRIANGLE_STRIP, 0, 4);
		
	}
	public function dispose()
	{
		GL.deleteProgram(shader);
		GL.deleteBuffer(vertexBuffer);
		GL.deleteBuffer(texCoordBuffer);
		GL.deleteTexture(texture);
	}
	
}