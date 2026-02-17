#pragma once

class Node
{
private:
	int robot_pos[2];
	int currentDepth;
	int currentCost;
	int heuristicCost;
	char actionPerformed;
	int depth;
	Node* parentNode;
public:
	Node();
	Node(int robot_posx, int robot_posy, int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth, int heuristicCost);
	Node(int robot_posx, int robot_posy, int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth);
	Node(int robot_pos[2], int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth);
	bool checkIfGoal(int goalcoord_x, int goalcoord_y);
	int* getRobot_pos();
	void setRobot_pos(int x, int y);
	int getCurrentDepth();
	void setCurrentDepth(int currentDepth);
	int getCurrentCost();
	void setCurrentCost(int currentCost);
	char getActionPerformed();
	void setActionPerformed(char actionPerformed);
	Node* getParentNode();
	void setParentNode(Node* parentNode);
	int getDepth();
	void setDepth(int depth);
	int getHeuristicCost();
	void setHeuristicCost(int heuristicCost);
	void calculateHeuristic(int goal_posx, int goal_posy);


};


