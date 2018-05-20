#pragma once

#include <vector>

class Node;

enum NumberOfNodes
{
	Default,
	NoNodes,
	OneNode,
	TwoNodes
};

class Heap
{
private:

	int SizeOfHeap;
	std::vector<Node*> heap;
	Node * root;

public:

	Heap();
	~Heap();

	NumberOfNodes NodeNumber(int PositionOfNode);

	void Insert(int node);

	void SortInsertion();

	int GetParentValue(int nodePosition) { return nodePosition / 2; }

	void SwapNodeValue(Node * parent, Node * child);

	void RemoveFirst();

	void ViewHeap();


};