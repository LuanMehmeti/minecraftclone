#include <acknex.h>


PANEL* menuBackground={
	bmap = backgroundMenu;
	layer = 1;
}


PANEL* textPan={
	digits(880,25,"Start game","Arial#40",0,0);
	digits(880,425,"Quit game","Arial#40",0,0);
	flags = SHOW;
	pos_y = 210;
	layer = 2;
}


PANEL* menuPan=
{
	
	button(720, 200,pressedButton,texButton,overButton,startGame,NULL,NULL);
	button(720, 600,pressedButton,texButton,overButton,quitGame,NULL,NULL);
	flags = SHOW;
	layer = 1;
}

function setPanel(){
	menuPan.flags = SHOW;
	
}