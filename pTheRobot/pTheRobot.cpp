// pTheRobot.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TheRobot.h"
#include <string>
#include <vector>

using namespace std;

string CleanString(string command)
{
	string clean;
	string::iterator it;
	for (it = command.begin(); it != command.end(); ++it)
		if (*it >= 'A' && *it <= 'Z')
			*it = *it + ' ';
	for (it = command.begin(); it != command.end(); ++it)
	{
		if ((*it == ' ' && clean.end() != clean.begin() && *(clean.end() - 1) != ' ') || (*it >= 'a' && *it <= 'z') || (*it >= '0' && *it <= '9'))
			clean.push_back(*it);
	}
	return clean;
}

int main()
{	
	string err;

	cout << "Introduceti numarul de blocuri: ";
	cin >> n;
	init();

	move_onto(4, 3, err);
	move_over(2, 5, err);
	pile_onto(3, 4, err);
	pile_over(1, 2, err);

    return 0;
}

