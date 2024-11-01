// punnymathtest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "punnymath.h"

// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier


int main()
{
    pum::vector2d a(10,10);
    pum::vector2d b = a;
    std::cout << b.x << " " << b.y << std::endl;
    pum::vector2d sum;
    sum = a + b;
    std::cout << sum.x << " " << sum.y << std::endl;
    sum = a - b;
    std::cout << sum.x << " " << sum.y << std::endl;
    sum = a * 2;
    std::cout << sum.x << " " << sum.y << std::endl;
    sum = a / 2;
    std::cout << sum.x << " " << sum.y << std::endl;

    bool test = pum::nearlyequal(a,b,10000);

    std::cout << "result of nearlyequal " << test << std::endl;
    int _;
    std::cin >> _;

}