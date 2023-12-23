#include <iostream>

#include "function.h"
using namespace std;


void addDocgia(Reader x[20], int &j, FILE* docgia)
{
	cout << "<<==============================THEM THONG TIN DOC GIA==============================>>"<<endl;

	j++;


		x[j - 1].code = MaDocGia();

		cout << "\nHo va ten: ";
		scanf_s("\n");
		fgets(x[j - 1].ho_ten, sizeof(x[j - 1].ho_ten), stdin);
		x[j - 1].ho_ten[strlen(x[j - 1].ho_ten) - 1] = '\0';
		
		upperName(x[j - 1].ho_ten);

		cout << "CMND/CCCD: ";

		fgets(x[j - 1].cccd, sizeof(x[j - 1].cccd), stdin);
		x[j - 1].cccd[strlen(x[j - 1].cccd) - 1] = '\0';

		while (checkCCCD(x[j - 1].cccd) == false)
		{
			cout << "CMND/CCCD: ";
			scanf_s("\n");
			fgets(x[j - 1].cccd, sizeof(x[j - 1].cccd), stdin);
			x[j - 1].cccd[strlen(x[j - 1].cccd) - 1] = '\0';
		}

		while (checkIsExistCCCD(x[j - 1].cccd, j, x) == false)
		{

			cout << "\nMa CMND/CCCD da ton tai. Xin vui long nhap lai!" << endl;

			int choose;
			cout << "1. Nhap lai CCCD/CMND" << endl;
			cout << "2. Thoat" << endl;
			cout << "\nNhap lua chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Ban vui long nhap CMND/CCCD: ";
				cin.ignore();
				fgets(x[j - 1].cccd, sizeof(x[j - 1].cccd), stdin);
				x[j - 1].cccd[strlen(x[j - 1].cccd) - 1] = '\0';
				while (checkCCCD(x[j - 1].cccd) == false)
				{
					cout << "CMND/CCCD (12 so): ";
					scanf_s("\n");
					fgets(x[j - 1].cccd, sizeof(x[j - 1].cccd), stdin);
					x[j - 1].cccd[strlen(x[j - 1].cccd) - 1] = '\0';
				}
				break;

			case 2:
				j--;
				return;
			}

		}

		

		cout << "Ngay thang nam sinh (dd/mm/yyyy): ";

		fgets(x[j - 1].ngay_sinh, sizeof(x[j - 1].ngay_sinh), stdin);
		x[j - 1].ngay_sinh[strlen(x[j - 1].ngay_sinh) - 1] = '\0';

		while (checkFormatDate(x[j - 1].ngay_sinh) == false)
		{ //Kiem tra xem ngay thang nhap co dung dinh dang (dd/mm/yyyy) neu khac thi nhap lai
			cout << "Ngay thang nam sinh (dd/mm/yyyy): ";
			fgets(x[j - 1].ngay_sinh, sizeof(x[j - 1].ngay_sinh), stdin);
			x[j - 1].ngay_sinh[strlen(x[j - 1].ngay_sinh) - 1] = '\0';
		}

		

		cout << "Gioi tinh (Nam/Nu): ";
		fgets(x[j - 1].gioi_tinh, sizeof(x[j - 1].gioi_tinh), stdin);
		x[j - 1].gioi_tinh[strlen(x[j - 1].gioi_tinh) - 1] = '\0';

		while (checkGender(x[j - 1].gioi_tinh) == false)		//Kiem tra xem gioi tinh co phai Nam hay nu neu khac thì nhap lai
		{
			cout << "Gioi tinh (Nam/Nu): ";
			scanf_s("\n");
			fgets(x[j - 1].gioi_tinh, sizeof(x[j - 1].gioi_tinh), stdin);
			x[j - 1].gioi_tinh[strlen(x[j - 1].gioi_tinh) - 1] = '\0';
		}

		

		cout << "Email: ";

		fgets(x[j - 1].email, sizeof(x[j - 1].email), stdin);
		x[j - 1].email[strlen(x[j - 1].email) - 1] = '\0';

		while (checkEmail(x[j - 1].email) == false)
		{
			cout << "Email: ";
			scanf_s("\n");
			fgets(x[j - 1].email, sizeof(x[j - 1].email), stdin);
			x[j - 1].email[strlen(x[j - 1].email) - 1] = '\0';
		}

		

		cout << "Dia chi: ";
		scanf_s("\n");
		fgets(x[j - 1].dia_chi, sizeof(x[j - 1].dia_chi), stdin);
		x[j - 1].dia_chi[strlen(x[j - 1].dia_chi) - 1] = '\0';

		

		cout << "Ngay lap the: ";

		fgets(x[j - 1].ngay_lap_the, sizeof(x[j - 1].ngay_lap_the), stdin);
		x[j - 1].ngay_lap_the[strlen(x[j - 1].ngay_lap_the) - 1] = '\0';
		while (checkFormatDate(x[j - 1].ngay_lap_the) == false)
		{
			cout << "Ngay lap the: ";
			scanf_s("\n");
			fgets(x[j - 1].ngay_lap_the, sizeof(x[j - 1].ngay_lap_the), stdin);
			x[j - 1].ngay_lap_the[strlen(x[j - 1].ngay_lap_the) - 1] = '\0';
		}

		


		strcpy_s(x[j - 1].ngay_het_han, x[j - 1].ngay_lap_the);


		int year = 0;
		char num;
		char num2;
		for (int i = 6; i < 10; i++)
		{
			num = x[j - 1].ngay_het_han[i];
			year = year * 10 + (static_cast<int>(num) - 48);
		}
		year += 4;
		for (int i = 9; i > 5; i--)
		{
			num2 = static_cast<char>((year % 10) + 48);
			year /= 10;
			x[j - 1].ngay_het_han[i] = num2;
		}

		
		cout << "Ngay het han cua the: " << x[j - 1].ngay_het_han << endl;

		

	errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "r+");
	if (docgia != NULL)
	{
		fprintf(docgia, "%d\n", j);
		fclose(docgia);
	}

	errno_t docgia3 = fopen_s(&docgia, "docgia.txt", "a");
	if (docgia != NULL)
	{
		fprintf(docgia, "%d,", x[j - 1].code);

		fprintf(docgia, "%s,", x[j - 1].ho_ten);

		fprintf(docgia, "%s,", x[j - 1].cccd);

		fprintf(docgia, "%s,", x[j - 1].ngay_sinh);

		fprintf(docgia, "%s,", x[j - 1].gioi_tinh);

		fprintf(docgia, "%s,", x[j - 1].email);

		fprintf(docgia, "%s,", x[j - 1].dia_chi);

		fprintf(docgia, "%s,", x[j - 1].ngay_lap_the);

		fprintf(docgia, "%s\n", x[j - 1].ngay_het_han);

		fclose(docgia);

		cout << "\nCap nhat du lieu doc gia thanh cong...!" << endl;
	}

	cout << "\nThong tin doc gia da duoc them!" << endl;
}

void printDocgia(Reader x[20], int j)
{
	cout << "<<==================================================================DANH SACH THONG TIN DOC GIA=======================================================================>>" << endl;


	cout << "========================================================================================================================================================================\n";
	cout << "|Ma   |" << setw(24) << left << "Ho va Ten" << setw(14) << left << "|CMND/CCCD" << setw(12) << left << "|Ngay sinh" << setw(11) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(45) << left << "|Dia chi" << setw(14) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << endl;
	cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
	for (int i = 0; i < j; i++) {

		cout << "|" << setw(5) << left << x[i].code << "|" << setw(24) << left << x[i].ho_ten << "|" << setw(13) << left << x[i].cccd << "|" << setw(11) << left << x[i].ngay_sinh << "|" << setw(10) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(44) << left << x[i].dia_chi << "|" << setw(13) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
		cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
	}
	cout << "========================================================================================================================================================================\n";
}

void searchDocgia(Reader x[20], int j)
{
	char cmnd[14];
	cout << "\nNhap CCCD/CMND doc gia ma ban muon tim kiem: ";
	scanf_s("\n");
	fgets(cmnd, sizeof(cmnd), stdin);
	cmnd[strlen(cmnd) - 1] = '\0';
	while (cccdInListReader(cmnd, j, x) == false)
	{
		cout << "\nKhong tim thay CCCD/CMND cua doc gia.Ban vui long nhap lai!" << endl;

		int choose;
		cout << "1. Nhap lai CCCD/CMND doc gia" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Nhap CCCD/CMND doc gia ma ban muon tim kiem: ";
			scanf_s("\n");
			fgets(cmnd, sizeof(cmnd), stdin);
			cmnd[strlen(cmnd) - 1] = '\0';
			break;

		case 2:
			return;
		}

	}
	for (int i = 0; i < j; i++)
	{
		if (strcmp(cmnd, x[i].cccd) == 0)
		{
			cout << "========================================================================================================================================================================\n";
			cout << "|Ma   |" << setw(24) << left << "Ho va Ten" << setw(14) << left << "|CMND/CCCD" << setw(12) << left << "|Ngay sinh" << setw(11) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(45) << left << "|Dia chi" << setw(14) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "|" << setw(5) << left << x[i].code << "|" << setw(24) << left << x[i].ho_ten << "|" << setw(13) << left << x[i].cccd << "|" << setw(11) << left << x[i].ngay_sinh << "|" << setw(10) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(44) << left << x[i].dia_chi << "|" << setw(13) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "========================================================================================================================================================================\n";
		}
	}

}

void editDocgia(Reader x[20], int j, FILE* docgia)
{
	char cmnd[14];
	cout << "\nNhap CCCD/CMND cua doc gia ma ban muon chinh sua ";
	scanf_s("\n");
	fgets(cmnd, sizeof(cmnd), stdin);
	cmnd[strlen(cmnd) - 1] = '\0';

	while (cccdInListReader(cmnd, j, x) == false)
	{
		cout << "\nKhong tim thay CCCD/CMND cua doc gia.Ban vui long nhap lai!" << endl;

		int choose;
		cout << "1. Nhap lai CCCD/CMND doc gia" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Nhap CCCD/CMND doc gia ma ban muon chinh sua: ";
			scanf_s("\n");
			fgets(cmnd, sizeof(cmnd), stdin);
			cmnd[strlen(cmnd) - 1] = '\0';
			break;

		case 2:
			return;
		}
	}

	int choose;


	for (int i = 0; i < j; i++)
	{

		if (strcmp(cmnd, x[i].cccd) == 0)
		{
			system("cls");
			cout << "<<=====================================================================CHINH SUA THONG TIN DOC GIA====================================================================>>" << endl;


			cout << "========================================================================================================================================================================\n";
			cout << "|Ma   |" << setw(24) << left << "Ho va Ten" << setw(14) << left << "|CMND/CCCD" << setw(12) << left << "|Ngay sinh" << setw(11) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(45) << left << "|Dia chi" << setw(14) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "|" << setw(5) << left << x[i].code << "|" << setw(24) << left << x[i].ho_ten << "|" << setw(13) << left << x[i].cccd << "|" << setw(11) << left << x[i].ngay_sinh << "|" << setw(10) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(44) << left << x[i].dia_chi << "|" << setw(13) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "========================================================================================================================================================================\n";

			cout << "1. Chinh sua ho ten \n";
			cout << "2. Chinh sua CCCD/CMND \n";
			cout << "3. Chinh sua ngay thang nam sinh \n";
			cout << "4. Chinh sua gioi tinh \n";
			cout << "5. Chinh sua email \n";
			cout << "6. Chinh sua dia chi \n";
			cout << "0. Khong chinh sua \n";
			cout << "Nhap lua chon (0->6) ";
			cin >> choose;


			switch (choose)
			{
			case 0:
				break;
			case 1:
				cout << "Nhap ho ten: ";
				cin.ignore();
				fgets(x[i].ho_ten, sizeof(x[i].ho_ten), stdin);
				x[i].ho_ten[strlen(x[i].ho_ten) - 1] = '\0';
				break;
			case 2:
				cout << "Nhap CCCD/CMND: ";
				cin.ignore();
				fgets(x[i].cccd, sizeof(x[i].cccd), stdin);
				x[i].cccd[strlen(x[i].cccd) - 1] = '\0';
				while (checkCCCD(x[i].cccd) == false) {
					cout << "CMND/CCCD: ";
					scanf_s("\n");
					fgets(x[i].cccd, sizeof(x[i].cccd), stdin);
					x[i].cccd[strlen(x[i].cccd) - 1] = '\0';
				}
				break;
			case 3:
				cout << "Nhap ngay thang nam sinh: ";
				cin.ignore();
				fgets(x[i].ngay_sinh, sizeof(x[i].ngay_sinh), stdin);
				x[i].ngay_sinh[strlen(x[i].ngay_sinh) - 1] = '\0';
				while (checkFormatDate(x[i].ngay_sinh) == false)
				{ //Kiem tra xem ngay thang nhap co dung dinh dang (dd/mm/yyyy) neu khac thi nhap lai
					cout << "Ngay thang nam sinh: ";
					fgets(x[i].ngay_sinh, sizeof(x[i].ngay_sinh), stdin);
					x[i].ngay_sinh[strlen(x[i].ngay_sinh) - 1] = '\0';
				}
				break;
			case 4:
				cout << "Nhap gioi tinh: ";
				cin.ignore();
				fgets(x[i].gioi_tinh, sizeof(x[i].gioi_tinh), stdin);
				x[i].gioi_tinh[strlen(x[i].gioi_tinh) - 1] = '\0';
				while (checkGender(x[i].gioi_tinh)==false) 		//Kiem tra xem gioi tinh co phai Nam hay nu neu khac thì nhap lai
				{
					cout << "Gioi tinh (Nam/Nu): ";
					scanf_s("\n");
					fgets(x[i].gioi_tinh, sizeof(x[i].gioi_tinh), stdin);
					x[i].gioi_tinh[strlen(x[i].gioi_tinh) - 1] = '\0';
				}
				break;
			case 5:
				cout << "Nhap email: ";
				cin.ignore();
				fgets(x[i].email, sizeof(x[i].email), stdin);
				x[i].email[strlen(x[i].email) - 1] = '\0';
				while (checkEmail(x[i].email) == false)
				{
					cout << "Email: ";
					scanf_s("\n");
					fgets(x[i].email, sizeof(x[i].email), stdin);
					x[i].email[strlen(x[i].email) - 1] = '\0';
				}
				break;
			case 6:
				cout << "Nhap dia chi: ";
				cin.ignore();
				fgets(x[i].dia_chi, sizeof(x[i].dia_chi), stdin);
				x[i].dia_chi[strlen(x[i].dia_chi) - 1] = '\0';
				break;
			default:
				cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;

			}
		}

	}

	errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "w");

	if (docgia != NULL)
	{
		fprintf(docgia, "%d\n", j);
		for (int i = 0; i < j; i++)
		{
			fprintf(docgia, "%d,", x[i].code);

			fprintf(docgia, "%s,", x[i].ho_ten);

			fprintf(docgia, "%s,", x[i].cccd);

			fprintf(docgia, "%s,", x[i].ngay_sinh);

			fprintf(docgia, "%s,", x[i].gioi_tinh);

			fprintf(docgia, "%s,", x[i].email);

			fprintf(docgia, "%s,", x[i].dia_chi);

			fprintf(docgia, "%s,", x[i].ngay_lap_the);

			fprintf(docgia, "%s\n", x[i].ngay_het_han);

		}
		fclose(docgia);
		cout << "\nCap nhat du lieu doc gia thanh cong...!" << endl;
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}

	cout << "\nThong tin da duoc chinh sua!" << endl;
}

void searchTenDocGia(Reader x[20], int j)
{
	char name[100];
	cout << "\nNhap ho va ten doc gia ma ban muon tim kiem: ";
	scanf_s("\n");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	while (nameInListReader(name, j, x) == false)
	{

		cout << "\nKhong tim thay ten cua doc gia.Ban vui long nhap lai!" << endl;

		int choose;
		cout << "1. Nhap lai ho va ten doc gia" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Nhap ho va ten doc gia ma ban muon tim kiem: ";
			scanf_s("\n");
			fgets(name, sizeof(name), stdin);
			name[strlen(name) - 1] = '\0';
			break;

		case 2:
			return;
		}

	}

	for (int i = 0; i < j; i++)
	{
		if (strcmp(name, x[i].ho_ten) == 0)
		{
			cout << "========================================================================================================================================================================\n";
			cout << "|Ma   |" << setw(24) << left << "Ho va Ten" << setw(14) << left << "|CMND/CCCD" << setw(12) << left << "|Ngay sinh" << setw(11) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(45) << left << "|Dia chi" << setw(14) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "|" << setw(5) << left << x[i].code << "|" << setw(24) << left << x[i].ho_ten << "|" << setw(13) << left << x[i].cccd << "|" << setw(11) << left << x[i].ngay_sinh << "|" << setw(10) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(44) << left << x[i].dia_chi << "|" << setw(13) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(5) << "_____" << "|" << setw(24) << "________________________" << "|" << setw(12) << "_____________" << "|" << setw(11) << "___________" << "|" << setw(10) << "__________" << "|" << setw(22) << "__________________________" << "|" << setw(44) << "____________________________________________" << "|" << setw(11) << "_____________" << "|" << setw(12) << "_____________" << endl;
			cout << "========================================================================================================================================================================\n";
		}
	}
}

int MaDocGia()
{
	srand(static_cast<unsigned>(time(0)));
	int random = rand();
	while (random > 9999)
	{
		random /= 10;
	}
	return random;
}

void deleteDocgia(Reader x[20], int& total, FILE* docgia)
{
	int choose;
	cout << "0. Thoat " << endl;
	cout << "1. Xoa toan bo thong tin doc gia " << endl;
	cout << "2. Xoa thong tin 1 doc gia " << endl;

	cout << "\nNhap lua chon ";
	cin >> choose;

	while (choose != 0 && choose != 1 && choose != 2) {
		cout << "\nLua chon khong hop le. Vui long nhap lai!" << endl;
		cout << "\nNhap lua chon ";
		cin >> choose;
	}
	switch (choose)
	{
	case 0:
		return;
	case 1:
		total = 0;
		break;
	case 2:
		char cmnd[20];
		cout << "\nNhap CCCD/CMND cua doc gia ma ban muon xoa ";
		scanf_s("\n");
		fgets(cmnd, sizeof(cmnd), stdin);
		cmnd[strlen(cmnd) - 1] = '\0';
		while (cccdInListReader(cmnd, total, x) == false)
		{
			cout << "CCCD/CMND khong the duoc tim thay. Vui long nhap lai!" << endl;
			int choose;
			cout << "1. Nhap lai CCCD/CMND doc gia" << endl;
			cout << "2. Thoat" << endl;
			cout << "\nNhap lua chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Nhap CCCD/CMND doc gia ma ban muon xoa: ";
				scanf_s("\n");
				fgets(cmnd, sizeof(cmnd), stdin);
				cmnd[strlen(cmnd) - 1] = '\0';
				break;

			case 2:
				return;
			}
		}
		for (int i = 0; i < total; i++)
		{
			if (strcmp(cmnd, x[i].cccd) == 0)
			{
				for (int j = i; j < total - 1; j++)
				{
					x[j].code = x[j+1].code;
					strcpy_s(x[j].ho_ten, x[j+1].ho_ten);
					strcpy_s(x[j].cccd, x[j+1].cccd);
					strcpy_s(x[j].ngay_sinh, x[j+1].ngay_sinh);
					strcpy_s(x[j].gioi_tinh, x[j+1].gioi_tinh);
					strcpy_s(x[j].email, x[j+1].email);
					strcpy_s(x[j].dia_chi, x[j+1].dia_chi);
					strcpy_s(x[j].ngay_lap_the, x[j+1].ngay_lap_the);
					strcpy_s(x[j].ngay_het_han, x[j+1].ngay_het_han);
				}
				break;
			}
		}
		total--;
		break;

	}

	errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "w");

	if (docgia != NULL)
	{
		fprintf(docgia, "%d\n", total);
		for (int i = 0; i < total; i++)
		{
			fprintf(docgia, "%d,", x[i].code);

			fprintf(docgia, "%s,", x[i].ho_ten);

			fprintf(docgia, "%s,", x[i].cccd);

			fprintf(docgia, "%s,", x[i].ngay_sinh);

			fprintf(docgia, "%s,", x[i].gioi_tinh);

			fprintf(docgia, "%s,", x[i].email);

			fprintf(docgia, "%s,", x[i].dia_chi);

			fprintf(docgia, "%s,", x[i].ngay_lap_the);

			fprintf(docgia, "%s\n", x[i].ngay_het_han);

		}
		fclose(docgia);
		cout << "\nCap nhat du lieu doc gia thanh cong...!" << endl;
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}

	cout << "\nThong tin doc gia da bi xoa" << endl;
}