#include <iostream>
#include <string>
#include "function.h"
using namespace std;

//Ham dung de xuat ra giao dien menu cac chuc nang co ban
int show_menu()
{
	int choose;
	system("cls");
	cout << "==================QUAN LI THU VIEN=================" << endl;


	cout << "||" << setw(9) << "=====================MENU======================||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "1. Quan li doc gia           " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "2. Quan li sach              " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "3. Lap phieu muon sach       " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "4. Lap phieu tra sach        " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "5. Cac thong ke co ban       " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "6. In phieu muon/tra        " << setw(10) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "     " << "0. Thoat chuong trinh        " << setw(9) << "||\n";
	cout << "||" << right << setw(49) << "||" << endl;
	cout << "||" << setw(12) << "=====================MENU======================||\n";

	cout << "\nLua chon cua ban la ";
	cin >> choose;

	while (cin.fail() || (choose != 0 && choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 && choose != 6))
	{
		cin.clear();
		cin.ignore();
		cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
		cout << "\nLua chon cua ban la ";
		cin >> choose;
	}

	return choose;
}