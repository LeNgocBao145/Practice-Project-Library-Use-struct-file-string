#include "function.h"
#include <iostream>
#include "Struct.h"


void ReadFileDocGia(FILE* docgia, Reader x[20], int &total)
{
	char buffer[2000];
	char* data;
	char* temp;

	errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "r");

	if (docgia != NULL) {
		fscanf_s(docgia, "%d\n", &total);

		for (int i = 0; i < total; i++) {

			fgets(buffer, sizeof(buffer), docgia);

			data = strtok_s(buffer, ",", &temp);


			x[i].code = atoi(data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].ho_ten, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].cccd, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].ngay_sinh, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].gioi_tinh, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].email, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].dia_chi, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].ngay_lap_the, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(x[i].ngay_het_han, data);
			x[i].ngay_het_han[strlen(x[i].ngay_het_han) - 1] = '\0';
			data = strtok_s(NULL, ",", &temp);

		}
		fclose(docgia);

		cout << "\nDU LIEU DOC GIA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
}

void ReadFileSach(FILE* sach, Book y[20], int &quantity)
{
	char buffer[2000];
	char* data;
	char* temp;

	errno_t sach2 = fopen_s(&sach, "sach.txt", "r");

	if (sach != NULL) {
		fscanf_s(sach, "%d\n", &quantity);
		for (int i = 0; i < quantity; i++) {

			fgets(buffer, sizeof(buffer), sach);

			data = strtok_s(buffer, ",", &temp);


			y[i].ISBN = atoi(data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(y[i].ten_sach, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(y[i].tac_gia, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(y[i].nha_xuat_ban, data);
			data = strtok_s(NULL, ",", &temp);

			y[i].nam_xuat_ban = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			strcpy_s(y[i].the_loai, data);
			data = strtok_s(NULL, ",", &temp);

			y[i].gia_tien = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			y[i].so_luong = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			y[i].BookIsBorrowing = atoi(data);
			data = strtok_s(NULL, ",", &temp);

		}
		fclose(sach);
		cout << "\nDU LIEU SACH DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
}

void ReadFilePhieu(FILE* phieu, Ticket z[20], int &so_Phieu)
{

	char buffer[2000];
	char* data;
	char* temp;

	errno_t phieu2 = fopen_s(&phieu, "phieu.txt", "r");

	if (phieu != NULL) {
		fscanf_s(phieu, "%d\n", &so_Phieu);
		for (int i = 0; i < so_Phieu; i++) {

			fgets(buffer, sizeof(buffer), phieu);

			data = strtok_s(buffer, ",", &temp);


			z[i].MaPhieu = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			z[i].codeDGMuon = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			strcpy_s(z[i].borrowDate, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(z[i].expectPayDate, data);
			data = strtok_s(NULL, ",", &temp);


			strcpy_s(z[i].actualPayDate, data);
			data = strtok_s(NULL, ",", &temp);

			z[i].SLmuon = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			for (int h = 0; h < z[i].SLmuon; h++)
			{
				z[i].codeSachMuon[h] = atoi(data);
				data = strtok_s(NULL, ",", &temp);
			}


			z[i].SLmat = atoi(data);
			data = strtok_s(NULL, ",", &temp);

			for (int h = 0; h < z[i].SLmat; h++)
			{
				z[i].codeSachMat[h] = atoi(data);
				data = strtok_s(NULL, ",", &temp);
			}


			z[i].TongTienPhat = atoi(data);
			data = strtok_s(NULL, ",", &temp);

		}
		fclose(phieu);
		cout << "\nDU LIEU PHIEU MUON TRA DA DUOC TAI LEN CHUONG TRINH THANH CONG...!" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
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


void InputDayNow(char daynow[20])
{
	system("cls");
	cout << "Truoc khi bat dau chuong trinh. Xin ban vui long nhap ngay thang nam hien tai (dd/mm/yyyy): ";
	cin >> daynow;
	while (checkFormatDate(daynow) == false)
	{
		cout << "Ngay thang nam (dd/mm/yyyy) khong hop le. Xin ban vui long nhap lai!!: ";
		cin >> daynow;
	}
}

//Ham dung de nhap lua chon a, b, c, d, e, f trong cac muc 1->6
void Luachon(Reader x[20], Book y[20], Ticket z[20], int n, char choose, int& total, int& quantity, FILE* sach, FILE* docgia)
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

bool codeInListBook(int code, int j, Book y[20])
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

bool cccdInListReader(char n[100], int j, Reader x[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (strcmp(n, x[i].cccd) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}

bool nameInListReader(char n[100], int j, Reader x[20])
{
	bool check = false;
	for (int i = 0; i < j; i++)
	{
		if (strcmp(n, x[i].ho_ten) == 0)
		{
			check = true;
			break;
		}
	}

	return check;
}



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

bool checkIsExistTicket(int ma, int n, Ticket z[20])
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (ma == z[i].MaPhieu)
		{
			if (strlen(z[i].actualPayDate) != 0 && checkFormatDate(z[i].actualPayDate) == true)
			{
				check = true;
				break;
			}
		}
	}
	return check;
}

bool checkIsExistCCCD(char cmnd[50], int n, Reader x[20])
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (strcmp(cmnd, x[i].cccd) == 0)
		{
			check = false;
			break;
		}
	}
	return check;
}

bool checkIsExistBook(char book[50], int n, Book y[20])
{
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (strcmp(book, y[i].ten_sach) == 0)
		{
			check = false;
			break;
		}
	}
	return check;
}

void upperName(char s[50])
{
	if (s[0] > 'Z')
	{
		s[0] = toupper(s[0]);
	}


	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			s[i + 1] = toupper(s[i + 1]);
		}
	}
}

void upperAllName(char s[50])
{
	
	for (int i = 0; i < strlen(s); i++)
	{
		
			s[i] = toupper(s[i]);
	}
}

bool Login(char tendangnhap[100], char matkhau[100], FILE* Account) {
	bool check = true;

	char buffer[100]{};
	char* data{};
	char* temp{};

	char Username[100]{};
	char Password[100]{};

	errno_t account = fopen_s(&Account, "Account.txt", "r");
	if (Account != NULL)
	{
		fgets(buffer, sizeof(buffer), Account);

		data = strtok_s(buffer, ",", &temp);

		strcpy_s(Username, data);
		data = strtok_s(NULL, " ", &temp);
		strcpy_s(Password, data);

		fclose(Account);
	}


	cout << "<<==========DANG NHAP=========>>" << endl;
	cout << "\nTen Dang Nhap: ";
	fgets(tendangnhap, sizeof(tendangnhap), stdin);
	tendangnhap[strlen(tendangnhap) - 1] = '\0';
	cout << "Mat Khau: ";
	fgets(matkhau, sizeof(matkhau), stdin);
	matkhau[strlen(matkhau) - 1] = '\0';

	while (strcmp(tendangnhap, Username) != 0 || strcmp(matkhau, Password) != 0)
	{
		system("cls");
		cout << "Ten dang nhap hay mat khau khong hop le" << endl;
		cout << "Vui long dang nhap lai!" << endl;
		cout << "<<==========DANG NHAP=========>>" << endl;
		cout << "\nTen Dang Nhap: ";
		fgets(tendangnhap, sizeof(tendangnhap), stdin);
		tendangnhap[strlen(tendangnhap) - 1] = '\0';
		cout << "Mat Khau: ";
		fgets(matkhau, sizeof(matkhau), stdin);
		matkhau[strlen(matkhau) - 1] = '\0';
	}

	if (strcmp(tendangnhap, Username) != 0 || strcmp(matkhau, Password) != 0)
	{
		check = false;
	}

	return check;
}
