#include "function.h"
#include <iostream>
#include "Struct.h"
void ReaderManager()
{
	cout << "a. Xem danh sach doc gia trong thu vien\n";
	cout << "b. Them doc gia\n";
	cout << "c. Chinh sua thong tin mot doc gia\n";
	cout << "d. Xoa thong tin mot doc gia\n";
	cout << "e. Tim kiem doc gia theo CMND/CCCD\n";
	cout << "f. Tim kiem sach theo ho ten\n";
	cout << "g. Thoat\n";
}
void BookManager()
{
	cout << "a. Xem danh sach cac sach trong thu vien\n";
	cout << "b. Them sach\n";
	cout << "c. Chinh sua thong tin mot quyen sach\n";
	cout << "d. Xoa thong tin sach\n";
	cout << "e. Tim kiem sach theo ISBN\n";
	cout << "f. Tim kiem sach theo ten sach\n";
	cout << "g. Thoat\n";
}
void BasicStatistic()
{
	cout << "a. Thong ke so luong sach trong thu vien\n";
	cout << "b. Thong ke so luong sach theo the loai\n";
	cout << "c. Thong ke so luong doc gia\n";
	cout << "d. Thong ke so luong doc gia theo gioi tinh\n";
	cout << "e. Thong ke so sach dang duoc muon\n";
	cout << "f. Thong ke danh sach doc gia bi tre han\n";
	cout << "g. Thoat\n";
}




//Ham dung de nhap lua chon a, b, c, d, e, f trong cac muc 1->6
void Luachon(Reader x[20], Book y[20], Ticket z[20], int n, char choose, int& total, int& quantity, FILE* sach)
{
	if (n == 1)
	{

		if (choose == 'b')
		{
			system("cls");
			addDocgia(x, total);
		}
		if (choose == 'a')
		{
			system("cls");
			printDocgia(x, total);
		}
		if (choose == 'c')
		{
			system("cls");
			editDocgia(x, total);
		}
		if (choose == 'd')
		{
			system("cls");
			deleteDocgia(x, total);
		}
		if (choose == 'e')
		{
			system("cls");
			searchDocgia(x, total);
		}
		if (choose == 'f')
		{
			system("cls");
			searchTenDocGia(x, total);
		}
		if (choose == 'g')
		{
			return;
		}

		if (choose != 'a' && choose != 'b' && choose != 'c' && choose != 'd' && choose != 'e' && choose != 'f' && choose != 'g')
		{
			cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			return;
		}

	}


	if (n == 2)
	{

		if (choose == 'a')
		{
			system("cls");
			printSach(y, quantity);
		}
		if (choose == 'b')
		{
			system("cls");
			addSach(y, quantity, sach);
		}
		if (choose == 'c')
		{
			system("cls");
			editSach(y, quantity);
		}
		if (choose == 'd')
		{
			system("cls");
			deleteSach(y, quantity);
		}
		if (choose == 'e')
		{
			system("cls");
			searchISBNSach(y, quantity);
		}
		if (choose == 'f')
		{
			system("cls");
			searchTenSach(y, quantity);
		}
		if (choose == 'g')
		{
			return;
		}


		if (choose != 'a' && choose != 'b' && choose != 'c' && choose != 'd' && choose != 'e' && choose != 'f' && choose != 'g')
		{
			cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			return;
		}
	}






	if (n == 5)
	{

		if (choose == 'a')
		{
			system("cls");
			statistic_quantity_book(y, quantity);

		}
		if (choose == 'b')
		{
			system("cls");
			statsitic_quantity_category(y, quantity);

		}
		if (choose == 'c')
		{
			system("cls");
			statistic_quantity_reader(x, total);

		}
		if (choose == 'd')
		{
			system("cls");
			statistic_quantity_gender(x, total);

		}
		if (choose == 'e')
		{
			system("cls");
			statistic_quantity_borrow(y, quantity);
		}
		if (choose == 'f')
		{
			system("cls");
			statistic_listReaders_late(z, n);
		}
		if (choose == 'g')
		{
			return;
		}

		if (choose != 'a' && choose != 'b' && choose != 'c' && choose != 'd' && choose != 'e' && choose != 'f' && choose != 'g')
		{
			cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			return;
		}
	}


}


bool checkFormatDate(char date[20])
{
	bool check = true;
	if (strlen(date) != 10 || date[2] != '/' || date[5] != '/')
	{
		check = false;
	}
	return check;
}

bool codeInListMaPhieu(int n, int j, Ticket z[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n == z[i].MaPhieu)
		{
			check = true;
			break;
		}
	}

	return check;
}

bool codeInListDGMuon(int n, int j, Reader x[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n == x[i].code)
		{
			check = true;
			break;
		}
	}

	return check;
}

bool codeInListSachMuon(int n, int j, Book y[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n == y[i].ISBN)
		{
			check = true;
			break;
		}
	}

	return check;
}


bool nameInListBook(char n[100], int j, Book y[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (strcmp(n, y[i].ten_sach) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}

//bool nameInList(char n[100], int j, char name[20][50])
//{
//	bool check = false;
//	for (int i = 0; i < j; i++)
//	{
//		if (strcmp(n, name[i]) == 0)
//		{
//			check = true;
//			break;
//		}
//	}
//
//	return check;
//}



bool checkCCCD(char cccd[50])
{
	bool check = true;
	if (strlen(cccd) != 12)
	{
		check = false;
	}
	return check;
}

bool checkEmail(char email[50]) //Kiem tra email co ki tu @ hay khong neu khong thi nhap lai
{
	bool check = false;


	for (int i = 0; i < 50; i++)
	{
		if (email[i] == '@')
		{
			check = true;
			break;
		}
	}
	return check;
}

bool checkGender(char gender[10])
{
	bool check = true;
	if (strcmp(gender, "Nam") != 0 && strcmp(gender, "Nu") != 0)
	{
		check = false;
	}
	return check;
}


int Distance2Date(char expectPayDate[20], char actualPayDate[20])
{
	int length = 0;

	
	int date = 0;
	int month = 0;
	int year = 0;
	int date2 = 0;
	int month2 = 0;
	int year2 = 0;
	

	char num;

	for (int j = 0; j < 2; j++)
	{
		num = expectPayDate[j];
		date = date * 10 + (static_cast<int>(num) - 48);
	}
	
	for (int j = 3; j < 5; j++)
	{
		num = expectPayDate[j];
		month = month * 10 + (static_cast<int>(num) - 48);
	}
	
	for (int j = 6; j < 10; j++)
	{
		num = expectPayDate[j];
		year = year * 10 + (static_cast<int>(num) - 48);
	}
	
	for (int j = 0; j < 2; j++)
	{
		num = actualPayDate[j];
		date2 = date2 * 10 + (static_cast<int>(num) - 48);
	}
	
	for (int j = 3; j < 5; j++)
	{
		num = actualPayDate[j];
		month2 = month2 * 10 + (static_cast<int>(num) - 48);
	}
	
	for (int j = 6; j < 10; j++)
	{
		num = actualPayDate[j];
		year2 = year2 * 10 + (static_cast<int>(num) - 48);
	}


	if (month2 - month != 0 && year == year2)
	{

		switch (month)
		{
		case 1:
			length = date2 + (31 - date);
			break;
		case 2:
			if (year % 4 == 0 && year % 100 != 0)
			{
				length = date2 + (29 - date);
				break;
			}
			else
			{
				length = date2 + (28 - date);
				break;
			}
		case 3:
			length = date2 + (31 - date);
			break;
		case 4:
			length = date2 + (30 - date);
			break;
		case 5:
			length = date2 + (31 - date);
			break;
		case 6:
			length = date2 + (30 - date);
			break;
		case 7:
			length = date2 + (31 - date);
			break;
		case 8:
			length = date2 + (31 - date);
			break;
		case 9:
			length = date2 + (30 - date);
			break;
		case 10:
			length = date2 + (31 - date);
			break;
		case 11:
			length = date2 + (30 - date);
			break;
		case 12:
			length = date2 + (31 - date);
			break;
		}

		for (int i = month + 1; i < month2; i++)
		{

			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				length += 31;

			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				length += 30;

			}
			else if (i == 2 && (year2 % 4 == 0 && year2 % 100 != 0))
			{
				length += 29;

			}
			else
			{
				length += 28;

			}

		}


	}
	if (month2 - month == 0 && year == year2)
	{
		length = abs(date2 - date);
	}

	if (year2 - year != 0)
	{
		int minus = date;
		for (int i = 1; i < month; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				minus += 31;

			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				minus += 30;

			}
			else if (i == 2 && (year % 4 == 0 && year % 100 != 0))
			{
				minus += 29;

			}
			else
			{
				minus += 28;

			}

		}

		if (year % 4 == 0 && year % 100 != 0)
		{
			length += 366 - minus;
		}
		else
		{
			length += 365 - minus;
		}



		for (int i = year + 1; i < year2; i++)
		{
			if (i % 4 == 0 && i % 100 != 0)
			{
				length += 366;

			}
			else
			{
				length += 365;

			}
		}


		length += date2;
		for (int i = 1; i < month2; i++)
		{

			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				length += 31;

			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				length += 30;

			}
			else if (i == 2 && (year2 % 4 == 0 && year2 % 100 != 0))
			{
				length += 29;

			}
			else
			{
				length += 28;

			}

		}
	}


	return length;
}

bool checkDsMuon(int n, int j, int code[20], int start)
{
	bool check = false;
	for (int i = start - j; i < start; i++)
	{
		if (n == code[i])
		{
			check = true;
			break;
		}
	}

	return check;
}



