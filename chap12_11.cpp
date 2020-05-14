#include<iostream>

//out operator�� overriding�� �� �� ����
using namespace std;

class Base
{
public:

	Base() {}

	//����� ����� �� ���� ��� �������̵��� �ȵǱ� ������ ����� ���ӹ��� �Լ��� virtual�� ���� ����Ѵ�.
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