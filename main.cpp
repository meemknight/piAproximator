#include <iostream>
#include <random>

#define SAMPLES 100
using real10 = long double;


int main() 
{
	std::mt19937 random(std::_Random_device());

	long circlePointCounter = 0;
	long NotCirclePointCounter = 0;

	real10 x;
	real10 y;

	for(int i=0; i< SAMPLES; i++)
	{
		x = 1 / (random() + 1);
		y = 1 / (random() + 1);

	}



	std::cin.get();
}