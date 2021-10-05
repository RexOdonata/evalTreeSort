#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>

struct nodeVal
{
	int sourceIndex;
	int key;
};

struct node
{
	nodeVal val;
	bool open;
};

class evalTree
{
	private:
		node* tree;
		int dataNodes;
		int totalTreeSize;

	public:
		evalTree(int * unsortedData, int size);

		~evalTree();

		void updateNodeInit(int index);

		void updateNode(int index);

		void closeNode(int index);

		int takeRoot(int count);

		void printTree();

};

