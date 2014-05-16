#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <sstream>

#include "SceneryFish.h"
#include "SDL_ttf.h"

using std::vector;
using std::string;

class Menu
{
public:
	Menu();
	~Menu();

	int Update(Timer deltaTicks,  SDL_Event &event);
	void Draw( SDL_Surface *buffer, Camera &camera );
	void DrawGameOver( SDL_Surface *buffer, int score, int deaths );
	bool CheckMouse(SDL_Rect a, SDL_Event &event);

private:

	 SDL_Color titleColour;
	 SDL_Color buttonColour1;
	 SDL_Color buttonColour2;


	SDL_Surface* background;
	SDL_Surface *title;
	SDL_Surface *button1Label;
	SDL_Surface *button2Label;

	TTF_Font *titleFont;
	TTF_Font *buttonFont;

	SDL_Rect titleRect;
	SDL_Rect button1;
	SDL_Rect button2;
	SDL_Rect mouseBox;

	SceneryFish* tempFish;
	vector<SceneryFish* > sceneryFish;

	enum states{MENU, INGAME, GAMEOVER};
};

#endif