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
	cout << "Introduceti numarul de blocuri: ";
	cin >> n;
	init();
	string command, clean, err;
	vector <string> args;
	unsigned int i, j;
	do
	{
		getline(cin, command);
		clean = CleanString(command);
		j = 0;
		for (i = 0; i < 4; ++i)
		{
			string arg;
			while (j < clean.size() && clean[j] != ' ')
			{
				arg.push_back(clean[j]);
				++j;
			}
			if (clean[j] == ' ')
				++j;
			args.push_back(arg);
		}
		if (args[1] != args[3])
		{
			if (args[0] == "move")
			{
				if (args[2] == "onto") {
					move_onto(stoi(args[1]), stoi(args[3]), err);
					afisare();
				}
				else if (args[2] == "over") {
					move_over(stoi(args[1]), stoi(args[3]), err);
					afisare();
				}
			}
			else if (args[0] == "pile")
			{
				if (args[2] == "onto") {
					pile_onto(stoi(args[1]), stoi(args[3]), err);
					afisare();
				}
				else if (args[2] == "over") {
					pile_over(stoi(args[1]), stoi(args[3]), err);
					afisare();
				}
			}
		}
		while (!args.empty())
			args.pop_back();
		if (clean == "quit")
		{
			cout << "Versiunea finala a blocurilor este : " << endl;
			afisare();
		}

	} while (clean != "quit");
	return 0;
}

