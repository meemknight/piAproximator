#include <iostream>
#include <random>
#include <math.h>
#include <chrono>
#include <iomanip>

#define SAMPLES 1000000000
#define RANDMAX 1000000
using real10 = long double;

using namespace std::chrono_literals;

int main() 
{
	std::mt19937 random(std::_Random_device());
	std::uniform_int<int> distribution(0, RANDMAX);
	auto getNumber = [&random, &distribution]() mutable
	{
		real10 number;
		int r = distribution(random);
		number = (real10)r / RANDMAX;
		return number;
	};

	unsigned long long circlePointCounter = 0;
	unsigned long long notCirclePointCounter = 0;

	real10 x;
	real10 y;

	auto startingTime = std::chrono::high_resolution_clock::now();

	int percentageCounter = 0;
	for(long long unsigned int i=0; i< SAMPLES; i++)
	{
		if(percentageCounter >= 1'000'000)
		{
			std::cout << (float)i / SAMPLES << "\n";
			percentageCounter = 0;
		}else
		{
			percentageCounter++;
		}


		x = getNumber();
		y = getNumber();

		if( std::sqrt(x*x + y*y) > 1)
		{
			notCirclePointCounter++;
		}else
		{
			circlePointCounter++;
		}

	}

	real10 pi;
	pi = (circlePointCounter * 4.f) / (circlePointCounter + notCirclePointCounter);

	auto endingTime = std::chrono::high_resolution_clock::now();
	
	std::cout << "\n\npoints inside the circle: " << circlePointCounter << "\n";
	std::cout << "points outside the circle: " << notCirclePointCounter << "\n";
	std::cout << "evaluated pi: " << std::setprecision(14) << pi << "\n";
	std::cout << "real      pi: " << "3.14159265358979\n";

	std::cout << std::endl;
	auto deltaTime = endingTime - startingTime;
	std::cout << "time(nanoseconds): " << deltaTime.count() << std::endl;
	std::cout << "time(miliseconds): " << std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count() << std::endl;
	std::cout << "time(seconds    ): " << std::chrono::duration_cast<std::chrono::seconds>(deltaTime).count() << std::endl;

	std::cin.get();
}