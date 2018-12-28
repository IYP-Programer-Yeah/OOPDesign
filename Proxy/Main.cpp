#include "List"
#include "ReadOnlyList.hpp"

#include <iostream>


int main()
{
	List list;
	ReadOnlyList read_only_list(list);
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);
	for (auto i = read_only_list.cbegin(); i != read_only_list.cend(); i++)
		std::cout << *i << std::endl;
	try
	{
		read_only_list.pop_front();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}