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
10000 ints comparison: Linked Array vs Vector vs List:

LinkedArray push_back execution time (s): 4.7e-05
LinkedArray random access execution time (s): 0.000288
LinkedArray pop_back execution time (s): 4.4e-05

Vector push_back execution time (s): 0.000436
Vector random access execution time (s): 3.2e-05
Vector pop_back execution time (s): 0.000359

List push_back execution time (s): 0.002354
List random access execution time (s): 0.128157
List pop_back execution time (s): 0.00066


100000000 ints comparison: Linked Array vs Vector vs List:

LinkedArray push_back execution time (s): 0.450082
LinkedArray random access execution time (s): 5.29738
LinkedArray pop_back execution time (s): 0.476507

Vector push_back execution time (s): 3.4248
Vector random access execution time (s): 0.340808
Vector pop_back execution time (s): 3.76075

List push_back execution time (s): 24.9823
** Code stopped, this mightve taken 2.49823e9 seconds
```
