#ifndef SPARSE_ARR_H
#define SPARSE_ARR_H
#include <list>

template <class DataT> 
class SA_item {
public:
	SA_item() : index(-1), info(DataT()) {}
	SA_item(long i, DataT d) : index(i), info(d) {}
	long index;
	DataT info;
};

template <class T> 
class SparseArr {
public:
	SparseArr(long len) : length(len) {}
	T& operator [] (long ind);
	void Show(const char*);
private:
	std::list<SA_item<T>> arr;
	long length;
};

template <class T>
void SparseArr<T>::Show(const char* title) {
	std::cout << "===== " << title << " =====\n";
	
	std::list<SA_item<T>>::iterator i = arr.begin();
	std::list<SA_item<T>>::iterator n = arr.end();
	
	for (i; i != n; ++i)
		std::cout << i->index << "\t" << i->info << std::endl;
};

template <class T>
T& SparseArr<T>::operator [] (long ind) {
	if ((ind < 0) || (ind > length - 1)) {
		std::cerr << "Error of index: " << ind << std::endl;
		SA_item<T> temp;
		return temp.info;
	}

	std::list<SA_item<T>>::iterator i = arr.begin();
	std::list<SA_item<T>>::iterator n = arr.end();

	for (i; i != n; ++i)
		if (ind == i->index)
			return i->info; // элемент найден
	// Элемент не найден, создаем новый элемент
	arr.push_back(SA_item<T>(ind, T()));
	i = arr.end();
	return (--i)->info;
};

#endif /* SPARSE_ARR_H */

#include <iostream>
#include <string>
#include "SparseArr.h"

int main() {
	SparseArr<double> sal(2000000);
	sal[127649] =1.1;
	sal[38225] = 1.2;
	sal[2004056] = 1.3;
	sal[1999999] = 1.4;

	sal.Show("sal");

	std::cout << "sal[38225] = " << sal[38225] << std::endl;
	sal[38225] = sal[93];
	
	std::cout << "After the modification of sal:\n";
	sal.Show("sal");
	
	SparseArr<std::string> sa2(1000);
	sa2[333] = "Nick";
	sa2[222] = "Peter";
	
	sa2[444] = "Ann";
	sa2.Show("sa2");

	sa2[222] = sa2[555];
	sa2.Show("sa2");

	system("pause");
	return 0;
}
