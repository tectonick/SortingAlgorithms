#include "Tracker.h"

void Tracker::StartTimer()
{
	startTime = clock();
}

void Tracker::PauseTimer()
{
	clock_t CurrentClock = clock();
	elapsedTime += CurrentClock - startTime;
}

void Tracker::ClearTimer()
{
	startTime = 0;
	elapsedTime = 0;
}

clock_t Tracker::GetTime()
{
	return elapsedTime;
}

void Tracker::SaveCurrentState(char* data, short size)
{
	if (this->Visualizing==false)
	{
		return;
	}
	PauseTimer();

	char* NewData = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		NewData[i] = data[i];
	}
	States->push_back(NewData);
	StartTimer();
}

char* Tracker::GetState(int i)
{
	return States->at(i);
}

void Tracker::ClearStates()
{
	for (size_t i = 0; i < StatesCount(); i++)
	{
		delete[] States->at(i);
	}
	States->clear();
}

int Tracker::StatesCount()
{
	return States->size();
}

Tracker::Tracker()
{
	States = new vector<char*>;
	Visualizing = true;
	startTime = 0;
	elapsedTime = 0;
}

Tracker::~Tracker()
{
	ClearStates();
}