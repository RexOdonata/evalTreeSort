#include "evalTree.h"


#define leftOpen tree[index * 2 + 1].open
#define rightOpen tree[index * 2 + 2].open

#define leftKey tree[index * 2 +1].val.key
#define rightKey tree[index * 2 +2].val.key

#define leftVal tree[index * 2 +1].val
#define rightVal tree[index * 2 +2].val

evalTree::evalTree(int* unsortedData, int setSize)
{
	dataNodes = setSize;

	totalTreeSize = 2 * dataNodes - 1;

	tree = new node[totalTreeSize];

	for (int i = totalTreeSize - 1; i >= 0; i--)
	{
		if (i >= dataNodes-1)
		{
			nodeVal newNodeVal;
			newNodeVal.key=unsortedData[i - dataNodes + 1];
			newNodeVal.sourceIndex = i;
			node newNode;
			newNode.val = newNodeVal;
			newNode.open = true;
			tree[i] = newNode;
		}
		else
		{
			nodeVal newNodeVal;
			newNodeVal.key = 0;
			newNodeVal.sourceIndex = -1;
			node newNode;
			newNode.val = newNodeVal;
			newNode.open = true;
			tree[i] = newNode;

			updateNodeInit(i);
		}
	}
}

evalTree::~evalTree()
{
	delete tree;
}

void evalTree::updateNode(int index)
{

	if (leftOpen)
	{
		if (rightOpen)
		{
			//evaluate both children
			if (leftKey < rightKey)
			{
				tree[index].val = leftVal;
			}
			else
			{
				tree[index].val = rightVal;
			}
		}
		else
		{
			//take left
			tree[index].val = leftVal;
		}

		//bubble eval up
		if (index > 0) updateNode((index - 1) / 2);
	}
	else
	{
		if (rightOpen)
		{
			//take right
			tree[index].val = rightVal;
			if (index > 0) updateNode((index - 1) / 2);
		}
		else
		{
			//if both children are closed, this node closes and bubbles the eval up
			closeNode(index);
		}
	}

	/*
	if (leftOpen == false )
	{
		closeNode(index);
	}
	else if (leftOpen)
	{
		if (rightOpen)
		{
			if (leftKey < rightKey)
			{
				tree[index].val = leftVal;
			}
			else
			{
				tree[index].val = rightVal;
			}
		}
		else
		{
			tree[index].val = leftVal;
		}
		if (index > 0) updateNode((index - 1) / 2);
	}
	else
	{
		tree[index].val = rightVal;
		if (index > 0) updateNode((index - 1) / 2);
	}
	*/

	

}

void evalTree::updateNodeInit(int index)
{
	if (leftKey < rightKey)
	{
		tree[index].val = leftVal;
	}
	else
	{
		tree[index].val = rightVal;
	}
}

void evalTree::printTree()
{
	int level= 0;
	int widthReg = 0;
	for (int i = 0; i < totalTreeSize; i++)
	{

		if (widthReg == 0)
		{
			printf("\n> ");
			widthReg = pow(2,level);
			level++;
		}
		std::cout<<"["<< tree[i].val.key <<"]/" << tree[i].open;
		widthReg--;		
		
	}
}


int evalTree::takeRoot(int count)
{
	int outputKey = tree[0].val.key;
	
	if (count!=dataNodes) closeNode(tree[0].val.sourceIndex);

	return outputKey;
}

void evalTree::closeNode(int index)
{
	//printf("Close Call from %d\n", index);
	tree[index].open = false;

	updateNode((index - 1) / 2);
	
}