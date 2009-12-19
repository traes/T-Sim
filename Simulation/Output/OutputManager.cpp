#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "OutputManager.h"

#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 600 

OutputManager::OutputManager(){
	start_opengl();
	camera = Camera();
	external_view = ExternalView();
	cockpit_view = CockpitView();
	instruments_view = InstrumentsView();
	current_view = USE_COCKPIT_3D_VIEW;
}

void OutputManager::use_external_3d_view(){
	current_view = USE_EXTERNAL_3D_VIEW;
}	

void OutputManager::use_cockpit_3d_view(){
	current_view = USE_COCKPIT_3D_VIEW;
}	

void OutputManager::use_cockpit_2d_view(){
	current_view = USE_COCKPIT_2D_VIEW;
}	

void OutputManager::update(World* world){
	glLoadIdentity();
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (current_view){
		case USE_COCKPIT_3D_VIEW :
			cockpit_view.show(world,&camera);
			break;
		case USE_COCKPIT_2D_VIEW :
			instruments_view.show(world,&camera);
			break;
		case USE_EXTERNAL_3D_VIEW :	
			external_view.show(world,&camera);
			break;
	};
	glFlush();
	SDL_GL_SwapBuffers();
}

void OutputManager::start_opengl(){
	const char *app_name = "T-sim";
	SDL_Surface *screen = NULL;
	unsigned int flags = 0;
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		std::cout << SDL_GetError() << std::endl;
		exit(1);
	}

	atexit(SDL_Quit);

	flags |= SDL_OPENGL;
	flags |= SDL_HWSURFACE;
	flags |= SDL_ANYFORMAT;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,flags);
	if (screen == NULL){
		std::cout << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	SDL_WM_SetCaption(app_name,NULL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,1.333,0.1,5000.0);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);

	// fog
	/*
	GLfloat fog[4]={1.0,1.0,1.0,1.0};        
	glFogfv(GL_FOG_COLOR,fog);            
	glFogf(GL_FOG_DENSITY,0.001);                
	glFogi(GL_FOG_MODE,GL_EXP);       
	glHint(GL_FOG_HINT, GL_FASTEST); 
	glEnable(GL_FOG); 
	*/
}

