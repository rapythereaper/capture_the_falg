#define Level 0

int i=0;

void  play(){
	move_left();
	i++;
	if(i==6){
		collect_flag();
	}
};
