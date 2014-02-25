package com.engine.render;

import com.engine.game.Game;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLFramebuffer;
import openfl.gl.GLRenderbuffer;
import openfl.gl.GLProgram;
import openfl.gl.GLTexture;
import openfl.utils.Int16Array;

/**
 * ...
 * @author djoker
 */
class RenderTexture extends Texture
{
   private var framebuffer:GLFramebuffer;
     //  private var renderbuffer:GLRenderbuffer;
   

	public function new(width:Int,height:Int) 
	{
		super();
		
		this.width = width;
		this.height = height;

		this.texWidth = width;
		this.texHeight = height;
		
		invTexWidth  = 1.0 / texWidth;
        invTexHeight = 1.0 / texHeight;

	    framebuffer = GL.createFramebuffer();
		GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
             
        data = GL.createTexture();
		GL.bindTexture(GL.TEXTURE_2D, data);
		GL.texImage2D(GL.TEXTURE_2D, 0, GL.RGB, width, height, 0, GL.RGBA, GL.UNSIGNED_INT, null);
				
				  
              
                
	    GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
		GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
		GL.texParameteri(GL.TEXTURE_2D,GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
	
		GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
        GL.framebufferTexture2D(GL.FRAMEBUFFER, GL.COLOR_ATTACHMENT0, GL.TEXTURE_2D, data, 0);
   

		
	}
	public function begin()
	{
		GL.colorMask(true, true, true, true); 
		GL.viewport(0, 0,  width, height);
	    GL.bindFramebuffer(GL.FRAMEBUFFER, framebuffer);
	    GL.clearColor(0, 0, 0, 1);
	 //   GL.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
	    GL.clear(GL.COLOR_BUFFER_BIT);
 	}
	public function end()
	{
	 GL.bindFramebuffer(GL.FRAMEBUFFER, null);
	}
	

	
}