#include <iostream>

#include "function.h"
using namespace std;


void addDocgia(Reader x[20], int &j)
{

	j++;
	x[j - 1].code = MaDocGia();
	cout << "Ho va ten: ";
	scanf_s("\n");
	fgets(x[j - 1].ho_ten, sizeof(x[j - 1].ho_ten), stdin);
	x[j - 1].ho_ten[strlen(x[j - 1].ho_ten) - 1] = '\0';
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



	cout << "\nThong tin doc gia da duoc them!" << endl;
}

void printDocgia(Reader x[20], int j)
{
	cout << "========================================================================================================================================================================\n";
	cout << "|Ma    |" << setw(18) << left << "Ho va Ten" << setw(16) << left << "|CMND/CCCD" << setw(13) << left << "|Ngay sinh" << setw(12) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(44) << left << "|Dia chi" << setw(16) << left << "|Ngay lap the" << setw(10) << left << "|Ngay het han" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "_____________" << endl;
	for (int i = 0; i < j; i++) {
		cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << setw(15) << left << x[i].cccd << "|" << setw(12) << left << x[i].ngay_sinh << "|" << setw(11) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(43) << left << x[i].dia_chi << "|" << setw(15) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "_____________" << endl;
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
	for (int i = 0; i < j; i++)
	{
		if (strcmp(cmnd, x[i].cccd) == 0)
		{
			cout << "========================================================================================================================================================================\n";
			cout << "|Ma    |" << setw(18) << left << "Ho va Ten" << setw(16) << left << "|CMND/CCCD" << setw(13) << left << "|Ngay sinh" << setw(12) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(44) << left << "|Dia chi" << setw(16) << left << "|Ngay lap the" << setw(12) << left << "|Ngay het han" << endl;
			cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << setw(15) << left << x[i].cccd << "|" << setw(12) << left << x[i].ngay_sinh << "|" << setw(11) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(43) << left << x[i].dia_chi << "|" << setw(15) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(14) << "_____________" << endl;
			cout << "========================================================================================================================================================================\n";
		}
	}

}

void editDocgia(Reader x[20], int j)
{
	char cmnd[14];
	cout << "\nNhap CCCD/CMND cua doc gia ma ban muon chinh sua ";
	scanf_s("\n");
	fgets(cmnd, sizeof(cmnd), stdin);
	cmnd[strlen(cmnd) - 1] = '\0';

	int choose;


	for (int i = 0; i < j; i++)
	{

		if (strcmp(cmnd, x[i].cccd) == 0)
		{
			system("cls");
			cout << "========================================================================================================================================================================\n";
			cout << "|Ma    |" << setw(18) << left << "Ho va Ten" << setw(16) << left << "|CMND/CCCD" << setw(13) << left << "|Ngay sinh" << setw(12) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(44) << left << "|Dia chi" << setw(16) << left << "|Ngay lap the" << setw(12) << left << "|Ngay het han" << endl;
			cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << setw(15) << left << x[i].cccd << "|" << setw(12) << left << x[i].ngay_sinh << "|" << setw(11) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(43) << left << x[i].dia_chi << "|" << setw(15) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(14) << "_____________" << endl;
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

	cout << "\nThong tin da duoc chinh sua!" << endl;
}

void searchTenDocGia(Reader x[20], int j)
{
	char name[100];
	cout << "\nNhap ho va ten doc gia ma ban muon tim kiem: ";
	scanf_s("\n");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	for (int i = 0; i < j; i++)
	{
		if (strcmp(name, x[i].ho_ten) == 0)
		{
			cout << "========================================================================================================================================================================\n";
			cout << "|Ma    |" << setw(18) << left << "Ho va Ten" << setw(16) << left << "|CMND/CCCD" << setw(13) << left << "|Ngay sinh" << setw(12) << left << "|Gioi tinh" << setw(27) << left << "|Email" << setw(44) << left << "|Dia chi" << setw(16) << left << "|Ngay lap the" << setw(12) << left << "|Ngay het han" << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(14) << "_____________" << endl;
			cout << "|" << setw(6) << left << x[i].code << "|" << setw(18) << left << x[i].ho_ten << "|" << setw(15) << left << x[i].cccd << "|" << setw(12) << left << x[i].ngay_sinh << "|" << setw(11) << left << x[i].gioi_tinh << "|" << setw(26) << left << x[i].email << "|" << setw(43) << left << x[i].dia_chi << "|" << setw(15) << left << x[i].ngay_lap_the << "|" << setw(13) << left << x[i].ngay_het_han << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(18) << "__________________" << "|" << setw(15) << "_______________" << "|" << setw(12) << "____________" << "|" << setw(11) << "___________" << "|" << setw(22) << "__________________________" << "|" << setw(43) << "___________________________________________" << "|" << setw(15) << "_______________" << "|" << setw(14) << "_____________" << endl;
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

void deleteDocgia(Reader x[20], int& total)
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
		/*while (nameInList(cmnd, total, x) == false)
		{
			cout << "CCCD/CMND khong the duoc tim thay. Vui long nhap lai!" << endl;
			cout << "\nNhap CCCD/CMND cua doc gia ma ban muon xoa ";
			scanf_s("\n");
			fgets(cmnd, sizeof(cmnd), stdin);
			cmnd[strlen(cmnd) - 1] = '\0';
		}*/
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


	cout << "\nThong tin doc gia da bi xoa" << endl;
}