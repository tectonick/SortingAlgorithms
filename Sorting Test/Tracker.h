#pragma once
#include <ctime>
#include <vector>

using std::vector;
using std::clock_t;

class Tracker
{
private:
	clock_t startTime;
	clock_t elapsedTime;
	vector<char*>* AlgorithmTracker;
public:
	bool Visualizing;
	void StartTimer();
	void PauseTimer();
	void ClearTimer();
	clock_t GetTime();

	void SaveCurrentState(char* data, int size);
	char* GetState(int i);
	void ClearStates();
	int StatesCount();

	Tracker();
	~Tracker();
};
