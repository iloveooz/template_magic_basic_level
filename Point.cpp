#include <iostream>
#include <utility>

template <class Type> 
class Point {
public:
	explicit Point(Type x = 0, Type y = 0, std::string name = "") : x_(x), y_(y), name_(std::move(name)) {}
	void show() const;
private:
	Type x_, y_;
	std::string name_;
};

template <class T> 
void Point<T>::show() const {
	std::cout << name_.data() << "(" << x_ << ", " << y_ << ")" << std::endl;
}

int main() {

	Point<int> A(10, 11, "A");
	Point<double> B(1., 1., "B");

	A.show();
	B.show();

	system("pause");
	return 0;
}
