namespace  api
{	
	int x=0;
	int y=0;
	MAP *map;
	bool game_running=true;
	std::string msg;
}


void move_left(){
	api::x=api::x+1;
};

void move_up(){
	api::y=api::y-1;
};

void move_down(){
	api::y=api::y+1;
};
 void move_right(){
 	api::y=api::x-1;
 }

void collect_flag(){
	if(api::map->map[api::x][api::y]==1){
		std::cout<<"[*]Flag collected\n";
		api::msg="Flag COLLECTED :)";
		api::game_running=false;
	}else{
		std::cout<<"[!]Notthing Fun :";
		api::msg="Notthing found Here :(";
		api::game_running=false;
	}
}

