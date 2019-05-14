
#include <ostream>

#ifndef _REFERENCES_H_
#define _REFERENCES_H_

class References {

private:
	char *word;
	int *pages; // Pages numbers
	int _size; // Number of pages

public:

	//
	// Constructors
	//

	References(const char *wrd, int pages_nmb, int *pages); 
	References(const References &ref); // Copy constructor
	References();

	//
	// Public methods
	//

	//
	bool SetNewWord(const char *newwrd);

	//
	bool SetNewPages(int num, int* _pages);
	
	//
	// Overloaded operators
	//

	bool operator ==(References &ref);
	bool operator !=(References &ref);
	References &operator =(References &ref);

	friend std::ostream& operator<<(std::ostream& stream, References &obj);
};

#endif // !_REFERENCES_H_