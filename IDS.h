#pragma once
#include "Node.h"
#include <stack>
#include <list>
#include <iterator>
using namespace std;
class IDS
{
private:
	int nodesCreated;
	Node* lastnode;
	stack<Node*> stack;
	list<Node*> list;
public:
	IDS();
	void setLastnode(Node* lastnode);
	Node* getLastnode();
	void setNodesCreated(int nodesCreated);
	int getNodesCreated();
	bool runIDS(char maze[11][13], int width, int height);
	void findStartandGoal(char maze[11][13], int width, int height, int* start_pos, int* goal_pos);
	Node* expandNodes(char maze[11][13], Node* node, char action, int width, int height);
	bool checkList(int x, int y);
};

