package com.djoker.glteste;

import com.engine.game.Entity;
import com.engine.game.Screen;
import com.engine.render.BlendMode;
import com.engine.render.filter.BlurFilter;
import com.engine.render.filter.BlurYFilter;
import com.engine.render.filter.BlurXFilter;
import com.engine.render.filter.ColorMatrixFilter;
import com.engine.render.filter.CrossHatchFilter;
import com.engine.render.filter.DotScreenFilter;
import com.engine.render.filter.InvertFilter;
import com.engine.render.filter.NormalFilter;
import com.engine.render.filter.GrayFilter;
import com.engine.render.filter.ColorStepFilter;
import com.engine.render.filter.PixelateFilter;
import com.engine.render.filter.RenderFilter;
import com.engine.render.filter.RGBSplitFilter;
import com.engine.render.filter.SepiaFilter;
import com.engine.render.filter.TwistFilter;
import com.engine.render.SpriteBatch;
import com.engine.render.BatchPrimitives;
import com.engine.render.Texture;
import com.engine.input.Keys;

import flash.text.TextField;
import flash.text.TextFormat;


/**
 * ...
 * @author djoker
 */
class TesteTexRender extends Screen
{


 var batch:SpriteBatch;


  var primitives:BatchPrimitives;
 var child:Entity;
 
 var player:Entity;
 var logo:Entity;
var back:Entity; 
 
 var filterIndex:Int = 0;
 var redy:Bool = false;
 
 var fblurX:BlurXFilter;
 var fblurY:BlurYFilter;
 var finvert:InvertFilter;
 var fNormal:NormalFilter;
 var fgary:GrayFilter;
 var fColorStep:ColorStepFilter;
 
 var filter:RenderFilter;
 
 var value:Float=0;
 
 
 var caption:TextField;

   var skew:Float = 0;
 
	
	override public function show()
	{
	 
	
         batch = new SpriteBatch(1000);
 
	
		  caption = new TextField();
		 caption.x =  game.gameWidth / 2-100;
		 caption.y = 20;
		 caption.width = 200;
		 caption.defaultTextFormat = new TextFormat ("_sans", 12, 0xffff00);
		 caption.text = "Render Filter";
		 caption.selectable = false;
		 game.addChild(caption);
		 
		var label = new TextField();
		 label.x = 5;
		 label.y = game.gameHeight-25;
		 label.width = 400;
		 label.defaultTextFormat = new TextFormat ("_sans", 22, 0xffff00);
		 label.text = "Left/Right keys switch filters";
		 label.selectable = false;
		 game.addChild(label);
		 	 
		 
	
		
		 player = new  Entity(300, 300,  getTexture("assets/zazaka.png",true));
		 child = new  Entity(0, 0,  getTexture("assets/zazaka.png",true));
		 child.blue = 0;
		 player.add(child);
		 
		 logo= new Entity(100+this.width/2,this.height/2,getTexture("assets/hxlogo.png",true));
		 
		 back = new Entity(512/2, 512/2, getTexture("assets/texture.jpg", true));
		// back.scaleX = 0.5;
		// back.scaleY = 0.5;

		 //texRender = new NormalFilter(game.screenWidth, game.screenHeight);
		 //texRender = new BlurXFilter(game.screenWidth, game.screenHeight);
		 primitives = new  BatchPrimitives( 500);
	
		 filterIndex = 0;
		 setFilter(filterIndex);
		
		 game.clarColor(0, 0, 0);


	}
    override public function update(dt:Float) 
	{ 

		
	
		  player.rotation += game.deltaTime * 2.1;
		  child.rotation -= game.deltaTime * 2.5;
		  player.skewX += game.deltaTime * 0.1;
		  
		skew +=game.deltaTime * 1;
 
		logo.skewX = Math.sin(skew)*1;
		logo.skewY = Math.cos(skew)*1;
	
		
	}
	
	public function setFilter(index:Int)
	{
		switch (index)
		{
		case 0:
			{

				
				caption.text = "Render Normal Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  NormalFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  NormalFilter(game.screenWidth, game.screenHeight);
				}
				
			}
		case 1:
			{
				value = 4.5;
				caption.text = "Render Color Step  Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  ColorStepFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  ColorStepFilter(game.screenWidth, game.screenHeight);
				}
				
			}
			case 2:
				{
				caption.text = "Render Gray Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  GrayFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  GrayFilter(game.screenWidth, game.screenHeight);
				}
					
				}
				case 3:
					{
					value = 0.8;
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  InvertFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  InvertFilter(game.screenWidth, game.screenHeight);
				}
			 }
				case 4:
					{
				   caption.text = "Render Blur X Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  BlurXFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  BlurXFilter(game.screenWidth, game.screenHeight);
				}
			 }	
			 case 5:
					{
		        caption.text = "Render Blur Y Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new  BlurYFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  BlurYFilter(game.screenWidth, game.screenHeight);
				}
			 }	
			 
			 	 case 6:
				{
						
					value = 0.5;
		        caption.text = "Render Twist Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new TwistFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  TwistFilter(game.screenWidth, game.screenHeight);
				}
			 }
			  case 7:
				{
						
					
		        caption.text = "Render Sepia Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new SepiaFilter(game.screenWidth, game.screenHeight);
				 
				
				} else
				{
				 filter =new  SepiaFilter(game.screenWidth, game.screenHeight);
				}
			 }
			 		  case 8:
				{
						
					
		        caption.text = "Render Blur Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new BlurFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  BlurFilter(game.screenWidth, game.screenHeight);
				}
			 }
			 	 case 9:
				{
						
					
		        caption.text = "Render Pixelate Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new PixelateFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  PixelateFilter(game.screenWidth, game.screenHeight);
				}
			 }
			 	 	 case 10:
				{
				value = 0;		
		        caption.text = "Render Dot Screen Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new DotScreenFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  DotScreenFilter(game.screenWidth, game.screenHeight);
				}
			 }
			  	case 11:
				{
				value = 0;		
		        caption.text = "Render  Split RGB Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new RGBSplitFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  RGBSplitFilter(game.screenWidth, game.screenHeight);
				}
			 }
			 	case 12:
				{
				value = 0;		
		        caption.text = "Render  Cross hatch Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new CrossHatchFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  CrossHatchFilter(game.screenWidth, game.screenHeight);
				}
			 }
			 	 	case 13:
				{
				value = 0;		
		        caption.text = "Render  Color Matrix Transformation Filter";
				if (filter != null)
				{
				 filter.dispose();
				 filter = null;
				 filter = new ColorMatrixFilter(game.screenWidth, game.screenHeight);
				
				} else
				{
				 filter =new  ColorMatrixFilter(game.screenWidth, game.screenHeight);
				}
			 }
		}
					redy = true;
	}
	public function renderToFilter(index:Int)
	{
		if (!redy) return;
		
		
		switch (index)
		{

			       case 1:
					{
			 
				   value += (game.deltaTime*0.1);
				   if (value > 10) value = 0.5;
				   var dataFilter:ColorStepFilter = cast(filter, ColorStepFilter);
			  	   dataFilter.setStep(value);
	
						
					}
					
				case 3:
					{
			 
				   value += (game.deltaTime*0.1);
				   if (value > 1) value = 0.0;
				   var dataFilter:InvertFilter = cast(filter, InvertFilter);
			  	   dataFilter.setInvert(value);
	
						
					}
		

					case 6:
					{
			 
				   value += (game.deltaTime*1.1);
				   if (value > 5) value = -1;
				   var dataFilter:TwistFilter = cast(filter, TwistFilter);
			  	   dataFilter.setRadius(value);
	
						
					}
		
			
				case 13:
					{
					 value += (game.deltaTime*1.1);
				   if (value > 100) value = 0;
				
				   
			 	   var dataFilter:ColorMatrixFilter = cast(filter, ColorMatrixFilter);
			  	   dataFilter.setTransformation(Math.sin(value),Math.cos(value),value,1);
	
						
					}
		
		}
		
			if (filter != null)
				{
				 filter.begin();
				 normalRender();
				 filter.end();
				 filter.render();
				} 
				
				
	}
	override public function keyUp(key:Int) 
	{
		redy = false;
		if (key == Keys.RIGHT)
		{
		 filterIndex++;	
		} else
		if (key == Keys.LEFT)
		{
		 filterIndex--;	
		}
		if (filterIndex <= 0) filterIndex = 0;
		if (filterIndex >= 13) filterIndex = 13;
		 value = 1;
		 setFilter(filterIndex);
		
	}
	public function normalRender()
	{
	
	  batch.Begin();
	  batch.drawEntity(back);
  	  batch.drawEntity(logo);
	  batch.drawEntity(player,true);
	  batch.End();
	  
	  primitives.begin();
	

	primitives.line(10, 10, 100, 100, 1, 0, 1);
	primitives.rect(100, 100, 90, 120, 1, 1, 1);
	primitives.circle(100, 100, 12, 8, 1, 1, 1, 1);
	primitives.ellipse(300, 90, 55, 15, 8, 1, 1, 1, 1);

	primitives.fillrect(200, 200, 50, 50, 1, 0, 0, 1);
	primitives.fillrect(280, 200, 50, 50, 0, 1, 1, 1);
	primitives.fillcircle(200, 100, 8, 18, 1, 0, 1, 1);
	primitives.fillellipse(300, 100, 55, 15, 8, 0, 1, 1, 1);

	
	primitives.end();
	}
	
	override public function render() 
	{ 
     renderToFilter(filterIndex);
    }

		
		

override public function mouseDown(mousex:Float, mousey:Float) 
{
	
}

	
	
}