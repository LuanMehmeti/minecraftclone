#include <acknex.h>
#include <default.c>w
#include "terain.c"
#include "block.c"w
#include "player.c"
#include "imports.c"
#include "menu.c"

int acreen_width = 1920;
int screen_height = 1080;
var slot = 0;


function camMovement();

function init();
function showInv();
function switchSlot();


function main(){
	max_entities = 99999;
	d3d_antialias = 9;
	wait(1);
	video_set(1920, screen_height,0,2);
	
	mouse_mode = 4;
	
	setPanel();
	
	
}


function startGame(){
	init();
	createLevel();
	camMovement();
	mouse_mode = 1;
	mouse_map = crosshair;
	on_p = changePerspective;
	showInv();
	
	reset(menuPan,SHOW);
	reset(textPan, SHOW);
	
}





function quitGame(){
	sys_exit(NULL);
}


PANEL* invslot1 =
{	
bmap = slot1;
layer = 1;
}


function showInv(){
	invslot1.pos_x = 777;
	invslot1.pos_y = 1000;
	invslot1.flags = SHOW;
}



function camMovement(){
	

	var force = 8;
	while(1){
		if (mouse_mode == 1){
			mouse_pos.x = screen_size.x / 2;
			mouse_pos.y = screen_size.y / 2;
			camera.pan -= mouse_force.x * time_step * force;
			if (camera_perspective == 1){
				camera.tilt += mouse_force.y * time_step * force;
				camera.tilt += mouse_force.y * time_step * force;
			}			
			
				
			mouse_pos.x = screen_size.x/2;
			mouse_pos.y = screen_size.y/2;
			if(camera.pan > 360){
				camera.pan = 0;
			}
			if(camera.pan < 0){
				camera.pan = 360;
			}
		}
		wait(1);
}
}


function init(){
	soundStep[0] = snd_create("sounds/step1.ogg");
	soundStep[1] = snd_create("sounds/step2.ogg");
	soundStep[2] = snd_create("sounds/step3.ogg");
	soundStep[3] = snd_create("sounds/step4.ogg");
	soundStep[4] = snd_create("sounds/step5.ogg");
	soundStep[5] = snd_create("sounds/step6.ogg");
	
}