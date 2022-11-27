#include<iostream>
#include<climits>
using namespace std;

// swap two integers
void swap(int* x, int* y);
class MinHeap {
	int* harray; // pointer to array of elements
	int capacity; // maximum size of min heap
	int heap_size; // Current number of elements
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index
	void MinHeapify(int);
	int parent(int i) { return (i - 1) / 2; }
	// get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	//get index of right child of node at index i
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the minimum element
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int getMin() { return harray[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);

	int get_level(int k);

	void print();
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap) {
	heap_size = 0;
	capacity = cap;
	harray = new int[cap];
}

// Inserts a new key
void MinHeap::insertKey(int k) {
	if(heap_size == capacity) {
		cout << "Capacity Reached." << endl;
		// Create new array.
		int oldCap = capacity;
		capacity = capacity * 2;
		int* newArr = new int[capacity];

		// Copy array.
		copy(harray, harray + min(oldCap, capacity), newArr);

		// Delete old array.
		delete[] harray;
		harray = newArr;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harray[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harray[parent(i)] > harray[i]) {
		swap(&harray[i], &harray[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  
//It is assumed that new_val is smaller than harray[i].
void MinHeap::decreaseKey(int i, int new_val) {
	harray[i] = new_val;
	while (i != 0 && harray[parent(i)] > harray[i]) {
		swap(&harray[i], &harray[parent(i)]);
		i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1) {
		heap_size--;
		return harray[0];
	}

	// Retrieve the minimum value, and remove it from heap
	int root = harray[0];
	harray[0] = harray[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

// This function deletes key at index i. 
void MinHeap::deleteKey(int i) {
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harray[l] < harray[i])
		smallest = l;
	if (r < heap_size && harray[r] < harray[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harray[i], &harray[smallest]);
		MinHeapify(smallest);
	}
}

int MinHeap::get_level(int k) {
	int j = k;
	int i = 0;
	while(j > 0) {
		j = parent(j);
		i++;
	}
	return i;
}

void MinHeap::print() {
	int level = 0;
	int prevLevel = 0;

	for(int i = 0; i < heap_size; i++) {
		level = get_level(i);
		if (level > prevLevel ) {
			prevLevel = level;
			cout << "\n";
		}
		cout << harray[i] << " ";
	}
}

// A utility function to swap two elements
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Driver program to test above functions
int main() {
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.print();
	return 0;
}
