# LinkedArray  
A different dynamic array

## Running Time:  
Note: these are all non-amortized  
Random Access: Ο(log n)  
Iterator Access: θ(1)  
Append: θ(1)  

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

LinkedArray push_back execution time (s): 0.460008
LinkedArray "iterator" access execution time (s):0.324898
LinkedArray random access execution time (s): 5.31022
LinkedArray pop_back execution time (s): 0.517355

Vector push_back execution time (s): 3.68421
Vector iterator access execution time (s):0.489282
Vector random access execution time (s): 0.330557
Vector pop_back execution time (s): 3.86254

List push_back execution time (s): 25.6141
List iterator access execution time (s):0.562516
List random access execution time (s): *did not run due to astronomically long running time*
List pop_back execution time (s): 8.65295
```
