
#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

template<typename T>

class SimpleVector
{
private:
	
	int index = 0;
	int cap = 0;

public:
	T* vec;

	SimpleVector( int size = 10) { 

		if (size <= 0) {
			cout << "크기는 양수여야 합니다." << endl;
			return;
		}
		vec = new T[size];
		cap = size;
	}

	SimpleVector(const SimpleVector& svector) {
		vec = svector.vec;
	}


	~SimpleVector() { delete[] vec; }

	void push_back(const T& value)
	{
		if (index >= cap - 1) {

			T* temp = vec;
			vec = new T[index + 5];

			for (int i = 0; i < index; i++) {
				vec[i] = temp[i];
			}

			cap += 5;

			push_back(value);

			delete []temp;
			
			return;
		}

		vec[index] = value;
		cout << vec[index] <<endl;
		index++;
	}

	void pop_back()
	{
		if (index < 0 ) {
			return;
		}
		vec[index] = T();
		index--;
	}

	void resize(int size) 
	{
		if (size > cap - 1) {

			T* temp = vec;
			vec = new T[size];

			for (int i = 0; i < index; i++) {
				vec[i] = temp[i];
			}

			size = cap;

			delete[]temp;
		}
	}

	void sortData()
	{

		sort(vec, vec + index);
	}

	int size() {
		return index;
	}

	int capacity() {
		return cap;
	}

	void print() {
		for (int i = 0; i < index; i++) {
			cout << vec[i] << endl;
		}
	}

};

int main()
{
	SimpleVector<int> temp(5);

	for(int i = 6; i > 0; i--) {
		temp.push_back(i);
		//cout << temp.vec[i] << endl;
		//cout << temp.capacity();
	}

	temp.sortData();

	temp.print();

	cout << "현재 cap " << temp.capacity() << endl;
}
