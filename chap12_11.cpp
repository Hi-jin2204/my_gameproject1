#include<iostream>

//out operator는 overriding을 할 수 없음
using namespace std;

class Base
{
public:

	Base() {}

	//멤버로 사용할 수 없는 경우 오버라이딩이 안되기 때문에 기능을 위임받은 함수를 virtual로 만들어서 사용한다.
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};
int main()
{
	Base b;

	cout << b << endl;

	Derived d;

	cout << d << endl;
	
	Base& bref = d;

	cout << bref << endl;

	return 0;
}