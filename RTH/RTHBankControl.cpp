#include "RTHBankControl.h"
#include "RTHAccout.h"
#include "RTHLog.h"


RTHBankControl::RTHBankControl()
{
	int num;
	cout << "최대 저장개수 : ";
	cin >> num;
	mlist = new BitArrayList(num);
	mlog = new BitArrayList(100);	//로그내역 100공간 생성
}


RTHBankControl::~RTHBankControl()
{
	delete mlist;
	delete mlog;
}

void RTHBankControl::SelectAll()
{
	for (int i = 0; i < mlist->getSize(); i++)
	{		
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		p->Print();
	}
}

void RTHBankControl::Insert()
{
	char name[20];
	int accNum;

	while (getchar() != '\n');	

	cout << "이름 입력 : ";
	cin.getline(name, sizeof(name));	//cin객체의 getline함수 한줄을 입력받는다.
	cout << "계좌번호 입력 : ";
	cin >> accNum;

	RTHAccout *p = new RTHAccout(name, accNum);

	if (mlist->pushBack(p))
		cout << "계좌가 생성되었습니다." << endl;
	else
	{
		cout << "저장공간이 없습니다." << endl;
		delete p;
	}
}

void RTHBankControl::Search()
{
	char name[20];
	cout << "검색할 이름 입력 : ";
		while (getchar() != '\n');
	cin.getline(name, sizeof(name));
	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (name == p->getName())
		{
			cout << "[인덱스] " << i << endl;
			p->Print();
			return;
		}
	}
	cout << "데이터가 존재하지 않습니다." << endl;
}

void RTHBankControl::UpdateAdd()
{
	char key[20];
	cout << "수정할 이름 입력 : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (key == p->getName())
		{
			int value;

			cout << "입금액 입력 : ";
			cin >> value;
			
			if (p->addMoney(value))
			{
				cout << "입금하였습니다." << endl;
				//log저장 ============================
				tm t = RTHLog::CurrentTime();
				RTHLog *log = new RTHLog("입금", p->getName(), value,t);
				mlog->pushBack(log);
				//====================================
			}
			else
			{
				//cout << "입금하지 못했습니다." << endl;
			}
			
			return;
		}
	}
	cout << "데이터가 존재하지 않습니다." << endl;
}

void RTHBankControl::UpdateSub()
{
	char key[20];
	cout << "수정할 이름 입력 : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (key == p->getName())
		{
			int value;

			cout << "출금액 입력 : ";
			cin >> value;

			if (p->subMoney(value))
			{
				cout << "출금하였습니다." << endl;
				//log저장 ============================
				tm t = RTHLog::CurrentTime();
				RTHLog *log = new RTHLog("출금", p->getName(), value, t);
				mlog->pushBack(log);
				//====================================
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}

			return;
		}
	}
	cout << "데이터가 존재하지 않습니다." << endl;
}

void RTHBankControl::Delete()
{
	char key[20];
	cout << "삭제할 이름 입력 : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (strcmp(key, p->getName().c_str()) ==0)
		{
			mlist->Erase(i);
			cout << "계좌가 삭제되었습니다." << endl;
			return;
		}
	}
	cout << "해당 계좌가 존재하지 않습니다." << endl;
}

void RTHBankControl::LogPrint() const
{
	for (int i = 0; i < mlog->getSize(); i++)
	{
		RTHLog *p = (RTHLog*)mlog->getData(i);
		p->Print();
	}
}
