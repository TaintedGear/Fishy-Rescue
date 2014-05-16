#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

using std::vector;

#include "System.h"
#include "Camera.h"
#include "Timer.h"
#include "BasicSprite.h"
#include "Fish.h"
#include "SchoolFish.h"
#include "GobblerFish.h"
#include "SceneryFish.h"
#include "Net.h"
#include "School.h"
#include "Coral.h"
#include "Level.h"
#include "Menu.h"
#include "Hud.h"

int main(int argc, char* args[])
{

	enum {MENU, RUNNING, GAMEOVER, END};
	int state = MENU;

	int score = 0;
	int deaths = 0;

	//Holds all game objects vectors
	vector<Net *> nets;
	vector<Coral *> corals;
	vector<School *> schools;
	vector<SceneryFish *> sceneryFish;
	vector<GobblerFish *> gobblerFish;

	//back buffer || bit messy can clean up
	System system("Fishy Game", false, 640, 480, 32, 60);
	if (!system.Setup())
	{
		MessageBox(NULL, "SDL DID NOT INITIALISE PROPERLY", NULL, MB_OK);
		return -1;
	}
	SDL_Surface* buffer = system.GetBuffer();

	Timer timer;
	Timer delta;
	Camera camera(640, 480);

	Level level;
	Menu menu;
	Hud hud;
	
	School* school;
	Net* net = NULL;
	Coral* coral = NULL;

	Mix_Music *music = NULL;
	Fish fish("Sprites/Player_Spritesheet.bmp", 64, 64, 0, 0, 200, 200);
	level.LoadLevel(fish, corals, nets, sceneryFish, gobblerFish);
	music = Mix_LoadMUS( "Sounds/DST-Aethereal.wav" );

	delta.Start();

	while(!system.Done())
	{
		srand(time(NULL));

		if(Mix_PlayingMusic () == 0)
		{
			Mix_PlayMusic(music, -1);
		}

		switch(state)
		{
		case MENU:

			state = (menu.Update( delta, system.GetEvent()));
			menu.Draw(buffer, camera);

			break;
		case RUNNING:


		hud.Update(score, deaths );

		//update
		fish.Update( delta.GetTicks() );

		for( int c = 0; c < corals.size(); c++)
		{
			corals[c]->Update(delta.GetTicks());
		}

		for( int i = 0; i < schools.size(); i++)
		{
			schools[i]->Update( delta.GetTicks(), fish, corals);
			for(int j = 0; j < 3; j++)
			{
				if(schools[i]->GetFish(j)->GetEaten()
					&& (!schools[i]->GetFish(j)->GetScored())) 
				{ 
						deaths += 1;
						schools[i]->GetFish(j)->SetScored(true);
				}
				if(schools[i]->GetFish(j)->GetSaved()
					&& (!schools[i]->GetFish(j)->GetScored()))
				{ 
					score += 10; 
					schools[i]->GetFish(j)->SetScored(true);
				}
			}
		}

		for( int g = 0; g < gobblerFish.size(); g++)
		{
			gobblerFish[g]->Update(delta.GetTicks(), schools);
		}

		for( int i = 0; i < nets.size(); i++)
		{
			nets[i]->Update(delta.GetTicks(), fish);

			if(nets[i]->GetReleased())
			{
				school = NULL;
				school = new School("Sprites/Player_SpriteSheet.bmp", 
					nets[i]->GetOffsetX(), nets[i]->GetOffsetY());
				schools.push_back(school);
			}

		}

		for( int f = 0; f < sceneryFish.size(); f++)
		{
			sceneryFish[f]->Update(delta.GetTicks(), fish);
		}

		camera.Update(fish.GetPosX(), fish.GetPosY(), fish.GetWidth(), fish.GetHeight());

		//Draw background first
		level.DrawBackdrop( buffer, camera );

		for( int f = 0; f < sceneryFish.size(); f++)
		{
			sceneryFish[f]->Draw( buffer, camera);
		}

		for(int s = 0; s < schools.size(); s++)
		{
			schools[s]->Draw( buffer, camera );
		}

		level.DrawBackground( buffer, camera );

		for(int i = 0; i < nets.size(); i++)
		{
			nets[i]->Draw( buffer, camera );
		}

		fish.Draw( buffer, camera );

		for(int g = 0; g < gobblerFish.size(); g++)
		{
			gobblerFish[g]->Draw( buffer, camera );
		}

		for(int c = 0; c < corals.size(); c++)
		{
			corals[c]->Draw( buffer, camera );
		}

		level.DrawForeground( buffer, camera );

		hud.Draw( buffer );

		if(hud.GetTime() <= 0)
		{
			state = GAMEOVER;
		}

			break;
		case GAMEOVER:

			if(!timer.GetStarted())
			{
				timer.Start();
			}

			menu.DrawGameOver( buffer, hud.GetScore(), hud.GetDeaths());

			if(timer.GetTicks() >= 5000)
			{
				state = MENU;

				for(int i = 0; i < schools.size(); i++)
				{
					delete schools[i];
				}


				schools.clear();
				score = 0;
				deaths = 0;
				hud.Reset();
				level.ResetLevel(fish, corals, nets, sceneryFish, gobblerFish);
				timer.Stop();
			}

			break;
		case END:
			Mix_FreeMusic(music);
			delete net;
			delete coral;
			system.CleanUp(buffer);
			return 0;
			break;
		}

		delta.Start();

		SDL_Flip( buffer );
		SDL_FillRect(buffer, NULL, SDL_MapRGB(buffer->format, 0, 0, 0));
	}

	if(net != NULL)
	{
		delete net;
	}
	if(coral != NULL)
	{
		delete coral;
	}
	system.CleanUp(buffer);

	return 0;
}

