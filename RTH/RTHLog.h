#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class RTHLog
{
	string fnType;	//�Ա� or ���
	string name;	//�����̸�
	int value;	//����ݿ�û��
	tm t;	//	����ݽð�
public:
	RTHLog();
	RTHLog(string _fnType, string _name, int _value, tm _t);
	~RTHLog();
public:
	static tm CurrentTime();
	void Print()const;
};

