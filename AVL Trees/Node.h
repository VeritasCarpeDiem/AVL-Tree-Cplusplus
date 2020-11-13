#pragma once
#include <memory>
class Node
{
private:

public:
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

	int ChildCount()
	{

	}
};

