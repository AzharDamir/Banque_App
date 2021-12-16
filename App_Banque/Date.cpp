#include "pch.h"
#include "Date.h"
#include <ctime>
#include <iostream>
using namespace std;
using namespace Banque;
Banque::Date::Date()
{

	time_t t = time(0);
	tm* now = new tm();
	localtime_s(now, &t);
	this->h = now->tm_hour;
	this->m = now->tm_min;
	this->s = now->tm_sec;
	this->j = now->tm_mday;
	this->mo = now->tm_mon;
	this->a = now->tm_year;
}

void Banque::Date::afficher()
{
	cout << this->h << ":" << this->m << ": " << this->s << endl;
	cout << this->j << " /" << this->mo << " /" << this->a << "|| ";
}
