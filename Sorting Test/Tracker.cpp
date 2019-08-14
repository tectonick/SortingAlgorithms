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

void Tracker::SaveCurrentState(char* data, int size)
{
	if (this->Visualizing==false)
	{
		return;
	}
	PauseTimer();

	//Copying current array
	char* NewData = new char[size];
	for (int i = 0; i < size; i++)
	{
		NewData[i] = data[i];
	}
	AlgorithmTracker->push_back(NewData);

	StartTimer();
}

char* Tracker::GetState(int i)
{
	return AlgorithmTracker->at(i);
}

void Tracker::ClearStates()
{
	for (int i = 0; i < StatesCount(); i++)
	{
		delete[] AlgorithmTracker->at(i);
	}
	AlgorithmTracker->clear();
}

int Tracker::StatesCount()
{
	return AlgorithmTracker->size();
}

Tracker::Tracker()
{
	AlgorithmTracker = new vector<char*>;
	Visualizing = true;
	startTime = 0;
	elapsedTime = 0;
}

Tracker::~Tracker()
{
	ClearStates();
}