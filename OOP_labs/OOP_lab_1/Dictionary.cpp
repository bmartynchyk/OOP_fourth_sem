
#include <iostream>
#include <fstream>
#include <list>

#include "Translate.h"
#define WSIZE 32

using namespace std;


void ListAll(const list<CTranslate> &lst);
void DelByEng(list<CTranslate> &lst, const char *eng);
void DelByIta(list<CTranslate> &lst, const char *ita);
void SortByEng(list<CTranslate> &lst);
void SortByIta(list<CTranslate> &lst);
void TranslateEng(const list<CTranslate> &lst, const char *eng);
void TranslateIta(const list<CTranslate> &lst, const char *ita);

int main() {
	ifstream eng_ita("English-Italian.txt");
	list<CTranslate> lst;
	CTranslate tmp;
	char eng[WSIZE], ital[WSIZE];

	// Pushing to the list all pairs from file. Pairs should be plased is such way: 
	//<1st eng word>;<1st ital word>;<2nd eng word>;<2nd ital word>;<3rd ...
	while (!eng_ita.eof()) {
		
		eng_ita.getline(eng, WSIZE, ';');
		eng_ita.getline(ital, WSIZE, ';');

		tmp.MakePair(eng, ital);
		cout << eng << " - " << ital << endl;

		lst.push_back(tmp);
	}

	eng_ita.close();
	system("pause");
}