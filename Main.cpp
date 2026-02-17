#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "UCS.h"
#include "IDS.h"
#include "AStar.h"
using namespace std;

const int WIDTH = 13;
const int HEIGHT = 11;
void printPath(Node* lastnode);
void printMaze(char maze[][WIDTH], int curx, int cury);
int main() {

	char answer;
	char maze[HEIGHT][WIDTH] = { {'S','\0','X','\0','\0','\0','\0','X','X','\0','X','\0','X'},
								 {'\0','\0','\0','D','X','\0','\0','\0','\0','\0','D','\0','X'},
								 {'X','\0','X','\0','\0','\0','\0','X','X','\0','X','\0','X'},
								 {'\0','\0','D','X','\0','D','X','\0','\0','D','\0','\0','\0',},
								 {'X','X','\0','\0','X','\0','\0','\0','X','X','X','X','\0',},
								 {'\0','D','\0','X','\0','X','\0','\0','X','X','\0','\0','\0',},
								 {'X','\0','D','X','\0','X','X','D','\0','\0','D','X','D'},
								 {'\0','X','\0','\0','D','\0','\0','\0','X','\0','\0','\0','\0',},
								 {'\0','\0','D','\0','\0','X','X','\0','X','X','X','X','\0'},
								 {'X','X','\0','\0','\0','\0','X','\0','\0','\0','\0','\0','D'},
								 {'X','X','\0','X','X','\0','\0','D','X','X','X','\0','G'} };



	printMaze(maze, 0, 0);
	cout << "Witch algorthm you want to run? " << endl;
	cout << "Press (U/u) if you want UCS!" << endl;
	cout << "Press (I/i) if you want IDS!" << endl;
	cout << "Press (A/a) if you want A*!" << endl;
	cout << "Press '*' to run all the available algorithms!" << endl;
	cin >> answer;
	while (answer != 'U' && answer != 'u' && answer != 'I' && answer != 'i' && answer != 'A' && answer != 'a' && answer != '*')
	{
		cout << "Wrong input! Please try again." << endl;
		cout << "Witch algorthm you want to run? " << endl;
		cout << "Press (U/u) if you want UCS!" << endl;
		cout << "Press (I/i) if you want IDS!" << endl;
		cout << "Press (A/a) if you want A*!" << endl;
		cout << "Press '*' to run all the available algorithms!" << endl;
		cin >> answer;
	}

	switch (answer)
	{
	case'U':
	case'u':
	{
		UCS Ucs;
		bool result = Ucs.runUCS(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << Ucs.getNodesCreated() << endl;
			printPath(Ucs.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << Ucs.getNodesCreated() << endl;
		}
		break;
	}
	case'I':
	case'i':
	{
		IDS Ids;
		bool result = Ids.runIDS(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << Ids.getNodesCreated() << endl;
			printPath(Ids.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << Ids.getNodesCreated() << endl;
		}
		break;
	}
	case'A':
	case'a':
	{
		AStar astar;
		bool result = astar.runAStar(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << astar.getNodesCreated() << endl;
			printPath(astar.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << astar.getNodesCreated() << endl;
		}
		break;
	}
	case '*':
	{
		cout << "------------Running UCS Algorithm------------\n";
		UCS Ucs;
		bool result = Ucs.runUCS(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << Ucs.getNodesCreated() << endl;
			printPath(Ucs.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << Ucs.getNodesCreated() << endl;
		}
		cout << endl;
		cout << "------------Running IDS Algorithm------------\n";
		cout << endl;
		IDS Ids;
		result = Ids.runIDS(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << Ids.getNodesCreated() << endl;
			printPath(Ids.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << Ids.getNodesCreated() << endl;
		}
		cout << endl;
		cout << "------------Running A* Algorithm------------\n";
		cout << endl;
		AStar astar;
		result = astar.runAStar(maze, WIDTH, HEIGHT);
		if (result) {
			cout << "Path Found!" << endl;
			cout << "Nodes Created: " << astar.getNodesCreated() << endl;
			printPath(astar.getLastnode());
		}
		else {
			cout << "Path Not Found!" << endl;
			cout << "Nodes Created: " << astar.getNodesCreated() << endl;
		}
		break;
	}
	default: {
		cout << "Wrong input! Exiting..." << endl;
		break;
	}

	}
	return 0;
}



void printMaze(char maze[][WIDTH], int curx, int cury)
{
	const int WIDTH = 13;
	const int HEIGHT = 11;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (maze[y][x] == '\0')
				cout << "^";
			else
				cout << maze[y][x];
		}
		cout << endl;
	}
}


void printPath(Node* lastnode)
{
	char* reversed_path;
	int index = 0;
	int size = 1;
	reversed_path = (char*)malloc(sizeof(char) * size);
	cout << lastnode->getRobot_pos()[0] << "," << lastnode->getRobot_pos()[1] << endl;
	while (lastnode->getParentNode() != nullptr)
	{
		reversed_path[index] = lastnode->getActionPerformed();
		lastnode = lastnode->getParentNode();
		size++;
		reversed_path = (char*)realloc(reversed_path, size * sizeof(int));
		index++;
	}
	int counter = 1;
	for (int i = size - 2; i >= 0; i--)
	{
		cout << "Step " << counter << ": " << reversed_path[i] << endl;
		counter++;
	}
	free(reversed_path);

}