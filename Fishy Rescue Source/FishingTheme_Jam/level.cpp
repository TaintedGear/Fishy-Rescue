#include "Level.h"

Level::Level()
{
	coralAmount = 0;
	netAmount = 0;
	gobblerAmount = 0;
	sceneryFishAmount = 0;

	state = LEVEL1;
}

Level::~Level()
{
	SDL_FreeSurface(foreground);
	SDL_FreeSurface(background);
	SDL_FreeSurface(backdrop);
	delete coral;
	delete net;
	delete scenFish;
	delete gobFish;
}

void Level::LoadLevel(Fish &fish, vector<Coral *> &corals, vector<Net *> &nets,
	vector<SceneryFish *> &sceneryFish, vector<GobblerFish *> &gobblerFish)
{

	srand(time(NULL));

	switch(state)
	{
	case LEVEL1:
		dropFilename = "Sprites/Backdrop.bmp";
		foreFilename = "Sprites/Foreground.bmp";
		backFilename = "Sprites/Background.bmp";

		coralAmount = 5;
		netAmount = 5;
		sceneryFishAmount = 20;
		gobblerAmount = 5;

		//set the fish start position
		fish.SetPosX(1000);
		fish.SetPosY(500);

		//set all the coral positions
		if(coralAmount != 0)
		{
			for(int i = 0; i < coralAmount; i++)
			{
				coral = NULL;
				coral = new Coral("Sprites/Player_SpriteSheet.bmp", 64, 64, 0, /*256*/ 324,
					(rand() % 2000 - 64),
					(rand() % 136 + 800));

				corals.push_back(coral);
			}
		}

		//set all the net positions
		if(netAmount != 0)
		{
			for (int i = 0; i < netAmount; i++)
			{
				net = NULL;
				net = new Net("Sprites/Player_SpriteSheet.bmp", 64,64, 0, /*192*/ 260,
					(rand() % 2000 - 64),
					(rand() % 500 + 64));

				nets.push_back(net);
			}
		}

		if(sceneryFishAmount != 0)
		{
			for (int i = 0; i < sceneryFishAmount; i++)
			{
				int randColour = rand() % 4;
				scenFish = NULL;
				scenFish = new SceneryFish("Sprites/Player_Spritesheet.bmp", 64, 64, 0,
					389 + (randColour * 128),
					(rand() % 2000 - 64),
					(rand() % 650 - 64));

				sceneryFish.push_back(scenFish);
			}
		}

		if(gobblerAmount != 0)
		{
			for(int i = 0; i < gobblerAmount; i++)
			{
				gobFish = NULL;
				gobFish = new GobblerFish("Sprites/Player_Spritesheet.bmp", 64, 64, 0, /*905*/ 909,
					(rand() % 2000 - 64),
					(rand() % 650 - 64));

				gobblerFish.push_back(gobFish);
			}
		}

		break;
	case LEVEL2:
		break;
	case LEVEL3:
		break;
	};

	SDL_Surface* temp = SDL_LoadBMP(backFilename.c_str());
	background = SDL_DisplayFormat(temp);

	SDL_Surface* fTemp = SDL_LoadBMP(foreFilename.c_str());
	foreground = SDL_DisplayFormat(fTemp);

	SDL_Surface* dTemp = SDL_LoadBMP(dropFilename.c_str());
	backdrop = SDL_DisplayFormat(dTemp);

	SDL_FreeSurface(dTemp);
	SDL_FreeSurface(fTemp);
	SDL_FreeSurface(temp);
}

void Level::ResetLevel(Fish &_fish, vector<Coral *> &corals, vector<Net *> &nets,
		vector<SceneryFish *> &sceneryFish, vector<GobblerFish *> &gobblerFish)
{
		_fish.SetPosX(1000);
		_fish.SetPosY(500);

		for(int i = 0; i < corals.size(); i++)
		{
			corals[i]->SetPosX(rand() % 2000 - 64);
			corals[i]->SetPosY(rand() % 136 + 800);
			corals[i]->SetState(0);
		}
		for(int i = 0; i < nets.size(); i++)
		{
			nets[i]->SetPosX(rand() % 2000 - 64);
			nets[i]->SetPosY(rand() % 500 + 64);
			nets[i]->SetState(0);
		}
		for(int i = 0; i < sceneryFish.size(); i++)
		{
			sceneryFish[i]->SetPosX(rand() % 2000 - 64);
			sceneryFish[i]->SetPosY(rand() % 650 - 64);
			sceneryFish[i]->SetState(0);
		}
		for(int i = 0; i < gobblerFish.size(); i++)
		{
			gobblerFish[i]->SetPosX(rand() % 2000 - 64);
			gobblerFish[i]->SetPosY(rand() % 650 - 64);
			gobblerFish[i]->SetState(0);
		}
}

void Level::DrawForeground(SDL_Surface* buffer, Camera &camera)
{
	Uint32 colourKey = SDL_MapRGB(foreground->format, 0xFF, 0, 0xFF);
	SDL_SetColorKey(foreground, SDL_SRCCOLORKEY | SDL_RLEACCEL, colourKey);

	SDL_BlitSurface(foreground, &camera.GetCamera(), buffer, NULL);
}


void Level::DrawBackdrop(SDL_Surface* buffer, Camera &camera)
{
	Uint32 colourKey = SDL_MapRGB(backdrop->format, 0xFF, 0, 0xFF);
	SDL_SetColorKey(backdrop, SDL_SRCCOLORKEY | SDL_RLEACCEL, colourKey);

	SDL_BlitSurface(backdrop, &camera.GetCamera(), buffer, NULL);
}

void Level::DrawBackground(SDL_Surface* buffer, Camera &camera)
{
	Uint32 colourKey = SDL_MapRGB(background->format, 0xFF, 0, 0xFF);
	SDL_SetColorKey(background, SDL_SRCCOLORKEY | SDL_RLEACCEL, colourKey);

	SDL_BlitSurface(background, &camera.GetCamera(), buffer, NULL);
}