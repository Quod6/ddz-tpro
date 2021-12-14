#include <iostream>

using namespace std;

class Foo
{
private:
	const int a;
	const int b;

public:
	Foo(int a, int b) : a(a), b(b) {}

	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}
};

int main()
{
	Foo A(2, 5);
	Foo B(3, 5);
	cout << A.getA() << endl;
	cout << B.getA() << endl;

}
