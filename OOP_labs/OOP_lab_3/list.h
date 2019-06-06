
#include <iostream>
#include <iomanip>
#include <fstream>
#include "iterator.h"

#ifndef _LIST_H_
#define _LIST_H_

#define WSIZE 32



// L I S T   C L A S S   D E C L A R A T I O N
template<class T> class List {
	struct ListNode { // Unit of list
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
	iterator find(const T &val);

	void clear(); // Erases all the elements of a list
	bool empty(); // Tests if a list is empty
	int size(); // Returns the number of elements in a list

	void pop_front(); //Deletes the element at the beginning of a list
	void push_front(const node_type val); // Adds an element to the beginning of a list
	void remove(const node_type val); // Erases first element in a list that match a specified value
	void load(const char *filename); // Uploads list items from file

	// Removes element from the target list and inserts it in first position of the argument list
	void splice(iterator _Where, List<T> &_Right);

	// Dumps list into the screen
	void Print();

private:
	node_type *head;
	iterator *first, *last;
};



// L I S T   C L A S S   I M P L E M E N T A T I O N
#pragma region List class implementation


// Constructors/Destructors
template<class T> List<T>::List() {
	first = nullptr;
	last = nullptr;
	head = nullptr;
}

template<class T> List<T>::~List() {
	clear();
}

//
// Public methods
//

// Methods for iterator
// Returns iterator on first element
template<class T>
typename List<T>::iterator List<T>::begin() {
	if (first == nullptr) { // If the container is empty
		iterator *itr = new iterator(head);
		return *itr;
	}
	return *first;
}

// Returns iterator on last element
template<class T>
typename List<T>::iterator List<T>::end() {
	if (first == nullptr) { // If the container is empty
		iterator *itr = new iterator(head);
		return *itr;
	}
	return *last;
}

// Finds first matching element
template<class T>
typename List<T>::iterator List<T>::find(const T &val) {
	node_type *ptr = head, *target = new node_type(val);
	iterator *res;

	while (ptr != nullptr) {
		if (ptr->data == target->data) break;
		ptr = ptr->next;
	}

	res = new iterator(ptr);
	return *res;
}

// Removes all elements in list
template<class T>
void List<T>::clear() {
	while (nullptr != head) pop_front();
}

// Checks if the list is empty
template<class T>
bool List<T>::empty() {
	return (head == nullptr);
}

// Adding elements to list. It is possible to push values with types 'node_type', 'T'
template<class T>
void List<T>::push_front(const node_type val) {
	try {
		if (node_type *node = new node_type(val)) {
			node->next = head;
			head = node;

			if (nullptr != first) delete first; // Iterator on first element still exists
			first = new iterator(head);

			// If it is first element, create last iterator
			if (nullptr == last) last = new iterator(head->next);
		}
		else throw "'List<T>::push_front', item didn't push to the list!";
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
	}
}

// Removing elements from list
template<class T>
void List<T>::pop_front() {
	if (!empty()) {
		node_type *tmp = head;

		head = head->next; // Deleting current element
		delete tmp; // Move head of list

		if (empty()) { // If deleted the last element
			delete first;
			delete last;
			first = nullptr;
			last = nullptr;
		}
		else {
			delete first;
			first = new iterator(head);
		}
	}
}

// Removes first required item from list
template<class T>
void List<T>::remove(const node_type val) {
	node_type *ptr = head, *tmp = nullptr;// ,
		//*target = new node_type(val);

	if (empty()) return;
	if (head->data == val.data) { // If target value is first
		pop_front(); // Modifies 'head', iterators 'first' and 'last'
		return;
	}

	while (ptr->next != nullptr) {
		if ((ptr->next)->data == val.data) {
			tmp = ptr->next; // Save target element
			ptr->next = tmp->next;

			// If removes the last element, need to modify iterator 'last'
			if (tmp->next == nullptr) {
				delete last;
				last = new iterator(ptr->next);
			}
			
			delete tmp;
			break;
		}

		ptr = ptr->next;
	}
}

// Outputs all list items
template<class T>
void List<T>::Print() {
	if (empty()) return;

	std::cout << std::endl<<std::setw(18) << std::left << " [WORD]" << " [NUMBER]"
		<< std::setw(30) << std::right <<"[PAGES]\n";
	for (node_type *i = head; i != nullptr; i = i->next) {
		i->Print();
		std::cout << std::endl;
	}
}

// Returns current size of container
template<class T>
int List<T>::size() {
	int size = 0;
	for (iterator i = begin(); i != end(); i++) size++;
	
	return size;
}

// Removes elenemt on which pointed iterator '_Where' from current list, pushes this 
//one to '_Right' list
template<class T>
void List<T>::splice(typename List<T>::iterator _Where, List<T> &_Right) {
	if (empty()) return; // If list is empty or iterator '_Where' is empty -
	if (_Where.empty()) return; //stop performing function!

	node_type *ptr = head;
	bool isPresent = false;

	// In case if method 'splice' used without 'find' method - search item in list.
	while (ptr != nullptr) {
		if (ptr->data == (*_Where).data) {
			isPresent = true;
			break;
		}

		ptr = ptr->next;
	}

	if(isPresent) { // Do actions if only the item is in the list
		_Right.push_front((*_Where).data);
		remove(*_Where);
	}
}

// Uploads items from file, for class 'References'
template<class References>
void List<References>::load(const char *filename) {
	try {
		if (0 == strlen(filename)) throw "path string is empty!";

		std::ifstream file(filename); // Checking the path string
		if (!file.is_open()) throw "seems like path string is incorrect!";

		if (!empty()) {
			clear();
			std::cerr << "WARNING: list wasn't empty - old data removed and new uploaded from file!\n";
		}

		int *pages = nullptr, num = 0, i = 0; // Declaration variables
		char *word = nullptr, str[WSIZE];
		References *ref;

		while (!file.eof()) {
			file.getline(str, WSIZE, ';'); // Getting 'word'
			word = _strdup(str);
			file.getline(str, WSIZE, ';'); // Getting 'num' of pages
			num = atoi(str);

			pages = new int[num];

			for (i = 0; i < num - 1; i++) { // Getting pages
				if (!file.getline(str, WSIZE, ';')) {
					delete[] pages; free(word); // memory release
					std::cerr << "invalid pages number, with reference: '" << word << "'!";
					return;
				}

				pages[i] = atoi(str);
			}
			file.getline(str, WSIZE, '\n');
			pages[num - 1] = atoi(str);

			ref = new References(word, num, pages);
			delete[] pages; // because of 'new' operator
			free(word); // because of '_strdup()' function

			push_front(*ref);
			delete ref;
		}

	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
	}
}

#pragma endregion

#endif // !_LIST_H_