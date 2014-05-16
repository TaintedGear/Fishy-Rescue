#include "Menu.h"

Menu::Menu()
{
	background = SDL_LoadBMP("Sprites/TitleScreen.bmp");
	title = NULL;
	button1Label = NULL;
	button2Label = NULL;

	for(int i = 0; i < 10; i++)
	{
		int randColour = rand() % 4;
		tempFish = NULL;
		tempFish = new SceneryFish("Sprites/Player_Spritesheet.bmp", 64, 64, 0,
					389 + (randColour * 128),
					(rand() % 640 - 64),
					(rand() % 480 - 64));

		sceneryFish.push_back(tempFish);
	}


	titleColour.r = 255;
	titleColour.g = 255;
	titleColour.b = 0;

	buttonColour1.r = 0;
	buttonColour1.g = 255;
	buttonColour1.b = 255;

	buttonColour2.r = 0;
	buttonColour2.g = 255;
	buttonColour2.b = 255;

	titleFont = TTF_OpenFont("Fonts/OUTTT.ttf", 60);
	buttonFont = TTF_OpenFont("Fonts/LILLIPUT.ttf", 30);

	titleRect.x = 175;
	titleRect.y = 50;

	button1.x = 265;
	button1.y = 150;
	button1.h = 50;
	button1.w = 50;

	button2.x = 265;
	button2.y = 250;
	button2.h = 50;
	button2.w = 50;

	mouseBox.x = 0;
	mouseBox.y = 0;
	mouseBox.h = 25;
	mouseBox.w = 25;
}

Menu::~Menu()
{
	for(int i = 0; i < sceneryFish.size(); i++)
	{
		if(sceneryFish[i] != NULL)
		{
			delete sceneryFish[i];
		}
	}

	if(tempFish != NULL)
	{
		//delete tempFish;
	}
	if(background != NULL)
	{
		SDL_FreeSurface(background);
	}
	if(titleFont != NULL)
	{
		//TTF_CloseFont(titleFont);
	}
	if(buttonFont != NULL)
	{
		//TTF_CloseFont(buttonFont);
	}
}

int Menu::Update(Timer deltaTicks, SDL_Event &event)
{
	button2.x = 265;
	button1.x = 265;

	//update the fish and the mouse;
	for(int i = 0; i < sceneryFish.size(); i++)
	{
		sceneryFish[i]->Update( deltaTicks.GetTicks() );
	}

	if(CheckMouse(button1, event))
	{
		buttonColour1.r = 0;
		buttonColour1.g = 255;
		buttonColour1.b = 0;

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				//return a state
				return 1;
			}
		}
	}
	else
	{
		buttonColour1.r = 0;
		buttonColour1.g = 255;
		buttonColour1.b = 255;
	}

	if(CheckMouse(button2, event))
	{
		buttonColour2.r = 0;
		buttonColour2.g = 255;
		buttonColour2.b = 0;

		if(event.button.button == SDL_BUTTON_LEFT)
		{
			//return a state
			return 3;
		}
	}
	else
	{
		buttonColour2.r = 0;
		buttonColour2.g = 255;
		buttonColour2.b = 255;
	}

	return 0;
}

void Menu::Draw( SDL_Surface *buffer, Camera &camera )
{
	
	SDL_BlitSurface(background, NULL, buffer, NULL);

	for(int i = 0; i < sceneryFish.size(); i++)
	{
		sceneryFish[i]->Draw( buffer, camera);
	}

	if (title = TTF_RenderText_Solid(titleFont, "FISHY RESCUE", titleColour))
	{
		SDL_BlitSurface(title, NULL, buffer, &titleRect);
		SDL_FreeSurface(title);
	}
	if(button1Label = TTF_RenderText_Solid(buttonFont, "PLAY!", buttonColour1))
	{
		SDL_BlitSurface(button1Label, NULL, buffer, &button1);
		SDL_FreeSurface(button1Label);
	}
	if(button2Label = TTF_RenderText_Solid(buttonFont, "Quit!", buttonColour2))
	{
		SDL_BlitSurface(button2Label, NULL, buffer, &button2);
		SDL_FreeSurface(button2Label);
	}
}

void Menu::DrawGameOver( SDL_Surface *buffer, int score, int deaths )
{
	button1.x = 200;
	button2.x = 200;

	SDL_BlitSurface(background, NULL, buffer, NULL);

	std::string sScore;
	std::stringstream out;
	out << score;
	sScore = ("Score:" + out.str());
	std::string sDeath;
	std::stringstream out1;
	out1 << deaths;
	sDeath = ("Deaths:" + out1.str());

	if(title = TTF_RenderText_Solid(titleFont, "GAME OVER", titleColour))
	{
		SDL_BlitSurface(title, NULL, buffer, &titleRect);
		SDL_FreeSurface(title);
	}
	if(button1Label = TTF_RenderText_Solid(buttonFont, sScore.c_str() , buttonColour1))
	{
		SDL_BlitSurface(button1Label, NULL, buffer, &button1);
		SDL_FreeSurface(button1Label);
	}
	if(button2Label = TTF_RenderText_Solid(buttonFont,  sDeath.c_str(), buttonColour1))
	{
		SDL_BlitSurface(button2Label, NULL, buffer, &button2);
		SDL_FreeSurface(button2Label);
	}
}

bool Menu::CheckMouse(SDL_Rect a, SDL_Event &event)
{
	if( event.type == SDL_MOUSEMOTION)
	{
		mouseBox.x = event.motion.x;
		mouseBox.y = event.motion.y;
	}

	if(( mouseBox.x > a.x ) && ( mouseBox.x < a.x + a.w ) && 
			( mouseBox.y > a.y ) && ( mouseBox.y < a.y + a.h ))
	{
		return true;
	}
	
	return false;
}