#include <iostream>
#include <time.h>
#include <vector>
#include <list>
#include "LinkedArray.h"

int main()
{
	int datasize = 100000000;
	std::cout << datasize << " ints comparison: LinkedArray vs Vector vs List:" << std::endl;
	clock_t t = clock();
	
	
	std::cout << std::endl;
	LinkedArray<int> lar;
	
	for (int i = 0; i < datasize; i++)
		lar.push_back(i);
	
	t = clock() - t;
	std::cout << "LinkedArray push_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	lar.to_array();
	
	t = clock() - t;
	std::cout << "LinkedArray \"iterator\" access execution time (s):" << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	for (int i = 0; i < lar.size(); i++)
		lar[i];
	
	t = clock() - t;
	std::cout << "LinkedArray random access execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	while (lar.size() > 0)
		lar.pop_back();
	
	t = clock() - t;
	std::cout << "LinkedArray pop_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	
	
	std::cout << std::endl;
	std::vector<int> vec;
	
	for (int i = 0; i < datasize; i++)
		vec.push_back(i);
	
	t = clock() - t;
	std::cout << "Vector push_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	std::vector<int>::iterator it = vec.begin();
	for (int i = 0; i < vec.size(); i++)
		it++;
	
	t = clock() - t;
	std::cout << "Vector iterator access execution time (s):" << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	for (int i = 0; i < vec.size(); i++)
		vec[i];
	
	t = clock() - t;
	std::cout << "Vector random access execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	// TODO: add iterators and profile
	
	while (vec.size() > 0)
		vec.pop_back();
	
	t = clock() - t;
	std::cout << "Vector pop_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	
	
	std::cout << std::endl;
	std::list<int> lst;
	
	for (int i = 0; i < datasize; i++)
		lst.push_back(i);
	
	t = clock() - t;
	std::cout << "List push_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	std::list<int>::iterator end = lst.end();
	for (std::list<int>::iterator it = lst.begin(); it != end; ++it);
	
	t = clock() - t;
	std::cout << "List iterator access execution time (s):" << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	/*
	for (int i = 0; i < lst.size(); i++)
	{
		std::list<int>::iterator front = lst.begin();
		std::advance(front, i);
	}
	*/
	
	t = clock() - t;
	std::cout << "List random access execution time (s): *did not run due to astronomically long running time*" << std::endl;
	t = clock();
	
	// TODO: add iterators and profile
	
	while (lst.size() > 0)
		lst.pop_back();
	
	t = clock() - t;
	std::cout << "List pop_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
}
