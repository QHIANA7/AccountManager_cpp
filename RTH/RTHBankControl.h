#pragma once
#include "BitArrayList.h"
#include <iostream>
using namespace std;

class RTHBankControl
{
	BitArrayList *mlist;//맴버를 담는배열
	BitArrayList *mlog;	//로그를 담는배열
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

