#pragma once
#include <iostream>
#include "genBST.h"
#include <string>
#include <Windows.h>

using namespace std;
class Menu
{
public:
	Menu();
	void run();
	~Menu();
protected:
	void DrawMenu();
	void Parse(int x, bool & b);
	BST<string> tree;
	void addName();
	void deleteName();
	void tTree();
	void list();
};	