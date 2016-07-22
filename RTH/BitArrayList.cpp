#include "BitArrayList.h"

BitArrayList::BitArrayList(int max /*=10*/)
		//�ǹ������� ����Ʈ �Ű������� ��� �ʱⰪ�� �ּ����� ����
{
	size = 0;
	this->max = max;	//this�� �ڽ��� ��ü �ּҸ� ������ �ִ�.
	//arr = (char**)malloc(sizeof(char*)*max);
	arr = new void*[max];	//�굵 �����Ҵ��̴�.
}


BitArrayList::~BitArrayList()
{
	//free(arr);	//malloc�� ���
	delete[] arr;		//new�� ���
	//�迭�ΰ�� [] �������
}

bool BitArrayList::pushBack(void* value)
{
	if(isOverflow())	//�����÷ο� �߻��� ���
		return false;
	arr[size] = value;
	size++;
	return true;
}

bool BitArrayList::isOverflow()
{
	if ((size + 1) > max)// �Ǵ� (size >= max)
		return true;
	else
		return false;
}

bool BitArrayList::Erase(int idx)
{
	if (idx >= 0 && idx < size)
	{
		delete arr[idx];	//<= �����޸𸮻���

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