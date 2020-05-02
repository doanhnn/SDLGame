#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<string>
#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
//#include<SDL_mixer.h>
//#include<SDL_ttf.h>
#include "BaseObject.h"

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32; //pixel

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff;

// Tile map

#define TILE_SIZE 64

#define MAX_MAP_X_ 400
#define MAX_MAP_Y_ 10

typedef struct Map
{
	int start_x_;
	int start_y_;	

	int max_x_;
	int max_y_;

	int tile[MAX_MAP_X_][MAX_MAP_Y_];	
	char* file_name_;
};


#endif // !COMMON_FUNCTION_H_


