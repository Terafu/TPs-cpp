// complex.cpp : classe permettant de gérer les complexes plus agréablement qu'avec la bilbiothèque standard.
//

#include "stdafx.h"
#include "complex.hpp"
#include <iostream>
#include <vector>


int main()
{
	float r = 2;
	float i = 1;

	float a = 1.1;
	float b = 1.7;

	Complex<float> test (r, i);
	Complex<float> test2(a, b);

	std::cout << test << "\n";
	//test2 /= test;
	std::cout << test2 << "\n";
	std::cout << exp(test2) << "\n";
	std::cout << cos(test2) << "\n";

	std::vector<Complex<float>> vect;
	vect.push_back(test);
	vect.push_back(test2);

	std::cout << dft(vect)[0] << "\n";
	std::cout << dft(vect)[1] << "\n";
	std::cout << inverse_dft(dft(vect))[0] << "\n";
	std::cout << inverse_dft(dft(vect))[1] << "\n";


    return 0;
}

