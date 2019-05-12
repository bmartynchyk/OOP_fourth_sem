
#include <iostream>
#include "iterator.h"

#ifndef _LIST_H_
#define _LIST_H_

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

	// Constructors
	List() {

	}

	// Destructors
	~List() {

	}
	
	//
	// Public methods
	//

	// Returns an iterator addressing the first element
	iterator begin() {
		return first;
	}

	// Returns an iterator that addresses the location succeeding the last element
	iterator end() {
		return last;
	}

	// Erases all the elements of a list
	void clear() {

	}

	// Tests if a list is empty
	bool empty() {
		return head;
	}

	// Returns an iterator to the first element in a list that match a specified value
	iterator find(const node_type & val);

	//Deletes the element at the beginning of a list
	void pop_front() {

	}

	// Adds an element to the beginning of a list
	void push_front(const node_type val) {

	}

	//Erases first element in a list that match a specified value
	void remove(const node_type val) {

	}

	// Returns the number of elements in a list
	int size() {

	}

	// Removes element from the target list and inserts it in first position of the argument list
	void splice(iterator _Where, List<T>& _Right) {

	}

	// Dumps list into the screen
	void Print() {

	}

private:
	node_type *head;
	iterator *first, *last;
};

#endif // !_LIST_H_