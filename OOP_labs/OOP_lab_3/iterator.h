
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

// _ I T E R A T O R   C L A S S   D E C L A R A T I O N
template <class T> class _iterator {
private:
	T* ptr;

public:

	typedef T value_type;
	typedef _iterator<T> it_type;

	// Constructors
	_iterator() { ptr = 0; }
	_iterator(T* _ptr) { ptr = _ptr; }

	// Operators
	T& operator *();
	void operator++();
	void operator++(int); // Dummy operator to keep compiler quiet
	bool operator ==(const it_type& _iter) const;
	bool operator !=(const it_type& _iter) const;

	// Methods
	bool empty();
};


// _ I T E R A T O R   C L A S S   I M P L E M E N T A T I O N
#pragma region _iterator class implementation

// Public methods
template <class T>
bool _iterator<T>::empty() {
	return ptr == NULL;
}

// Operators
template <class T>
void _iterator<T>::operator++() {
	ptr = ptr->next;
}
template <class T>
T& _iterator<T>::operator*() {
	return *ptr;
}
template <class T>
void _iterator<T>::operator++(int) {
	ptr = ptr->next;
}
template <class T>
bool _iterator<T>::operator==(const it_type& _iter) const {
	return (ptr == _iter.ptr);
}
template <class T>
bool _iterator<T>::operator!=(const it_type& _iter) const {
	return !(*this == _iter);
}

#pragma endregion

#endif // !_ITERATOR_H_