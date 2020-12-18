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
		int count = 0;
		if (right)
		{
			count++;
		}
		if (left)
		{
			count++;
		}
		return count;
	}
	int value{};
	Node() {};
	Node(int v) :value(v) {};

	int leftHeight()
	{
		if (left)
		{
			return left->getHeight();
		}
		return 0;
	}
	int rightHeight()
	{
		if (right)
		{
			return right->getHeight();
		}
		return 0;
	}
	int getHeight()
	{
		int rightH = rightHeight();
		int leftH = leftHeight();
		if (rightH > leftH)
		{
			return rightH + 1;
		}
		return leftH + 1;
	}
	int getBalance()
	{
		int rightH = 0;
		int leftH = 0;
		if (right)
		{
			rightH = right->getHeight();
		}
		if (left)
		{
			leftH= left->getHeight();
		}
		return rightH - leftH;
	}
};

