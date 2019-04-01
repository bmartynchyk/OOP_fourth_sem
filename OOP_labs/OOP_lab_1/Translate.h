
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