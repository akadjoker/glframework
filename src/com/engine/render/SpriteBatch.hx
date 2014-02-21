package com.engine.render;

import flash.geom.Matrix3D;

import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;


import com.engine.render.BlendMode;
import com.engine.game.Game;

/**
 * ...
 * @author djoker
 */
class SpriteBatch extends Buffer
{

	private var capacity:Int;
	private var numVerts:Int;
	private var numIndices:Int; 
	private var vertices:Float32Array;
	private var lastIndexCount:Int;
	private var drawing:Bool;
	private var currentBatchSize:Int;
	private var currentBlendMode:Int;
	private var currentBaseTexture:Texture;

	
	public var numTex:Int=0;
	public var numBlend:Int=0;

private var vertexBuffer:GLBuffer;
private var indexBuffer:GLBuffer;

private var invTexWidth:Float = 0;
private var invTexHeight:Float = 0;


	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;


   
public var shader:SpriteShader;

	public function new(capacity:Int ) 
	{
		super();
	   this.capacity = capacity;
	   vertexStrideSize =  9 * 4; // 9 floats (x, y, z,u,v, r, g, b, a)
       numVerts = capacity * vertexStrideSize *   4;
       numIndices = capacity * 6;
      vertices = new Float32Array(numVerts);

    

	
	
        var indices:Array<Int> = [];
        var index = 0;
        for (count in 0...numIndices) {
            indices.push(index);
            indices.push(index + 1);
            indices.push(index + 2);
            indices.push(index);
            indices.push(index + 2);
            indices.push(index + 3);
            index += 4;
        }
		

    drawing = false;
    currentBatchSize = 0;
	currentBlendMode = BlendMode.NORMAL;
	
	currentBaseTexture = null;

	

    vertexBuffer = GL.createBuffer();
    indexBuffer = GL.createBuffer();


    //upload the index data
    GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
    GL.bufferData(GL.ELEMENT_ARRAY_BUFFER,  new Int16Array(indices), GL.STATIC_DRAW);


    GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
    GL.bufferData(GL.ARRAY_BUFFER, vertices, GL.DYNAMIC_DRAW);
	

	
	shader = new SpriteShader();
  	start();
	}
	
	
    public function Render(texture:Texture, x:Float, y:Float,  srcX:Int,  srcY:Int,  srcWidth:Int,  srcHeight:Int,blendMode:Int)
	{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    // check blend mode
    if(blendMode != this.currentBlendMode)
    {
        this.setBlendMode(blendMode);
    }
	
 var u:Float = srcX * invTexWidth;
 var v:Float = (srcY + srcHeight) * invTexHeight;
 var u2:Float = (srcX + srcWidth) * invTexWidth;
 var v2:Float = srcY * invTexHeight;
 var fx2:Float = x + srcWidth;
 var fy2:Float = y + srcHeight;

 
var r, g, b, a:Float;
r = 1;
g = 1;
b = 1;
a = 1;




var index:Int = currentBatchSize *  vertexStrideSize;

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


 
 
this.currentBatchSize++;
	
	

	}
public function RenderTile(texture:Texture,x:Float,y:Float,width:Float,height:Float,clip:Clip,flipx:Bool,flipy:Bool,blendMode:Int)
{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    // check blend mode
    if(blendMode != this.currentBlendMode)
    {
       this.setBlendMode(blendMode);
    }	
	





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
		
		
		var index:Int = currentBatchSize *  vertexStrideSize;

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


 
 
this.currentBatchSize++;
	
	
		
}
public function RenderTileScale(texture:Texture,x:Float,y:Float,width:Float,height:Float,scaleX:Float,scaleY:Float,clip:Clip,flipx:Bool,flipy:Bool,blendMode:Int)
{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    // check blend mode
    if(blendMode != this.currentBlendMode)
    {
       this.setBlendMode(blendMode);
    }	
	





	    var fx:Float = x;
		var fy:Float = y;
		var fx2:Float = x+width ;
		var fy2:Float = y+height ;
		
		if (scaleX != 1 || scaleY != 1)
		{
			fx *= scaleX;
			fy *= scaleY;
			fx2 *= scaleX;
			fy2 *= scaleY;
		}
		
		
				
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
		
		
		var index:Int = currentBatchSize *  vertexStrideSize;

vertices[index++] = fx;
vertices[index++] = fy;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v;
vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;
	
vertices[index++] = fx;
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
vertices[index++] = fy;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;


 
 
this.currentBatchSize++;
	
	
		
}
    public function Blt(texture:Texture, src:Clip,dst:Clip,flipX:Bool,flipY:Bool,blendMode:Int)
	{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    if(blendMode != this.currentBlendMode)
    {
        this.setBlendMode(blendMode);
    }




		var fx2:Float = src.x+src.width;
		var fy2:Float = src.y+src.height;
		

		
		
		
				
 var u:Float  = dst.x * invTexWidth;
 var u2:Float = (dst.x + dst.width) * invTexWidth;
 
 var v:Float  = (dst.y + dst.height) * invTexHeight;
 var v2:Float = dst.y * invTexHeight;

 if (flipX) 
 {
			var tmp:Float = u;
			u = u2;
			u2 = tmp;
		}

		if (flipY)
		{
			var tmp:Float = v;
			v = v2;
			v2 = tmp;
		}
 


var index:Int = currentBatchSize *  vertexStrideSize;

vertices[index++] = src.x;
vertices[index++] = src.y;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v;
vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;vertices[index++] = 1;
	
vertices[index++] = src.x;
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
vertices[index++] = src.y;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v;
vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1; vertices[index++] = 1;


 

 
this.currentBatchSize++;
	
	

	}
	
	 public function RenderClip(texture:Texture, x:Float, y:Float,c:Clip,flipX:Bool,flipY:Bool,blendMode:Int)
	{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    // check blend mode
    if(blendMode != this.currentBlendMode)
    {
        this.setBlendMode(blendMode);
    }
	
 var u:Float  = c.x * invTexWidth;
 var u2:Float = (c.x + c.width) * invTexWidth;
 
 var v:Float = (c.y + c.height) * invTexHeight;
 var v2:Float = c.y * invTexHeight;
 

 
 
 var fx2:Float = x + c.width;
 var fy2:Float = y + c.height;

 
 if (flipX) {
			var tmp:Float = u;
			u = u2;
			u2 = tmp;
		}

		if (flipY) {
			var tmp:Float = v;
			v = v2;
			v2 = tmp;
		} 




var index:Int = currentBatchSize *  vertexStrideSize;


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


 
this.currentBatchSize++;
	
	

	}
	
	public function drawImage(img:Image)
	{
		if(img.texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(img.texture);
    }


    // check blend mode
    if(img.blendMode != this.currentBlendMode)
    {
        this.setBlendMode(img.blendMode);
    }
	
	


var r, g, b, a:Float;
r = img.red;
g = img.green;
b = img.blue;
a = img.alpha;




var index:Int = currentBatchSize *  vertexStrideSize;

					
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
 
vertices[index++] = x1;
vertices[index++] = y1;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v;
vertices[index++] = r;vertices[index++] = g;vertices[index++] = b;vertices[index++] = a;
	
vertices[index++] = x2;
vertices[index++] = y2;
vertices[index++] = 0;
vertices[index++] = u;vertices[index++] = v2;
vertices[index++] = r;vertices[index++] = g;vertices[index++] = b;vertices[index++] = a;

vertices[index++] = x3;
vertices[index++] = y3;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v2;
vertices[index++] = r;vertices[index++] = g;vertices[index++] = b;vertices[index++] = a;

vertices[index++] = x4;
vertices[index++] = y4;
vertices[index++] = 0;
vertices[index++] = u2;vertices[index++] = v;
vertices[index++] = r;vertices[index++] = g;vertices[index++] = b;vertices[index++] = a;


    currentBatchSize++;
	
	}
	
	inline public function RenderNormal(texture:Texture, x:Float, y:Float,blendMode:Int)
	{
	if(texture!= this.currentBaseTexture || this.currentBatchSize >= this.capacity)
    {
       		switchTexture(texture);
    }


    // check blend mode
    if(blendMode != this.currentBlendMode)
    {
        this.setBlendMode(blendMode);
    }
	
 var u:Float = 0;
 var v:Float = 1;
 var u2:Float = 1;
 var v2:Float = 0;
 var fx2:Float = x + texture.width;
 var fy2:Float = y + texture.height;





var index:Int = currentBatchSize *  vertexStrideSize;

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


    currentBatchSize++;

	}
	
	public function Begin()
	{
		 numTex = 0;
	     numBlend = 0;
		 currentBatchSize = 0;
		 start();
	}
	public function End()
	{
	  flush();
      shader.Disable();
	}
	
	private function start()
    {
     shader.Enable();
 	 GL.activeTexture(GL.TEXTURE0);
     GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(shader.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3+2) * 4);
     if(currentBlendMode != BlendMode.NORMAL)
     {
        setBlendMode(currentBlendMode);
     }
}
	
private function flush()
{
    if (currentBatchSize == 0) return;
	this.update();
	currentBaseTexture.Bind();
	numTex++;
	 GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(Game.projMatrix.toArray()));
     GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(viewMatrix.toArray()));
      
    GL.uniform1i (shader.imageUniform, 0);
    GL.bufferSubData(GL.ARRAY_BUFFER, 0, vertices);
	GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
    GL.drawElements(GL.TRIANGLES, currentBatchSize * 6, GL.UNSIGNED_SHORT, 0);
//	trace(currentBatchSize);
    currentBatchSize = 0;
}
private function switchTexture (texture:Texture) 
{
this.flush();
this.currentBaseTexture = texture;
invTexWidth  = 1.0 / texture.width;
invTexHeight = 1.0 / texture.height;

}

public function setBlendMode(blendMode:Int)
{
    flush();
    currentBlendMode = blendMode;
    BlendMode.setBlend(currentBlendMode);
    numBlend++;
	
}
override public function dispose():Void 
{
	this.vertices = null;
	GL.deleteBuffer(indexBuffer);
	GL.deleteBuffer(vertexBuffer);
	super.dispose();
	
}


}