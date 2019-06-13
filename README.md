# LinkedArray  
A different dynamic array

## Running Time:  
Random Access: Ο(log n)  
Iterator Access: θ(1)  
(Non-amortized) Add element at end: θ(1)

## Usage:  
```
#include "LinkedArray.h"

LinkedArray<int> arr;

for (int i = 0; i < 2048; i++)
  arr.push_back(i);
  
for (int i = 0; i < arr.size(); i++)
  std::cout << arr[i] << ", ";
```
