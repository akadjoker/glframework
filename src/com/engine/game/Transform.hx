package com.engine.game;

import flash.geom.Matrix;
import com.engine.misc.MatrixHelp;
/**
 * ...
 * @author djoker
 */
class Transform
{
    public var mTransformationMatrix:Matrix;
	public var parent:Transform;


	    public var rotation:Float = 0;
		public var scaleX:Float = 1;
		public var scaleY:Float = 1;
		public var skewX:Float = 0;
		public var skewY:Float = 0;
		public var pivotX:Float = 0;
		public var pivotY:Float = 0;
		public var x:Float = 0;
		public var y:Float = 0;
		public var scrollFactorX:Float = 0;
		public var scrollFactorY:Float = 0;
		
		


	public function new() 
	{
		parent = null;
		mTransformationMatrix = new Matrix();
	}
	
	
		
	public function getTransformationMatrix():Matrix
	{
	
		   mTransformationMatrix.identity();
	
				
			var cx:Float =  Game.scrollX;
			var cy:Float =  Game.scrollY;
			var sx:Float = x - cx * scrollFactorX;
			var sy:Float = y - cy * scrollFactorY;
			
         
                if (scaleX != 1.0 || scaleY != 1.0) mTransformationMatrix.scale(scaleX, scaleY);
                if (skewX  != 0.0 || skewY  != 0.0) MatrixHelp.skew(mTransformationMatrix, skewX, skewY);
                if (rotation != 0.0)                 mTransformationMatrix.rotate(rotation);
                if (sx != 0.0 || sy != 0.0)          mTransformationMatrix.translate(sx, sy);
                
                if (pivotX != 0.0 || pivotY != 0.0)
                {
                    mTransformationMatrix.tx = sx - mTransformationMatrix.a * pivotX
                                                  - mTransformationMatrix.c * pivotY;
                    mTransformationMatrix.ty = sy - mTransformationMatrix.b * pivotX 
                                                  - mTransformationMatrix.d * pivotY;
                }
            return mTransformationMatrix;
		
	}
	public function getLocalToWorldMatrix():Matrix
    {
            if (parent == null)
            {
            return  getTransformationMatrix();
            }
           	else
            {
			return  getTransformationMatrix().mult(parent.getTransformationMatrix());
            }
            
       
    }
	public function dispose()
	{
		this.mTransformationMatrix = null;
		
	}
}