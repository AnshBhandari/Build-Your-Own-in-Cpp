#include<iostream>
#include<stdexcept>

using namespace std;

template <typename T>
class MyVector {

private:
	T* data;
	size_t _size;
	size_t _capacity;

	void resize(size_t new_capacity) {
		T* new_data = new T[new_capacity];
		for (size_t i = 0; i < _size; ++i) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		_capacity = new_capacity;
	}

public:
	
	MyVector() : data(nullptr), _size(0), _capacity(0) {}

	~MyVector() {
		delete[] data;
	}

	void push_back(const T& value) {
		if(_capacity == _size) {
			size_t new_capacity = (_capacity == 0) ? 1 : 2 * _capacity;
			resize(new_capacity);
		}
		data[_size++] = value;
	}

	void pop_back() {
		if(_size > 0)
			--_size;
	}


/* 

const (The most important part of this syntax):

1. Placing const after the function parentheses () but before the body {} tells the compiler: "I promise this function will NOT change any member variables."

2. If you try to write _capacity = 5; inside this function, the compiler will throw an error.

*/
	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _capacity;
	}

	bool empty() const {
		return _size == 0;
	}

	T& operator[](size_t index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		// cout << "from first" << endl;
		return data[index];
	}

	const T& operator[](size_t index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		// cout << "from second" << endl;
		return data[index];
	}
};


void push_elements_with_logs (MyVector<int>& vec) {
	
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;

	vec.push_back(1);
	
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;

	vec.push_back(2);
	
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;

	vec.push_back(3);
	
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	
	vec.push_back(4);
	
	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
	
	vec.push_back(5);

	cout << "size: " << vec.size() << " capacity: " << vec.capacity() << endl;
}


void push_elements (MyVector<int>& vec) {

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

}


int main() {
	MyVector<int> v;
	
	push_elements_with_logs(v);
	
	// push_elements(v);
	
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	cout << endl;
	
	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;

	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	cout << endl;

	return 0;
}
