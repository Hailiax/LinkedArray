#include <iostream>
#include <time.h>
#include <vector>
#include "../../GitHub/LinkedArray/LinkedArray.h"

int main()
{
	std::cout << "100000000 ints comparison: Linked Array vs Vector vs List:" << std::endl << std::endl;
	
	clock_t t = clock();
	
	LinkedArray<int> arr;
	
	for (int i = 0; i < 100000000; i++)
		arr.push_back(i);
	
	t = clock() - t;
	std::cout << "LinkedArray push_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	for (int i = 0; i < arr.size(); i++)
		arr[i] = arr[i] * 5;
	
	t = clock() - t;
	std::cout << "LinkedArray random access execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	// TODO: add iterators and profile
	
	while (arr.size() > 0)
		arr.pop_back();
	
	t = clock() - t;
	std::cout << "LinkedArray pop_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	
	
	std::vector<int> vec;
	
	for (int i = 0; i < 100000000; i++)
		vec.push_back(i);
	
	t = clock() - t;
	std::cout << "Vector push_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	for (int i = 0; i < vec.size(); i++)
		vec[i] = vec[i] * 5;
	
	t = clock() - t;
	std::cout << "Vector random access execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
	
	// TODO: add iterators and profile
	
	while (vec.size() > 0)
		vec.pop_back();
	
	t = clock() - t;
	std::cout << "Vector pop_back execution time (s): " << ((float)t)/CLOCKS_PER_SEC << std::endl;
	t = clock();
}
