#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class RTHLog
{
	string fnType;	//입금 or 출금
	string name;	//계좌이름
	int value;	//입출금요청액
	tm t;	//	입출금시간
public:
	RTHLog();
	RTHLog(string _fnType, string _name, int _value, tm _t);
	~RTHLog();
public:
	static tm CurrentTime();
	void Print()const;
};

