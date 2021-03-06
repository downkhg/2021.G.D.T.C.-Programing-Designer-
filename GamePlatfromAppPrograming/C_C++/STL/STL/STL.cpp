#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>

//using namespace std;
#include"DynamicArray.h"
#include"LinkedList.h"
//#include"QueueList.h"
//#include"StackArray.h"
#include"QueueList.h"
//using namespace demo;
using namespace std;

//자료구조라이브러
//벡터: 동적배열 <-> List(컬랙션) 동영상플레이어
//1.벡터의 크기를 1로 만들고, 첫번째값에 10을 초기화하고 출력.
//2.크기를 3으로만들고 출력
//3.추가: 데이터를 추가
//4.삽입: 중간에 데이터를 추가
//5.삭제,모두삭제
//6.위 알고리즘을 모두 정상작동확인하기.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
	container.resize(3);
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
	container.push_back(99);
	vector<int>::iterator it = container.begin();//반복자
	container.insert(it+2, 88);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = container.end();
	container.erase(it-2);
	container.pop_back();
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//리스트: 이중연결리스트 <-> LinkedList(컬럭션) 비디오테이프
void ListMain()
{
	list<int> container(1);
	list<int>::iterator it = container.begin();//반복자
	*it = 10;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.resize(3);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.push_back(99);
	it = container.begin();//반복자
	it++; it++;//연결리스트이므로 순서대로 원하는 값에 접근해야한다.
	container.insert(it, 88);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = container.end();
	it--; it--;
	container.erase(it);
	container.pop_back();
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//큐: 후입선출
//문자열을 순서대로 넣고, 순서대로 큐에 내용을 넣는다.
void QuequeMain()
{
	char strName[] = "GDTC2021-1";
	queue<char> queString;
	cout << "Origin:" << strName << endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		cout << cData << endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.front();
		queString.pop();
		pStr++;
	}
	cout << "Result:"<< strName << endl;
}
//스택: 후입후출
//문자열을 차례로 넣고, 뒤에서 꺼낸다.(뒤집기)
void StackMain()
{
	char strName[] = "GDTC2021-1";
	stack<char> queString;
	cout << "Origin:" << strName << endl;
	char* pStr = strName;
	while (*pStr != '\0')
	{
		char cData = *pStr;
		queString.push(cData);
		cout << cData << endl;
		pStr++;
	}
	pStr = strName;
	while (!queString.empty())
	{
		*pStr = queString.top();
		queString.pop();
		pStr++;
	}
	cout << "Result:" << strName << endl;
}

void main()
{
	//VectorMain();
	//demo::VectorSampleTestMain();
	//demo::VectorMain();
	//demo::ListMain();
	//demo::ListTestMain();
	//ListMain();
	//QuequeMain();
	//StackMain();
	//demo::StackMain();
	demo::QuequeMain();
}