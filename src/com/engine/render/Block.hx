package com.engine.render;

import flash.geom.Rectangle;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;

import com.engine.game.Game;
import com.engine.render.filter.Filter;
import flash.geom.Matrix;
import flash.geom.Matrix3D;
import flash.geom.Vector3D;

/**
 * ...
 * @author djoker
 */
class Block
{
	
	    private var vertexBuffer:GLBuffer;
        private var indexBuffer:GLBuffer;
		public var width:Int;
		public var height:Int;
		public var vertices:Array<Float>;
	    public var indices:Array<Int>;
	    public var index:Int;
		public var vertexStrideSize:Int;
		public var vMin:Vector3D;
		public var vMax:Vector3D;
		public var AMin:Vector3D;
		public var AMax:Vector3D;
		public var bound:Rectangle;
		public var triangles:Int;
	

		

	public function new(width:Int, height:Int) 
	{
		 vertexStrideSize =  (3 + 2 + 4)   * 4  ; 
		this.width = width;
		this.height = height;
		vertices = new Array<Float>();
		indices = new Array<Int>();
		index = 0;
		vMin = new Vector3D(1000, 1000);
		vMax = new Vector3D(-1000, -1000);
		AMin = new Vector3D(1000, 1000);
		AMax = new Vector3D(-1000, -1000);
		bound = new  Rectangle();
	
	}
	public function updateBound()
	{
		setBound(AMin.x, AMin.y, AMax.x, AMax.y);
	}
	public function setBound(minX:Float, minY:Float, maxX:Float , maxY:Float)
	{
		bound.left = minX;
		bound.top = minY;
		bound.right = maxX - minX;
		bound.bottom=maxY - minY;
	}
	public function addVertex(x:Float, y:Float, u:Float, v:Float,?alpha:Float=1)
	{
		vertices.push(x);
		vertices.push(y);
		vertices.push(0);
		vertices.push(u);
		vertices.push(v);
		vertices.push(1);
		vertices.push(1);
		vertices.push(1);
		vertices.push(alpha);
	}
	public function build()
	{
		indexBuffer = GL.createBuffer();
        GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, indexBuffer);
        GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, new Int16Array(indices), GL.STATIC_DRAW);
		vertexBuffer = GL.createBuffer();
        GL.bindBuffer(GL.ARRAY_BUFFER, vertexBuffer);
        GL.bufferData(GL.ARRAY_BUFFER, new Float32Array(vertices), GL.STATIC_DRAW);
		getAABB();
		triangles = indices.length;
  	    indices = null;
	    vertices = null;
	}
	public function render()
	{
	 GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
	 GL.vertexAttribPointer(Filter.vertexAttribute, 3, GL.FLOAT, false, vertexStrideSize, 0);
     GL.vertexAttribPointer(Filter.texCoordAttribute  , 2, GL.FLOAT, false, vertexStrideSize, 3 * 4);
     GL.vertexAttribPointer(Filter.colorAttribute, 4, GL.FLOAT, false, vertexStrideSize, (3+2) * 4);
     GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, this.indexBuffer); 
     GL.drawElements(GL.TRIANGLES, triangles, GL.UNSIGNED_SHORT, 0);
	}
	public function getAABB()
	{
		    var x:Float;
			var y:Float;
			
			var  ELEMENTS_PER_VERTEX:Int = 9;
			var offset:Int=0;
        

		
			for (i in 0...vertices.length)
			{
				        x = vertices[offset];
                        y = vertices[offset+1];
                        offset += ELEMENTS_PER_VERTEX;
                        
                        if (vMin.x > x) vMin.x = x;
                        if (vMax.x < x) vMax.x = x;
                        if (vMin.y > y) vMin.y = y;
                        if (vMax.y < y) vMax.y = y;
			}
                
				
	}
	
	public function dispose()
	{
	   GL.deleteBuffer(indexBuffer);
	   GL.deleteBuffer(vertexBuffer);
	}
}