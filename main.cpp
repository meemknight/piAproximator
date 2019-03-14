#include <iostream>
#include <random>
#include <math.h>
#include <chrono>
#include <iomanip>

#define SAMPLES 10000000000
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

	long circlePointCounter = 0;
	long notCirclePointCounter = 0;

	real10 x;
	real10 y;

	auto startingTime = std::chrono::high_resolution_clock::now();

	for(int i=0; i< SAMPLES; i++)
	{
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
	
	std::cout << "points inside the circle: " << circlePointCounter << "\n";
	std::cout << "points outside the circle: " << notCirclePointCounter << "\n";
	std::cout << "evaluated pi: " << std::setprecision(14) << pi << "\n";
	std::cout << "real      pi: " << "3.14159265358979\n";

	std::cout << std::endl;
	auto deltaTime = endingTime - startingTime;
	std::cout << "time(nanoseconds): " << deltaTime.count() << std::endl;
	std::cout << "time(miliseconds): " << std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count() << std::endl;

	std::cin.get();
}