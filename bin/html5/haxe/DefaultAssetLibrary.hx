package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.MovieClip;
import flash.text.Font;
import flash.media.Sound;
import flash.net.URLRequest;
import flash.utils.ByteArray;
import haxe.Unserializer;
import openfl.Assets;

#if (flash || js)
import flash.display.Loader;
import flash.events.Event;
import flash.net.URLLoader;
#end

#if ios
import openfl.utils.SystemPath;
#end


class DefaultAssetLibrary extends AssetLibrary {
	
	
	public static var className (default, null) = new Map <String, Dynamic> ();
	public static var path (default, null) = new Map <String, String> ();
	public static var type (default, null) = new Map <String, AssetType> ();
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		className.set ("assets/desert.tmx", __ASSET__assets_desert_tmx);
		type.set ("assets/desert.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/hxlogo.png", __ASSET__assets_hxlogo_png);
		type.set ("assets/hxlogo.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/map.tmx", __ASSET__assets_map_tmx);
		type.set ("assets/map.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/mapxml.tmx", __ASSET__assets_mapxml_tmx);
		type.set ("assets/mapxml.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/player.png", __ASSET__assets_player_png);
		type.set ("assets/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/scrol.tmx", __ASSET__assets_scrol_tmx);
		type.set ("assets/scrol.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/sewers.tmx", __ASSET__assets_sewers_tmx);
		type.set ("assets/sewers.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/sewer_tileset.png", __ASSET__assets_sewer_tileset_png);
		type.set ("assets/sewer_tileset.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/sprites.png", __ASSET__assets_sprites_png);
		type.set ("assets/sprites.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/texture.png", __ASSET__assets_texture_png);
		type.set ("assets/texture.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/TileMap.tmx", __ASSET__assets_tilemap_tmx);
		type.set ("assets/TileMap.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		className.set ("assets/tiles.png", __ASSET__assets_tiles_png);
		type.set ("assets/tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/tmw_desert_spacing.png", __ASSET__assets_tmw_desert_spacing_png);
		type.set ("assets/tmw_desert_spacing.png", Reflect.field (AssetType, "image".toUpperCase ()));
		className.set ("assets/zazaka.png", __ASSET__assets_zazaka_png);
		type.set ("assets/zazaka.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		
		#elseif html5
		
		path.set ("assets/desert.tmx", "assets/desert.tmx");
		type.set ("assets/desert.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/hxlogo.png", "assets/hxlogo.png");
		type.set ("assets/hxlogo.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/map.tmx", "assets/map.tmx");
		type.set ("assets/map.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/mapxml.tmx", "assets/mapxml.tmx");
		type.set ("assets/mapxml.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/player.png", "assets/player.png");
		type.set ("assets/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/scrol.tmx", "assets/scrol.tmx");
		type.set ("assets/scrol.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/sewers.tmx", "assets/sewers.tmx");
		type.set ("assets/sewers.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/sewer_tileset.png", "assets/sewer_tileset.png");
		type.set ("assets/sewer_tileset.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/sprites.png", "assets/sprites.png");
		type.set ("assets/sprites.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/texture.png", "assets/texture.png");
		type.set ("assets/texture.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/TileMap.tmx", "assets/TileMap.tmx");
		type.set ("assets/TileMap.tmx", Reflect.field (AssetType, "binary".toUpperCase ()));
		path.set ("assets/tiles.png", "assets/tiles.png");
		type.set ("assets/tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/tmw_desert_spacing.png", "assets/tmw_desert_spacing.png");
		type.set ("assets/tmw_desert_spacing.png", Reflect.field (AssetType, "image".toUpperCase ()));
		path.set ("assets/zazaka.png", "assets/zazaka.png");
		type.set ("assets/zazaka.png", Reflect.field (AssetType, "image".toUpperCase ()));
		
		
		#else
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
			var bytes = ByteArray.readFile ("assets/manifest");
			#else
			var bytes = ByteArray.readFile ("manifest");
			#end
			
			if (bytes != null) {
				
				bytes.position = 0;
				
				if (bytes.length > 0) {
					
					var data = bytes.readUTFBytes (bytes.length);
					
					if (data != null && data.length > 0) {
						
						var manifest:Array<AssetData> = Unserializer.run (data);
						
						for (asset in manifest) {
							
							path.set (asset.id, asset.path);
							type.set (asset.id, asset.type);
							
						}
						
					}
					
				}
				
			} else {
				
				trace ("Warning: Could not load asset manifest");
				
			}
			
		} catch (e:Dynamic) {
			
			trace ("Warning: Could not load asset manifest");
			
		}
		
		#end
		
	}
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = DefaultAssetLibrary.type.get (id);
		
		#if pixi
		
		if (assetType == IMAGE) {
			
			return true;
			
		} else {
			
			return false;
			
		}
		
		#end
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && type == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (type == BINARY || type == null) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		#if pixi
		
		return BitmapData.fromImage (path.get (id));
		
		#elseif flash
		
		return cast (Type.createInstance (className.get (id), []), BitmapData);
		
		#elseif js
		
		return cast (ApplicationMain.loaders.get (path.get (id)).contentLoaderInfo.content, Bitmap).bitmapData;
		
		#else
		
		return BitmapData.load (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if pixi
		
		return null;
		
		#elseif flash
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);
		
		#elseif js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}

		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if pixi
		
		return null;
		
		#elseif (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		return new Font (path.get (id));
		
		#end
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		#if pixi
		
		//return null;		
		
		#elseif flash
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif flash
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		#if flash
		
		if (type != AssetType.MUSIC && type != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		#if pixi
		
		handler (getBitmapData (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBitmapData (id));
			
		}
		
		#else
		
		handler (getBitmapData (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if pixi
		
		handler (getBytes (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		handler (getBytes (id));
		
		#end
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getFont (id));
			
		//}
		
		#else
		
		handler (getFont (id));
		
		#end
		
	}
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getSound (id));
			
		//}
		
		#else
		
		handler (getSound (id));
		
		#end
		
	}
	
	
}


#if pixi
#elseif flash

class __ASSET__assets_desert_tmx extends null { }
class __ASSET__assets_hxlogo_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_map_tmx extends null { }
class __ASSET__assets_mapxml_tmx extends null { }
class __ASSET__assets_player_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_scrol_tmx extends null { }
class __ASSET__assets_sewers_tmx extends null { }
class __ASSET__assets_sewer_tileset_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_sprites_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_texture_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_tilemap_tmx extends null { }
class __ASSET__assets_tiles_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_tmw_desert_spacing_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class __ASSET__assets_zazaka_png extends flash.display.BitmapData { public function new () { super (0, 0); } }


#elseif html5

















#end