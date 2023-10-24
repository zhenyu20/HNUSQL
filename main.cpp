
#include <iostream>
#include <string>
#include "Interpreter.h"
#include "base.h"
#include "BufferManager.h"
#include "RecordManager.h"
using namespace std;

BufferManager bf;
extern int Number;

//加密 
void encryption(string& c, int a[]) {
	for (int i = 0, j = 0; c[j]; j++, i = (i + 1) % 7) {
		if (c[j] == ' ') {
			j++;
		}
		c[j] += a[i];
		if (c[j] > 122) c[j] -= 90;
	}
}
int main() {
	int a[] = { 4, 9, 6, 2, 8, 7, 3 };
	int re = 1;
	InterManager itp;
	cout << "please enter your ID and password:" << endl;
	string user;//用户名密码输入 
	getline(cin, user);
	//encryption(user, a);//加密 
	ifstream test("../Debug/USER.txt", ios::in);//与文件内容对应 
	string str;
	getline(test, str);//按行读文件 
	test.close();
	if (user == str)
	{
		cout << "welcome!" << endl;
		char c = 'N';
		if (c == 'Y')
		{
			cout << "please enter new ID and password:" << endl;
			string nua;
			cin.ignore();
			getline(cin, nua);
			encryption(nua, a);//加密 

			ofstream fuser("../Debug/USER.txt");
			fuser << nua << endl;
			fuser.close();
			cout << "successful change!" << endl;
			cout << "please enter your order:" << endl;
			while (re)
			{
				try {
					cout << "HNUSQL >";
					itp.GetQs();
					re = itp.EXEC();
				}
				catch (TableException te) {
					cout << te.what() << endl;
				}
				catch (QueryException qe) {
					cout << qe.what() << endl;
				}
			}
		}
		else if (c == 'N')
		{
			cout << "please enter your order:" << endl;
			while (re)
			{

				try {
					cout << "HNUSQL >";
					itp.GetQs();
					re = itp.EXEC();
				}
				catch (TableException te) {
					cout << te.what() << endl;
				}
				catch (QueryException qe) {
					cout << qe.what() << endl;
				}
			}
		}
	}
	else
	{
		cout << "login fail! " << endl;
		cout << "please enter your ID and password again(the final chance):" << endl;
		string usera;//用户名密码输入 

		getline(cin, usera);

		if (usera == str) //与文件内容对应 
		{
			cout << "welcome!" << endl;
			cout << "if you want to change the ID and password (Y/N)?" << endl;
			char ca;
			cin >> ca;
			if (ca == 'Y')
			{
				cout << "please enter new ID and password:" << endl;
				string nua;
				cin.ignore();
				getline(cin, nua);
				ofstream fusera("../Debug/USER.txt");
				fusera << nua << endl;
				fusera.close();
				cout << "successful change!" << endl;
				cout << "please enter your order:" << endl;
				while (re)
				{
					try {
						cout << "HnuSQL >";
						itp.GetQs();
						re = itp.EXEC();
					}
					catch (TableException te) {
						cout << te.what() << endl;
					}
					catch (QueryException qe) {
						cout << qe.what() << endl;
					}
				}
			}
			else if (ca == 'N')
			{
				cout << "please enter your order:" << endl;
				while (re)
				{

					try {
						cout << "HNUSQL >";
						itp.GetQs();
						re = itp.EXEC();
					}
					catch (TableException te) {
						cout << te.what() << endl;
					}
					catch (QueryException qe) {
						cout << qe.what() << endl;
					}
				}
			}
		}
		else
		{
			cout << "login fail! you have no chance ! please enter 'Y' to close the system! " << endl;
			while (re)
			{

				try {
					cout << "please enter Y:";
					itp.GetQs();
					re = itp.EXEC();
				}
				catch (TableException te) {
					cout << te.what() << endl;
				}
				catch (QueryException qe) {
					cout << qe.what() << endl;
				}
			}
		}

	}
	return 0;
}

