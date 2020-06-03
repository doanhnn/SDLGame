#include "CommonFunction.h"
#include "game_map.h"
#include "MainObject.h"

#undef main

BaseObject g_background;

bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);    // Khoi tao du lieu va load thu vien SDL
	if (ret < 0)
		return false;
	
	// Thiet lap ti le ve chat luong
	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("SDL_Game",
								SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, 
								SCREEN_WIDTH, SCREEN_HEIGHT, 
								SDL_WINDOW_SHOWN);
	if (g_window == NULL)
	{
		success = false;
	}
	else
	{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);   // render using hardware
		if (g_screen == NULL)
		{
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
				success = false;			
		}
	}

	return success;
}

bool LoadBackground()
{
	return g_background.LoadImg("img\\background.png", g_screen);
}

void close()
{
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main(int arc, char* argv[])
{
	if (!InitData())
		return -1;

	if (!LoadBackground())
		return -1;

	GameMap game_map;
	game_map.LoadMap((char*)"map/map01.dat");
	game_map.LoadTiles(g_screen);

	MainObject p_player;
	p_player.LoadImg("img//player_right.png", g_screen);
	p_player.setClips();

	bool is_quit = false;
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}
			p_player.HandleInputAction(g_event, g_screen);
		}

		g_background.Render(g_screen, NULL);
		Map map_data = game_map.getMap();

		p_player.SetMapXY(map_data.start_x_, map_data.start_y_);
		p_player.DoPlayer(map_data);
		p_player.Show(g_screen);

		game_map.setMap(map_data);
		game_map.DrawMap(g_screen);

		SDL_RenderPresent(g_screen); // Update screen again
	}

	close();
	return 0;
}