#include <iostream>
#include <string>
#include "function.h"
using namespace std;

//Ham dung de xuat ra giao dien menu cac chuc nang co ban
int show_menu()
{
	int choose;
	system("cls");
	cout << "===============QUAN LI THU VIEN===============" << endl;
	cout << "        " << "||===========MENU===========||\n";
	cout << "        " << "||" << "  " << "1. Quan li doc gia      ||\n";
	cout << "        " << "||" << "  " << "2. Quan li sach         ||\n";
	cout << "        " << "||" << "  " << "3. Lap phieu muon sach  ||\n";
	cout << "        " << "||" << "  " << "4. Lap phieu tra sach   ||\n";
	cout << "        " << "||" << "  " << "5. Cac thong ke co ban  ||\n";
	cout << "        " << "||" << "  " << "6. In phieu muon/ tra   ||\n";
	cout << "        " << "||" << "  " << "0. Thoat chuong trinh   ||\n";
	cout << "        " << "||===========MENU===========||\n";

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