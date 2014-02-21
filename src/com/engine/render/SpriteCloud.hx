package com.engine.render;





import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;

import com.engine.misc.Util;
import com.engine.math.Matrix;
import com.engine.math.Vector2;

import com.engine.game.Game;

/**
 * ...
 * @author djoker
 */
class SpriteCloud extends Buffer
{

	private var capacity:Int;
	private var numVerts:Int;
	private var numIndices:Int; 
	private var tmpVertices:Float32Array;
	private var vertices:Float32Array;
	private var indices:Int16Array;
	private var lastIndexCount:Int;
	private var drawing:Bool;
	public var currentBatchSize:Int;
	private var currentBlendMode:Int;
	private var currentBaseTexture:Texture;
    private var vertexBuffer:GLBuffer;
    private var indexBuffer:GLBuffer;
    private var invTexWidth:Float = 0;
    private var invTexHeight:Float = 0;
 	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;
    public var shader:SpriteShader;
	private var index:Int;
	private var rebuid:Bool;

	
		

	public function new(texture:Texture,capacity:Int ) 
	{
		super();
	 this.capacity = capacity;


	
	
	   vertexDeclaration = [3, 2,4];
       vertexStrideSize =  9 * 4; 
 
	 
       index = 0;
  
      tmpVertices = new Float32Array(capacity*vertexStrideSize);


    drawing = false;
    currentBatchSize = 0;
	currentBlendMode = BlendMode.NORMAL;
    this.currentBaseTexture = texture;
    invTexWidth  = 1.0 / texture.width;
    invTexHeight = 1.0 / texture.height;

	
	
		    
    vertexBuffer = GL.createBuffer();
    indexBuffer = GL.createBuffer();

	
	shader = new SpriteShader();

	rebuid = false;
	}
	
	public function build()
	{

       numVerts = tmpVertices.length * vertexStrideSize *   4;
       numIndices = tmpVertices.length * 6;
	   
	   
       vertices = new Float32Array(numVerts);

	   for ( i in 0...tmpVertices.length )
	   {
             vertices[i]=tmpVertices[i];
	   }
     tmpVertices = null;

	
	
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
		
		

    
    GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
    GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, indices, GL.STATIC_DRAW);
    GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, null);
   
    GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.STATIC_DRAW);
	GL.bindBuffer(GL.ARRAY_BUFFER, null);
	rebuid = true;
		
	}
	
override public function dispose():Void 
{
	    this.indices = null;
		this.vertices = null;
        GL.deleteBuffer(indexBuffer);
		GL.deleteBuffer(vertexBuffer);
	super.dispose();
	
}
	

	
public function addImage(img:Image)
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
 
tmpVertices[index++] = x1;
tmpVertices[index++] = y1;
tmpVertices[index++] = 0;
tmpVertices[index++] = u;tmpVertices[index++] = v;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;
	
tmpVertices[index++] = x2;
tmpVertices[index++] = y2;
tmpVertices[index++] = 0;
tmpVertices[index++] = u;tmpVertices[index++] = v2;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;

tmpVertices[index++] = x3;
tmpVertices[index++] = y3;
tmpVertices[index++] = 0;
tmpVertices[index++] = u2;tmpVertices[index++] = v2;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;

tmpVertices[index++] = x4;
tmpVertices[index++] = y4;
tmpVertices[index++] = 0;
tmpVertices[index++] = u2;tmpVertices[index++] = v;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;


    currentBatchSize++;
	
	}
	
	public function add()
	{
		currentBatchSize++;
	}
public function addTile(x:Float,y:Float,width:Float,height:Float,clip:Clip,flipx:Bool,flipy:Bool)
{
var r, g, b, a:Float;
r = 1;
g = 1;
b = 1;
a = 1;




		var fx2:Float = x+width;
		var fy2:Float = y+height;
		

		
		
		
				
 var u:Float  = clip.x * invTexWidth;
 var u2:Float = (clip.x + clip.width) * invTexWidth;
 
 var v:Float  = (clip.y + clip.height) * invTexHeight;
 var v2:Float = clip.y * invTexHeight;

 if (flipx) 
 {
			var tmp:Float = u;
			u = u2;
			u2 = tmp;
		}

		if (flipy)
		{
			var tmp:Float = v;
			v = v2;
			v2 = tmp;
		}
 
tmpVertices[index++] = x;
tmpVertices[index++] = y;
tmpVertices[index++] = 0;
tmpVertices[index++] = u;tmpVertices[index++] = v;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;
	
tmpVertices[index++] = x;
tmpVertices[index++] = fy2;
tmpVertices[index++] = 0;
tmpVertices[index++] = u;tmpVertices[index++] = v2;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;

tmpVertices[index++] = fx2;
tmpVertices[index++] = fy2;
tmpVertices[index++] = 0;
tmpVertices[index++] = u2;tmpVertices[index++] = v2;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;

tmpVertices[index++] = fx2;
tmpVertices[index++] = y;
tmpVertices[index++] = 0;
tmpVertices[index++] = u2;tmpVertices[index++] = v;
tmpVertices[index++] = r;tmpVertices[index++] = g;tmpVertices[index++] = b;tmpVertices[index++] = a;

		    
						
				
			
						
    currentBatchSize++;
	
	}
	
	public function addVertex(x:Float, y:Float, u:Float, v:Float)
	{
    tmpVertices[index++] = x;
    tmpVertices[index++] = y;
    tmpVertices[index++] = 0;
    tmpVertices[index++] = u;tmpVertices[index++] = v;
    tmpVertices[index++] = 1;tmpVertices[index++] = 1;tmpVertices[index++] = 1;tmpVertices[index++] = 1;
	}

	
	
	public function render()
	{
		this.update();
		if (!rebuid) 
		{
			rebuid = true;
			build();
			return;
		}

	 if (currentBatchSize==0) return;
	 shader.Enable();
 	// GL.bufferSubData(GL.ARRAY_BUFFER, 0, vertices);
	  
     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(shader.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3+2) * 4);
     BlendMode.setBlend(currentBlendMode);
     GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(viewMatrix.toArray()));
     GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(Game.projMatrix.toArray()));
	 GL.activeTexture(GL.TEXTURE0);
 	 currentBaseTexture.Bind();
     GL.uniform1i (shader.imageUniform, 0);
	 GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer); 
     GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
     shader.Disable();
    }

}