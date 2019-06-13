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

## Preliminary Tests:  
```
100000000 ints comparison: Linked Array vs Vector vs List:

LinkedArray push_back execution time (s): 0.43606
LinkedArray random access execution time (s): 10.9912
LinkedArray pop_back execution time (s): 0.493611
Vector push_back execution time (s): 3.49354
Vector random access execution time (s): 0.572086
Vector pop_back execution time (s): 3.78261
```
