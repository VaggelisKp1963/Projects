#include "UCS.h"
#include "Node.h"
#include <iostream>
#include <iterator>


UCS::UCS() {
	this->nodesCreated = 0;
}
void UCS::setNodesCreated(int nodesCreated) {
	this->nodesCreated = nodesCreated;
}
int UCS::getNodesCreated() {
	return this->nodesCreated;
}

void UCS::setLastnode(Node* lastnode)
{
	this->lastnode = lastnode;
}
Node* UCS::getLastnode()
{
	return this->lastnode;
}


bool UCS::checkList(int x, int y) {
	Node* temp;
	for (std::list<Node*>::iterator it = list.begin(); it != list.end(); it++) {
		temp = *it;
		if (x == temp->getRobot_pos()[0] && y == temp->getRobot_pos()[1])
			return false;
	}
	return true;
}


void UCS::findStartandGoal(char maze[11][13], int width, int height, int* start_pos, int* goal_pos) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (maze[i][j] == 'S') {
				start_pos[0] = i;
				start_pos[1] = j;
			}
			if (maze[i][j] == 'G') {
				goal_pos[0] = i;
				goal_pos[1] = j;
			}
		}
	}
}


Node* UCS::expandNodes(char maze[11][13], Node* node, char action, int width, int height) {
	int x = node->getRobot_pos()[0];
	int y = node->getRobot_pos()[1];

	switch (action)
	{
	case 'r': {
		if (y + 1 > width - 1) { return nullptr; }
		else {
			if (maze[x][y + 1] == 'X') return nullptr;
			else if ((maze[x][y + 1] == '\0' || maze[x][y + 1] == 'S' || maze[x][y + 1] == 'G') && checkList(x, y + 1)) return new Node(x, y + 1, node->getCurrentDepth() + 1, node->getCurrentCost() + 1, 'r', node, node->getCurrentDepth() + 1);
			else if ((maze[x][y + 1] == 'D') && checkList(x, y + 1)) return new Node(x, y + 1, node->getCurrentDepth() + 1, node->getCurrentCost() + 2, 'r', node, node->getCurrentDepth() + 1);
			else return nullptr;
		}
		break;
	}
	case 'l': {
		if (y - 1 < 0) { return nullptr; }
		else {
			if (maze[x][y - 1] == 'X') return nullptr;
			else if ((maze[x][y - 1] == '\0' || maze[x][y - 1] == 'S' || maze[x][y - 1] == 'G') && checkList(x, y - 1)) return new Node(x, y - 1, node->getCurrentDepth() + 1, node->getCurrentCost() + 1, 'l', node, node->getCurrentDepth() + 1);
			else if ((maze[x][y - 1] == 'D') && checkList(x, y - 1)) return new Node(x, y - 1, node->getCurrentDepth() + 1, node->getCurrentCost() + 2, 'l', node, node->getCurrentDepth() + 1);
			else return nullptr;
		}
		break;
	}
	case 'u': {
		if (x - 1 < 0) { return nullptr; }
		else {
			if (maze[x - 1][y] == 'X') return nullptr;
			else if ((maze[x - 1][y] == '\0' || maze[x - 1][y] == 'S' || maze[x - 1][y] == 'G') && checkList(x - 1, y)) return new Node(x - 1, y, node->getCurrentDepth() + 1, node->getCurrentCost() + 1, 'u', node, node->getCurrentDepth() + 1);
			else if ((maze[x - 1][y] == 'D') && checkList(x - 1, y)) return new Node(x - 1, y, node->getCurrentDepth() + 1, node->getCurrentCost() + 2, 'u', node, node->getCurrentDepth() + 1);
			else return nullptr;
		}
		break;
	}
	case 'd': {
		if (x + 1 > height - 1) { return nullptr; }
		else {
			if (maze[x + 1][y] == 'X') return nullptr;
			else if ((maze[x + 1][y] == '\0' || maze[x + 1][y] == 'S' || maze[x + 1][y] == 'G') && checkList(x + 1, y)) return new Node(x + 1, y, node->getCurrentDepth() + 1, node->getCurrentCost() + 1, 'd', node, node->getCurrentDepth() + 1);
			else if ((maze[x + 1][y] == 'D') && checkList(x + 1, y)) return new Node(x + 1, y, node->getCurrentDepth() + 1, node->getCurrentCost() + 2, 'd', node, node->getCurrentDepth() + 1);
			else return nullptr;
		}
		break;
	}
	default:
		return nullptr;
	}
}

bool UCS::runUCS(char maze[11][13], int width, int height) {
	int* start_pos;
	int* goal_pos;
	Node* leftNode;
	Node* rightNode;
	Node* upNode;
	Node* downNode;
	goal_pos = (int*)malloc(sizeof(int) * 2);
	start_pos = (int*)malloc(sizeof(int) * 2);
	this->findStartandGoal(maze, width, height, start_pos, goal_pos);
	int goal_x = *goal_pos;
	int goal_y = *(goal_pos + 1);

	Node* root = new Node(start_pos, 0, 0, '\0', nullptr, 0);
	this->list.push_front(root);
	this->priority_queue.push(root);
	while (!priority_queue.empty()) {
		Node* tempnode;
		tempnode = this->priority_queue.top();
		this->priority_queue.pop();

		if (tempnode->checkIfGoal(goal_x, goal_y)) {
			this->lastnode = tempnode;
			return true;
		}
		leftNode = expandNodes(maze, tempnode, 'l', width, height);
		rightNode = expandNodes(maze, tempnode, 'r', width, height);
		upNode = expandNodes(maze, tempnode, 'u', width, height);
		downNode = expandNodes(maze, tempnode, 'd', width, height);
		if (leftNode != nullptr) {
			this->nodesCreated++;
			priority_queue.push(leftNode);
			this->list.push_front(leftNode);
		}
		if (rightNode != nullptr) {
			this->nodesCreated++;
			priority_queue.push(rightNode);
			this->list.push_front(rightNode);
		}
		if (upNode != nullptr) {
			this->nodesCreated++;
			priority_queue.push(upNode);
			this->list.push_front(upNode);
		}
		if (downNode != nullptr) {
			this->nodesCreated++;
			priority_queue.push(downNode);
			this->list.push_front(downNode);
		}
	}
	return false;

}