#include "list.h"
#include "references.h"
#include <iostream>

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
void UploadRefFromFile(char *fname, List<References> &lst) {

}

void main() {
	List<References> list;
	List<References> trash;

	system("pause");
}