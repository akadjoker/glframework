package com.engine.render;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLProgram;

/**
 * ...
 * @author djoker
 */
class BlendMode
{

public static var NORMAL:Int      = 0;
public static var ADD:Int         = 1;
public static var MULTIPLY:Int    = 2;
public static var SCREEN:Int      = 3;

static 	public function setBlend(mode:Int ) 
	{
	 switch( mode ) {
    case 0:
       GL.blendFunc(GL.SRC_ALPHA,GL.ONE_MINUS_SRC_ALPHA );
	  
    case 1:
        GL.blendFunc(GL.SRC_ALPHA, GL.DST_ALPHA );
    case 2:
        GL.blendFunc(GL.DST_COLOR,GL.ONE_MINUS_SRC_ALPHA );
    case 3:
       GL.blendFunc(GL.SRC_ALPHA,GL.ONE );		
    default:
        GL.blendFunc(GL.ONE,GL.ONE_MINUS_SRC_ALPHA );
    }
}
	
	
	
	
		
	
}