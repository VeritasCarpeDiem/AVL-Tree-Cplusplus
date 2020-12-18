#pragma once
#include "Node.h"

class AVL
{
private:
	int count{};
	std::shared_ptr<Node> Add(int value, const std::shared_ptr<Node> &node);
	std::shared_ptr<Node> Remove(int value, const std::shared_ptr<Node> &node);
	std::shared_ptr<Node> Minimum(std::shared_ptr<Node> node);

public:
	std::shared_ptr<Node> root{};

	AVL()= default; //if programmer provided parameters, use that

	~AVL();

	void Add(int value);
	std::shared_ptr<Node> Balance(std::shared_ptr<Node> node);
	std::shared_ptr<Node> RotateRight(const std::shared_ptr<Node> &node);
	std::shared_ptr<Node> RotateLeft(const std::shared_ptr<Node> &node);

	bool Delete(int value);

	void PreOrder() const;
	//void InOrder();
	//void PostOrder();
	//void BreadthFirst();

	void Clear();
};

