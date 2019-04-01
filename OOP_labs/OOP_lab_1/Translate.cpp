#define _CRT_SECURE_NO_WARNINGS

#include "Translate.h"
#include <iostream>

// Constructors
CTranslate::CTranslate() {
	eng = NULL;
	ita = NULL;
}

CTranslate::CTranslate(const CTranslate &obj) {
	this->eng = new char[strlen(obj.eng) + 1];
	strcpy(this->eng, obj.eng);

	this->ita = new char[strlen(obj.ita) + 1];
	strcpy(this->ita, obj.ita);
}

// Destructor
CTranslate::~CTranslate() {
	if (NULL != eng) delete[] this->eng;
	if (NULL != ita) delete[] this->ita;
}


// Public methods

char *CTranslate::GetEng() const {
	return eng;
}

char *CTranslate::GetIta() const {
	return ita;
}

void CTranslate::Print() {
	std::cout << eng << " - " << ita << std::endl;
}

void CTranslate::MakePair(char *eng, char *ita) {
	if (NULL != this->eng) delete[] this->eng;
	this->eng = new char[strlen(eng) + 1];
	strcpy(this->eng, eng);

	if (NULL != this->ita) delete[] this->ita;
	this->ita = new char[strlen(ita) + 1];
	strcpy(this->ita, ita);
}

// Overloaded operators
//!!
CTranslate & CTranslate::operator=(const CTranslate &obj) {
	if (NULL != this->eng) delete[] this->eng;
	this->eng = new char[strlen(obj.eng) + 1];
	strcpy(this->eng, obj.eng);

	if (NULL != this->ita) delete[] this->ita;
	this->ita = new char[strlen(obj.ita) + 1];
	strcpy(this->ita, obj.ita);

	return *this;
}

//!!
bool CTranslate::operator<(const CTranslate &obj) {
	return (bool)strcmp(this->eng, obj.eng);
}