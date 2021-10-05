#pragma once

#include "evalTree.h"

#include <time.h>
#include <chrono>
#include <numeric>
#include <vector>

class handler
{
	private:
		double avgTime;
		std::vector<double> timeData;

		int size;
		bool showData;
		int trials;

	public:
		void randTrial();
	
		void randExperiment();

		handler(int setSize, bool setDataVisibility, int trials);

		bool checkSort(int * data);
};

