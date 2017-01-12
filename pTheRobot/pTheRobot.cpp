// pTheRobot.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TheRobot.h"
#include <string>
#include <vector>

using namespace std;

int main()
{	
	string err;

	cout << "Introduceti numarul de blocuri: ";
	cin >> n;
	init();

	move_onto(4, 3, err);
	move_over(2, 5, err);

    return 0;
}

