
#include <iostream>
#include "function.h"
#include "Struct.h"
using namespace std;




int main()
{

	string tendangnhap;
	string matkhau;

	char choose;

	string daynow;
	
	int total;
	int quantity;
	int so_Phieu;

	Reader x[20];
	Book y[20];
	Ticket z[20];

	 Account{};

	fstream docgia{};

	fstream sach{};

	fstream phieu{};

	while (Login(tendangnhap, matkhau, Account) == false)
	{
		Login(tendangnhap, matkhau, Account);
	}

	
	system("cls");

	ReadFileDocGia(docgia, x, total);

	ReadFileSach(sach, y, quantity);

	ReadFilePhieu(phieu, z, so_Phieu);

	cout << "\nDANG NHAP TAI KHOAN ADMIN THANH CONG!" << endl;
	
	char is_continue2;
	cout << "\nMoi ban vui long nhap lua chon de tiep tuc (y/n)" << endl;
	cin >> is_continue2;
	while (is_continue2 != 'y' && is_continue2 != 'n')
	{
		cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
		cout << "\nBan co muon lua chon tiep khong (y/n)" << endl;
		cin >> is_continue2;
	}
	if (is_continue2 == 'n')
	{
		cout << "Xin chao tam biet. Hen gap lai lan sau";
		return 0;
	}
	else {
		InputDayNow(daynow);
	}

	while (true)
	{
		int n = show_menu();
		
		switch (n)
		{
		case 0:
			cout << "Xin chao tam biet. Hen gap lai lan sau!\n";
			return 0;
		case  1:
			system("cls");
			ReaderManager();
			break;
		case  2:
			system("cls");
			BookManager();
			break;

		case  3:
			LapPhieuMuon(x, y, z, so_Phieu, total, quantity, daynow, phieu, sach);
			break;
		case  4:
			LapPhieuTra(y,z, so_Phieu, quantity, daynow, phieu, sach);
			break;

		case  5:
			system("cls");
			BasicStatistic();
			break;
		case 6:
			InPhieuMuonTra(z, so_Phieu);
			break;
		default:
			cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
		}

		
		if (n == 1 || n == 2 || n == 5)
		{
			cout << "\nLua chon cua ban la ";
			cin >> choose;

			while (!isalpha(choose))
			{
				cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
				cout << "\nLua chon cua ban la ";
				cin >> choose;
			}
		}


		Luachon(x, y, z, n, choose, total, quantity, sach, docgia);


		string is_continue;
		cout << "\nBan co muon lua chon tiep khong (y/n)" << endl;
		cin >> is_continue;
		while (is_continue != 'y' && is_continue != 'n')
		{
			cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
			cout << "\nBan co muon lua chon tiep khong (y/n)" << endl;
			cin >> is_continue;
		}
		if (is_continue == 'n')
		{
			cout << "Xin chao tam biet. Hen gap lai lan sau";
			return 0;
		}
	}


	return 0;
}