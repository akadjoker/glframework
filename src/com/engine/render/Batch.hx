package com.engine.render;

import com.engine.game.GameObject;
import flash.geom.Matrix3D;

import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;


import com.engine.render.BlendMode;

/**
 * ...
 * @author djoker
 */
class Batch
{
	public var colorBuffer:GLBuffer;
	public var colorIndex:Int;
	public var colors:Float32Array;

	public var indexBuffer:GLBuffer;
	public var indices:Int16Array;
	public var uvBuffer:GLBuffer;
	public var uvs:Float32Array;
	public var vertexBuffer:GLBuffer;
	public var vertices:Float32Array;
	
    private var capacity:Int;
	private var numVerts:Int;
	private var numIndices:Int; 

	private var currentBatchSize:Int;
	private var currentBlendMode:Int;
	private var currentBaseTexture:Texture;


	private var uvCount:Int;
	private var colorCount:Int;
	private var vertexCount:Int;
	
	
   
public var shader:SpriteShader;

private var invTexWidth:Float = 0;
private var invTexHeight:Float = 0;


	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;

	
    public var camera:OrthoCamera;


	public function new(texture:Texture,Camera:OrthoCamera,capacity:Int) 
	{
	
		
		this.vertexBuffer =  GL.createBuffer();
		this.indexBuffer =  GL.createBuffer();
		this.uvBuffer =  GL.createBuffer();
		this.colorBuffer =  GL.createBuffer();
	
		
		 this.capacity = capacity;
		 camera = Camera;
           
     
	   vertexDeclaration = [3, 2,4];
       vertexStrideSize =  9 * 4; // 9 floats (x, y, z,u,v, r, g, b, a)
 
	   numVerts = capacity * vertexStrideSize *   4;
       numIndices = capacity * 6;

	uvCount = 0;
	colorCount=0;
	vertexCount = 0;
	
  

    vertices = new Float32Array(capacity * 3 *4);
	GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
	GL.bufferData(GL.ARRAY_BUFFER,this.vertices , GL.DYNAMIC_DRAW);
	
		
	uvs = new Float32Array(capacity * 2*4);
	GL.bindBuffer(GL.ARRAY_BUFFER, this.uvBuffer);
	GL.bufferData(GL.ARRAY_BUFFER, this.uvs , GL.DYNAMIC_DRAW);
	
		
	colors = new Float32Array(capacity * 4 * 4);
	GL.bindBuffer(GL.ARRAY_BUFFER, this.colorBuffer);
	GL.bufferData(GL.ARRAY_BUFFER, this.colors , GL.DYNAMIC_DRAW);
		
		
		

    

	
	
        this.indices = new Int16Array(numIndices); 
		var length = Std.int(this.indices.length/6);
		
		for (i in 0...length) 
		{
			var index2 = i * 6;
			var index3 = i * 4;
			this.indices[index2 + 0] = index3 + 0;
			this.indices[index2 + 1] = index3 + 1;
			this.indices[index2 + 2] = index3 + 2;
			this.indices[index2 + 3] = index3 + 0;
			this.indices[index2 + 4] = index3 + 2;
			this.indices[index2 + 5] = index3 + 3;
		};
		
		GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
		GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, this.indices, GL.STATIC_DRAW);
		


    currentBatchSize = 0;
	currentBlendMode = BlendMode.SCREEN;
    this.currentBaseTexture = texture;
    invTexWidth  = 1.0 / texture.texWidth;
    invTexHeight = 1.0 / texture.texHeight;
	
	shader = new SpriteShader();

	}
	public function dispose ():Void {
		
		this.vertices = new Float32Array ([]);
		this.uvs = new Float32Array ([]);
		this.indices = new Int16Array ([]);
		this.colors = new Float32Array ([]);
        GL.deleteBuffer(indexBuffer);
		GL.deleteBuffer(vertexBuffer);
		GL.deleteBuffer(colorBuffer);
		GL.deleteBuffer(uvBuffer);
	}
	
	
	public function Begin()
	{
	 uvCount = 0;
	 colorCount=0;
	 vertexCount = 0;
	 currentBatchSize = 0;
     shader.Enable();


     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
	 GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.vertices);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, 0, 0);
	 
	 GL.bindBuffer(GL.ARRAY_BUFFER, this.uvBuffer);
	 GL.bufferSubData(GL.ARRAY_BUFFER,  0, this.uvs);
     GL.vertexAttribPointer(shader.texCoordAttribute  , 2, GL.FLOAT, false, 0, 0);
	 
	 GL.activeTexture(GL.TEXTURE0);
	 currentBaseTexture.Bind();
	
	 GL.bindBuffer(GL.ARRAY_BUFFER, this.colorBuffer);
	 GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.colors);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, 0,0);
	 
    BlendMode.setBlend(currentBlendMode);
    }
	public function End()
	{
	 if (currentBatchSize==0) return;

	
 GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(camera.projMatrix.toArray()));
 GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(camera.modelViewMatrix.toArray()));
        
    GL.uniform1i (shader.imageUniform, 0);
	GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
    GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
    currentBatchSize = 0;
    shader.Disable();
	}
	
	

	
	public function drawImage(img:Image)
	{

	


var r, g, b, a:Float;
r = img.red;
g = img.green;
b = img.blue;
a = img.alpha;




					
		var worldOriginX:Float = img.x + img.originX;
		var worldOriginY:Float = img.y + img.originY;
		var fx:Float = -img.originX;
		var fy:Float = -img.originY;
		var fx2:Float = img.width - img.originX;
		var fy2:Float = img.height - img.originY;
		
		if (img.scaleX != 1 || img.scaleY != 1)
		{
			fx *= img.scaleX;
			fy *= img.scaleY;
			fx2 *= img.scaleX;
			fy2 *= img.scaleY;
		}
		
		 var p1x:Float = fx;
		var p1y:Float = fy;
		var p2x:Float = fx;
		var p2y:Float = fy2;
		var p3x:Float = fx2;
		var p3y:Float = fy2;
		var p4x:Float = fx2;
		var p4y:Float = fy;

		var x1:Float;
		var y1:Float;
		var x2:Float;
		var y2:Float;
		var x3:Float;
		var y3:Float;
		var x4:Float;
		var y4:Float;
		
		
		
			if (img.angle != 0) 
			{
		
	                var angle:Float = img.angle * Math.PI / 180;
					var cos:Float = Math.cos(angle);
					var sin:Float = Math.sin(angle);
					
			x1 = cos * p1x - sin * p1y;
			y1 = sin * p1x + cos * p1y;

			x2 = cos * p2x - sin * p2y;
			y2 = sin * p2x + cos * p2y;

			x3 = cos * p3x - sin * p3y;
			y3 = sin * p3x + cos * p3y;

			x4 = x1 + (x3 - x2);
			y4 = y3 - (y2 - y1);
		} else {
			x1 = p1x;
			y1 = p1y;

			x2 = p2x;
			y2 = p2y;

			x3 = p3x;
			y3 = p3y;

			x4 = p4x;
			y4 = p4y;
		}

		x1 += worldOriginX;
		y1 += worldOriginY;
		x2 += worldOriginX;
		y2 += worldOriginY;
		x3 += worldOriginX;
		y3 += worldOriginY;
		x4 += worldOriginX;
		y4 += worldOriginY;
		
				
 var u:Float  = img.clip.x * invTexWidth;
 var u2:Float = (img.clip.x + img.clip.width) * invTexWidth;
 
 var v:Float  = (img.clip.y + img.clip.height) * invTexHeight;
 var v2:Float = img.clip.y * invTexHeight;
 
 
 if (img.flipX) {
			var tmp:Float = u;
			u = u2;
			u2 = tmp;
		}

		if (img.flipY) {
			var tmp:Float = v;
			v = v2;
			v2 = tmp;
		}
 
vertices[vertexCount++] = x1;
vertices[vertexCount++] = y1;
vertices[vertexCount++] = 0;
uvs[uvCount++] = u;uvs[uvCount++] = v;
colors[colorCount++] = r;colors[colorCount++] = g;colors[colorCount++] = b;colors[colorCount++] = a;
	
vertices[vertexCount++] = x2;
vertices[vertexCount++] = y2;
vertices[vertexCount++] = 0;
uvs[uvCount++] = u;uvs[uvCount++] = v2;
colors[colorCount++] = r;colors[colorCount++] = g;colors[colorCount++] = b;colors[colorCount++] = a;

vertices[vertexCount++] = x3;
vertices[vertexCount++] = y3;
vertices[vertexCount++] = 0;
uvs[uvCount++] = u2;uvs[uvCount++] = v2;
colors[colorCount++] = r;colors[colorCount++] = g;colors[colorCount++] = b;colors[colorCount++] = a;

vertices[vertexCount++] = x4;
vertices[vertexCount++] = y4;
vertices[vertexCount++] = 0;
uvs[uvCount++] = u2;uvs[uvCount++] = v;
colors[colorCount++] = r;colors[colorCount++] = g;colors[colorCount++] = b;colors[colorCount++] = a;


    currentBatchSize++;
	
	}
	
}