#pragma once
//배열을 자료구조의 관점에서 보려고한다.
//int arr[10] : 정수 10개 저장	//정적
//int *arr : 정수 N개 저장		//동적메모리개념
//	arr = (int*)malloc(sizeof(int)*N); 힙메모리에 4*N크기 할당
//int *arr[10] : 정수 주소 10개 저장	//정적
//int **arr : 정수 주소 N개 저장		//동적메모리개념
//	arr = (int**)malloc(sizeof(int*)*N); 힙메모리에 주소*N크기 할당

//자바의 Wrapper 클래스와 같은 개념
//int *arr1 = new int;		//4byte, 쓰레기
//int *arr2 = new int(3);	//4byte, 초기화
//int *arr3 = new int[3];	//12byte, 쓰레기

//컴파일러는 변수의 타입만으로 크기를 판단해서 메모리를 해제한다.
//delete arr1;
//delete arr2;
//delete[] arr3;
//배열같이 기본크기보다 높은경우 컴파일러에게 배열임을 알려줘야 함 : []

class BitArrayList	//변수의 주소를 N개 저장관리
{
	//자료구조 관점에서 배열은 3개의 맴버변수
	void **arr;	//저장소(문자의 주소를 N개 저장할 수 있는 공간)
				//배열을 임의의 개수까지 저장가능
				//int *arr[10] 같은경우 10개가 정적으로 제한됨.
				//void포인터로 바뀜으로써 모든 변수에 대응할수 있다.
				//다만 값을 부를때 형변환을 해줘야한다.
	int max;	//저장소의 최대값
	int size;	//마지막을 알아야 다음 추가할 값이 그 뒤에 올 수있다.
				//size는 갯수로도 볼수있고 인덱스로도 볼 수 있다.
public:
	BitArrayList(int max = 10);	//디폴트 매개변수
	//기본적으로 초기화를 선언부에서 해준다. 
	~BitArrayList();
public:
	int getMax() {	return max;	}
	int getSize(){	return size;}
	void* getData(int idx)	{	return arr[idx];}
public:
	bool pushBack(void *value);
	bool Erase(int idx);
private:
	bool isOverflow();	//추가하려고 하지만 이미 최대치일 경우
};

