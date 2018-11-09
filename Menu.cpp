#include "Menu.h"

using namespace std;

Menu::Menu()
{
}

void Menu::run()
{
	while (true) {
		bool exit = false;
		string temp;
		DrawMenu();
		getline(cin, temp);
		try {//Exceptions can be useful it turns out. 
			Parse(stoi(temp), exit);
		}
		catch (...) {
			cout << "Invalid entry";
			Sleep(1000);
		}
		if (exit == true)
			break;
		Sleep(100);
	}
}

void Menu::DrawMenu()
{
	system("cls");
	cout << "Welcome to Tree Menu" << endl;
	cout << "1. Add New Name" << endl;
	cout << "2. Delete A name" << endl;
	cout << "3. List the contents in ascending order" << endl;
	cout << "4. Display the number of nodes in the tree" << endl;
	cout << "5. Display the number of leafs" << endl;
	cout << "6. Create and display a mirror image of the tree" << endl;//Due to the way delete and add function work this will not be compatible with them.
	cout << "7. Visualize tree (May need to enlarge console screen)" << endl;//Made this originally to bug check but turned out to be a pain,
	cout << "8. Exit the System" << endl;//So I finished just because it would be a good side project.
	cout << ">";


}

void Menu::Parse(int x, bool &b)
{
	switch (x) {
	case -1:
		tTree();
		cout << "Test tree made 1-7 (Strings)";
		Sleep(500);
		break;
	case 1:
		addName();
		Sleep(500);
		break;
	case 2:
		deleteName();
		Sleep(500);
		break;
	case 3:
		list();
		break;
	case 4:
		system("cls");
		cout << tree.nNodes() << endl;
		system("pause");
		break;
	case 5:
		system("cls");
		cout << tree.lNodes() << endl;
		system("pause");
		break;
	case 6:
		tree.tMirror();
		cout << "Mirrored" << endl;
		list();
		break;
	case 7:
		system("cls");
		tree.display();
		cout << endl;
		system("pause");
		break;
	case 8:
		cout << "GoodBye!";
		Sleep(500);
		b = true;
		break;
	default:
		cout << "Invalid entry";
		Sleep(1000);
		break;
	}
}

void Menu::addName()
{
	system("cls");
	string temp;
	cout << "Enter the name you would like to add: ";
	getline(cin, temp);
	if (tree.search(temp)) {
		cout << "Already added";
		return;
	}
	tree.insert(temp);
	cout << "Added";
	Sleep(500);
}

void Menu::deleteName()//I added a bool to find and delete to let me know if it was successful.
{
	system("cls");
	string temp;
	cout << "Enter the name you would like to delete: ";
	getline(cin, temp);
	if(tree.findAndDeleteByCopying(temp))
		cout << "Deleted";
	Sleep(500);
}

void Menu::tTree()
{
	for (int x = 1; x < 8; x++)
		tree.insert(to_string(x));
}

void Menu::list()
{
	system("cls");
	tree.inorder();
	cout << endl;
	system("pause");
}


Menu::~Menu()
{
}
