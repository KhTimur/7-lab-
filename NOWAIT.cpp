// ConsoleApplication20.cpp: определяет точку входа для консольного приложения.
//NOSYNC

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <thread>
using namespace std;

void f1(){
	for (int i = 1; i <= 100; i++)
	{
		std::cout << 'a';
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
void f2(){
	for (int i = 0; i < 100; i++)
	{
		std::cout << 'b';
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread t1(f1);
	f2();
	t1.join();
	system("pause");
	return 0;
}

