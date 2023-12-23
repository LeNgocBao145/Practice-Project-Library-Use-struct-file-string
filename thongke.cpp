#include <iostream>

#include "function.h"

using namespace std;


void statistic_quantity_book(Book y[20], int quantity)
{
	int S = 0;
	cout << "<<========THONG KE SO LUONG SACH TRONG THU VIEN========>>" << endl;
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
	cout << "<<===THONG KE SACH THEO THE LOAI==>>" << endl;
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
	cout << "<<THONG KE SO LUONG DOC GIA>>" << endl;

	cout << "=============================" << endl;
	cout << "|" << setw(6) << left << "Ma" << "|" << setw(20) << left << "Ho va Ten" << "|" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(20) << "____________________" << "|" << endl;
	for (int i = 0; i < total; i++)
	{
		cout << "|" << setw(6) << left << x[i].code << "|" << setw(20) << left << x[i].ho_ten << "|" << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(20) << "____________________" << "|" << endl;

	}
	cout << "=============================" << endl;

	cout << "\nTong so luong doc gia la " << total << endl;
}

void statistic_quantity_gender(Reader x[20], int total)
{
	int nam = 0;
	int nu = 0;
	for (int i = 0; i < total; i++)
		if (strcmp(x[i].gioi_tinh, "Nam")==0)
		{
			nam++;
		}
		else
		{
			nu++;
		}
	cout << "<<THONG KE SO LUONG DOC GIA THEO GIOI TINH>>" << endl;
	cout << "============================================" << endl;
	cout << "|" << setw(21) << left << "Nam" << "|" << setw(20) << left << "Nu" << "|" << endl;
	cout << "|" << setw(21) << "_____________________" << "|" << setw(20) << "____________________" << "|" << endl;
	cout << "|" << setw(21) << right << nam << "|" << setw(20) << right << nu << "|" << endl;
	cout << "============================================" << endl;
}

void statistic_quantity_borrow(Book y[20], int quantity)
{
	cout << "<<================THONG KE SO LUONG SACH DANG DUOC MUON================>>" << endl;

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
	cout << "<<THONG KE DANH SACH DOC GIA DANG BI TRE HAN>>" << endl;

	cout << "==============================================" << endl;
	cout << "|" << setw(7) << left << "Ma DG" << "|" << setw(15) << left << "So ngay tre han" << "|" << endl;
	cout << "|" << setw(7) << "_______" << "|" << setw(15) << "_______________" << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		if (strlen(z[i].actualPayDate) != 0 && checkFormatDate(z[i].actualPayDate) == true)
		{

			if (Distance2Date(z[i].expectPayDate, z[i].actualPayDate) > 7)
			{
				cout << "|" << setw(7) << left << z[i].codeDGMuon << "|" << setw(15) << right << Distance2Date(z[i].expectPayDate, z[i].actualPayDate) << "|" << endl;
				cout << "|" << setw(7) << "_______" << "|" << setw(15) << "_______________" << "|" << endl;
			}
		}
	}
	cout << "==============================================" << endl;


}