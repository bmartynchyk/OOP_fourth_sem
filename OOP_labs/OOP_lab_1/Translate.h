/***************************************************************************************************
* File:          Translate.h
* Synopsis:      declaration of methods, constructors, destructors and overloaded operators of class
* CTranslate. Forms module with file Translate.cpp.
* Related files: Translate.cpp
* Author:        Bohdan Martynchyk KV-74
* Written:       31/03/2019
* Last modified: 01/04/2019
* Source:        https://github.com/bmartynchyk/OOP_fourth_sem
***************************************************************************************************/

#ifndef _TRANSLATE_H_
#define _TRANSLATE_H_

class CTranslate {

private:
	char *eng;
	char *ita;

public:
	
	// Constructors
	CTranslate();
	CTranslate(const CTranslate &);

	// Destructor
	~CTranslate();

	// Methods
	void MakePair(char *eng, char *ital);
	void Print();
	char *GetEng() const;
	char *GetIta() const;

	// Overaloaded operators
	CTranslate & operator=(const CTranslate &obj);
	bool operator<(const CTranslate &obj);
};

#endif // !_TRANSLATE_H_