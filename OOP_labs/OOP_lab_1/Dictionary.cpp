
#include <iostream>
#include <list>
#include "Translate.h"

using namespace std;


void ListAll(const list<CTranslate> &lst);
void DelByEng(list<CTranslate> &lst, const char *eng);
void DelByIta(list<CTranslate> &lst, const char *ita);
void SortByEng(list<CTranslate> &lst);
void SortByIta(list<CTranslate> &lst);
void TranslateEng(const list<CTranslate> &lst, const char *eng);
void TranslateIta(const list<CTranslate> &lst, const char *ita);

void main() {

}