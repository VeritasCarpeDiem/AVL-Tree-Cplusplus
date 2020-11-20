#include "Node.h"
#include "AVL.h"
#include <fstream>
#include <iostream>
#include <string>

std::pair<char, std::string> splitString(std::string input)
{
	std::pair<char, std::string> myPair{};

	myPair.first = input[0];
	myPair.second = input.substr(2); //this returns a substring 

	return myPair;
}

int main()
{
	std::fstream file("c:\\temp\\input.txt");
	AVL avl{};
	int num{};
	std::string line{};
	
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
			auto pair = splitString(line);
			if (pair.first == 'a') //Add node
			{
				num = std::stoi(pair.second); //convert string number to int number
				avl.Add(num);
			}
			else if (pair.first == 'd') //Delete Node
			{
				num = std::stoi(pair.second);
				avl.Delete(num);
			}
			else //exit
			{
				break;
			}
		}
		avl.PreOrder();
		file.close();
	}
	

	return 0;
}