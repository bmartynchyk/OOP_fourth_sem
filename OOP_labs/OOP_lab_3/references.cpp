#include "references.h" // Module
#include <iostream>
#include <algorithm>
#include <functional>

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
		std::sort(pages, pages + _size, std::greater<int>());
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return;
	}
}

// Copy constructor
References::References(const References &ref) {
	_size = ref._size;
	pages = new int[_size]; // Alocation memory
	word = _strdup(ref.word); // Copying memory
	for (int i = 0; i < _size; i++) pages[i] = ref.pages[i];
}

References::References() : _size(0), word(nullptr), pages(nullptr) { }

//References::~References() {
//	
//	//if (nullptr == word) 
//		//free(word);
//	//if (nullptr == pages) 
//		//delete[] pages;
//}

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

bool References::operator ==(References &ref) {
	try {
		bool res = true;

		if (!this) throw "'operator ==(References &ref)', calling object is NULL!";
		if (&ref == nullptr) throw "'operator ==(References &ref)', NULL as parameter!";

		if (_size == ref._size) { // If size of array the same - compare each element of array
			for (int i = 0; i < _size; i++)
				if (pages[i] != ref.pages[i])
					return false; // If only one element differs - return false
		}
		else res == false;

		return (strstr(word, ref.word) && res);
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

bool References::operator!=(References &ref) {
	try {
		if (!this) throw "'operator !=(References &ref)', calling object is NULL!";
		if (&ref == nullptr) throw "'operator !=(References &ref)', NULL as parameter!";

		return !(*this == ref);
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return false;
	}
}

References &References::operator=(References &ref) {
	try {
		if (!this) throw "'operator =(References &ref)', calling object is NULL!";
		if (&ref == nullptr) throw "'operator =(References &ref)', NULL as parameter!";

		if (this != &ref) { // If objects are different - modify this
			this->_size = ref._size;

			free(this->word); // Memory release
			delete[] pages;

			this->word = _strdup(ref.word); // Memory copying
			this->pages = new int[_size];
			for (int i = 0; i < _size; i++) pages[i] = ref.pages[i];
		}

		return *this;
	}
	catch (const char *mes) {
		std::cerr << "ERROR: " << mes << std::endl;
		return *this;
	}
}

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