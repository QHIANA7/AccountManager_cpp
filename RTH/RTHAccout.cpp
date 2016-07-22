#include "RTHAccout.h"


RTHAccout::RTHAccout(string _name, int _accNum, int _balance)
	:name(_name), accNum(_accNum), balance(_balance/*=0*/)
{
}

RTHAccout::~RTHAccout()
{
}

bool RTHAccout::addMoney(int value)
{
	if (value >= 0)
	{
		balance += value;
		return true;
	}
	else
		return false;
}

bool RTHAccout::subMoney(int value)
{
	if (value > balance)
	{
		
		return false;
	}
	else
	{
		balance -= value;
		return true;
	}

}

void RTHAccout::Print() const
{
	printf("[�̸�] %-10s [���¹�ȣ] %-10d [�ܾ�] %-10d\n", name.c_str(), accNum, balance);
}

