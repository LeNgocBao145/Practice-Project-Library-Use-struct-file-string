#include <iostream>
#include <string>
#include <iomanip>
#include "function.h"
#include "Struct.h"
using namespace std;


void LapPhieuMuon(Reader x[20], Book y[20], Ticket z[20], int &n, int j, int quantity, char daynow[20])
{
	n++;
	int S = 0;
	system("cls");
	cout << "========================================================================================================================================================================\n";
	cout << "|Ma    |" << setw(18) << left << "Ho va Ten" << setw(16) << left << "|CMND/CCCD" << setw(13) << left << "|Ngay sinh" << setw(12) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(44) << left << "|Dia chi" << setw(16) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << "|" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << endl;
	for (int i = 0; i < j; i++) {
		cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << setw(15) << left << x[i].cccd << "|" << setw(12) << left << x[i].ngay_sinh << "|" << setw(11) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(43) << left << x[i].dia_chi << "|" << setw(15) << left << x[i].ngay_lap_the << "|" << setw(12) << left << x[i].ngay_het_han << "|" << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << endl;
	}
	cout << "========================================================================================================================================================================\n" << endl;

	cout << "\nNhap ma doc gia (4 so): ";
	cin >> z[n-1].codeDGMuon;


	while (!codeInListDGMuon(z[n - 1].codeDGMuon, j, x))
	{
		cout << "\nKhong ton tai ma doc gia! " << endl;
		cout << "\nXin ban vui long nhap lai " << endl;
		cout << "\nNhap ma doc gia (4 so): ";
		cin >> z[n - 1].codeDGMuon;
	}




	system("cls");
	cout << "========================================================================================================================================================================\n";
	cout << "|ISBN  |" << setw(39) << left << "Ten Sach" << setw(28) << left << "|Tac gia" << setw(28) << left << "|Nha xuat ban" << setw(12) << left << "|Nam xuat ban" << setw(25) << left << "|The loai" << setw(15) << left << "|Gia tien" << setw(9) << left << "|So luong" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
	for (int i = 0; i < quantity; i++) {
		cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(39) << left << y[i].ten_sach << "|" << setw(27) << left << y[i].tac_gia << "|" << setw(27) << left << y[i].nha_xuat_ban << "|" << setw(12) << left << y[i].nam_xuat_ban << "|" << setw(24) << left << y[i].the_loai << "|" << setw(14) << left << fixed << setprecision(3) << (y[i].gia_tien) << "|" << setw(9) << left << y[i].so_luong << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
	}
	cout << "========================================================================================================================================================================\n" << endl;

	cout << "Nhap so luong sach ma ban muon muon (toi da 5 cuon): ";
	cin >> z[n-1].SLmuon;

	while (z[n - 1].SLmuon > 5)
	{
		cout << "Nhap so luong sach ma ban muon muon (toi da 5 cuon): ";
		cin >> z[n - 1].SLmuon;
	}
	for (int j = 0; j < n; j++)
	{
		
		if (j == n - 1)
		{
			int dem = 1;
			for (int i = 0; i < 5; i++)
			{

				cout << "\nNhap ma ISBN cua sach " << dem << " (4 so): ";
				cin >> z[j].codeSachMuon[i];
				while (codeInListSachMuon(z[j].codeSachMuon[i], quantity, y) == false)
				{
					cout << "\nNhap ma ISBN cua sach " << dem << " (4 so): ";
					cin >> z[j].codeSachMuon[i];
				}
				dem++;

				for (int k = 0; k < quantity; k++)
				{
					if (y[k].ISBN == z[j].codeSachMuon[i])
					{
						y[k].so_luong--;
						y[j].BookIsBorrowing++;
						break;
					}
				}


			}




		}



	}

	for (int i = n - 1; i < n; i++)
	{
		int day = 0;
		int month = 0;
		char date;
		char num;
		char num2;
		char num3;
		strcpy_s(z[i].borrowDate, daynow);
		z[i].MaPhieu = CodeTicket();
		strcpy_s(z[i].expectPayDate, daynow);
		for (int j = 0; j < 2; j++)
		{
			num = z[i].expectPayDate[j];
			day = day * 10 + (static_cast<int>(num) - 48);
		}
		for (int k = 3; k < 5; k++)
		{
			num2 = z[i].expectPayDate[k];
			month = month * 10 + (static_cast<int>(num2) - 48);
		}
		
		day += 7;
		if (day > 31 && month == 1)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '2';
			
		}
		else if (day > 31 && month == 2)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '3';

		}
		else if (day > 31 && month == 3)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '4';
			

		}
		else if (day > 30 && month == 4)
		{
			int g = day - 30;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '5';
			
		}
		else if (day > 31 && month == 5)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '6';
			
		}
		else if (day > 30 && month == 6)
		{
			int g = day - 30;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '7';
			
		}
		else if (day > 31 && month == 7)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '8';
			
		}

		else if (day > 31 && month == 8)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '9';
			
		}

		else if (day > 30 && month == 9)
		{
			int g = day - 30;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '1';
			z[i].expectPayDate[4] = '0';
			
		}

		else if (day > 31 && month == 10)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '1';
			z[i].expectPayDate[4] = '1';
			
		}

		else if (day > 30 && month == 11)
		{
			int g = day - 30;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '1';
			z[i].expectPayDate[4] = '2';
			
		}
		else if (day > 31 && month == 12)
		{
			int g = day - 31;
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((g % 10) + 48);
				g /= 10;
				z[i].expectPayDate[h] = num3;
			}
			z[i].expectPayDate[3] = '0';
			z[i].expectPayDate[4] = '1';
			
		}
		else
		{
			for (int h = 1; h >= 0; h--)
			{
				num3 = static_cast<char>((day % 10) + 48);
				day /= 10;
				z[i].expectPayDate[h] = num3;
			}

			
		}



	}



	cout << "\nLap phieu muon thanh cong!" << endl;
}

void LapPhieuTra(Book y[20], Ticket z[20], int n, int j, char daynow[20])
{

	int ma;
	int S = 0;
	int S2 = 0;
	InPhieuMuonTra(z, n);

	cout << "Ban vui long nhap ma phieu muon: ";
	cin >> ma;
	while (codeInListMaPhieu(ma, n, z) == false)
	{
		cout << "Khong the tim thay ma phieu muon. Xin vui long nhap lai!" << endl;
		cout << "Ban vui long nhap ma phieu muon: ";
		cin >> ma;
	}
	for (int i = 0; i < n; i++)
	{
		S += (z[i].SLmuon);
		if (ma == z[i].MaPhieu)
		{
			system("cls");
			cout << "=======================================================================================================================================================================" << endl;
			cout << "|" << setw(8) << left << "Ma phieu" << "|" << setw(9) << left << "Ma doc gia" << "|" << setw(14) << left << "Ngay muon" << "|" << setw(18) << left << "Ngay tra du kien" << "|" << setw(18) << left << "Ngay tra thuc te" << "|" << setw(8) << left << "SL muon" << "|" << setw(31) << left << "Danh sach ISBN sach duoc muon" << "|" << setw(7) << left << "SL mat" << "|" << setw(28) << left << "Danh sach ISBN sach bi mat" << "|" << setw(14) << left << "Tong tien phat" << "|" << endl;
			cout << "|" << setw(8) << "________" << "|" << setw(9) << "__________" << "|" << setw(14) << "______________" << "|" << setw(18) << "__________________" << "|" << setw(18) << "__________________" << "|" << setw(8) << "________" << "|" << setw(26) << "_______________________________" << "|" << setw(7) << "_______" << "|" << setw(27) << "____________________________" << "|" << setw(14) << "______________" << "|" << endl;
			cout << "|" << setw(8) << left << z[i].MaPhieu << "|" << setw(10) << left << z[i].codeDGMuon << "|" << setw(14) << left << z[i].borrowDate << "|" << setw(18) << left << z[i].expectPayDate << "|" << setw(18) << left << " " << "|" << setw(8) << left << z[i].SLmuon << "|";
			for (int a = S - z[i].SLmuon; a < S; a++)
			{
				cout << left << z[a].codeSachMuon << " ";
			}
			switch (z[i].SLmuon)
			{
			case 1:
				cout << setw(27);
				break;
			case 2:
				cout << setw(22);
				break;
			case 3:
				cout << setw(17);
				break;
			case 4:
				cout << setw(12);
				break;
			case 5:
				cout << setw(7);
				break;
			}
			cout << right << "|" << setw(7) << left << z[i].SLmat << "|" << setw(28) << left << " " << "|" << setw(14) << left << z[i].TongTienPhat << "|" << endl;
			cout << "|" << setw(8) << "________" << "|" << setw(9) << "__________" << "|" << setw(14) << "______________" << "|" << setw(18) << "__________________" << "|" << setw(18) << "__________________" << "|" << setw(8) << "________" << "|" << setw(26) << "_______________________________" << "|" << setw(7) << "_______" << "|" << setw(27) << "____________________________" << "|" << setw(14) << "______________" << "|" << endl;
			cout << "=======================================================================================================================================================================" << endl;



			cout << "So sach bi mat ";
			cin >> z[i].SLmat;
			while (z[i].SLmat > z[i].SLmuon)
			{
				cout << "So sach bi mat ";
				cin >> z[i].SLmat;
			}

			if (z[i].SLmat == 0)
			{
				for (int b = S - z[i].SLmuon; b < S; b++)
				{
					for (int c = 0; c < j; c++)
					{
						if (z[i].codeSachMuon[b] == y[c].ISBN)
						{
							y[c].so_luong++;
							y[c].BookIsBorrowing--;
							break;
						}
					}

				}
			}

			strcpy_s(z[i].actualPayDate, daynow);


			if (Distance2Date(z[i].expectPayDate, z[i].actualPayDate) > 7)
			{
				z[i].TongTienPhat = Distance2Date(z[i].expectPayDate, z[i].actualPayDate) * 5000;
				cout << "Sach tre han " << Distance2Date(z[i].expectPayDate, z[i].actualPayDate) << " ngay" << endl;
			}
			else
			{
				cout << "Sach khong tre han" << endl;
				z[i].TongTienPhat = 0;
			}



			for (int i = 0; i < n; i++)
			{
				S2 += z[i].SLmat;
				if (ma == z[i].MaPhieu)
				{
					for (int h = 0; h < 5; h++)
					{

						cout << "\nNhap ma ISBN cua sach mat ";
						cin >> z[i].codeSachMat[h];
						while (checkDsMuon(z[i].codeSachMat[h], z[i].SLmuon, z[i].codeSachMuon, S) == false)
						{
							cout << "Khong the tim thay ma ISBN cua sach trong danh sach muon" << endl;
							cout << "\nNhap ma ISBN cua sach mat ";
							cin >> z[i].codeSachMat[h];
						}

						for (int b = 0; b < j; b++)
						{

							if (y[b].ISBN == z[i].codeSachMat[h])
							{
								z[i].TongTienPhat += y[b].gia_tien * 2;
								cout << "\nTen sach: " << y[b].ten_sach << endl;
								cout << "Gia tien: " << y[b].gia_tien << endl;
								break;
							}
						}



						for (int b = S - z[i].SLmuon; b < S; b++)
						{
							for (int c = 0; c < j; c++)
							{

								if (z[i].codeSachMat[h] != z[i].codeSachMuon[b] && z[i].codeSachMuon[b] == y[c].ISBN)
								{
									y[c].so_luong++;
									break;
								}

							}
						}

					}
				}
			}


			cout << "\nTong tien phat: " << z[i].TongTienPhat << endl;



		}

	}


}

void InPhieuMuonTra(Ticket z[20], int n)
{
	int S = 0;
	int S2 = 0;
	cout << "=======================================================================================================================================================================" << endl;
	cout << "|" << setw(8) << left << "Ma phieu" << "|" << setw(9) << left << "Ma doc gia" << "|" << setw(14) << left << "Ngay muon" << "|" << setw(18) << left << "Ngay tra du kien" << "|" << setw(18) << left << "Ngay tra thuc te" << "|" << setw(8) << left << "SL muon" << "|" << setw(31) << left << "Danh sach ISBN sach duoc muon" << "|" << setw(7) << left << "SL mat" << "|" << setw(28) << left << "Danh sach ISBN sach bi mat" << "|" << setw(14) << left << "Tong tien phat" << "|" << endl;
	cout << "|" << setw(8) << "________" << "|" << setw(9) << "__________" << "|" << setw(14) << "______________" << "|" << setw(18) << "__________________" << "|" << setw(18) << "__________________" << "|" << setw(8) << "________" << "|" << setw(26) << "_______________________________" << "|" << setw(7) << "_______" << "|" << setw(27) << "____________________________" << "|" << setw(14) << "______________" << "|" << endl;
	for (int i = 0; i < n; i++)
	{

		cout << "|" << setw(8) << left << z[i].MaPhieu << "|" << setw(10) << left << z[i].codeDGMuon << "|" << setw(14) << left << z[i].borrowDate << "|" << setw(18) << left << z[i].expectPayDate << "|" << setw(18) << left << z[i].actualPayDate << "|" << setw(8) << left << z[i].SLmuon << "|";
		for (int j = 0; j < z[i].SLmuon; j++)
		{
			cout << left << z[i].codeSachMuon[j] << " ";

		}
		switch (z[i].SLmuon)
		{
		case 0:
			cout << setw(29);
			break;
		case 1:
			cout << setw(27);
			break;
		case 2:
			cout << setw(22);
			break;
		case 3:
			cout << setw(17);
			break;
		case 4:
			cout << setw(12);
			break;
		case 5:
			cout << setw(7);
			break;
		}
		cout << right << "|" << setw(7) << left << z[i].SLmat << "|";
		for (int h = 0; h < z[i].SLmat; h++)
		{
			cout << left << z[i].codeSachMat[h] << " ";

		}
		switch (z[i].SLmat)
		{
		case 0:
			cout << setw(29);
			break;
		case 1:
			cout << setw(24);
			break;
		case 2:
			cout << setw(19);
			break;
		case 3:
			cout << setw(14);
			break;
		case 4:
			cout << setw(9);
			break;
		case 5:
			cout << setw(4);
			break;
		}
		cout << right << "|" << setw(14) << left << z[i].TongTienPhat << "|" << endl;
		cout << "|" << setw(8) << "________" << "|" << setw(9) << "__________" << "|" << setw(14) << "______________" << "|" << setw(18) << "__________________" << "|" << setw(18) << "__________________" << "|" << setw(8) << "________" << "|" << setw(26) << "_______________________________" << "|" << setw(7) << "_______" << "|" << setw(27) << "____________________________" << "|" << setw(14) << "______________" << "|" << endl;
		S += z[i].SLmuon;
		S2 += z[i].SLmat;
	}
	cout << "=======================================================================================================================================================================" << endl;
}


int CodeTicket()
{
	srand(static_cast<unsigned>(time(0)));
	int random = rand();
	while (random > 9999)
	{
		random /= 10;
	}
	return random;
}



