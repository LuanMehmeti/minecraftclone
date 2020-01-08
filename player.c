#include "imports.c"
#include "terain.c"

#define Run skill1
#define speed_down skill2
#define dist_down skill3
#define STEP skill4


#define FIRSTPERSON 1
#define THIRDPERSON 2
var generatedBlocks = 64;

var slot = 0;
var i = 0;
var k = 0;
var j = 0;

STRING* animationSequence = "walk";

var camera_perspective = THIRDPERSON;
var camera_tilt = -20;
var camera_x = -260;
var camera_y = 0;
var camera_z = 150;





action player_act(){
	camera.tilt = -20;
	my.ambient = 50;
	vec_scale(my.scale_x,2);
	c_setminmax(me);
	vec_scale(my.min_x, 0.5);
	vec_scale(my.max_x, 0.5);
	my.min_z *= 2;
	my.max_z *= 2;
	
	
	VECTOR VectorFeet;
	vec_for_min(VectorFeet, me);
	if(camera_perspective==FIRSTPERSON){
	set(my, INVISIBLE);
	camera_x = my.x;
	camera_y = my.y;
	camera_z = 100;
	}
	
	
	
	player = me;

	while(1){
		my.dist_down = c_trace(my.x, vector(my.x, my.y, my.z - 5000),IGNORE_ME | IGNORE_PASSABLE | USE_BOX);
		if(my.dist_down > 10){
			if(my.speed_down >  -9){
			my.speed_down -= 1.5 * time_step;
		}
		}
		else 
		{
			my.speed_down = 0;
			if(key_space){
				my.speed_down = 10;
			}
			
		}
		

		
		
  	
		
		
		c_move(me, vector((key_w - key_s) * 12 * time_step, (key_a - key_d) * 7 * time_step, my.speed_down), nullvector, IGNORE_PASSABLE | GLIDE);
		
		my.Run += (key_w || key_s || key_a || key_d) * 3 * time_step;
		my.STEP += (key_w || key_s || key_a || key_d) * 3 * time_step;
		
		ent_animate(me, animationSequence, my.Run, ANM_CYCLE);
		
		if(my.STEP >= 10){
			int i = random(5);
			
			ent_playsound(me, soundStep[i],100);
			my.STEP = 0;
		}
		
		my.pan = camera.pan;
		vec_set(camera.x, vector(camera_x, camera_y, camera_z));

		
		vec_rotate(camera.x, my.pan);
		vec_add(camera.x, my.x);
		
		//BORDER
		if(player.x < 0){
			player.x = 0;
			my.speed_down = 0;
		}
		if (player.y < 0){
			player.y = 0;
			my.speed_down = 0;
		}
		
		if(player.y > generatedBlocks*64-64){
			player.y = generatedBlocks*64-64;
		}
		
		if(player.x > generatedBlocks*64-64){
			player.x = generatedBlocks*64-64;
		}
		
		
		wait(1);
		
		
	}
	
	
	
}


function changePerspective(){
	if(camera_perspective == THIRDPERSON){
		camera_perspective = FIRSTPERSON;
		int test = 50;
		set(player, INVISIBLE);
		camera_x = 0;
		camera_y = 0;
		camera_z = 100;
		
	} else{
		camera_perspective = THIRDPERSON;
		reset(player,INVISIBLE);
		camera.tilt = -20;
		camera_x = -260;
		camera_y = 0;
		camera_z = 150;
		
		
	}
	
	
}
