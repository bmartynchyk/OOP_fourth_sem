#include "references.h" // Module
#include <iostream>

//
// Constructors
//

// Creates reference with word 'wrd' and pages on which the word is mentioned
References::References(const char *wrd, int pages_nmb, int *_pages): _size(pages_nmb) {
	try {
		if (nullptr == wrd || strlen(wrd) == 0) throw "invalid parameter 'wrd'!\n";
		if (_pages == nullptr) throw "invalid parameter '_pages'!\n";
		if (0 >= pages_nmb) throw "invalid parameter 'pages_nmb'!\n";

		pages = new int[_size]; // Alocation memory

		word = _strdup(wrd); // Copying memory
		for (int i = 0; i < _size; i++) pages[i] = _pages[i];
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return;
	}
}

//
// Public methods
//

// Replaces 'word' value by new value 'newwrd'
bool References::SetNewWord(const char *newwrd) {
	try {
		if (strlen(newwrd) == 0) throw "invalid parameter 'newwrd'!";

		if (nullptr != word) delete word;
		word = _strdup(newwrd);

		return true;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

//
bool References::SetNewPages(int num, int* _pages) {
	try {
		if (0 == num) throw "invalid parameter 'newwrd'!";

		if (nullptr != pages) delete pages;

		//if (nullptr != word) delete word;
		//word = _strdup(newwrd);

		return true;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

//
// Overloaded operators
//

std::ostream &operator<<(std::ostream & stream, References & obj)  {
	try {
		if (nullptr == obj.word) throw "invalid field 'word' in parameter 'obj'!";

		stream << "Word: " << obj.word << "; " << obj._size << " pages: ";
		for (int i = 0; i < obj._size; i++)
			if (i == obj._size - 1) stream << obj.pages[i] << ";";
			else stream << obj.pages[i] << ", ";

		return stream;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		stream << "";
		return stream;
	}
}