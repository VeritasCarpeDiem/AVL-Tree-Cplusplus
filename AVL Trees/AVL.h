#pragma once
#include "Node.h"

class AVL
{
private:
	int count{};
	std::shared_ptr<Node> Add(int value, std::shared_ptr<Node> node);
	std::shared_ptr<Node> Remove(int value, std::shared_ptr<Node> node);
	std::shared_ptr<Node> Minimum(std::shared_ptr<Node> node);

public:
	std::shared_ptr<Node> root{};

	AVL();
	~AVL();

	void Add(int value);
	std::shared_ptr<Node> Balance(std::shared_ptr<Node> node);
	std::shared_ptr<Node> RotateRight(std::shared_ptr<Node> node);
	std::shared_ptr<Node> RotateLeft(std::shared_ptr<Node> node);

	bool Delete(int value);

	void PreOrder();
	//void InOrder();
	//void PostOrder();
	//void BreadthFirst();

	void Clear();
};

