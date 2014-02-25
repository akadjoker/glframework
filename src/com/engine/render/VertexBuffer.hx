package com.engine.render;

import flash.geom.Matrix;
import flash.geom.Point;

import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.gl.GLUniformLocation;
import openfl.utils.Float32Array;
import openfl.utils.UInt8Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;

import flash.geom.Matrix;
import com.engine.render.BlendMode;

/**
 * ...
 * @author djoker
 */
class VertexBuffer
{
private var vertexBuffer:GLBuffer;
private var indexBuffer:GLBuffer;

public var vertexAttribute:Int=0;
public var textureAttribute :Int=1;
public var colorAttribute:Int=2;

public var vertices:Float32Array;

	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;
	
	
private var imageUniform:GLUniformLocation;
private var modelViewMatrixUniform:GLUniformLocation;
private var projectionMatrixUniform:GLUniformLocation;
private var shaderProgram:GLProgram;


	private var size:Int;
    private var vertSize:Int;
	private var numVerts:Int;
	private var numIndices:Int;
	private var idx:Int = 0;
    private var primitiveCount:Int = 0;

	public function new() 
	{
		
		

  size = 1000;
  vertSize = 6;
  numVerts = size * 4 *   vertSize;
  numIndices = size * 6;
	 
vertices = new Float32Array(numVerts); 


var indices:Int16Array = new Int16Array(numIndices); 
var j:Int = 0;
var i:Int = 0;
 for (count in 0...numIndices) 
		{
         indices[i] = j + 0; i++;
         indices[i] = j + 1; i++;
         indices[i] = j + 2; i++;
         indices[i] = j + 0; i++;
         indices[i] = j + 2; i++;
         indices[i] = j + 3; i++;
		 
		 j += 4;
        }
		

 

primitiveCount = 0;



   vertexDeclaration = [3, 2,4];
   vertexStrideSize =  9 * 4 ; // 9 floats (x, y, z,u,v, r, g, b, a)




 if (!initializeShaders()) return;

 
vertexBuffer = GL.createBuffer();
GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
GL.bindBuffer(GL.ARRAY_BUFFER, null);

 indexBuffer= GL.createBuffer();
 GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
 GL.bufferData(GL.ELEMENT_ARRAY_BUFFER,  indices, GL.STATIC_DRAW);
 
 

	}
	
	
 public function RenderNormal( x:Float, y:Float,w:Float,h:Float)
{

	
 var u:Float = 0;
 var v:Float = 1;
 var u2:Float = 1;
 var v2:Float = 0;

 var fx2:Float = x + w;
 var fy2:Float = y + h;


var index:Int = primitiveCount *  vertexStrideSize;

vertices[index++] = x;
vertices[index++] = y;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v;
vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;
	
vertices[index++] = x;
vertices[index++] = fy2;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v2;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;

vertices[index++] = fx2;
vertices[index++] = fy2;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v2;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;

vertices[index++] = fx2;
vertices[index++] = y;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;
/*

vertices[idx++] = x;
vertices[idx++] = y;
vertices[idx++] = 0;
vertices[idx++] = u;vertices[idx++] = v;
vertices[idx++] = 1;vertices[idx++] = 1;vertices[idx++] = 1;vertices[idx++] = 1;
	
vertices[idx++] = x;
vertices[idx++] = fy2;
vertices[idx++] = 0;
vertices[idx++] = u;vertices[idx++] = v2;
vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1;

vertices[idx++] = fx2;
vertices[idx++] = fy2;
vertices[idx++] = 0;
vertices[idx++] = u2;vertices[idx++] = v2;
vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1;

vertices[idx++] = fx2;
vertices[idx++] = y;
vertices[idx++] = 0;
vertices[idx++] = u2;vertices[idx++] = v;
vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1; vertices[idx++] = 1;
*/

primitiveCount++;

}

	public function Begin(matProj:Matrix3D,matView:Matrix3D)
	{
		primitiveCount = 0;
		idx = 0;
		

GL.useProgram (shaderProgram);		
GL.enableVertexAttribArray(vertexAttribute);
GL.enableVertexAttribArray(textureAttribute);
GL.enableVertexAttribArray(colorAttribute);


GL.activeTexture (GL.TEXTURE0);
GL.enable (GL.TEXTURE_2D);



 GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
 GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
 
GL.vertexAttribPointer(vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize,0);
GL.vertexAttribPointer(textureAttribute,2, GL.FLOAT, false, vertexStrideSize,3*4);
GL.vertexAttribPointer(colorAttribute  ,4, GL.FLOAT, false, vertexStrideSize,(3+2) * 4);

GL.uniformMatrix3D (projectionMatrixUniform, false, matProj);
GL.uniformMatrix3D (modelViewMatrixUniform, false, matView);
GL.uniform1i (imageUniform, 0);

 
 		
	}
	public function End()
	{
		
 GL.bufferSubData(GL.ARRAY_BUFFER, 0, vertices);
 GL.drawElements(GL.TRIANGLES, primitiveCount * 6, GL.UNSIGNED_SHORT, 0);
		
		
GL.bindBuffer (GL.ARRAY_BUFFER, null);
GL.bindTexture (GL.TEXTURE_2D, null);


GL.disable (GL.TEXTURE_2D);

GL.disableVertexAttribArray (vertexAttribute);
GL.disableVertexAttribArray (textureAttribute);
GL.disableVertexAttribArray (colorAttribute);
GL.useProgram (null);
	}
	

private function initializeShaders ():Bool {

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

var vertexShader = GL.createShader (GL.VERTEX_SHADER);
GL.shaderSource (vertexShader, vertexShaderSource);
GL.compileShader (vertexShader);

if (GL.getShaderParameter (vertexShader, GL.COMPILE_STATUS) == 0) {

throw "Error compiling vertex shader";

}

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
     gl_FragColor = vColor * texColor;
  // gl_FragColor = texColor *vec4(1.0, 1.0, 1.0, 1.0);
  
//gl_FragColor = texture2D (uImage0, vTexCoord);
}";

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

vertexAttribute  = GL.getAttribLocation (shaderProgram, "aVertexPosition");
textureAttribute = GL.getAttribLocation (shaderProgram, "aTexCoord");
//colorAttribute   = GL.getAttribLocation (shaderProgram, "aColor");

//GL.bindAttribLocation(shaderProgram, vertexAttribute, "aVertexPosition");
//GL.bindAttribLocation(shaderProgram,textureAttribute, "aTexCoord");
GL.bindAttribLocation(shaderProgram, colorAttribute, "aColor");


trace(vertexAttribute);
trace(textureAttribute);
trace(colorAttribute);

projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");
imageUniform = GL.getUniformLocation (shaderProgram, "uImage0");
return true;
}

		
public function addVertex(index:Int, x:Float, y:Float, u:Float, v:Float, r:Float, g:Float, b:Float, a:Float ) 
{
        var offset = index * 9;
        vertices[offset] = x;
        vertices[offset + 1] = y;
        vertices[offset + 2] = 0;
        vertices[offset + 3] = u;
        vertices[offset + 4] = v;
        vertices[offset + 5] = r;
        vertices[offset + 6] = g;
        vertices[offset + 7] = b;
        vertices[offset + 8] = a;
        
    }
	
}