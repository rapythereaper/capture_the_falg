# Capture  The Flag

A simple maze navigating game that is played by writing c code.


The project is build using [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine). Make sure you have it install before proceding.
## Map Editor
![map editor](https://raw.githubusercontent.com/rapythereaper/capture_the_falg/main/assets/map_editor.gif)

#### Build
```bash
./map_editor.sh #builds map editor form source code
./map_editor # run map editor
```
Map editor gives a gui interface for creating and saving map for the game. Menu are navigated with "w" "s" "ENTER" keys. "A" and " S" are used to switch between blocks in map editor. Use left click to place the block and right click to remove the block and "ctrl+s" is used for saving the map.
## Game
Game is played by writing the play.cpp file, The boiler plate code looks something like :
```c
#define Level 0
void play(){
 //code goes here
}
```
Level denotes the level you are playing the game for. Think of it like selecting a level . The movement of player is controlled with in the play function. User have 5 function to controll the Player movement.
```c
void move_left(); //moves player along left
void move_rigt(); //moves player along lright
void move_up();   // move player upward
void move_down();   // move player along downward
void collect_flag(); //collect the flag 
 ```
The game is simple where wrriten  code inside play() function governs the game play. The objectice of the game is to capture the flag by moving on the grass are. If the player moves outside the grass or executes collect_flag in wrong position, this would result in play loosing the game.
### Running The Game:
Once the user writes the code use the folloing command to execte the gameplay.
```bash
./play.sh
```
## Example
play.cpp

```c
#define Level 0
int i=0;
void play(){
  move_left();
  i++;
  if(i==7){
   collect_flag();
  }
}

 ```
![game_play](https://raw.githubusercontent.com/rapythereaper/capture_the_falg/main/assets/game_play.gif)



## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
