class Menu:public Sceen{
	Asset *btn1;
	Asset *btn2;
	Asset* btns;
public:
	~Menu(){delete btn1;delete btn2;}
	void load(olc::PixelGameEngine* game){
		btn1=new Asset("./assets/btn1.png",5,5);
		btn2=new Asset("./assets/btn2.png",5,5);
		btns=btn1;
	};
	
	void draw(olc::PixelGameEngine* game){
		float x=game->ScreenWidth()/2-5;
		float y= game->ScreenHeight()/2-5;
		if (game->GetKey(olc::Key::W).bPressed)btns=btn1;
		if (game->GetKey(olc::Key::S).bPressed)btns=btn2;
		if (game->GetKey(olc::Key::ENTER).bPressed){
			if(btns==btn1)changeSceen(game,1);
			else changeSceen(game,2);
		}
		if(btns==btn1)btn1->draw(game,10,10);
		else btn1->draw(game,10,10,olc::Pixel(255,255,0,64));
		if(btns==btn2)btn2->draw(game,10,100);
		else btn2->draw(game,10,100,olc::Pixel(255,255,0,64));
	};
};