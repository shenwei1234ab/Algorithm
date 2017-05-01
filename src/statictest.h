//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include <fstream>
#ifndef _STATICTEST_H
#define _STATICTEST_H
using namespace std;

class MyLog
{
public :
	MyLog(int id,const std::string &filename):m_id(id)
	{
		//m_f.open(filename.c_str(),std::fstream::out|std::fstream::app);
		m_f.open(filename.c_str(),std::fstream::out);
	}

	void log(const std::string &info)
	{
		//std::cout<<info;
		//当mylog析构的时候才会从缓冲区写入文件
		m_f<<info;
		//m_f.flush();
	}
	~MyLog()
	{
		m_f.close();
		std::cout << "~MyLog"<< m_id<< std::endl;
	}
private:
	int m_id;
	std::fstream m_f;
};
#endif




