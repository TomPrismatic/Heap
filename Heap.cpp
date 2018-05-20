#include "Heap.h"
#include "Node.h"

#include <iostream>


Heap::Heap()
{
	SizeOfHeap = 0;
	root = nullptr;
	heap.push_back(nullptr);
}


Heap::~Heap()
{
}

NumberOfNodes Heap::NodeNumber(int PositionOfNode)
{
	return NumberOfNodes();
}

void Heap::Insert(int node)
{

	Node * NewNode = new Node(node);
	SizeOfHeap++;

	// Aif new Node is first node make it the root
	if (SizeOfHeap == 1)
		root = NewNode;

	// Add new Node to heap
	heap.push_back(NewNode);

	// Sort the heap
	SortInsertion();
}

void Heap::SortInsertion()
{
	Node * NewNode = heap.at(SizeOfHeap);
	int nodePosition = SizeOfHeap;

	//If the first node, return
	if (NewNode == root) { return; }

	// While the NewNode is smaller than it's parent value
	while (NewNode != root && heap.at(nodePosition / 2)->GetNodeData() > heap.at(nodePosition)->GetNodeData())
	{
		// Swap the child with the parent
		SwapNodeValue(heap.at(nodePosition / 2), NewNode);

		NewNode = heap.at(nodePosition / 2);
		nodePosition = nodePosition / 2;
	}
}


void Heap::SwapNodeValue(Node * parentNode, Node * childNode)
{
	int Data = parentNode->GetNodeData();
	parentNode->SetNodeData(childNode->GetNodeData());
	childNode->SetNodeData(Data);
}

void Heap::RemoveFirst()
{
	// Replace first node value with the last inserted Node's node Value
	SwapNodeValue(heap.at(1), heap.at(SizeOfHeap));
	// Remove last Node from heap
	delete heap.back();
	heap.pop_back();
	SizeOfHeap--;

	int nodePosition = 1;

	NumberOfNodes Number = Default;

	while (true)
	{
		// Define number of Nodes
		Number = NodeNumber(nodePosition);

		switch (Number)
		{

		case NoNodes:
		{
			//If no nodes just return
			std::cout << "No Nodes" << std::endl;
			return;
		}
		// Left Node

		case OneNode:
		{
			std::cout << "One Node" << std::endl;
			// Compare parent with Left Node
			if (heap.at(nodePosition)->GetNodeData() > heap.at(nodePosition * 2)->GetNodeData())
				SwapNodeValue(heap.at(nodePosition), heap.at(nodePosition * 2));
			return;
		}
		break;

		

		case TwoNodes:
		{
			std::cout << "Two Nodes" << std::endl;
			// Find the smaller Node
			int smallerNode;

			int leftNode = heap.at(nodePosition * 2)->GetNodeData();
			int rightNode = heap.at((nodePosition * 2) + 1)->GetNodeData();

			// If left is smaller than right
			if (leftNode < rightNode)
			{
				smallerNode = nodePosition * 2;
			}
			// If right is smaller
			else
			{
				smallerNode = (nodePosition * 2) + 1;
			}

			if (heap.at(nodePosition)->GetNodeData() > heap.at(smallerNode)->GetNodeData())
			{
				SwapNodeValue(heap.at(nodePosition), heap.at(smallerNode));
				nodePosition = smallerNode;
				break;
			}

			else
			{
				return;
			}

		break;
		}
		default:
			return;
		}
	}
}

void Heap::ViewHeap()
{
	int Size = 1;

	while (Size != SizeOfHeap + 1)
	{
		//Show whats in the heap
		std::cout << heap.at(Size)->GetNodeData() << std::endl;
		Size++;
	}
}
