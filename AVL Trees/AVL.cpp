#include "AVL.h"
#include <iostream>
#include <list>
#include "Stack.h"

AVL::~AVL()
{
	Clear();
}
//AVL::AVL()
//{
//
//}//runs this if defined

void AVL::Clear()
{
	count = 0;

	Stack<std::shared_ptr<Node>> stack{};

	if (root)
	{
		stack.Push(root);
		while (stack.count > 0)
		{
			root = stack.Pop();
			if (root->right)
			{
				stack.Push(root->right);
			}
			if (root->left)
			{
				stack.Push(root->left);
			}
			root.reset();
		}
	}
}

void AVL::Add(int value)
{
	count++;
	root = Add(value, root);
}

std::shared_ptr<Node> AVL::Add(int value, const std::shared_ptr<Node>& node)
{
	if (!node)
	{
		return std::make_shared<Node>(value);
	}

	if (value >= node->value)
	{
		node->right = Add(value, node->right);
	}
	else
	{
		node->left = Add(value, node->left);
	}

	return Balance(node);
}

std::shared_ptr<Node> AVL::Remove(int value, const std::shared_ptr<Node>& node)
{
	if (!node) return {};

	if (value < node->value)
	{
		node->left = Remove(value, node->left);
	}
	else if (value > node->value)
	{
		node->right = Remove(value, node->right);
	}

	else
	{
		if (node->ChildCount() == 2)
		{
			auto temp = Minimum(node->right);
			node->value = temp->value;
			node->right = Remove(temp->value, node->right);
		}
		else
		{
			count--;
			auto firstFirst = node->left;
			if (!firstFirst)
			{
				firstFirst = node->right;
			}

			return firstFirst;
		}
	}

	return Balance(node);
	//return node;
}

std::shared_ptr<Node> AVL::Minimum(std::shared_ptr<Node> node)
{
	if (node->left)
	{
		return Minimum(node->left);
	}
	return node;
}

// TODO: Fix Balance function
std::shared_ptr<Node> AVL::Balance(std::shared_ptr<Node> node)
{
	int balance = node->getBalance();
	if (balance < -1)
	{
		if (node->left)
		{
			if (node->left->getBalance() > 0)
			{
				node->left = RotateLeft(node->left);
			}
		}
		node = RotateRight(node);
	}
	else if (balance > 1)
	{
		if (node->right)
		{
			if (node->right->getBalance() < 0)
			{
				node->right = RotateRight(node->right);
			}
		}
		node = RotateLeft(node);
	}
	return node;
}

std::shared_ptr<Node> AVL::RotateRight(const std::shared_ptr<Node>& node)
{
	auto left = node->left;
	node->left = left->right;
	auto tempNode = node;
	left->right = std::move(tempNode);

	return left;
}

std::shared_ptr<Node> AVL::RotateLeft(const std::shared_ptr<Node>& node)
{
	auto right = node->right;
	node->right = right->left;
	auto tempNode = node;
	right->left = std::move(tempNode);


	return right;
}

bool AVL::Delete(int value)
{
	auto oldCount = count;
	root=Remove(value, root);
	return count != oldCount;
}

void AVL::PreOrder() const
{
	std::list<int> output{};
	if (count > 0)
	{
		Stack<std::shared_ptr<Node>> stack{};

		stack.Push(root);
		//std::shared_ptr<Node> current;

		while (stack.count > 0)
		{
			auto current = stack.Pop();
			output.push_back(current->value);
			if (current->right)
			{
				stack.Push(current->right);
			}
			if (current->left)
			{
				stack.Push(current->left);
			}
		}
	}
	//std::list<int>::iterator i;

	std::cout << "Pre Order:" << std::endl;

	for (auto i = output.begin(); i != output.end(); i++)
	{
		std::cout << *i << std::endl;
	}
}


