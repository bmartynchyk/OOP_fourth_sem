
#include <iostream>
#include "iterator.h"

#ifndef _LIST_H_
#define _LIST_H_



// L I S T   C L A S S   D E C L A R A T I O N
#pragma region List class declaration

template<class T> class List {

	struct ListNode {
		T data;
		ListNode *next;

		ListNode() {
			next = NULL;
		}
		ListNode(T dat) {
			data = dat;
		}
		void Print() {
			std::cout << data;
		}
	};

public:
	typedef ListNode node_type;
	typedef _iterator<node_type> iterator;

	// Constructors/Destructors
	List();
	~List();
	
	// Public methods

	// Returns an iterator addressing the first element
	iterator begin();
	// Returns an iterator that addresses the location succeeding the last element
	iterator end();
	// Returns an iterator to the first element in a list that match a specified value
	iterator find(const T & val);

	void clear(); // Erases all the elements of a list
	bool empty(); // Tests if a list is empty
	int size(); // Returns the number of elements in a list

	void pop_front(); //Deletes the element at the beginning of a list
	void push_front(const T val); // Adds an element to the beginning of a list
	void remove(const T val); 	// Erases first element in a list that match a specified value

	// Removes element from the target list and inserts it in first position of the argument list
	void splice(iterator _Where, List<T>& _Right);

	// Dumps list into the screen
	void Print();

private:
	node_type *head;
	iterator *first, *last;
};

#pragma endregion



// L I S T   C L A S S   I M P L E M E N T A T I O N
#pragma region List class implementation


// Constructors/Destructors
template<class T> List<T>::List() {

}

template<class T> List<T>::~List() {

}

//
// Public methods
//

// Methods for iterator
template<class T>
typename List<T>::iterator List<T>::begin() {
	return *first;
}

template<class T>
typename List<T>::iterator List<T>::end() {
	return iterator(nullptr);
}

template<class T>
typename List<T>::iterator List<T>::find(const T & val) {
	return *last;
}


template<class T>
void List<T>::clear() {
	while (nullptr != head) pop_front();
}

template<class T>
bool List<T>::empty() {
	return (head == nullptr);
}

// Adding/Deleting elements of list
template<class T>
void List<T>::push_front(const T val) {
	if (node_type *node = new node_type(val)) {
		node->next = head;

		if (nullptr == last) {
			first = new iterator(head);
			//last = new iterator(head);
		}

		head = node;
	}
}

template<class T>
void List<T>::pop_front() {
	if (nullptr == head) {
		node_type tmp = head->next;

		delete head;
		head = tmp;
	}
}

template<class T>
void List<T>::remove(const T val) {

}


template<class T>
void List<T>::Print() {
	for (iterator *itr = first; itr != first; itr++) {
		std::cout << *itr;
	}
}

template<class T>
int List<T>::size() {
	int size = 0;

	for (iterator i = begin(); i != end(); i++) size++;
	
	return size;
}

template<class T>
void List<T>::splice(iterator _Where, List<T>& _Right) {
	//typename List<T>::iterator
}

#pragma endregion

#endif // !_LIST_H_