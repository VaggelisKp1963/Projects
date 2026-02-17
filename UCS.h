#pragma once
#include <queue>
#include <list>
#include <iterator>
#include "Node.h"
using namespace std;
struct Compare
{
    bool operator()(Node* node1, Node* node2) const
    {
        return node1->getCurrentCost() > node2->getCurrentCost();
    }
};
class UCS
{

private:
    priority_queue<Node*, vector<Node*>, Compare> priority_queue;
    list<Node*> list;
    int nodesCreated;
    Node* lastnode;
public:
    UCS();
    void setLastnode(Node* lastnode);
    Node* getLastnode();
    void setNodesCreated(int nodesCreated);
    int getNodesCreated();
    bool runUCS(char maze[11][13], int width, int height);
    void findStartandGoal(char maze[11][13], int width, int height, int* start_pos, int* goal_pos);
    Node* expandNodes(char maze[11][13], Node* node, char action, int width, int height);
    bool checkList(int x, int y);
};

