#pragma once
//�迭�� �ڷᱸ���� �������� �������Ѵ�.
//int arr[10] : ���� 10�� ����	//����
//int *arr : ���� N�� ����		//�����޸𸮰���
//	arr = (int*)malloc(sizeof(int)*N); ���޸𸮿� 4*Nũ�� �Ҵ�
//int *arr[10] : ���� �ּ� 10�� ����	//����
//int **arr : ���� �ּ� N�� ����		//�����޸𸮰���
//	arr = (int**)malloc(sizeof(int*)*N); ���޸𸮿� �ּ�*Nũ�� �Ҵ�

//�ڹ��� Wrapper Ŭ������ ���� ����
//int *arr1 = new int;		//4byte, ������
//int *arr2 = new int(3);	//4byte, �ʱ�ȭ
//int *arr3 = new int[3];	//12byte, ������

//�����Ϸ��� ������ Ÿ�Ը����� ũ�⸦ �Ǵ��ؼ� �޸𸮸� �����Ѵ�.
//delete arr1;
//delete arr2;
//delete[] arr3;
//�迭���� �⺻ũ�⺸�� ������� �����Ϸ����� �迭���� �˷���� �� : []

class BitArrayList	//������ �ּҸ� N�� �������
{
	//�ڷᱸ�� �������� �迭�� 3���� �ɹ�����
	void **arr;	//�����(������ �ּҸ� N�� ������ �� �ִ� ����)
				//�迭�� ������ �������� ���尡��
				//int *arr[10] ������� 10���� �������� ���ѵ�.
				//void�����ͷ� �ٲ����ν� ��� ������ �����Ҽ� �ִ�.
				//�ٸ� ���� �θ��� ����ȯ�� ������Ѵ�.
	int max;	//������� �ִ밪
	int size;	//�������� �˾ƾ� ���� �߰��� ���� �� �ڿ� �� ���ִ�.
				//size�� �����ε� �����ְ� �ε����ε� �� �� �ִ�.
public:
	BitArrayList(int max = 10);	//����Ʈ �Ű�����
	//�⺻������ �ʱ�ȭ�� ����ο��� ���ش�. 
	~BitArrayList();
public:
	int getMax() {	return max;	}
	int getSize(){	return size;}
	void* getData(int idx)	{	return arr[idx];}
public:
	bool pushBack(void *value);
	bool Erase(int idx);
private:
	bool isOverflow();	//�߰��Ϸ��� ������ �̹� �ִ�ġ�� ���
};

