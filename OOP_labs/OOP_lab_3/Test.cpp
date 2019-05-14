#include "list.h"
#include "references.h"
#include <iostream>
#include <fstream>

#include <list>

#define WSIZE 32

using namespace std;

// Delete reference from list 'lst' if the number of pages less then 'page_numb'
void DeleteRef(List<References> &lst,  int page_numb) {

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
bool UploadRefFromFile(const char *path, List<References*> &lst) {
	try {
		if (0 == strlen(path)) throw "path string is empty!";

		std::ifstream file(path); // Checking the path string
		if (!file.is_open()) throw "seems like path string is incorrect!";

		//if (lst.empty()) {
		//	lst.clear();
		//	std::cout << "WARNING: list wasn't empty - old data removed and new uploaded from file!\n";
		//}

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

			List<References*>::node_type *node = new List<References*>::node_type(ref);

			lst.push_front(ref);

			cout << *ref <<"\n";
		}

		//lst.push_front();
		return true;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}



void main() {
	List<References*> list;
	List<References> trash;
	List<References> lst;

	int d1[] = { 1, 2, 34, 5 };
	int d2[] = { 3, 4, 36, 7 };
	References *ref = nullptr;

	// Copy constructor, operator ==
	//References *ref = nullptr;
	//References r1("str111", 4, d1), r2("str111", 4, d2);
	//References *r3 = nullptr;
	////*r3 = r1;
	////r1 = *r3;
	//if (r1 == *r3) cout << "TRUE\n";
	//else cout << "FALSE\n";

	ref = new References("str111", 4, d1);
	lst.push_front(*ref);
	ref = new References("str222", 4, d2);
	lst.push_front(*ref);

	ref = new References("str111", 4, d1);

	lst.remove(*ref);

	//lst.pop_front();
	//lst.pop_front();
	//lst.pop_front();

	List<References>::iterator i = lst.begin();

	//std::list<References> loo;
	//loo.push_front(*ref);

	//std::list<References>::iterator i = loo.begin();

	cout << **i << "\n";

	//ref = &(**i);

	//cout << *ref << "\n";

	system("pause");
}