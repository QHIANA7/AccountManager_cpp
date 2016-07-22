#include "BitArrayList.h"

BitArrayList::BitArrayList(int max /*=10*/)
		//실무에서는 디폴트 매개변수의 경우 초기값을 주석으로 남김
{
	size = 0;
	this->max = max;	//this는 자신의 객체 주소를 가지고 있다.
	//arr = (char**)malloc(sizeof(char*)*max);
	arr = new void*[max];	//얘도 동적할당이다.
}


BitArrayList::~BitArrayList()
{
	//free(arr);	//malloc의 경우
	delete[] arr;		//new의 경우
	//배열인경우 [] 써줘야함
}

bool BitArrayList::pushBack(void* value)
{
	if(isOverflow())	//오버플로우 발생의 경우
		return false;
	arr[size] = value;
	size++;
	return true;
}

bool BitArrayList::isOverflow()
{
	if ((size + 1) > max)// 또는 (size >= max)
		return true;
	else
		return false;
}

bool BitArrayList::Erase(int idx)
{
	if (idx >= 0 && idx < size)
	{
		delete arr[idx];	//<= 동적메모리삭제

		for (int i = idx; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
		return true;
	}
	else
		return false;
}