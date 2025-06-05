
#include <iostream>
#include <string>

using namespace std;

template<typename T>

class SimpleVector
{
private:
	T* vec;
	int index = 0;
	int cap = 0;
public:
	SimpleVector( int size = 10) { 

		if (size <= 0) {
			cout << "크기는 양수여야 합니다." << endl;
			return;
		}

		vec = new T[size];
		cap = size;
	}
	~SimpleVector() { delete[] vec; }

	void push_back(const T& value)
	{
		if (index >= cap - 1) {
			return;
		}
		index++;
		vec[index] = value;
	}

	void pop_back()
	{
		if (index < 0 ) {
			return;
		}
		vec[index] = T();
		index--;
	}

	int size() {
		return index;
	}

	int capacity() {
		return cap;
	}

};

int main()
{
	SimpleVector<string> temp(5);

	cout << temp.size() << endl;
	cout <<  temp.capacity() << endl;

	temp.push_back("a");

	cout << temp.size() << endl;
	cout << temp.capacity() << endl;

	temp.pop_back();

	cout << temp.size() << endl;
	cout << temp.capacity() << endl;

}
