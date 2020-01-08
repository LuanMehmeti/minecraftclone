#include <acknex.h>
#include "block.c"
#include "imports.c"
#include "player.c"

function createTree();
function createGrass();
function createCloud();

var generatedBlocks = 64;


ENTITY* sky_day =
{
	type = "textures/sky_day.png";
	layer = 104;
	scale_x = 0.25;
	tilt = -25;
	flags2 = SKY | SCENE | VISIBLE;
	flags = TRANSLUCENT;
	alpha = 100;
}

	
function level_attributes(){
	sun_light = 100;	
	sky_color.blue = 255;
	sky_color.green = 255;
	sky_color.red = 255;
	d3d_antialias = 9;
	d3d_fogcolor1.red = 214;
	d3d_fogcolor1.green = 255;
	d3d_fogcolor1.blue = 255;
	fog_color = 1;
	camera.fog_start = 5000;
	camera.fog_end = 8000;
	
}



function createBlock(VECTOR* vec_pos, int texNumb){
	you =	ent_create(modul_block, vec_pos, block_act);
	your.skin = texNumb;
}

function createGrass(i,j){
	you =	ent_create(str_grass, vector(i*64, j*64, 128), grass_event);
}


function createTerrain(){
	int i;
	int j;
	int k;
	createCloud();
	for(i=0; i<generatedBlocks; i++){
		for(j=0; j<generatedBlocks; j++){
			for(k=0; k>-2; k--){
			if(k==0){
			
			createBlock(vector(i*64, j*64, k*64),2);
			
			} else{
				createBlock(vector(i*64, j*64, k*64),1);
			}
			
			int generator1 = random(30)+1;
			int generator2 = random(100)+1;
			
			if(generator1 == 30){
				createGrass(i,j);
			vec_scale(your.scale_x, 4);
			your.pan = random(360);
			set(you,PASSABLE | NOFILTER);
			your.ambient = 50;
				
			}
			
			if(generator2 == 100){
				
				//Wood
				createBlock(vector(i*64, j*64, 64),5);
				createBlock(vector(i*64, j*64, 128),5);
				createBlock(vector(i*64, j*64, 192),5);
				createBlock(vector(i*64, j*64, 256),5);
				
				//Leaves
				
				createBlock(vector((i*64)-64, j*64, 320),6);
				createBlock(vector(i*64, j*64, 320),6);
				createBlock(vector((i*64)+64, j*64, 320),6);
				createBlock(vector((i*64)-64, (j*64)-64, 320),6);
				createBlock(vector(i*64, (j*64)-64, 320),6);
				createBlock(vector((i*64)+64, (j*64)-64, 320),6);
				createBlock(vector(i*64, (j*64)+64, 320),6);
				createBlock(vector(i*64, (j*64)+64, 320),6);
				createBlock(vector(i*64, (j*64)+64, 320),6);
				
				createBlock(vector((i*64)-64, j*64, 384),6);
				createBlock(vector(i*64, j*64, 384),6);
				createBlock(vector((i*64)+64, j*64, 384),6);
				createBlock(vector((i*64)-64, (j*64)-64, 384),6);
				createBlock(vector(i*64, (j*64)-64, 384),6);
				createBlock(vector((i*64)+64, (j*64)-64, 384),6);
				createBlock(vector(i*64, (j*64)+64, 384),6);
				createBlock(vector(i*64, (j*64)+64, 384),6);
				createBlock(vector(i*64, (j*64)+64, 384),6);
				
				createBlock(vector(i*64, j*64, 448),6);

			}
		}
		}
			
		}
	}
	
	


function createCloud(){
	you =	ent_create(modul_cloud,vector(64, 64, 6000), block_act);
	you =	ent_create(modul_cloud,vector(8192, 64, 6000), block_act);
	you =	ent_create(modul_cloud,vector(64, 8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(8192, 8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(16384, 8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(8192, 1024, 6000), block_act);
	you =	ent_create(modul_cloud,vector(8192, 16384, 6000), block_act);
	you =	ent_create(modul_cloud,vector(8192, 32768, 6000), block_act);
	you =	ent_create(modul_cloud,vector(32768, 8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(-32768, 8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(32768, -8192, 6000), block_act);
	you =	ent_create(modul_cloud,vector(-32768, -8192, 6000), block_act);
	
	
	
	
	
	your.skin = 7;
	
}



function createLevel(){
	level_load(NULL);
	level_attributes();
	createTerrain();
	//Random-Spawn Point
	ent_create(playerFile, vector((random(16) +1) * 64,(random(128) + 125) * 64,1000), player_act);
}
