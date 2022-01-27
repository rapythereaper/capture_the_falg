class Asset{
protected:
	olc::vf2d size; 
	olc::Decal *dec=NULL;
	olc::Sprite *Texture;
public:	
	Asset(){}
	Asset(std::string path){
		Texture=new olc::Sprite(path);
	}
	Asset(std::string path,float x,float y){
		Texture=new olc::Sprite(path);
		dec=new olc::Decal(Texture);
		size= {x,y};

	}
	~Asset(){
		if(dec)delete dec;
		delete Texture;
	}
	void setxy(float x,float y){
		size=olc::vf2d(x,y);
	}
	void draw(olc::PixelGameEngine* game,int x,int y){
		if(dec==NULL){
			game->DrawSprite(olc::vi2d(x, y), this->Texture);
		}else{
			game->DrawDecal(olc::vi2d(x, y),this->dec,size);
		}
	};
	void draw(olc::PixelGameEngine* game,int x,int y,olc::Pixel p){
		game->DrawDecal(olc::vi2d(x, y),this->dec,size,p);
	};
};

class Sceen{
public:	
	virtual void load(olc::PixelGameEngine* game){
		return;
	}
	virtual void draw(olc::PixelGameEngine*game ){
		return;
	};
};


