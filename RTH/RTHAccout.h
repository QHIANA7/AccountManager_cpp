#pragma once
#include <iostream>
using namespace std;

class RTHAccout
{
	string name;
	int accNum;
	int balance;
public:
	RTHAccout(string _name, int _accNum, int _balance = 0);
	~RTHAccout();
public:
	string getName()const { return name; }
	int getAccNum()const { return accNum; }
	int getBalance()const { return balance; }
public:
	bool addMoney(int value);
	bool subMoney(int value);
	void Print()const;
};