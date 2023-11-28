#include <iostream>

#include "function.h"

using namespace std;


void statistic_quantity_book(Book y[20], int quantity)
{
	int S = 0;
	cout << "=========================================================" << endl;
	cout << "|" << setw(6) << left << "ISBN" << setw(39) << left << "|Ten sach" << setw(10) << left << "|So luong" << "|" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(38) << "______________________________________" << "|" << setw(9) << "_________" << "|" << endl;
	for (int i = 0; i < quantity; i++)
	{
		S += y[i].so_luong;
		cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(38) << left << y[i].ten_sach << "|" << setw(9) << right << y[i].so_luong << "|" << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(38) << "______________________________________" << "|" << setw(9) << "_________" << "|" << endl;
	}
	cout << "=========================================================" << endl;

	cout << "\nTong so luong sach trong thu vien la " << S << endl;
}


void statsitic_quantity_category(Book y[20], int quantity)
{
	int S;
	cout << "====================================" << endl;
	cout << "|" << setw(24) << left << "The loai" << "|" << setw(9) << left << "So luong" << "|" << endl;
	cout << "|" << setw(24) << "________________________" << "|" << setw(9) << "_________" << "|" << endl;
	for (int i = 0; i < quantity; i++)
	{

		bool chuaXuatHien = true;
		for (int j = 0; j < i; j++)
		{

			if (y[i].the_loai == y[j].the_loai)
			{
				chuaXuatHien = false;
				break;
			}

		}


		S = y[i].so_luong;
		if (chuaXuatHien)
		{
			for (int k = i + 1; k < quantity; k++)
			{

				if (y[k].the_loai == y[i].the_loai)
				{
					S += y[k].so_luong;

				}

			}
			cout << "|" << setw(24) << left << y[i].the_loai << "|" << setw(9) << left << S << "|" << endl;
			cout << "|" << setw(24) << "________________________" << "|" << setw(9) << "_________" << "|" << endl;

		}
	}
	cout << "====================================" << endl;

}

void statistic_quantity_reader(Reader x[20], int total)
{
	cout << "===========================" << endl;
	cout << "|" << setw(6) << left << "Ma" << "|" << setw(18) << left << "Ho va Ten" << "|" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << endl;
	for (int i = 0; i < total; i++)
	{
		cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << endl;

	}
	cout << "===========================" << endl;

	cout << "\nTong so luong doc gia la " << total << endl;
}

void statistic_quantity_gender(Reader x[20], int total)
{
	int nam = 0;
	int nu = 0;
	for (int i = 0; i < total; i++)
		if (x[i].gioi_tinh == "Nam")
		{
			nam++;
		}
		else
		{
			nu++;
		}

	cout << "===================================" << endl;
	cout << "|" << setw(16) << left << "Nam" << "|" << setw(16) << left << "Nu" << "|" << endl;
	cout << "|" << setw(16) << "________________" << "|" << setw(16) << "________________" << "|" << endl;
	cout << "|" << setw(16) << right << nam << "|" << setw(16) << right << nu << "|" << endl;
	cout << "===================================" << endl;
}

void statistic_quantity_borrow(Book y[20], int quantity)
{

	cout << "=========================================================================" << endl;
	cout << "|" << setw(6) << left << "ISBN" << "|" << setw(39) << left << "Ten sach" << "|" << setw(24) << left << "So sach dang duoc muon" << "|" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(24) << "________________________" << "|" << endl;

	for (int j = 0; j < quantity; j++)
	{

		cout << "|" << setw(6) << left << y[j].ISBN << "|" << setw(39) << y[j].ten_sach << "|" << setw(24) << right << y[j].BookIsBorrowing << "|" << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(24) << "________________________" << "|" << endl;

	}
	cout << "========================================================================" << endl;
}

void statistic_listReaders_late(Ticket z[20], int n)
{
	cout << "=========================" << endl;
	cout << "|" << setw(7) << left << "Ma DG" << "|" << setw(15) << left << "So ngay tre han" << "|" << endl;
	cout << "|" << setw(7) << "_______" << "|" << setw(15) << "_______________" << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		if (sizeof(z[i].actualPayDate) != 0)
		{

			if (Distance2Date(z[i].expectPayDate, z[i].actualPayDate) > 7)
			{
				cout << "|" << setw(7) << left << z[i].codeDGMuon << "|" << setw(15) << right << Distance2Date(z[i].expectPayDate, z[i].actualPayDate) << "|" << endl;
				cout << "|" << setw(7) << "_______" << "|" << setw(15) << "_______________" << "|" << endl;
			}
		}
	}
	cout << "=========================" << endl;


}