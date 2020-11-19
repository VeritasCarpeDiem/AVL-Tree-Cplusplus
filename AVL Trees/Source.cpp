#include "Node.h"
#include "AVL.h"
#include <fstream>
int main()
{
	/*int num{};
	char c{};
	std::ifstream file("c:\temp\input.txt");*/
	AVL avl{};

	//while (!file.eof())
	//{
	//
	//	if (c == 'a') //Add node
	//	{
	//		tree.Add(num);
	//	}
	//	else if (c== 'd') //Delete Node
	//	{
	//		
	//	}
	//	else //exit
	//	{
	//		break;
	//	}
	//}
	//file.close();

	avl.Add(15);
	avl.Add(20);
	avl.Add(10);
	avl.Delete(20);
	avl.PreOrder();

	return 0;
}