#include "handler.h"

handler::handler(int setSize, bool setDataVisibility, int inTrials)
{
	size = setSize;
	showData = setDataVisibility;
	trials = inTrials;
	srand(time(NULL));
}

bool handler::checkSort(int* data)
{
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 1; i < size; i++)
	{
		if (data[i] < data[i - 1]) return false;
	}

	return true;
}


void handler::randTrial()
{
	int* data = new int[size];
	int* sortedData = new int[size];

	if (showData) printf("\n\nInput: \n");
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 10000 + 1;
		//if (showData) printf("[%d] ", data[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();

	evalTree trial(data, size);

	for (int i = 2; i < size; i++)
	{
		sortedData[i]=trial.takeRoot(data[i]);
	}

	std::chrono::duration<double, std::milli> timeElapsed = std::chrono::high_resolution_clock::now() - start;

	if (checkSort(sortedData))
	{
		if (showData)
		{
			printf("PASS\n");
			printf("Time: %f\n", timeElapsed.count());
		}
		timeData.push_back(timeElapsed.count());
	}
	else
	{
		printf("FAIL\n");
	}

	delete[] sortedData;
	delete[] data;
}

void handler::randExperiment()
{
	for (int i = 0; i < trials; i++)
	{
		randTrial();
	}
	avgTime = (double)std::accumulate(timeData.begin(), timeData.end(), 0.0) / trials;

	printf("Trials: %d - Size: %d \n", trials, size);
	printf("avgTime: %f\n", avgTime);
}