#pragma once
#include <queue>
#include "Node.h"
using namespace std;
struct Compare2
{
    bool operator()(Node* node1, Node* node2) const
    {
        return (node1->getCurrentCost() + node1->getHeuristicCost()) > (node2->getCurrentCost() + node2->getHeuristicCost());
    }
};
class AStar
{

private:
    priority_queue<Node*, vector<Node*>, Compare2> priority_queue;
    int nodesCreated;
    Node* lastnode;
public:
    AStar();
    void setNodesCreated(int nodesCreated);
    int getNodesCreated();
    void setLastnode(Node* lastnode);
    Node* getLastnode();
    bool runAStar(char maze[11][13], int width, int height);
    void findStartandGoal(char maze[11][13], int width, int height, int* start_pos, int* goal_pos);
    Node* expandNodes(char maze[11][13], Node* node, char action, int width, int height);
};