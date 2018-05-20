#include "Node.h"


Node::Node(int Nodedata)
{
	this->nodeData = nodeData;
}

void Node::SetNodeData(int Nodedata)
{
	this->nodeData = nodeData;
}

int Node::GetNodeData() const
{
	return nodeData;
}
