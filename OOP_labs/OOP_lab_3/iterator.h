
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class _iterator {
private:
	T* ptr;

public:

	typedef T value_type;
	typedef _iterator<T> it_type;
	_iterator() { ptr = 0; }
	_iterator(T* _ptr) { ptr = _ptr; }

	T& operator *() {
		return *ptr;
	}

	void operator ++() {
		ptr = ptr->next;
	}

	// Dummy operator to keep compiler quiet
	void operator++(int) {
		ptr = ptr->next;
	}

	bool operator ==(const it_type& _iter) const {
		return (ptr == _iter.ptr);
	}

	bool operator !=(const it_type& _iter) const {
		return !(*this == _iter);
	}

	bool empty() { return ptr == NULL; }
};

#endif // !_ITERATOR_H_