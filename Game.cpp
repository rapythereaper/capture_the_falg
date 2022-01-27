#define OLC_PGE_APPLICATION
#include "../olcPixelGameEngine.h"
#include "module/file.h"
#include "module/assets.h"
#include "api.h"
#include <unistd.h>
#include "play.cpp"


class Example : public olc::PixelGameEngine
{
public:
    Example()
    {
        sAppName = "Example";
    }
    ~Example(){
        for(int i=0;i<4;i++){
            delete arr[i];
        };
        free(map);
    }

    Asset *flag;
    Asset *grass;
    Asset *wall;
    Asset *player;
    Asset *arr[4];
    MAP *map;
    //void (*current)(float ,olc::PixelGameEngine*);
public:
    bool OnUserCreate() override
    {
        arr[0]=flag=new Asset("./assets/flag.png",5,5);
        arr[1]=grass=new Asset("./assets/grass.png",5,5);
        arr[2]=wall=new Asset("./assets/wall.png",5,5);
        arr[3]=player=new Asset("./assets/player.png",5,5);
        // Called once at the start, so create things here
        map=get_map(Level);
        api::map=map;
        api::x=(map->player-1)%10;
        api::y=(map->player-1)/10;
        return true;
    }
    float tempTime = 0.0f;

    void game_play(float fElapsedTime){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(map->map[i][j]-1!=-1){
                    arr[map->map[i][j]-1]->draw(this,i*115,j*115);
                }
            }
        }
        if(api::game_running){
        tempTime += fElapsedTime;
        if (tempTime >= 0.5){
            tempTime -= tempTime;
            fElapsedTime =0.5;
           play();
        }
        }

        player->draw(this,api::x*115,api::y*115);
        Asset *ptr=arr[map->map[api::x][api::y]-1];
        if(ptr!=grass && ptr!=flag){
            api::game_running=false;
            //std::cout<<"[!]ay yo crashed\n";
            api::msg="Crashed on the wall :|";
        }

    };
    void game_over(){
        this->DrawString(this->ScreenWidth()/2-500,10,api::msg,olc::WHITE,5);
    };

    bool OnUserUpdate(float fElapsedTime) override
    {
        Clear(olc::VERY_DARK_BLUE);
        if(api::game_running){
            game_play(fElapsedTime);
        }else{
            game_over();
        }
        //api::dt=fElapsedTime;

        	
        return true;
        
    }
};



int main()
{
    Example demo;
    if (demo.Construct(1150, 1150, 1, 1))
        demo.Start();

    return 0;
}