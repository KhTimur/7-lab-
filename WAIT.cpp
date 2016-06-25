// ConsoleApplication21.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mute;
condition_variable cv;

void f1()
{

	for (int i = 1; i < 100; i++)
	{
		cout << 'a' << "  ";;
		this_thread::sleep_for(chrono::milliseconds(100));
		if (i == 51)
			cv.notify_one();
	}
}

void f2()
{
	for (int i = 0; i < 100; i++)
	{
			cout << 'b' << "  ";
			this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	unique_lock<mutex> q(mute);
	thread t1(f1);
	cv.wait(q);
	thread t2(f2);
	t1.join();
	t2.join();
	system("pause");
	return 0;
}

