#include "School.h"

School::School(std::string filename, int netPosX, int netPosY)
{

	//possible mem leak here
	for (int i = 0; i < 3; i++)
	{
		SchoolFish *fish = NULL;
		fish = new SchoolFish(filename, 64, 64, 0, 129, netPosX + i * 10, netPosY);

		school.push_back(fish);
	}

}

School::~School()
{
	for (int i = 0; i < 3; i++)
	{
		delete school[i];
	}
}

void School::Update(float deltaTicks, Fish &fish, vector<Coral *> corals)
{
	for(int i = 0; i < 3; i++)
	{

		school[i]->Update(deltaTicks, fish, corals);

	}
}

void School::Draw( SDL_Surface* buffer, Camera &camera )
{
	for(int i = 0; i < 3; i++)
	{
		school[i]->Draw( buffer, camera);
	}
}

SchoolFish* School::GetFish(int i)
{
	if(school.size() >= i)
	{
		return school[i];
	}
}