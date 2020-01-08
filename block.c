#include <acknex.h>
#include "imports.c"

#define BLOCK 85

function block_event();



function setTexture(ENTITY* ent){
	ent_setskin(ent,texDirt, 1);
	ent_setskin(ent,texGrass, 2);
	ent_setskin(ent,texStone, 3);
	ent_setskin(ent,texSand, 4);
	ent_setskin(ent,texWood, 5);
	ent_setskin(ent,texLeaves, 6);
	ent_setskin(ent,texCloud, 7);
	
	
}


action cloud_act(){
	setTexture(me);
	set(me, NOFILTER);
}


action block_act(){
	my.skill1 = 85;
	my.ambient = 50;
	setTexture(me);
	set(me, NOFILTER);
	my.event = block_event;
	my.emask = ENABLE_CLICK | ENABLE_RIGHTCLICK;
}


function grass_event(){
	my.emask = ENABLE_CLICK | ENABLE_RIGHTCLICK;
	my.event = grass_event;
}

function grass_event(){
	if(event_type == EVENT_CLICK){
		ent_remove(me);
	}
		if(event_type == EVENT_RIGHTCLICK){
		you = ent_create(modul_block, vector(my.x, my.y, my.z+64),block_act);
		your.skin = 2;
	}		
}

function block_event(){
	if(event_type == EVENT_CLICK){
		ent_remove(me);
	}
		if(event_type == EVENT_RIGHTCLICK){
		you = ent_create(modul_block, vector(my.x, my.y, my.z+64),block_act);
		your.skin = 2;
	}		
}