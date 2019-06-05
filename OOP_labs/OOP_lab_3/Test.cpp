#include "list.h"
#include "references.h"
#include <iostream>
#include <fstream>

#include <list>

#define WSIZE 32

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

}
void EditRef(List<References> &lst, List<References>::iterator ref, const char *newwrd) {

}

//Removes reference from 'lst' to 'trash'
void RemoveRef(List<References> &lst, List<References> &trash) {

}

// Restores reference from 'trash' to 'lst'
void RestoreRef(List<References> &lst, List<References> &trash) {

}

// Uploads references from file 'fname' to list 'lst'
bool UploadRefFromFile(const char *path, List<References> &lst) {
	try {
		if (0 == strlen(path)) throw "path string is empty!";

		std::ifstream file(path); // Checking the path string
		if (!file.is_open()) throw "seems like path string is incorrect!";

		if (!lst.empty()) {
			lst.clear();
			std::cout << "WARNING: list wasn't empty - old data removed and new uploaded from file!\n";
		}

		int *pages = nullptr, num = 0, i = 0; // Declaration variables
		char *word = nullptr, str[WSIZE];

		while (!file.eof()) {
			file.getline(str, WSIZE, ';'); // Getting 'word'
			word = _strdup(str);
			file.getline(str, WSIZE, ';'); // Getting 'num' of pages
			num = atoi(str);

			pages = new int[num];

			for (i = 0; i < num - 1; i++) {
				if (!file.getline(str, WSIZE, ';')) {
					delete[] pages; free(word); // memory release
					std::cerr << "invalid pages number, with reference: '" << word << "'!";
					return false;
				}

				pages[i] = atoi(str);
			}
			file.getline(str, WSIZE, '\n');
			pages[num - 1] = atoi(str);

			References *ref = new References(word, num, pages);
			delete[] pages; // because of 'new' operator
			free(word); // because of '_strdup()' function

			lst.push_front(*ref);
		}

		return true;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}



void main() {
	List<References> list;
	List<References> trash;
	References *ref = nullptr;

	UploadRefFromFile("Input.csv", list);
	//list.Print();

	DeleteRef(list, trash, 12);
	list.Print();

	List<References> lst, ls1;

	int d1[] = { 1, 2, 34, 5 };
	int d2[] = { 3, 4, 36, 7 };
	

	ref = new References("1", 4, d1);
	lst.push_front(*ref);
	ref = new References("2", 3, d2);
	lst.push_front(*ref);
	ref = new References("3", 2, d1);
	lst.push_front(*ref);
	ref = new References("4", 1, d1);
	lst.push_front(*ref);

	ref = new References("1", 4, d1);

	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();
	/*lst.pop_front();*/

	//auto it = lst.begin();
	//it++;
	for (auto itr = lst.begin(); itr != lst.end(); itr++) {
		std::cout << (*itr).data << std::endl;
	}
	//if (lst.end() == it) std::cout << "TRUE\n";
	//else std::cout << "FALSE\n";

	lst.find(*ref);
	
	ref = new References("5", 1, d1);
	lst.splice(lst.find(*ref), ls1);
	ls1.Print();

	//std::cout << "Size: " << lst.size() << std::endl;
	//lst.Print();
	//lst.clear();
	
	List<References>::iterator itr = lst.find(*ref);

		//lst.begin();
	 
	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();


	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();

	List<References>::iterator i = lst.begin();

	//std::list<References> loo;
	//loo.push_front(*ref);

	//std::list<References>::iterator i = loo.begin();

	// Error!! with copying constructor
	// Is it normal?
	//cout << **i << "\n";

	//ref = &(**i);

	//cout << *ref << "\n";

	system("pause");
}