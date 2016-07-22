#include "RTHBankControl.h"
#include "RTHAccout.h"
#include "RTHLog.h"


RTHBankControl::RTHBankControl()
{
	int num;
	cout << "�ִ� ���尳�� : ";
	cin >> num;
	mlist = new BitArrayList(num);
	mlog = new BitArrayList(100);	//�α׳��� 100���� ����
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

	cout << "�̸� �Է� : ";
	cin.getline(name, sizeof(name));	//cin��ü�� getline�Լ� ������ �Է¹޴´�.
	cout << "���¹�ȣ �Է� : ";
	cin >> accNum;

	RTHAccout *p = new RTHAccout(name, accNum);

	if (mlist->pushBack(p))
		cout << "���°� �����Ǿ����ϴ�." << endl;
	else
	{
		cout << "��������� �����ϴ�." << endl;
		delete p;
	}
}

void RTHBankControl::Search()
{
	char name[20];
	cout << "�˻��� �̸� �Է� : ";
		while (getchar() != '\n');
	cin.getline(name, sizeof(name));
	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (name == p->getName())
		{
			cout << "[�ε���] " << i << endl;
			p->Print();
			return;
		}
	}
	cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
}

void RTHBankControl::UpdateAdd()
{
	char key[20];
	cout << "������ �̸� �Է� : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (key == p->getName())
		{
			int value;

			cout << "�Աݾ� �Է� : ";
			cin >> value;
			
			if (p->addMoney(value))
			{
				cout << "�Ա��Ͽ����ϴ�." << endl;
				//log���� ============================
				tm t = RTHLog::CurrentTime();
				RTHLog *log = new RTHLog("�Ա�", p->getName(), value,t);
				mlog->pushBack(log);
				//====================================
			}
			else
			{
				//cout << "�Ա����� ���߽��ϴ�." << endl;
			}
			
			return;
		}
	}
	cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
}

void RTHBankControl::UpdateSub()
{
	char key[20];
	cout << "������ �̸� �Է� : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (key == p->getName())
		{
			int value;

			cout << "��ݾ� �Է� : ";
			cin >> value;

			if (p->subMoney(value))
			{
				cout << "����Ͽ����ϴ�." << endl;
				//log���� ============================
				tm t = RTHLog::CurrentTime();
				RTHLog *log = new RTHLog("���", p->getName(), value, t);
				mlog->pushBack(log);
				//====================================
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
			}

			return;
		}
	}
	cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
}

void RTHBankControl::Delete()
{
	char key[20];
	cout << "������ �̸� �Է� : ";
	while (getchar() != '\n');
	cin.getline(key, sizeof(key));

	for (int i = 0; i < mlist->getSize(); i++)
	{
		RTHAccout *p = (RTHAccout*)mlist->getData(i);
		if (strcmp(key, p->getName().c_str()) ==0)
		{
			mlist->Erase(i);
			cout << "���°� �����Ǿ����ϴ�." << endl;
			return;
		}
	}
	cout << "�ش� ���°� �������� �ʽ��ϴ�." << endl;
}

void RTHBankControl::LogPrint() const
{
	for (int i = 0; i < mlog->getSize(); i++)
	{
		RTHLog *p = (RTHLog*)mlog->getData(i);
		p->Print();
	}
}
