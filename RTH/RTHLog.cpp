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
	time_t timer;	//미리정의된 구조체이기때문에 struct를 쓸 필요가없다.
	timer = time(NULL);	//시분초가 오로지 초단위로 구성되어있다.

	tm t;
	localtime_s(&t, &timer);

	return t;
}

void RTHLog::Print() const
{
	char temp[20];
	sprintf_s(temp, "%02d:%02d:%02d", t.tm_hour, t.tm_min, t.tm_sec);	// %02가능
	printf("[유형] %-5s [사용자] %-15s [금액] %10d\\ [시간] %-10s\n", fnType.c_str(), name.c_str(), value, temp);
}
