#include <iostream>
#include <utility>

template <class Type> 
class Point {
public:
	explicit Point(std::string name = "", Type x = 0, Type y = 0) : name_(std::move(name)), x_(x), y_(y) {}
	void show() const;
private:
	Type x_, y_;
	std::string name_;
};

template <class T> 
void Point<T>::show() const {
	std::cout << name_.data() << "(" << x_ << ", " << y_ << ")" << std::endl;
}

void f1() { std::cout << "I'm f1()." << std::endl; }
void f2() { std::cout << "I'm f1()." << std::endl; }

template <void(*pf)()>
struct F {
	void show() { pf(); }
};

int main() {

	Point<int> A("A", 10, 11);
	Point<double> B("B", 1.1, 1.2);

	Point<double>* pOtherPoint = new Point<double>("C", 9.99, 5.55);

	A.show();
	B.show();
	pOtherPoint->show();

	F<&f1> aa;
	aa.show();

	system("pause");
	return 0;
}
