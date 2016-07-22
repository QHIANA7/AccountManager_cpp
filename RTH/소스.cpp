#include <iostream>
#include "RTHBankControl.h"
using namespace std;

int main()
{
	{
		RTHBankControl *con = new RTHBankControl();
		int num;
		while (true)
		{
			system("cls");
			con->SelectAll();
			cout << "\n========================================================================" << endl;
			cout << "[1] 생성 [2] 조회 [3] 수정(입금) [4] 수정(출금) [5] 삭제 [6]로그 [7]종료" << endl;
			cout << "========================================================================" << endl;
			cin >> num;
			switch (num)
			{
			case 1: con->Insert();	 break;
			case 2: con->Search();	 break;
			case 3: con->UpdateAdd();break;
			case 4: con->UpdateSub();break;
			case 5: con->Delete();	 break;
			case 6: con->LogPrint(); break;
			case 7: return 0;
			}
			system("pause");

		}
		delete con;
	}

	return 0;
}
