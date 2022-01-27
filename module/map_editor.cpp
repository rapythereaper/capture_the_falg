#define OLC_PGE_APPLICATION
#include "../../olcPixelGameEngine.h"
#include "file.h"
void changeSceen(void*p,int n);
void *getSceen(void *p,int n);

#include "assets.h"
#include "menu.h"
#include "map.h"



class Game : public olc::PixelGameEngine
{
public:
    Game()
    {
        sAppName = "Game";
    }
    ~Game(){
        for(int i=0;i<SCEEN_LEN;i++){
            delete SCEEN[i];
        }
       };
public:
   int SCEEN_LEN=4;
    Sceen *SCEEN[4]={new Menu(),new Map(),new Map_menue(),new Map_view()};
    
    Sceen *CURRENT_SCEEN;


public:
    void changeSceen(int n) {
        std::cout<<" fuck changin g: "<<n<<"\n";
        CURRENT_SCEEN=SCEEN[n];
    };

    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        for(int i=0;i<SCEEN_LEN;i++){
            SCEEN[i]->load(this);
        }
        CURRENT_SCEEN=SCEEN[0];
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        Clear(olc::VERY_DARK_BLUE);
        // called once per frame
        CURRENT_SCEEN->draw(this);
        return true;
    }
};

void changeSceen(void*p,int n){
    std::cout<<"changin g: "<<n<<"\n";
   ( (Game*) p)->changeSceen(n);
};

void *getSceen(void *p,int n){
    return ( (Game*) p)->SCEEN[n];
}



int main()
{
    Game demo;
    if (demo.Construct(1150, 1150, 1, 1))
        demo.Start();

    return 0;
}