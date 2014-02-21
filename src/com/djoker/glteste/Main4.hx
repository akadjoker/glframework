package com.djoker.glteste;
 
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.geom.Matrix3D;
import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;

import com.engine.math.Matrix;
import com.engine.render.SpriteBatch;
import com.engine.render.Texture;

// Based on https://github.com/openfl/openfl-samples/blob/master/SimpleOpenGLView/Source/Main.hx
// Draws 100 000 white(!) rectangles on top of each other
class Main extends Sprite {
private var shaderProgram:GLProgram;
private var vertexAttribute:Int;
private var colorAttribute:Int;
 public var textureAttribute :Int;
private var vertexBuffer:GLBuffer;
private var indexBuffer:GLBuffer;
private var imageUniform:Dynamic;

private var view:OpenGLView;
private var Tex:Texture;
private var batch:SpriteBatch;
 
var vertices:Float32Array;

	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;

	private var size:Int;
    private var vertSize:Int;
	private var numVerts:Int;
	private var numIndices:Int;
	private var idx:Int=0;

private var rectangleCount:Int = 100;
private var primitiveIndex:Int = 0;
private var colorIndex:Int = 0;
private var primitiveCount:Int = 0;
 

 
 public function RenderNormal( x:Float, y:Float,w:Float,h:Float)
{

	
 var u:Float = 0;
 var v:Float = 1;
 var u2:Float = 1;
 var v2:Float = 0;

 var fx2:Float = x + w;
 var fy2:Float = y + h;

/*
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
*/

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


primitiveCount++;

}
	public static function getColorValue(color:Int):Float
	{
		var h:Int = (color >> 16) & 0xFF;
		var s:Int = (color >> 8) & 0xFF;
		var v:Int = color & 0xFF;

		return Std.int(Math.max(h, Math.max(s, v))) / 255;
	}

public function new() {
super();
if (OpenGLView.isSupported) {
view = new OpenGLView();

Tex = new Texture("assets/openfl.png",true);
batch = new SpriteBatch();

 
createProgram();

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
         indices[i] = j + 2; i++;
         indices[i] = j + 3; i++;
         indices[i] = j + 0; i++;
		 
		 j += 4;
        }
		

/*
	    var indices:Array<Int> = [];
        var index:Int = 0;
        for (count in 0...numIndices) 
		{
            indices.push(index);
            indices.push(index + 1);
            indices.push(index + 2);
            indices.push(index);
            indices.push(index + 2);
            indices.push(index + 3);
            index += 4;
        }
*/
 

primitiveCount = 0;
primitiveIndex = 0;



   //vertexDeclaration = [3, 2, 4];
   //vertexStrideSize =  9 * 4; // 9 floats (x, y, z,u,v, r, g, b, a)
   vertexDeclaration = [3, 2,4];
   vertexStrideSize =  9 * 4; // 9 floats (x, y, z,u,v, r, g, b, a)
   trace("size:" + vertexStrideSize);
     
     var offset:Int = 0;
  
		



 

 
vertexBuffer = GL.createBuffer();
GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
GL.bindBuffer(GL.ARRAY_BUFFER, null);

  indexBuffer= GL.createBuffer();
  GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
  //GL.bufferData(GL.ELEMENT_ARRAY_BUFFER,  new Int16Array(indices), GL.STATIC_DRAW);
 GL.bufferData(GL.ELEMENT_ARRAY_BUFFER,  indices, GL.STATIC_DRAW);

	

view.render = renderView;
addChild(view);
addChild(new FPS(10,10,0xff0ff));
}
}
 

	
 
private function createProgram():Void {
	
	
	GL.disable(GL.DEPTH_TEST);
    GL.disable(GL.CULL_FACE);

    GL.enable(GL.BLEND);
    GL.colorMask(true, true, true, true);
	
			var vertexShaderSource = 
			
	"
    uniform mat4 modelViewMatrix;
    uniform mat4 projectionMatrix;
    attribute vec3 a_position;
    attribute vec2 a_texCoord;
	attribute vec4 a_color;
	varying vec2 v_texCoord;
	varying vec4 vColor;
    void main()
    {
	    vColor = a_color;
        v_texCoord = a_texCoord;
        //gl_Position = u_projection * vec4(a_position, 0.0, 1.0);
		gl_Position = projectionMatrix * modelViewMatrix * vec4(a_position, 1.0);
				
        gl_PointSize = 1.0;
    }";
 
var vertexShader = GL.createShader(GL.VERTEX_SHADER);
GL.shaderSource(vertexShader, vertexShaderSource);
GL.compileShader(vertexShader);

if (GL.getShaderParameter(vertexShader, GL.COMPILE_STATUS) == 0) {
throw throw(GL.getShaderInfoLog(vertexShader));
 
}
		
		var fragmentShaderSource = 
"		
varying vec2 v_texCoord;
varying vec4 vColor;
uniform sampler2D u_texture;
void main()
{
   vec4 texColor = texture2D(u_texture, v_texCoord);
  // gl_FragColor = vColor * texColor;
  // gl_FragColor = texColor *vec4(1.0, 1.0, 1.0, 1.0);

gl_FragColor = texture2D (u_texture, v_texCoord);



  //gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
}";
		



 
var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
 
GL.shaderSource(fragmentShader, fragmentShaderSource);
GL.compileShader(fragmentShader);

 
if (GL.getShaderParameter(fragmentShader, GL.COMPILE_STATUS) == 0) {
 throw(GL.getShaderInfoLog(fragmentShader));

}
 
shaderProgram = GL.createProgram();
GL.attachShader(shaderProgram, vertexShader);
GL.attachShader(shaderProgram, fragmentShader);
GL.linkProgram(shaderProgram);

if (GL.getProgramParameter(shaderProgram, GL.LINK_STATUS) == 0)
{
 throw(GL.getShaderInfoLog(fragmentShader));
}

vertexAttribute = GL.getAttribLocation(shaderProgram, "a_position");
textureAttribute = GL.getAttribLocation(shaderProgram, "a_texCoord");
colorAttribute = GL.getAttribLocation(shaderProgram, "a_color");
imageUniform = GL.getUniformLocation (shaderProgram, "u_texture");


}
 
 
private function renderView(rect:Rectangle):Void {
GL.viewport(Std.int(rect.x), Std.int(rect.y), Std.int(rect.width), Std.int(rect.height));
 
GL.clearColor(0,0,0.4, 1);
GL.clear(GL.COLOR_BUFFER_BIT);
 
var positionX = 0;// rect.width / 2;
var positionY = 0;// rect.height / 2;


/*

primitiveCount = 0;
primitiveIndex = 0;
idx = 0;

				

RenderNormal(0, 0, 100, 100);
RenderNormal(100, 100, 400, 400);



 
var projMatrix:Matrix = Matrix.OrthoOffCenterLH(0, rect.width, rect.height, 0, 1000, -1000);
var modelViewMatrix = Matrix.create2D(positionX, positionY, 1, 0);



var projectionMatrixUniform = GL.getUniformLocation(shaderProgram, "projectionMatrix");
var modelViewMatrixUniform = GL.getUniformLocation(shaderProgram, "modelViewMatrix");


GL.useProgram(shaderProgram);
GL.enableVertexAttribArray(vertexAttribute);
GL.enableVertexAttribArray(textureAttribute);
GL.enableVertexAttribArray(colorAttribute);

GL.enable (GL.TEXTURE_2D);
GL.activeTexture(GL.TEXTURE0);
Tex.Bind();

GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);




GL.vertexAttribPointer(vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize,0);
GL.vertexAttribPointer(textureAttribute,2, GL.FLOAT, false, vertexStrideSize,3*4);
GL.vertexAttribPointer(colorAttribute  ,4, GL.FLOAT, false, vertexStrideSize,(3+2)*4);




GL.uniformMatrix4fv(projectionMatrixUniform, false, new Float32Array(projMatrix.toArray()));
GL.uniformMatrix4fv(modelViewMatrixUniform, false, new Float32Array(modelViewMatrix.toArray()));
GL.uniform1i (imageUniform, 0);


GL.bufferSubData(GL.ARRAY_BUFFER, 0, vertices);
GL.drawElements(GL.TRIANGLES, primitiveCount * 6, GL.UNSIGNED_SHORT, 0);

 
GL.bindBuffer (GL.ARRAY_BUFFER, null);
GL.disableVertexAttribArray (vertexAttribute);
GL.disableVertexAttribArray (colorAttribute);
GL.disableVertexAttribArray(textureAttribute);
GL.useProgram (null);
*/


 
var projMatrix:Matrix = Matrix.OrthoOffCenterLH(0, rect.width, rect.height, 0, 1000, -1000);
var modelViewMatrix = Matrix.create2D(positionX, positionY, 1, 0);


batch.shader.projMatrix = projMatrix;
batch.shader.modelViewMatrix = modelViewMatrix;

batch.Begin();

batch.Render(Tex, 100, 100, 0, 0, 120, 120, 0);

batch.RenderNormal(Tex, 0, 0, 0);

batch.End();
	
}
}