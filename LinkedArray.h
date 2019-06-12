#include <iostream>

// General Structure for growth factor of 2: \
TODO: Get rid of first node \
[a] <-> [b] <-> [c,d] <-> [e,f,g,h] <-> [i,j,k,l,m,n,o,p] and so on

template <typename T>
struct LinkedArrayNode
{
	T* array;
	LinkedArrayNode* next;
	LinkedArrayNode* prev;
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
	
	LinkedArray();
	~LinkedArray();
	
	int size();
	int capacity();
	
	T& operator[] (int);
	void push_back(const T &);
	
	void double_capacity();
	void halve_capacity();
	void resize(int);
};

template <typename T>
LinkedArray<T>::LinkedArray()
	: first_node_( new LinkedArrayNode<T> ),
	  reserved_size_exponent_( 0 ),
	  reserved_size_power_( 1 ), // Starts with one reserved space
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
	// TODO: delete all arrays
}

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
	
	// Find and return value
	LinkedArrayNode<T>* temp_node = first_node_;
	int temp_power = 1;
	
	if (index == 0) // Weird math since there are two arrays with size 2^0. There should be one.
		return first_node_->array[0];
	index--;
	temp_node = temp_node->next;
	
	while (index >= temp_power)
	{
		temp_node = temp_node->next;
		index -= temp_power; // subtract the indicies skipped in last node
		temp_power <<= 1; // equiv to *2
	}
	
	return temp_node->array[index];
}

template <typename T>
void LinkedArray<T>::push_back(const T &new_element)
{
	// If ran out of space, reserve more
	if (size_ == reserved_size_power_)
		double_capacity();
	
	// Add value to end of last_node_ by subtracting previous node indicies (capacity/2) from the size
	// size_ starts at 1 while indicies start at 0 => this is not off by one
	last_node_->array[ size_ - (reserved_size_power_ >> 1) ] = new_element;
	
	// increase size
	size_++;
}

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
	// TODO: this
}

template <typename T>
void LinkedArray<T>::resize(int n) // Accepts the new exponenet as n
{
	while (reserved_size_exponent_ < n)
		double_capacity();
	
	while (reserved_size_exponent_ > n)
		halve_capacity();
}