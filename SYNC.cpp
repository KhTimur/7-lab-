// SYNC.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mute;

void f1()
{

	for (int i = 1; i < 100; i++)
	{
		int k = 0;
		this_thread::sleep_for(chrono::milliseconds(100));
		lock_guard<mutex> guard(mute);
		while (k < 4)
		{
			cout << 'a' << "  ";
			this_thread::sleep_for(chrono::milliseconds(100));
			k++;
			if (k == 1)
				i++;
		}
	}
}

void f2()
{
	for (int i = 1; i < 100; i++)
	{
		int k = 0;
		this_thread::sleep_for(chrono::milliseconds(100));
		lock_guard<mutex> guard(mute);
		while (k < 4)
		{
			cout << 'b' << "  ";
			this_thread::sleep_for(chrono::milliseconds(100));
			k++;
			if (k == 1)
				i++;
		}
	}
}

int main()
{
	thread t1(f1);
	thread t2(f2);
	t1.join();
	t2.join();
	system("pause");
	return 0;
}


