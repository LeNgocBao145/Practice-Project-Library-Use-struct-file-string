#include "function.h"
#include <iostream>
#include "Struct.h"


void ReadFileDocGia(fstream& docgia, Reader* &x, int &total)
{
	string line;
	string tmp;
	
	docgia.open("docgia.txt", ios::in);

	if(docgia.is_open())
	{
		getline(docgia, line);
		istringstream ss(line);
		getline(ss, tmp, ',');
		total = stoi(tmp);

		x = new Reader[total];
		
		for(int i = 0; i < total; i++)
		{
			getline(docgia, line);
			istringstream ss(line);
			getline(ss, tmp, ',');
			x[i].code = stoi(tmp);
			getline(ss, x[i].ho_ten, ',');
			getline(ss, x[i].cccd, ',');
			getline(ss, x[i].ngay_sinh, ',');
			getline(ss, x[i].gioi_tinh, ',');
			getline(ss, x[i].email, ',');
			getline(ss, x[i].dia_chi, ',');
			getline(ss, x[i].ngay_lap_the, ',');
			getline(ss, x[i].ngay_het_han, ',');
				
		}
		
		docgia.close();
		cout << "\nDU LIEU DOC GIA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}

	// errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "r");

	// if (docgia != NULL) {
	// 	fscanf_s(docgia, "%d\n", &total);

	// 	for (int i = 0; i < total; i++) {

	// 		fgets(buffer, sizeof(buffer), docgia);

	// 		data = strtok_s(buffer, ",", &temp);


	// 		x[i].code = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].ho_ten, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].cccd, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].ngay_sinh, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].gioi_tinh, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].email, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].dia_chi, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(x[i].ngay_lap_the, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		x[i].ngay_het_han = data;
	// 		x[i].ngay_het_han[strlen(x[i].ngay_het_han) - 1] = '\0';
	// 		data = strtok_s(NULL, ",", &temp);

	// 	}
	// 	fclose(docgia);

	// 	cout << "\nDU LIEU DOC GIA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	// }
	// else
	// {
	// 	cout << "Khong mo duoc file" << endl;
	// 	return;
	// }
}

void ReadFileSach(fstream& sach, Book* &y, int &quantity)
{
	string line;
	string tmp;
	
	sach.open("sach.txt");

	if(sach.is_open())
	{
		getline(sach, line);
		istringstream ss(line);
		getline(ss, tmp, ',');
		quantity = stoi(tmp);
		
		
		y = new Book[quantity];
	

			for(int i = 0; i < quantity; i++)
			{
				getline(sach, line);
				istringstream ss(line);
				getline(ss, tmp, ',');
				y[i].ISBN = stoi(tmp);
				
				getline(ss, y[i].ten_sach, ',');
				getline(ss, y[i].tac_gia, ',');
				getline(ss, y[i].nha_xuat_ban, ',');
				getline(ss, tmp, ',');
				y[i].nam_xuat_ban = stoi(tmp);

				getline(ss, y[i].the_loai, ',');

				getline(ss, tmp, ',');
				y[i].gia_tien = stoi(tmp);

				getline(ss, tmp, ',');
				y[i].so_luong = stoi(tmp);

				getline(ss, tmp, ',');
				y[i].BookIsBorrowing = stoi(tmp);
			}
		
		sach.close();
		cout << "\nDU LIEU SACH DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}

	// errno_t sach2 = fopen_s(&sach, "sach.txt", "r");

	// if (sach != NULL) {
	// 	fscanf_s(sach, "%d\n", &quantity);
	// 	for (int i = 0; i < quantity; i++) {

	// 		fgets(buffer, sizeof(buffer), sach);

	// 		data = strtok_s(buffer, ",", &temp);


	// 		y[i].ISBN = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(y[i].ten_sach, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(y[i].tac_gia, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(y[i].nha_xuat_ban, data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		y[i].nam_xuat_ban = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		strcpy_s(y[i].the_loai, data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		y[i].gia_tien = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		y[i].so_luong = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		y[i].BookIsBorrowing = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 	}
	// 	fclose(sach);
	// 	cout << "\nDU LIEU SACH DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	// }
	// else
	// {
	// 	cout << "Khong mo duoc file" << endl;
	// 	return;
	// }
}

void ReadFilePhieu(fstream& phieu, Ticket* &z, int &so_Phieu)
{
	string line;
	string tmp;
	
	phieu.open("phieu.txt");

	if(phieu.is_open())
	{
		getline(phieu, line);
		istringstream ss(line);
		getline(ss, tmp, ',');
		so_Phieu = stoi(tmp);
		
		
		z = new Ticket[so_Phieu];

			for(int i = 0; i < so_Phieu; i++)
			{
				getline(phieu, line);
				istringstream ss(line);
				getline(ss, tmp, ',');
				z[i].MaPhieu = stoi(tmp);
				getline(ss, tmp, ',');
				z[i].codeDGMuon = stoi(tmp);
				getline(ss, z[i].borrowDate, ',');
				getline(ss, z[i].expectPayDate, ',');
				getline(ss, z[i].actualPayDate, ',');
				getline(ss, tmp, ',');
				z[i].SLmuon = stoi(tmp);

				z[i].codeSachMuon = new int[z[i].SLmuon];

				for (int h = 0; h < z[i].SLmuon; h++)
				{
					getline(ss, tmp, ',');
					z[i].codeSachMuon[h] = stoi(tmp);
				}


				getline(ss, tmp, ',');
				z[i].SLmat = stoi(tmp);

				z[i].codeSachMat = new int[z[i].SLmat];

				for (int h = 0; h < z[i].SLmat; h++)
				{
					getline(ss, tmp, ',');
					z[i].codeSachMat[h] = stoi(tmp);
				}

				getline(ss, tmp, ',');
				z[i].TongTienPhat = stoi(tmp);
			}
		
		phieu.close();
		cout << "\nDU LIEU PHIEU MUON TRA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}


	// errno_t phieu2 = fopen_s(&phieu, "phieu.txt", "r");

	// if (phieu != NULL) {
	// 	fscanf_s(phieu, "%d\n", &so_Phieu);
	// 	for (int i = 0; i < so_Phieu; i++) {

	// 		fgets(buffer, sizeof(buffer), phieu);

	// 		data = strtok_s(buffer, ",", &temp);


	// 		z[i].MaPhieu = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		z[i].codeDGMuon = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		strcpy_s(z[i].borrowDate, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(z[i].expectPayDate, data);
	// 		data = strtok_s(NULL, ",", &temp);


	// 		strcpy_s(z[i].actualPayDate, data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		z[i].SLmuon = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		for (int h = 0; h < z[i].SLmuon; h++)
	// 		{
	// 			z[i].codeSachMuon[h] = atoi(data);
	// 			data = strtok_s(NULL, ",", &temp);
	// 		}


	// 		z[i].SLmat = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 		for (int h = 0; h < z[i].SLmat; h++)
	// 		{
	// 			z[i].codeSachMat[h] = atoi(data);
	// 			data = strtok_s(NULL, ",", &temp);
	// 		}


	// 		z[i].TongTienPhat = atoi(data);
	// 		data = strtok_s(NULL, ",", &temp);

	// 	}
	// 	fclose(phieu);
	// 	cout << "\nDU LIEU PHIEU MUON TRA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	// }
	// else
	// {
	// 	cout << "Khong mo duoc file" << endl;
	// 	return;
	// }
}







void ReaderManager()
{
	cout << "a. Xem danh sach doc gia trong thu vien\n";
	cout << "\nb. Them doc gia\n";
	cout << "\nc. Chinh sua thong tin mot doc gia\n";
	cout << "\nd. Xoa thong tin doc gia\n";
	cout << "\ne. Tim kiem doc gia theo CMND/CCCD\n";
	cout << "\nf. Tim kiem thong tin doc gia theo ho ten\n";
	cout << "\ng. Thoat\n";
}
void BookManager()
{
	cout << "a. Xem danh sach cac sach trong thu vien\n";
	cout << "\nb. Them sach\n";
	cout << "\nc. Chinh sua thong tin mot quyen sach\n";
	cout << "\nd. Xoa thong tin sach\n";
	cout << "\ne. Tim kiem sach theo ISBN\n";
	cout << "\nf. Tim kiem sach theo ten sach\n";
	cout << "\ng. Thoat\n";
}
void BasicStatistic()
{
	cout << "a. Thong ke so luong sach trong thu vien\n";
	cout << "\nb. Thong ke so luong sach theo the loai\n";
	cout << "\nc. Thong ke so luong doc gia\n";
	cout << "\nd. Thong ke so luong doc gia theo gioi tinh\n";
	cout << "\ne. Thong ke so sach dang duoc muon\n";
	cout << "\nf. Thong ke danh sach doc gia bi tre han\n";
	cout << "\ng. Thoat\n";
}


void InputDayNow(string daynow)
{
	system("cls");
	cout << "Truoc khi bat dau chuong trinh. Xin ban vui long nhap ngay thang nam hien tai (dd/mm/yyyy): ";
	cin.ignore();
	getline(cin, daynow);
	while (checkFormatDate(daynow) == false)
	{
		cout << "Ngay thang nam (dd/mm/yyyy) khong hop le. Xin ban vui long nhap lai!!: ";
		getline(cin, daynow);
	}
}

//Ham dung de nhap lua chon a, b, c, d, e, f trong cac muc 1->6
void Luachon(Reader* x, Book* y, Ticket* z, int n, char choose, int& total, int& quantity, fstream& sach, fstream& docgia)
{
	if (n == 1)
	{

		if (choose == 'b')
		{
			system("cls");
			addDocgia(x, total, docgia);
		}
		if (choose == 'a')
		{
			system("cls");
			printDocgia(x, total);
		}
		if (choose == 'c')
		{
			system("cls");
			editDocgia(x, total, docgia);
		}
		if (choose == 'd')
		{
			system("cls");
			deleteDocgia(x, total, docgia);
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
			editSach(y, quantity, sach);
		}
		if (choose == 'd')
		{
			system("cls");
			deleteSach(y, quantity, sach);
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
			statistic_listReaders_late(z, x, n, total);
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


bool checkFormatDate(string date)
{
	bool check = true;
	if (date.length() != 10 || date[2] != '/' || date[5] != '/')
	{
		check = false;
	}
	return check;
}

bool codeInListMaPhieu(int n, int j, Ticket* z)
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

bool codeInListDGMuon(int n, int j, Reader* x)
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

bool codeInListSachMuon(int n, int j, Book* y)
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


bool nameInListBook(string n, int j, Book* y)
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n.compare(y[i].ten_sach) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}

bool codeInListBook(int code, int j, Book* y)
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (code == y[i].ISBN)
		{
			check = true;
			break;
		}
	}

	return check;
}

//bool nameInList(string n[100], int j, string name[20][50])
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

bool cccdInListReader(string n, int j, Reader* x)
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n.compare(x[i].cccd) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}

bool nameInListReader(string n, int j, Reader* x)
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (n.compare(x[i].ho_ten) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}



bool checkCCCD(string cccd)
{
	bool check = true;
	if (cccd.length() != 12)
	{
		check = false;
	}
	return check;
}

bool checkEmail(string email) //Kiem tra email co ki tu @ hay khong neu khong thi nhap lai
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

bool checkGender(string gender)
{
	bool check = true;
	if (gender.compare("Nam") != 0 && gender.compare("Nu") != 0)
	{
		check = false;
	}
	return check;
}


int Distance2Date(string expectPayDate, string actualPayDate)
{
	int length = 0;
	string tmp;
	
	tmp = expectPayDate.substr(0, 2);
	int date = stoi(tmp);

	tmp = expectPayDate.substr(3, 2);
	int month = stoi(tmp);

	tmp = expectPayDate.substr(6, 4);
	int year = stoi(tmp);

	tmp = actualPayDate.substr(0, 2);
	int date2 = stoi(tmp);

	tmp = actualPayDate.substr(3, 2);
	int month2 = stoi(tmp);

	tmp = actualPayDate.substr(6, 4);
	int year2 = stoi(tmp);
	

	// string num;

	// for (int j = 0; j < 2; j++)
	// {
	// 	num = expectPayDate[j];
	// 	date = date * 10 + (static_cast<int>(num) - 48);
	// }
	
	// for (int j = 3; j < 5; j++)
	// {
	// 	num = expectPayDate[j];
	// 	month = month * 10 + (static_cast<int>(num) - 48);
	// }
	
	// for (int j = 6; j < 10; j++)
	// {
	// 	num = expectPayDate[j];
	// 	year = year * 10 + (static_cast<int>(num) - 48);
	// }
	
	// for (int j = 0; j < 2; j++)
	// {
	// 	num = actualPayDate[j];
	// 	date2 = date2 * 10 + (static_cast<int>(num) - 48);
	// }
	
	// for (int j = 3; j < 5; j++)
	// {
	// 	num = actualPayDate[j];
	// 	month2 = month2 * 10 + (static_cast<int>(num) - 48);
	// }
	
	// for (int j = 6; j < 10; j++)
	// {
	// 	num = actualPayDate[j];
	// 	year2 = year2 * 10 + (static_cast<int>(num) - 48);
	// }


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

bool checkDsMuon(int n, int code[20])
{
	bool check = false;
	for (int i = 0; i < 5; i++)
	{
		if (n == code[i])
		{
			check = true;
			break;
		}
	}

	return check;
}

bool checkIsExistTicket(int ma, int n, Ticket* z)
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (ma == z[i].MaPhieu)
		{
			if (z[i].actualPayDate.length() != 0 && checkFormatDate(z[i].actualPayDate) == true)
			{
				check = true;
				break;
			}
		}
	}
	return check;
}

bool checkIsExistCCCD(string cmnd, int n, Reader* x)
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (cmnd.compare(x[i].cccd) == 0)
		{
			check = false;
			break;
		}
	}
	return check;
}

bool checkIsExistBook(string book, int n, Book* y)
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (book.compare(y[i].ten_sach) == 0)
		{
			check = false;
			break;
		}
	}
	return check;
}

void upperName(string s)
{
	if (s[0] > 'Z')
	{
		s[0] = toupper(s[0]);
	}


	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			s[i + 1] = toupper(s[i + 1]);
		}
	}
}

void upperAllName(string s)
{
	
	for (int i = 0; i < s.length(); i++)
	{
		
			s[i] = toupper(s[i]);
	}
}

bool Login(string tendangnhap, string matkhau, fstream& Account) {
	bool check = true;
	
	string line;
	

	string Username;
	string Password;
	
	Account.open("Account.txt");
	if(Account.is_open())
	{
		getline(Account, line);
		istringstream ss(line);
		getline(ss, Username, ',');
		getline(ss, Password, ',');
		Account.close();
	}

	// errno_t account = fopen_s(&Account, "Account.txt", "r");
	// if (Account != NULL)
	// {
	// 	fgets(buffer, sizeof(buffer), Account);

	// 	data = strtok_s(buffer, ",", &temp);

	// 	strcpy_s(Username, data);
	// 	data = strtok_s(NULL, " ", &temp);
	// 	strcpy_s(Password, data);

	// 	fclose(Account);
	// }


	cout << "<<==========DANG NHAP=========>>" << endl;
	cout << "\nTen Dang Nhap: ";
	getline(cin, tendangnhap);
	// fgets(tendangnhap, sizeof(tendangnhap), stdin);
	// tendangnhap[strlen(tendangnhap) - 1] = '\0';
	cout << "Mat Khau: ";
	getline(cin, matkhau);
	// fgets(matkhau, sizeof(matkhau), stdin);
	// matkhau[strlen(matkhau) - 1] = '\0';

	while (tendangnhap.compare(Username) != 0 || matkhau.compare(Password) != 0)
	{
		system("cls");
		cout << "Ten dang nhap hay mat khau khong hop le" << endl;
		cout << "Vui long dang nhap lai!" << endl;
		cout << "<<==========DANG NHAP=========>>" << endl;
		cout << "\nTen Dang Nhap: ";
		getline(cin, tendangnhap);
		// fgets(tendangnhap, sizeof(tendangnhap), stdin);
		// tendangnhap[strlen(tendangnhap) - 1] = '\0';
		cout << "Mat Khau: ";
		getline(cin, matkhau);
		// fgets(matkhau, sizeof(matkhau), stdin);
		// matkhau[strlen(matkhau) - 1] = '\0';
	}

	if (tendangnhap.compare(Username) != 0 || matkhau.compare(Password) != 0)
	{
		check = false;
	}

	return check;
}

void updateFileSach(Book* y, int quantity, fstream& sach)
{
	sach.open("sach.txt", ios::out);

	if(sach.is_open())
	{
		sach << quantity << endl;
		for (int i = 0; i < quantity; i++)
		{
			sach << y[i].ISBN << "," << y[i].ISBN << "," << y[i].ten_sach << "," << y[i].tac_gia << "," << y[i].nha_xuat_ban << "," << y[i].nam_xuat_ban << "," << y[i].the_loai << "," << y[i].gia_tien << "," << y[i].so_luong << "," << y[i].BookIsBorrowing << endl;
		}
		sach.close();
		cout << "\nCap nhat du lieu sach thanh cong...!" << endl;
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}
}

void updateFileDocGia(Reader* x, int total, fstream& docgia)
{
	docgia.open("docgia.txt", ios::out);

	if(docgia.is_open())
	{
		docgia << total << endl;
		for (int i = 0; i < total; i++)
		{
			docgia << x[i].code << "," << x[i].ho_ten << "," << x[i].cccd << "," << x[i].ngay_sinh << "," << x[i].gioi_tinh << "," << x[i].email << "," << x[i].dia_chi << "," << x[i].ngay_lap_the << "," << x[i].ngay_het_han << endl;
		}
		docgia.close();
		cout << "\nCap nhat du lieu doc gia thanh cong...!" << endl;
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}
}

void updateFilePhieu(Ticket* z, int n, fstream& phieu)
{
	phieu.open("phieu.txt", ios::out);

	if(phieu.is_open())
	{
		phieu << n << endl;
		for (int i = 0; i < n; i++)
		{
			phieu << z[i].MaPhieu << "," << z[i].codeDGMuon << "," << z[i].borrowDate << "," << z[i].expectPayDate << "," << z[i].actualPayDate << "," << z[i].SLmuon << ",";

			for (int i = 0; i < z[i].SLmuon; i++)
			{
				phieu << z[i].codeSachMuon[i] << ",";
			}

			phieu << z[i].SLmat << "," << z[i].codeSachMat << "," << z[i].TongTienPhat << endl;
		}
		phieu.close();
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}
}

int sTOI(string s)
{
	int n = s.length();
	cout << n << endl;
	int ans = 0;
	int index;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			index = 0;
			ans = ans*10 + index;
		}else if(s[i] == '1')
		{
			index = 1;
			ans = ans*10 + index;
		}else if(s[i] == '2')
		{
			index = 2;
			ans = ans*10 + index;
		}else if(s[i] == '3')
		{
			index = 3;
			ans = ans*10 + index;
		}else if(s[i] == '4')
		{
			index = 4;
			ans = ans*10 + index;
		}else if(s[i] == '5')
		{
			index = 5;
			ans = ans*10 + index;
		}else if(s[i] == '6')
		{
			index = 6;
			ans = ans*10 + index;
		}else if(s[i] == '7')
		{
			index = 7;
			ans = ans*10 + index;
		}else if(s[i] == '8')
		{
			index = 8;
			ans = ans*10 + index;
		}else
		{
			index = 9;
			ans = ans*10 + index;
		}
	}
	return ans;
}