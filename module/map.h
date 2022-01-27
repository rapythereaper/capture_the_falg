class Map:public Sceen{
	Asset *flag;
	Asset *grass;
	Asset *wall;
	Asset *player;
	//Asset *arr[3];
	int current=0;
	MAP map;
	//bool flag;
public:
	Asset *arr[4];
	~Map(){delete flag;delete grass;delete wall;delete player;}
	void load(olc::PixelGameEngine* game){
		arr[0]=flag=new Asset("./assets/flag.png",5,5);
		arr[1]=grass=new Asset("./assets/grass.png",5,5);
		arr[2]=wall=new Asset("./assets/wall.png",5,5);
		arr[3]=player=new Asset("./assets/player.png",5,5);


	}
	void draw(olc::PixelGameEngine* game){
		if (game->GetKey(olc::Key::A).bPressed){
			current--;
			if(current<0)current=3;
		}
		if (game->GetKey(olc::Key::D).bPressed){
			current++;
			if(current==4)current=0;

		}
		if(game->GetKey(olc::Key::CTRL).bHeld && game->GetKey(olc::Key::S).bPressed){
			if(map.player!=0 ){
				std::cout<<"[*]Saving....\n";
				write_map(&map);
				std::cout<<"[+]Saved as id:"<<get_total_map()<<"\n";
			}else{
				std::cout<<"[!]Plseae inret player and flag\n";
			}
		}

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(map.map[i][j]-1!=-1){
					arr[map.map[i][j]-1]->draw(game,i*115,j*115);
				}
			}
		}
		if(map.player!=0){
			int x=(map.player-1)%10;
			int y=(map.player-1)/10;
			player->draw(game,x*115,y*115);
		}

		int x=game->GetMouseX();
		int y=game->GetMouseY();
		if(game->GetMouse(0).bHeld){
			if(arr[current]==player){
				if(arr[map.map[x/115][y/115]-1]==grass)
				map.player=(x/115+(y/115)*10)+1;
				
				//std::cout<<map.player<<"\n";
			}else 
				map.map[x/115][y/115]=current+1;
		};
		if(game->GetMouse(1).bHeld){
			map.map[x/115][y/115]=0;
		}


		arr[current]->draw(game,x,y);
		
	}	
};

class Map_view:public Sceen{
	MAP *map=NULL;
	Asset *arr[4];
public:
	~Map_view(){if(map)free(map);}

	void setMap(MAP*m){
		if(map)free(map);
		map=m;
	}
	void load(olc::PixelGameEngine* game){
		Map *m=(Map*)getSceen(game,1);
		memcpy(arr,m->arr,4*sizeof(Asset*));
	}
	void draw(olc::PixelGameEngine* game){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(map->map[i][j]-1!=-1){
					arr[map->map[i][j]-1]->draw(game,i*115,j*115);
				}
			}
		}
		if(map->player!=0){
			int x=(map->player-1)%10;
			int y=(map->player-1)/10;
			arr[3]->draw(game,x*115,y*115);
		}
	}


};

class Map_menue:public Sceen{
	int total;
	int current=0;
public:
	void load(olc::PixelGameEngine* game){
		total=get_total_map();
		std::cout<<total<<"\n";
	};
	void draw(olc::PixelGameEngine* game){
		if (game->GetKey(olc::Key::W).bPressed && total!=0){
			current--;
			if(current<0)current=total-1;
		}
		if (game->GetKey(olc::Key::S).bPressed && total!=0){
			current++;
			if(current==total)current=0;
		};
		if (game->GetKey(olc::Key::ENTER).bPressed && total!=0){
			Map_view* m=(Map_view*)getSceen(game,3);
			m->setMap(get_map(current));
			changeSceen(game,3);
		}
		std::string s="Map :: "+std::to_string(current);
		if(total==0)
			game->DrawString(game->ScreenWidth()/2-500,10,"No Map found!",olc::WHITE,5);
		else
		game->DrawString(game->ScreenWidth()/2-500,10,"Map :: "+std::to_string(current),olc::WHITE,10);
	}

};