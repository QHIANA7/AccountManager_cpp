#pragma once
#include "BitArrayList.h"
#include <iostream>
using namespace std;

class RTHBankControl
{
	BitArrayList *mlist;//�ɹ��� ��¹迭
	BitArrayList *mlog;	//�α׸� ��¹迭
public:
	RTHBankControl();
	~RTHBankControl();
public:
	void SelectAll();
	void Insert();
	void Search();
	void UpdateAdd();
	void UpdateSub();
	void Delete();
	void LogPrint()const;
};

