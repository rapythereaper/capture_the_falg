#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int player;
	int map[10][10];
} MAP;


void write_map(MAP *m){
	int total=1;
	FILE *f= fopen("map.bin","r+b");
	if(!f){
		f=fopen("map.bin","wb");
		fwrite(&total,sizeof(int),1,f);
		fwrite(m,sizeof(MAP),1,f);
		fclose(f);
	}else{
		
		fread(&total,sizeof(int),1,f);
		total++;
		fseek(f,0,SEEK_SET);
		fwrite(&total,sizeof(int),1,f);
		fclose(f);
		f=fopen("map.bin","ab");
		fwrite(m,sizeof(MAP),1,f);
		fclose(f);

	}

}

int get_total_map(){
	int total=0;
	FILE *f= fopen("map.bin","rb");
	if(!f)return 0;
	fread(&total,sizeof(int),1,f);
	return total;


}

MAP* get_map(int id){
	MAP *map= (MAP*)malloc(sizeof(MAP));
	FILE *f=fopen("map.bin","r+b");
	if(!f)return NULL;
	fseek(f,sizeof(int)+sizeof(MAP)*id,SEEK_SET);
	fread(map,sizeof(MAP),1,f);
	return map;
}