
#include <iostream>
#include<ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// A linked list node
class Node
{
public:
	int data;
	Node* next;
};


void InsertFront(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point
	// to the new node
	(*head_ref) = new_node;
}


void InsertAfter(Node* prev_node, int new_data)
{
	// 1. check if the given prev_node
	// is NULL
	if (prev_node == NULL)
	{
		cout << "The given previous node cannot be NULL";
		return;
	}

	// 2. allocate new node
	Node* new_node = new Node();

	// 3. put in the data
	new_node->data = new_data;

	// 4. Make next of new node
	// as next of prev_node
	new_node->next = prev_node->next;

	// 5. move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

void Append(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	//used in step 5
	Node* last = *head_ref;

	// 2. put in the data
	new_node->data = new_data;

	/* 3. This new node is going to be
	the last node, so make next of
	it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty,
	then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
	{
		last = last->next;
	}

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}


void printList(Node* node)
{
	while (node != NULL)
	{
		cout << " " << node->data;
		node = node->next;
	}
}


int main()
{

	// Start with the empty list
	Node* head = NULL;
	Node* head2 = NULL;

	const int N = 100000;
	int arr[N];
	int i, x;
	for (i = 0; i < N; i++) {
		x = (rand() % 50000) + 1;
		arr[i] = x;
	}
	auto start = high_resolution_clock::now();

	for (i = 0; i < N; i++) {
		Append(&head, arr[i]);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken to add node at the end: " << duration.count() << " microseconds" << endl;


	auto start2 = high_resolution_clock::now();

	for (i = 0; i < N; i++) {
		InsertFront(&head2, arr[i]);
	}

	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken to add node at the front: " << duration2.count() << " microseconds" << endl;


	return 0;
}

