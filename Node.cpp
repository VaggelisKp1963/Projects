#include "Node.h"

Node::Node() {
	robot_pos[0] = 0;
	robot_pos[1] = 0;
	currentCost = 0;
	currentDepth = 0;
	depth = 0;
	actionPerformed = '\0';
	parentNode = nullptr;
	this->heuristicCost = 0;
}

Node::Node(int robot_posx, int robot_posy, int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth, int heuristicCost)
{
	this->robot_pos[0] = robot_posx;
	this->robot_pos[1] = robot_posy;
	this->currentCost = currentCost;
	this->currentDepth = currentDepth;
	this->actionPerformed = actionPerformed;
	this->parentNode = parentNode;
	this->depth = depth;
	this->heuristicCost = heuristicCost;
}

Node::Node(int robot_pos[2], int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth) {
	this->robot_pos[0] = robot_pos[0];
	this->robot_pos[1] = robot_pos[1];
	this->currentCost = currentCost;
	this->currentDepth = currentDepth;
	this->actionPerformed = actionPerformed;
	this->parentNode = parentNode;
	this->depth = depth;
	this->heuristicCost = 0;
}

Node::Node(int robot_posx, int robot_posy, int currentDepth, int currentCost, char actionPerformed, Node* parentNode, int depth) {
	this->robot_pos[0] = robot_posx;
	this->robot_pos[1] = robot_posy;
	this->currentCost = currentCost;
	this->currentDepth = currentDepth;
	this->actionPerformed = actionPerformed;
	this->parentNode = parentNode;
	this->depth = depth;
	this->heuristicCost = 0;
}

int* Node::getRobot_pos() {
	return this->robot_pos;
}
void Node::setRobot_pos(int x, int y) {
	this->robot_pos[0] = x;
	this->robot_pos[1] = y;
}
int Node::getCurrentDepth() {
	return this->currentDepth;
}
void Node::setCurrentDepth(int currentDepth) {
	this->currentDepth = currentDepth;
}
int Node::getCurrentCost() {
	return this->currentCost;
}
void Node::setCurrentCost(int currentCost) {
	this->currentCost = currentCost;
}
char Node::getActionPerformed() {
	return this->actionPerformed;
}
void Node::setActionPerformed(char actionPerformed) {
	this->actionPerformed = actionPerformed;
}
Node* Node::getParentNode() {
	return this->parentNode;
}
void Node::setParentNode(Node* parentNode) {
	this->parentNode = parentNode;
}
int Node::getDepth() {
	return this->depth;
}
void Node::setDepth(int depth) {
	this->depth = depth;
}

int Node::getHeuristicCost() {
	return this->heuristicCost;
}
void Node::setHeuristicCost(int heuristicCost) {
	this->heuristicCost = heuristicCost;
}

void Node::calculateHeuristic(int goal_posx, int goal_posy) {
	this->heuristicCost = (goal_posx - this->robot_pos[0]) + (goal_posy - this->robot_pos[1]);
}


bool Node::checkIfGoal(int goalcoord_x, int goalcoord_y) {
	if (this->robot_pos[0] == goalcoord_x && this->robot_pos[1] == goalcoord_y)
		return true;
	else return false;
}
