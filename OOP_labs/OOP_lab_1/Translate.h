
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
	void MakePair(char *, char *);
	void Print();
	char *GetEng() const;
	char *GetIta() const;

	// Overaloaded operators
	CTranslate & operator=(const CTranslate &);
	bool operator<(const CTranslate &);

};

#endif // !_TRANSLATE_H_