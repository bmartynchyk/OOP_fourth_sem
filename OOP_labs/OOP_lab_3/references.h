
#include <ostream>

#ifndef _REFERENCES_H_
#define _REFERENCES_H_

class References {

private:
	char *word;
	int *pages;//pages numbers
	int _size;//number of pages

public:

	// Constructor 
	References();

	/*
	methods
	*/
	friend std::ostream& operator<<(std::ostream& stream, References &obj);
};

#endif // !_REFERENCES_H_