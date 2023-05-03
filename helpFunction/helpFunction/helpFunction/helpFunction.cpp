// helpFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>      
#include <array>
#include <cstdint>


extern "C"
{

	struct diff_type
	{
		double var;
		uint32_t x_delta;
		uint32_t x;
		uint32_t y_delta;
		uint32_t y;
	};

	void  diff_constructor(struct diff_type* c_this, uint32_t x, uint32_t y)
	{
		c_this->x = 0;
	}
	double getRes(struct diff_type* c_this, uint32_t current_x, uint32_t current_y)
	{
		double diff = 0;
		c_this->x_delta = current_x - c_this->x;
		c_this->y_delta = current_y - c_this->y;
		diff = static_cast<double>(c_this->y_delta) / c_this->x_delta;
		return diff;
	}
}



int main()
{
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

