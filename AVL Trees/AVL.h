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
	AVL();
	~AVL();

	std::shared_ptr<Node> root{};
	void Add(int value);


};

