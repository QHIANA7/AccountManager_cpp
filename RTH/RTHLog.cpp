#include "RTHLog.h"



RTHLog::RTHLog()
{
}

RTHLog::RTHLog(string _fnType, string _name, int _value, tm _t)
	:fnType(_fnType),name(_name),value(_value),t(_t)
{
}


RTHLog::~RTHLog()
{
}

tm RTHLog::CurrentTime()
{
	time_t timer;	//�̸����ǵ� ����ü�̱⶧���� struct�� �� �ʿ䰡����.
	timer = time(NULL);	//�ú��ʰ� ������ �ʴ����� �����Ǿ��ִ�.

	tm t;
	localtime_s(&t, &timer);

	return t;
}

void RTHLog::Print() const
{
	char temp[20];
	sprintf_s(temp, "%02d:%02d:%02d", t.tm_hour, t.tm_min, t.tm_sec);	// %02����
	printf("[����] %-5s [�����] %-15s [�ݾ�] %10d\\ [�ð�] %-10s\n", fnType.c_str(), name.c_str(), value, temp);
}
