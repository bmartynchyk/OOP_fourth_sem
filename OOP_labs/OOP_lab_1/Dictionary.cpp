/***************************************************************************************************
* File:          Dictionary.cpp
* Synopsis:      testing file for CTranslate class. In this file there are realization of functions
* for working with list container which contains CTranslate objects. These files compiled and debug
* in VS 2015. You also can freely download the source files from the link below. The version of
* uploaded files could be different.
* Author:        Bohdan Martynchyk KV-74
* Written:       31/03/2019
* Last modified: 02/04/2019
* Source:        https://github.com/bmartynchyk/OOP_fourth_sem
***************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

#include "Translate.h"
#define WSIZE 32 // Max size for words in dictionary pairs

using namespace std;


// Function for working with container list, which contains CTranslate objects
void ListAll(const list<CTranslate> &lst);
void DelByEng(list<CTranslate> &lst, const char *eng);
void DelByIta(list<CTranslate> &lst, const char *ita);
void SortByEng(list<CTranslate> &lst);
void SortByIta(list<CTranslate> &lst);
void TranslateEng(const list<CTranslate> &lst, const char *eng);
void TranslateIta(const list<CTranslate> &lst, const char *ita);


int main() {
	ifstream eng_ita("English-Italian.txt"); // Dictionary source
	list<CTranslate> lst; // Container
	CTranslate tmp; // Temporary object for filling container
	char eng[WSIZE], ital[WSIZE]; // Strings for storing english and italian words

	// Pushing to the list all pairs from file. Pairs should be plased is such way: 
	//<1st eng word>;<1st ital word>;<2nd eng word>;<2nd ital word>;<3rd ...
	while (!eng_ita.eof()) {
		
		eng_ita.getline(eng, WSIZE, ';');
		eng_ita.getline(ital, WSIZE, ';');

		tmp.MakePair(eng, ital);
		lst.push_back(tmp);
	}

	eng_ita.close();

	// Work with list container
	cout << "[Outputting full list]:\n";
	ListAll(lst);

	cout << "\n[Deleting 'lazy']:\n";
	DelByEng(lst, "lazy");
	ListAll(lst);
	
	cout << "\n[Deleting 'volpe']:\n";
	DelByIta(lst, "volpe");
	ListAll(lst);

	cout << "\n[Sort by English words]:\n";
	SortByEng(lst);
	ListAll(lst);

	cout << "\n[Sort by Italian words]:\n";
	SortByIta(lst);
	ListAll(lst);

	cout << "\n[Translate from English]:\n";
	cout << "quick - "; 
	TranslateEng(lst, "quick");
	cout << "link - ";
	TranslateEng(lst, "link");

	cout << "\n[Translate from Italian 'cane']:\n";
	cout << "cane - ";
	TranslateIta(lst, "cane");
	cout << "luna - ";
	TranslateIta(lst, "luna");

	system("pause");
}

// Outputs all pairs
void ListAll(const list<CTranslate> &lst) {
	for (auto itr : lst)
		itr.Print();
}

// Deletes element from list 'lst' by 'eng'
void DelByEng(list<CTranslate> &lst, const char *eng) {
	for (auto i = lst.begin(); i != lst.end(); i++) {
		if (0 == strcmp(eng, (*i).GetEng())) {
			lst.erase(i);
			break;
		}
	}
}

// Deletes element from list 'lst' by 'ita'
void DelByIta(list<CTranslate> &lst, const char *ita) {
	for (auto i = lst.begin(); i != lst.end(); i++) {
		if (0 == strcmp(ita, (*i).GetIta())) {
			lst.erase(i);
			break;
		}
	}
}

// Sorting by english words
void SortByEng(list<CTranslate> &lst) {
	lst.sort();
}

// Sorting by italian words
void SortByIta(list<CTranslate> &lst) {

	// Using lambda expressions to perform sorting by italian words
	lst.sort([](CTranslate &obj1, CTranslate &obj2) {
		char *str1 = obj1.GetIta(), *str2 = obj2.GetIta();

		// <0 => str2 < str1 => flase
		// 0 => str2 == str1 => false
		// >0 => str2 > str1 => true
		if (strcmp(str2, str1) > 0) return true;
		return false;
	});
}

// Finds italian translation of english word
void TranslateEng(const list<CTranslate> &lst, const char *eng) {
	for (auto i : lst)
		if (0 == strcmp(eng, i.GetEng())) {
			std::cout << i.GetIta() << std::endl;
			return;
		}

	cout << "no translation!\n";
}

// Finds english translation of italian word
void TranslateIta(const list<CTranslate> &lst, const char *ita) {
	for (auto i : lst)
		if (0 == strcmp(ita, i.GetIta())) {
			std::cout << i.GetEng() << std::endl;
			return;
		}

	cout << "nessuna traduzione!\n";
}