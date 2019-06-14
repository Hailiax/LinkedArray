#include <iostream>


///////////
// NOTES //
///////////


// General Structure for growth factor of 2:
// [a] <-> [b] <-> [c,d] <-> [e,f,g,h] <-> [i,j,k,l,m,n,o,p] and so on




/////////////////
// DEFINITIONS //
/////////////////


template <typename T>
struct LinkedArrayNode
{
	T* array;
	LinkedArrayNode* next;
	LinkedArrayNode* prev;
	
	~LinkedArrayNode()
	{
		delete[] array;
	}
};

template <typename T>
class LinkedArray
{
private:
	
	LinkedArrayNode<T>* first_node_;
	LinkedArrayNode<T>* last_node_;
	
	int size_;
	int reserved_size_exponent_; // x
	int reserved_size_power_; // reserved size = 2^x

public:
	
	// Construction/Destruction
	LinkedArray();
	~LinkedArray();
	
	// Traits
	int size();
	int capacity();
	
	// Accessing elements
	T& operator[] (int);
	T* to_array();
	
	// Updating elements
	void push_back(const T &);
	void pop_back();
	
	// Updating capacity
	void double_capacity();
	void halve_capacity();
	void resize(int);
};




//////////////////////////////
// CONSTRUCTION/DESTRUCTION //
//////////////////////////////


template <typename T>
LinkedArray<T>::LinkedArray()
	: first_node_( new LinkedArrayNode<T> ),
	  reserved_size_exponent_( 0 ),
	  reserved_size_power_( 1 ), // Starts with one reserved space. Described the sum of all reserved arrays
	  size_( 0 )
{
	last_node_ = first_node_;
	first_node_->array = new T[1];
	first_node_->next = NULL;
	first_node_->prev = NULL;
}

template <typename T>
LinkedArray<T>::~LinkedArray()
{
	while (last_node_->prev != NULL) // Until the last node is the first node
	{
		// Delete last node
		last_node_ = last_node_->prev;
		delete last_node_->next;
	}
	// Delete the first node
	delete last_node_;
}




////////////
// TRAITS //
////////////


template <typename T>
int LinkedArray<T>::size()
{
	return size_;
}

template <typename T>
int LinkedArray<T>::capacity()
{
	return reserved_size_power_;
}




////////////////////////
// ACCESSING ELEMENTS //
////////////////////////


// Uses & so this returns a reference to make [] assignable; a[i] = b
template <typename T>
T& LinkedArray<T>::operator[](int index)
{
	// Check if in bounds
	if (index > size_)
	{
		std::cout << "Array index out of bound, exiting";
		exit(0);
	}
	
	// TODO: get rid of large subtractions/additions
	// Find and return value by
	// Finding the node the value is in by comparing to powers of two. (advancing to next node if the value is greater than the node's array size)
	// Returning with the index subtracted by all skipped array's sizes
	
	// The beginning of the list has two arrays with length one so we need to explicity check for the first one before using 2^n to traverse the list (our list has array lenghts 1,1,2,4,8... while 2^n gives 1,2,4,8,16...)
	if (index == 0)
		return first_node_->array[0]; // If it is, then stop the function here
	
	// If not, then we need to pretend that the second node is the first node in the coming while loop for easier calculation
	LinkedArrayNode<T>* temp_node = first_node_->next;
	index--; // Subtract the index skipped in the first array
	int temp_power = 1; // This is one power of two behind how reserved_size_power_ is calculated. (that's why we have the skipping first node step above.) This describes the size of the node currently being traversed instead of the sum of all nodes traversed thus far.
	
	while (index >= temp_power) // While the index is larger than the current node's array size
	{
		// Skip to next node, updating index and temp_power to reflect
		temp_node = temp_node->next;
		index -= temp_power; // subtract the indicies (traversed/skipped) in last node
		temp_power <<= 1; // equiv to *2
	}
	
	// Index has had all the previous traversals subtracted so this number is accurate for the current temp_node
	return temp_node->array[index];
}

template <typename T>
T* LinkedArray<T>::to_array()
{
	// Allocate array
	T* arr = new T[size_];
	
	// Fill by iterating over all values
	int elements_traversed = 0; // Counter for how many elements have been traversed
	LinkedArrayNode<T>* traversing_node = first_node_; // Array that is being traversed
	T* traversing_array_ptr = traversing_node->array; // Ptr to array/element to be incremented
	int traversing_array_index = 0; // Counter for index in traversing array
	int traversed_traversing_arrays_size_sum = 1; // If elements_traversed equals this, advance to next node/array,  double this, set traversing_array_index to 0
	
	while (elements_traversed < size_)
	{
		if (elements_traversed >= traversed_traversing_arrays_size_sum)
		{
			traversing_node = traversing_node->next;
			traversing_array_ptr = traversing_node->array;
			traversed_traversing_arrays_size_sum <<= 1;
			traversing_array_index = 0;
		}
		
		arr[elements_traversed] = *traversing_array_ptr;
		traversing_array_ptr++;
		elements_traversed++;
	}
	
	// Return filled array
	return arr;
}




///////////////////////
// UPDATING ELEMENTS //
///////////////////////


template <typename T>
void LinkedArray<T>::push_back(const T &new_element)
{
	// If ran out of space, reserve more
	// size_ starts at 1 while indicies start at 0 => this is not off by one (don't need to add +1)
	if (size_ == reserved_size_power_)
		double_capacity();
	
	// Add value to end of last_node_ by subtracting previous node indicies (capacity/2) from the size
	last_node_->array[ size_ - (reserved_size_power_ >> 1) ] = new_element;
	
	// increase size
	size_++;
}

template <typename T>
void LinkedArray<T>::pop_back()
{
	if (size_ == 0) // Ensure there is something to pop
	{
		std::cout << "Cannot pop_back list of 0 size, exiting";
		exit(0);
	}
	
	// decrease size
	size_--;
	
	// If size is a quarter of the reserved size, shrink the list
	if (size_-1 == reserved_size_power_ >> 2)
		halve_capacity();
	
	// TODO: fix, the list will never shrink back down to one element with this logic
}




///////////////////////
// UPDATING CAPACITY //
///////////////////////


template <typename T>
void LinkedArray<T>::double_capacity()
{
	// Allocate new larger node
	LinkedArrayNode<T>* new_node = new LinkedArrayNode<T>;
	new_node->array = new T[reserved_size_power_]; // Create new array as big as total capacity currently is (doubling capacity)
	new_node->next = NULL;
	
	// Connect nodes
	new_node->prev = last_node_;
	last_node_->next = new_node;
	last_node_ = new_node;
	
	// Update reserved size values
	reserved_size_exponent_++;
	reserved_size_power_ <<= 1; // equiv to *2
}

template <typename T>
void LinkedArray<T>::halve_capacity()
{
	// Delete last node
	last_node_ = last_node_->prev;
	delete last_node_->next;
	
	// Updated reserved size values
	reserved_size_exponent_--;
	reserved_size_power_ >>= 1;
}

template <typename T>
void LinkedArray<T>::resize(int n) // Accepts the new exponenet as n
{
	if (n < 0)
	{
		std::cout << "Cannot resize array to a negative exponenet, exiting";
		exit(0);
	}
	
	while (reserved_size_exponent_ < n)
		double_capacity();
	
	while (reserved_size_exponent_ > n)
		halve_capacity();
}
