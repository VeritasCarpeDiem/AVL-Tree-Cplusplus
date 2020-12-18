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
	//std::fstream file("c:\\temp\\input.txt");
	AVL avl{};
	/*avl.Add(5);
	avl.Add(3);
	avl.Add(8);
	avl.Add(10);
	bool res = avl.Delete(3);*/

	//avl.Add(20);
	//avl.Add(30);

	for (size_t i = 0; i < 10; i++)
	{
		avl.Add(i);
	}

	std::cout << "test";

	/*int num{};
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
	*/

	return 0;
}