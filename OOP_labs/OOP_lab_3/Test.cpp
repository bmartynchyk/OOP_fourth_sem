#include "list.h"
#include "references.h"
#include <iostream>
#include <fstream>

#include <list>



using namespace std;

// Delete reference from list 'lst' if the number of pages less then 'page_numb'
void DeleteRef(List<References> &lst, List<References> &trash, int page_numb) {
	try {
		List<References> tmp;

		if (lst.empty()) throw "list was empty, func 'DeleteRef()'!";

		for (auto itr = lst.begin(); itr != lst.end(); itr++) // Saving matching items to a temporary list 'tmp'
			if ((*itr).data < page_numb) tmp.push_front(*itr);

		for (auto itr = tmp.begin(); itr != tmp.end(); itr++) // Moving elements to trash-list
			lst.splice(tmp.find((*itr).data), trash);
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return;
	}
}

// Edit word in reference from reference list 'lst'. Replaces word 'wrd' by 'newwrd'
void EditRef(List<References> &lst, const char *wrd, const char *newwrd) {
	auto itr = lst.begin();

	while (itr != lst.end()) {
		if ((*itr).data == wrd) {
			(*itr).data.SetNewWord(newwrd);
			break;
		}
		itr++;
	}
}



void main() {
	List<References> list;
	List<References> trash;
	References *ref = nullptr;

	list.load("Input.csv"); // Uploads values from file
	list.Print(); // Outputs values
	cout << endl;

	DeleteRef(list, trash, 12); // Remove all values less then 12
	list.Print();

	cout << endl;
	EditRef(list, "offset", "Overloaded"); // Edit reference with word "offset"
	list.Print();

	int arr1[] = { 1, 2, 34, 5 }, arr2[] = { 3, 4, 36 }, arr3[] = {34, 135, 230, 341, 342};
	

	cout << endl;
	ref = new References("Encapsulation", 4, arr1); // Pushing into list new references
	list.push_front(*ref);
	ref = new References("Ploymorphism", 3, arr2);
	list.push_front(*ref);
	ref = new References("Recursion", 5, arr3);
	list.push_front(*ref);
	ref = new References("Aggregation", 3, arr2);
	list.push_front(*ref);
	list.Print();

	cout << endl;
	list.pop_front(); // Deleting 2 front elements from list
	list.pop_front();
	list.Print();

	system("pause");
}