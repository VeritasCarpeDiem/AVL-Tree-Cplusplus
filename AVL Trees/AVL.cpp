#include "AVL.h"
#include <iostream>
#include <list>
#include "Stack.h"

AVL::AVL()
{

}

AVL::~AVL()
{
	Clear();
}

void AVL::Clear()
{
	count = 0;
	
	Stack <std::shared_ptr<Node>> stack{};

	if (root)
	{
		stack.Push(root);
		while (stack.count> 0)
		{
			root = std::move(stack.Pop());
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
	root = std::move(Add(value, root));
}

std::shared_ptr<Node> AVL::Add(int value, std::shared_ptr<Node> node)
{
	if (node == nullptr)
	{
		std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
		return newNode;
	}

	if (value >= node->value)
	{
		if (node->right)
		{
			node->right = Add(value, node->right);
		}
		else
		{
			node->right = std::move(std::make_shared<Node>(value));
		}
	}
	else
	{
		if (node->left)
		{
			node->left = Add(value, node->left);
		}
		else
		{
			node->left = std::make_shared<Node>(value);
		}
	}

	return Balance(node);
}

std::shared_ptr<Node> AVL::Remove(int value, std::shared_ptr<Node> node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value > value)
	{
		node->left = std::move(Remove(value, node->left));
	}
	else if (node->value < value)
	{
		node->right = std::move(Remove(value, node->right));
	}
	else
	{
		if (node->right && node->left)
		{
			auto min = Minimum(node->right);
			node->value = min->value;
			node->right = std::move(Remove(min->value, node->right));
		}
		else
		{
			count--;
			if (node->right)
			{
				return node->right;
			}
			else if (node->left)
			{
				return node->left;
			}
			else
			{
				return nullptr;
			}
		}
	}

	return Balance(node);
}

std::shared_ptr<Node> AVL::Minimum(std::shared_ptr<Node> node)
{
	if (node->left)
	{
		return Minimum(node->left);
	}
	return node;
}


std::shared_ptr<Node> AVL::Balance(std::shared_ptr<Node> node)
{
	int balance = node->getBalance();
	if (balance < -1)
	{
		if (node->left)
		{
			if (node->left->getBalance() > 0)
			{
				node->left = std::move(RotateRight(node->left));
			}
		}
		node = std::move(RotateLeft(node));
	}
	else if (balance > 1)
	{
		if (node->right)
		{
			if (node->right->getBalance() < 0)
			{
				node->right = std::move(RotateLeft(node->right));
			}
		}
		node = std::move(RotateRight(node));
	}
	return node;
}

std::shared_ptr<Node> AVL::RotateRight(std::shared_ptr<Node> node)
{
	auto left = node->left;
	node->left = std::move(left->right);
	auto tempNode = node;
	left->right = std::move(tempNode);

	return left;
}

std::shared_ptr<Node> AVL::RotateLeft(std::shared_ptr<Node> node)
{
	auto right = node->right;
	node->right = std::move(right->left);
	auto tempNode = node;
	right->left = std::move(tempNode);


	return right;
}

bool AVL::Delete(int value)
{
	int oldCount = count;
	Remove(value, root);
	return count != oldCount;
}

void AVL::PreOrder()
{
	std::list<int> output{};
	if (count > 0)
	{
		Stack <std::shared_ptr<Node>> stack{};

		stack.Push(root);
		std::shared_ptr<Node> current;

		while (stack.count > 0)
		{
			current = stack.Pop();
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
	
	std::list<int>::iterator i;

	std::cout << "Pre Order:" << std::endl;

	for (i=output.begin(); i != output.end(); i++)
	{
		std::cout << *i << std::endl;
	}
}


