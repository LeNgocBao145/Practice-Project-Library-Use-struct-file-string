
#include <iostream>
#include "function.h"
#include "Struct.h"
using namespace std;




int main()
{
	char choose{};
	
	int total;
	int quantity;
	int so_Phieu;

	Reader x[20];
	Book y[20];
	Ticket z[20];

	FILE* docgia{};
	ReadFileDocGia(docgia, x, total);

	FILE* sach{};
	ReadFileSach(sach, y, quantity);

	FILE* phieu{};
	ReadFilePhieu(phieu, z, so_Phieu);


	char daynow[20];
	cout << "Truoc khi bat dau chuong trinh. Xin ban vui long nhap ngay thang nam hien tai (dd/mm/yyyy): ";
	cin >> daynow;
	while (checkFormatDate(daynow) == false)
	{
		cout << "Ngay thang nam (dd/mm/yyyy) khong hop le. Xin ban vui long nhap lai!!: ";
		cin >> daynow;
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
			LapPhieuMuon(x, y, z, so_Phieu, total, quantity, daynow, phieu);
			break;
		case  4:
			LapPhieuTra(y,z, so_Phieu, quantity, daynow, phieu);
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


		char is_continue;
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