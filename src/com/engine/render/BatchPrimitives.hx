package com.engine.render;

import openfl.display.OpenGLView;
import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;
import openfl.utils.Float32Array;
import openfl.utils.Int16Array;
import openfl.display.FPS;

import com.engine.misc.Util;
import com.engine.game.Game;


/**
 * ...
 * @author djoker
 */
class BatchPrimitives extends Buffer
{
	public var colorBuffer:GLBuffer;
	public var colorIndex:Int;
	public var colors:Float32Array;



	public var vertexBuffer:GLBuffer;
	public var vertices:Float32Array;
	
    private var capacity:Int;



	private var fillMode:Bool;
	private var currentBlendMode:Int;


	private var idxCols:Int;
	private var idxPos:Int;
	private var numVertices:Int;
	

   
    public var shader:PrimitiveShader;
  


	public var vertexDeclaration:Array<Int>;
	public var vertexStrideSize:Int;

	


	
	public function new(capacity:Int) 
	{
	super();
	this.vertexBuffer =  GL.createBuffer();
	this.colorBuffer =  GL.createBuffer();
	this.capacity = capacity;

    idxPos=0;
	idxCols = 0;
	numVertices = 0;
	
//	Util.create2D(matrix, x, y, zoom, -rotation *Math.PI / 180);
    vertices = new Float32Array(capacity * 3 *4);
	GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);
	GL.bufferData(GL.ARRAY_BUFFER,this.vertices , GL.DYNAMIC_DRAW);
	colors = new Float32Array(capacity * 4 * 4);
	GL.bindBuffer(GL.ARRAY_BUFFER, this.colorBuffer);
	GL.bufferData(GL.ARRAY_BUFFER, this.colors , GL.DYNAMIC_DRAW);
    fillMode = false;
	currentBlendMode = BlendMode.NORMAL;
	shader = new PrimitiveShader();
	}
	
	

	
	
public function vertex(x:Float, y:Float, ?z:Float = 0.0)
{
		vertices[idxPos++] = x;
        vertices[idxPos++] = y;
        vertices[idxPos++] = z;
		numVertices++;
}
public function color(r:Float, g:Float,b:Float, ?a:Float =0.0)
	{
	colors[idxCols++] = r;
	colors[idxCols++] = g;
	colors[idxCols++] = b;
	colors[idxCols++] = a;	
	}


	
	public function renderMode(fill:Bool=false)
	{
	 idxPos=0;
	 idxCols = 0;
	 numVertices = 0;
	 fillMode = fill;
    }
	
	public function render()
	{

	 
	 GL.bindBuffer(GL.ARRAY_BUFFER, this.vertexBuffer);	
     GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.vertices);
     GL.vertexAttribPointer(shader.vertexAttribute, 3, GL.FLOAT, false, 0, 0);
	 GL.bindBuffer(GL.ARRAY_BUFFER, this.colorBuffer);
	 GL.bufferSubData(GL.ARRAY_BUFFER, 0, this.colors);
     GL.vertexAttribPointer(shader.colorAttribute, 4, GL.FLOAT, false, 0, 0);
	
			if (fillMode == true)
			{
					GL.drawArrays( GL.TRIANGLES, 0, Std.int(idxPos / 3));
			} else
			{
	                GL.drawArrays(GL.LINES, 0, Std.int(idxPos / 3));
            }
			
	 idxPos  = 0;
	 idxCols = 0;

	}
	public function begin()
	{
	    shader.Enable();
		 GL.uniformMatrix4fv(shader.projectionMatrixUniform, false,new Float32Array(Game.projMatrix.toArray()));
         GL.uniformMatrix4fv(shader.modelViewMatrixUniform, false, new Float32Array(viewMatrix.toArray()));
         BlendMode.setBlend(currentBlendMode);
	}
    public function end()
	{

		     shader.Disable();
	}


	
	//**********
	public function circle (x:Float, y:Float, radius:Float , segments:Int,r:Float,g:Float,b:Float,?a:Float=1 ) 
	{
	
		var angle:Float = 2 * 3.1415926 / segments;
		var cos:Float = Math.cos(angle);
		var sin:Float = Math.sin(angle);
		var cx:Float = radius;
		var cy:Float = 0;
		for ( i  in 0...segments)
		 {
	
				vertex(x + cx, y + cy, 0);color(r, g, b, a);
				var temp = cx;
				cx = cos * cx - sin * cy;
				cy = sin * temp + cos * cy;
				
				vertex(x + cx, y + cy, 0);color(r, g, b, a);
			}
			
			vertex(x + cx, y + cy, 0);color(r, g, b, a);
			
			vertex(x, y, 0);color(r, g, b, a);
			
			vertex(x + cx, y + cy, 0);color(r, g, b, a);
		

		var temp:Float = cx;
		cx = radius;
		cy = 0;
		
		vertex(x + cx, y + cy, 0);color(r, g, b, a);
	}
public function fillcircle (x:Float, y:Float, radius:Float , segments:Int,r:Float,g:Float,b:Float,?a:Float=1 ) 
	{
	
		var angle:Float = 2 * 3.1415926 / segments;
		var cos:Float = Math.cos(angle);
		var sin:Float = Math.sin(angle);
		var cx:Float = radius;
		var cy:Float = 0;
		segments--;
		for ( i  in 0...segments)
		 {
				vertex(x, y, 0);color(r, g, b, a);
				vertex(x + cx, y + cy, 0);color(r, g, b, a);
				var temp:Float = cx;
				cx = cos * cx - sin * cy;
				cy = sin * temp + cos * cy;

				vertex(x + cx, y + cy, 0);color(r, g, b, a);
				
			}
		
			
	
			vertex(x, y, 0);color(r, g, b, a);
			vertex(x + cx, y + cy, 0);color(r, g, b, a);
		

		var temp:Float = cx;
		cx = radius;
		cy = 0;
		
		vertex(x + cx, y + cy, 0);color(r, g, b, a);
	}

	public function ellipse ( x:Float, y:Float, width:Float, height:Float, segments:Int,r:Float,g:Float,b:Float,?a:Float=1 ) 
	{
	
		var  angle:Float = 2 * 3.1415926/ segments;

		var cx:Float = x + width / 2; 
		var cy:Float = y + height / 2;
		

			for (i in 0... segments)
			{
	
				vertex(cx + (width * 0.5 * Math.cos(i * angle)), cy + (height * 0.5 * Math.sin(i * angle)), 0);
				color(r, g, b, a);

		
				vertex(cx + (width * 0.5 * Math.cos((i + 1) * angle)),cy + (height * 0.5 * Math.sin((i + 1) * angle)), 0);
				color(r, g, b, a);
			}
		
	}
	public function fillellipse ( x:Float, y:Float, width:Float, height:Float, segments:Int,r:Float,g:Float,b:Float,?a:Float=1 ) 
	{
	
		var  angle:Float = 2 * 3.1415926/ segments;

		var cx:Float = x + width / 2; 
		var cy:Float = y + height / 2;
		

			for (i in 0... segments)
			{
	
				vertex(cx + (width * 0.5 * Math.cos(i * angle)), cy + (height * 0.5 * Math.sin(i * angle)), 0);
				color(r, g, b, a);

		     	vertex(cx ,cy, 0);
				color(r, g, b, a);
				
				vertex(cx + (width * 0.5 * Math.cos((i + 1) * angle)),cy + (height * 0.5 * Math.sin((i + 1) * angle)), 0);
				color(r, g, b, a);
			}
		
	}	
public function line(x1:Float,y1:Float,x2:Float,y2:Float,r:Float,g:Float,b:Float,?a:Float=1)
{

vertex(x1, y1);
color(r, g, b, a);
vertex(x2, y2);
color(r, g, b, a);
}

public function rect(x:Float,y:Float,width:Float,height:Float,r:Float,g:Float,b:Float,?a:Float=1)
{
			vertex(x, y, 0);color(r, g, b, a);
			vertex(x + width, y, 0);color(r, g, b, a);
			vertex(x + width, y, 0);color(r, g, b, a);
			vertex(x + width, y + height, 0);color(r, g, b, a);
			vertex(x + width, y + height, 0);color(r, g, b, a);
			vertex(x, y + height, 0);color(r, g, b, a);
			vertex(x, y + height, 0);color(r, g, b, a);
			vertex(x, y, 0);color(r, g, b, a);
}

public function fillrect(x:Float,y:Float,width:Float,height:Float,r:Float,g:Float,b:Float,?a:Float=1)
{
		
			vertex(x, y, 0);color(r, g, b, a);
			vertex(x + width, y, 0);color(r, g, b, a);
			vertex(x + width, y + height, 0);color(r, g, b, a);
			vertex(x + width, y + height, 0);color(r, g, b, a);
			vertex(x, y + height, 0);color(r, g, b, a);
			vertex(x, y, 0);color(r, g, b, a);
}
override public function dispose():Void 
{
		this.vertices = new Float32Array ([]);
		this.colors = new Float32Array ([]);
    	GL.deleteBuffer(vertexBuffer);
		GL.deleteBuffer(colorBuffer);
	
	super.dispose();
}


}