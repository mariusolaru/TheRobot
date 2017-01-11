#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

#define N 25

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

struct stive {
	int val[N];
	int length;
};

struct position {
	int x;
	int y;
};

stive stiva[N];
double n;
position poz[N];


void pop(int k) {
	int i = 0;
	while (stiva[k].val[i] != -1) {
		i++;
	}
	stiva[k].val[i - 1] = -1;
	stiva[k].length--;
}


void push(int k, int p) {
	int i = 0;
	while (stiva[k].val[i] != -1) {
		i++;
	}
	stiva[k].val[i] = p;
	poz[p].y = k;
	poz[p].x = i;
	stiva[k].length++;
}


void push_stiva(int pos, stive c) {
	int k = 0;
	while (stiva[pos].val[k] != -1) { k++; }
	for (int i = c.length - 1; i >= 0; i--) {
		stiva[pos].val[k] = c.val[i];

		poz[c.val[i]].x = k;
		poz[c.val[i]].y = pos;

		k++;

	}
	stiva[k].length = k;
}


void spread(stive c) {
	for (int i = 0; i < c.length; i++) {
		push(c.val[i], c.val[i]);
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		stiva[i].val[0] = i;
		stiva[i].length = 1;
		poz[i].y = i;
		poz[i].x = 0;
		for (int j = 1; j < n; j++) {
			stiva[i].val[j] = -1;
		}
	}
}

void afisare()
{
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<stiva[i].length; j++) {
			cout << stiva[i].val[j] << " ";
		}
		cout << endl;
	}
}