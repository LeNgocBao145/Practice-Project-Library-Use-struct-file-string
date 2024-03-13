#include <iostream>

#include "function.h"
using namespace std;


void addSach(Book* y, int &quantity, fstream& sach)
{
	quantity++;



	y[quantity - 1].ISBN = MaISBN();
		cout << "Ten sach (toi da 39 ki tu): ";
		cin.ignore();
		getline(cin, y[quantity - 1].ten_sach);
		// fgets(y[quantity - 1].ten_sach, sizeof(y[quantity - 1].ten_sach), stdin);
		// y[quantity - 1].ten_sach[strlen(y[quantity - 1].ten_sach) - 1] = '\0';
		
		upperName(y[quantity - 1].ten_sach);

		while (checkIsExistBook(y[quantity - 1].ten_sach, quantity, y) == false)
		{

			cout << "Sach da ton tai trong thu vien. Xin vui long nhap lai!" << endl;

			int choose;
			cout << "1. Nhap lai ten sach" << endl;
			cout << "2. Thoat" << endl;
			cout << "\nNhap lua chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "Ban vui long nhap ten sach (toi da 39 ki tu): ";
				cin.ignore();
				getline(cin, y[quantity - 1].ten_sach);
				// fgets(y[quantity - 1].ten_sach, sizeof(y[quantity - 1].ten_sach), stdin);
				// y[quantity - 1].ten_sach[strlen(y[quantity - 1].ten_sach) - 1] = '\0';
				break;

			case 2:
				quantity--;
				return;
			}

		}

		upperName(y[quantity - 1].ten_sach);

		cout << "Tac gia (toi da 27 ki tu): ";
		getline(cin, y[quantity - 1].tac_gia);
		// fgets(y[quantity - 1].tac_gia, sizeof(y[quantity - 1].tac_gia), stdin);
		// y[quantity - 1].tac_gia[strlen(y[quantity - 1].tac_gia) - 1] = '\0';
		
		upperAllName(y[quantity - 1].tac_gia);

		cout << "Nha xuat ban (toi da 27 ki tu): ";
		getline(cin, y[quantity - 1].nha_xuat_ban);
		// fgets(y[quantity - 1].nha_xuat_ban, sizeof(y[quantity - 1].nha_xuat_ban), stdin);
		// y[quantity - 1].nha_xuat_ban[strlen(y[quantity - 1].nha_xuat_ban) - 1] = '\0';
		
		upperAllName(y[quantity - 1].nha_xuat_ban);

		cout << "Nam xuat ban (4 so): ";
		cin >> y[quantity - 1].nam_xuat_ban;
		while (y[quantity - 1].nam_xuat_ban > 3000 || y[quantity - 1].nam_xuat_ban < 2000)
		{
			cout << "Nam xuat ban (4 so): ";
			cin >> y[quantity - 1].nam_xuat_ban;
		}
		

		cout << "The loai (toi da 24 ki tu): ";
		cin.ignore();
		getline(cin, y[quantity - 1].the_loai);
		// fgets(y[quantity - 1].the_loai, sizeof(y[quantity - 1].the_loai), stdin);
		// y[quantity - 1].the_loai[strlen(y[quantity - 1].the_loai) - 1] = '\0';
		
		upperAllName(y[quantity - 1].the_loai);

		cout << "Gia tien: ";
		cin >> y[quantity - 1].gia_tien;
		

		cout << "So luong: ";
		cin >> y[quantity - 1].so_luong;
		

		y[quantity - 1].BookIsBorrowing = 0;
		
	sach.open("sach.txt", ios::app);

	if(sach.is_open())
	{
		sach << y[quantity - 1].ISBN << "," << y[quantity - 1].ISBN << "," << y[quantity - 1].ten_sach << "," << y[quantity - 1].tac_gia << "," << y[quantity - 1].nha_xuat_ban << "," << y[quantity - 1].nam_xuat_ban << "," << y[quantity - 1].the_loai << "," << y[quantity - 1].gia_tien << "," << y[quantity - 1].so_luong << "," << y[quantity - 1].BookIsBorrowing << endl;
		sach.close();
		cout << "\nCap nhat du lieu sach thanh cong...!" << endl;
	}
	else {
		cout << "Khong the mo tep tin." << endl;
	}

	// errno_t sach2 = fopen_s(&sach, "sach.txt", "r+");
	// if (sach != NULL)
	// {
	// 	fprintf(sach, "%d", quantity);
	// 	fclose(sach);
	// }

	// errno_t sach3 = fopen_s(&sach, "sach.txt", "a");

	// if (sach != NULL)
	// {
	// 	fprintf(sach, "%d,", y[quantity - 1].ISBN);

	// 	fprintf(sach, "%s,", y[quantity - 1].ten_sach);

	// 	fprintf(sach, "%s,", y[quantity - 1].tac_gia);

	// 	fprintf(sach, "%s,", y[quantity - 1].nha_xuat_ban);

	// 	fprintf(sach, "%d,", y[quantity - 1].nam_xuat_ban);

	// 	fprintf(sach, "%s,", y[quantity - 1].the_loai);

	// 	fprintf(sach, "%d,", y[quantity - 1].gia_tien);

	// 	fprintf(sach, "%d,", y[quantity - 1].so_luong);

	// 	fprintf(sach, "%d\n", y[quantity - 1].BookIsBorrowing);

	// 	fclose(sach);

	// 	cout << "\nCap nhat du lieu sach thanh cong...!" << endl;
	// }

	cout << "\nThong tin sach da duoc them!" << endl;
}


void printSach(Book* y, int quantity)
{
	cout << "<<==========================================================DANH SACH THONG TIN CUA SACH TRONG THU VIEN===============================================================>>" << endl;

	cout << "========================================================================================================================================================================\n";
	cout << "|ISBN  |" << setw(39) << left << "Ten Sach" << setw(28) << left << "|Tac gia" << setw(28) << left << "|Nha xuat ban" << setw(12) << left << "|Nam xuat ban" << setw(25) << left << "|The loai" << setw(15) << left << "|Gia tien" << setw(9) << left << "|So luong" << endl;
	cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
	for (int i = 0; i < quantity; i++) {
		cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(39) << left << y[i].ten_sach << "|" << setw(27) << left << y[i].tac_gia << "|" << setw(27) << left << y[i].nha_xuat_ban << "|" << setw(12) << left << y[i].nam_xuat_ban << "|" << setw(24) << left << y[i].the_loai << "|" << setw(14) << left << fixed << setprecision(3) << y[i].gia_tien << "|" << setw(9) << left << y[i].so_luong << endl;
		cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
	}
	cout << "========================================================================================================================================================================\n";
}


void searchISBNSach(Book* y, int quantity)
{
	int code;
	cout << "\nNhap ISBN cua sach ma ban muon tim kiem: ";
	cin >> code;

	while (cin.fail() || (codeInListBook(code, quantity, y) == false))
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Ma ISBN khong tim thay. Vui long nhap lai!" << endl;
		int choose;
		cout << "1. Nhap lai ma ISBN" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "\nNhap ISBN cua sach ma ban muon tim kiem: ";
			cin >> code;
			break;

		case 2:
			return;
		}

	}

	for (int i = 0; i < quantity; i++)
	{
		if (code == y[i].ISBN)
		{
			system("cls");
			cout << "========================================================================================================================================================================\n";
			cout << "|ISBN  |" << setw(39) << left << "Ten Sach" << setw(28) << left << "|Tac gia" << setw(28) << left << "|Nha xuat ban" << setw(12) << left << "|Nam xuat ban" << setw(25) << left << "|The loai" << setw(15) << left << "|Gia tien" << setw(9) << left << "|So luong" << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(39) << left << y[i].ten_sach << "|" << setw(27) << left << y[i].tac_gia << "|" << setw(27) << left << y[i].nha_xuat_ban << "|" << setw(12) << left << y[i].nam_xuat_ban << "|" << setw(24) << left << y[i].the_loai << "|" << setw(14) << left << y[i].gia_tien << "|" << setw(9) << left << y[i].so_luong << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "========================================================================================================================================================================\n";
		}
	}

}


void editSach(Book* y, int quantity, fstream& sach)
{

	int code;
	cout << "\nNhap ISBN cua sach ma ban muon chinh sua ";
	cin >> code;
	while (cin.fail() || (codeInListBook(code, quantity, y) == false))
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Ma ISBN khong tim thay. Vui long nhap lai!" << endl;
		int choose;
		cout << "1. Nhap lai ma ISBN" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "\nNhap ISBN cua sach ma ban muon chinh sua: ";
			cin >> code;
			break;

		case 2:
			return;
		}
	}

	int choose;


	for (int i = 0; i < quantity; i++)
	{

		if (code == y[i].ISBN)
		{
			system("cls");
			cout << "<<=======================================================================CHINH SUA THONG TIN SACH=====================================================================>>" << endl;

			cout << "========================================================================================================================================================================\n";
			cout << "|ISBN  |" << setw(39) << left << "Ten Sach" << setw(28) << left << "|Tac gia" << setw(28) << left << "|Nha xuat ban" << setw(12) << left << "|Nam xuat ban" << setw(25) << left << "|The loai" << setw(15) << left << "|Gia tien" << setw(9) << left << "|So luong" << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(39) << left << y[i].ten_sach << "|" << setw(27) << left << y[i].tac_gia << "|" << setw(27) << left << y[i].nha_xuat_ban << "|" << setw(12) << left << y[i].nam_xuat_ban << "|" << setw(24) << left << y[i].the_loai << "|" << setw(14) << left << y[i].gia_tien << "|" << setw(9) << left << y[i].so_luong << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "========================================================================================================================================================================\n";


			cout << "1. Chinh sua ten sach \n";
			cout << "2. Chinh sua ten tac gia \n";
			cout << "3. Chinh sua ten nha xuat ban \n";
			cout << "4. Chinh sua nam xuat ban \n";
			cout << "5. Chinh sua the loai \n";
			cout << "6. Chinh sua gia tien \n";
			cout << "7. Chinh sua so luong \n";
			cout << "0. Khong chinh sua \n";
			cout << "\nNhap lua chon (0->7) ";
			cin >> choose;


			switch (choose)
			{
			case 0:
				break;
			case 1:
				cout << "Nhap ten sach (toi da 39 ki tu): ";
				cin.ignore();
				getline(cin, y[i].ten_sach);
				// fgets(y[i].ten_sach, sizeof(y[i].ten_sach), stdin);
				// y[i].ten_sach[strlen(y[i].ten_sach) - 1] = '\0';
				upperName(y[i].ten_sach);
				break;
			case 2:
				cout << "Nhap ten tac gia (toi da 27 ki tu): ";
				cin.ignore();
				getline(cin, y[i].tac_gia);
				// fgets(y[i].tac_gia, sizeof(y[i].tac_gia), stdin);
				// y[i].tac_gia[strlen(y[i].tac_gia) - 1] = '\0';
				upperAllName(y[i].tac_gia);
				break;
			case 3:
				cout << "Nhap ten nha xuat ban (toi da 27 ki tu): ";
				cin.ignore();
				getline(cin, y[i].nha_xuat_ban);
				// fgets(y[i].nha_xuat_ban, sizeof(y[i].nha_xuat_ban), stdin);
				// y[i].nha_xuat_ban[strlen(y[i].nha_xuat_ban) - 1] = '\0';
				upperAllName(y[i].nha_xuat_ban);
				break;
			case 4:
				cout << "Nhap nam xuat ban (4 so): ";
				cin >> y[i].nam_xuat_ban;
				while (y[i].nam_xuat_ban > 3000 || y[i].nam_xuat_ban < 2000)
				{
					cout << "Nam xuat ban (4 so): ";
					cin >> y[i].nam_xuat_ban;
				}
				break;
			case 5:
				cout << "Nhap the loai (toi da 24 ki tu): ";
				cin.ignore();
				getline(cin, y[i].the_loai);
				// fgets(y[i].the_loai, sizeof(y[i].the_loai), stdin);
				// y[i].the_loai[strlen(y[i].the_loai) - 1] = '\0';
				upperAllName(y[i].the_loai);
				break;
			case 6:
				cout << "Nhap gia tien: ";
				cin.ignore();
				cin >> y[i].gia_tien;
				break;
			case 7:
				cout << "Chinh sua so luong: ";
				cin >> y[i].so_luong;
				break;
			default:
				cout << "Lua chon khong hop le. Vui long nhap lai!\n";

			}


			cout << "\nThong tin da duoc chinh sua!" << endl;
		}
	}
	
	sach.open("sach.txt");

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

	// errno_t sach2 = fopen_s(&sach, "sach.txt", "w");

	// if (sach != NULL)
	// {
	// 	fprintf(sach, "%d\n", quantity);
	// 	for (int i = 0; i < quantity; i++)
	// 	{
	// 		fprintf(sach, "%d,", y[i].ISBN);

	// 		fprintf(sach, "%s,", y[i].ten_sach);

	// 		fprintf(sach, "%s,", y[i].tac_gia);

	// 		fprintf(sach, "%s,", y[i].nha_xuat_ban);

	// 		fprintf(sach, "%d,", y[i].nam_xuat_ban);

	// 		fprintf(sach, "%s,", y[i].the_loai);

	// 		fprintf(sach, "%d,", y[i].gia_tien);

	// 		fprintf(sach, "%d,", y[i].so_luong);

	// 		fprintf(sach, "%d\n", y[i].BookIsBorrowing);

	// 	}
	// 	fclose(sach);

	// 	cout << "\nCap nhat du lieu sach thanh cong...!" << endl;
	// }
	// else {
	// 	cout << "Khong the mo tep tin." << endl;
	// }
}


void searchTenSach(Book* y, int quantity)
{
	string name;
	cout << "\nNhap ten sach ma ban muon tim kiem: ";
	cin.ignore();
	getline(cin, name);
	// fgets(name, sizeof(name), stdin);
	// name[strlen(name) - 1] = '\0';
	while (nameInListBook(name, quantity, y) == false)
	{
		cout << "Ten sach khong the duoc tim thay. Vui long nhap lai!" << endl;
		int choose;
		cout << "1. Nhap lai ten sach" << endl;
		cout << "2. Thoat" << endl;
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cin.ignore();
			cout << "\nNhap ten sach ma ban muon tim kiem: ";
			getline(cin, name);
			// fgets(name, sizeof(name), stdin);
			// name[strlen(name) - 1] = '\0';
			break;

		case 2:
			return;
		}
	}

	for (int i = 0; i < quantity; i++)
	{
		if (name.compare(y[i].ten_sach) == 0)
		{
			system("cls");
			cout << "========================================================================================================================================================================\n";
			cout << "|ISBN  |" << setw(39) << left << "Ten Sach" << setw(28) << left << "|Tac gia" << setw(28) << left << "|Nha xuat ban" << setw(12) << left << "|Nam xuat ban" << setw(25) << left << "|The loai" << setw(15) << left << "|Gia tien" << setw(9) << left << "|So luong" << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "|" << setw(6) << left << y[i].ISBN << "|" << setw(39) << left << y[i].ten_sach << "|" << setw(27) << left << y[i].tac_gia << "|" << setw(27) << left << y[i].nha_xuat_ban << "|" << setw(12) << left << y[i].nam_xuat_ban << "|" << setw(24) << left << y[i].the_loai << "|" << setw(14) << left << y[i].gia_tien << "|" << setw(9) << left << y[i].so_luong << endl;
			cout << "|" << setw(6) << "______" << "|" << setw(39) << "_______________________________________" << "|" << setw(27) << "___________________________" << "|" << setw(27) << "___________________________" << "|" << setw(12) << "____________" << "|" << setw(23) << "________________________" << "|" << setw(14) << "______________" << "|" << setw(9) << "___________" << endl;
			cout << "========================================================================================================================================================================\n";
		}
	}
}


void deleteSach(Book* y, int& quantity, fstream& sach)
{
	int choose;
	cout << "0. Thoat " << endl;
	cout << "1. Xoa toan bo thong tin sach " << endl;
	cout << "2. Xoa thong tin 1 cuon sach " << endl;

	cout << "\nNhap lua chon ";
	cin >> choose;

	switch (choose)
	{
	case 0:
		return;
	case 1:
		quantity = 0;
		break;
	case 2:
		int code;
		cout << "\nNhap ma ISBN cua sach ma ban muon xoa ";
		cin >> code;

		while (cin.fail() || (codeInListBook(code, quantity, y) == false))
		{
			cin.clear();
			cin.ignore(50, '\n');
			cout << "Ma ISBN khong tim thay. Vui long nhap lai!" << endl;
			int choose;
			cout << "1. Nhap lai ma ISBN" << endl;
			cout << "2. Thoat" << endl;
			cout << "\nNhap lua chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "\nNhap ISBN cua sach ma ban muon xoa: ";
				cin >> code;
				break;

			case 2:
				return;
			}
		}

		for (int i = 0; i < quantity; i++)
		{
			if (code == y[i].ISBN)
			{
				for (int j = quantity - 1; j > 0; j--)
				{
					for (int a = i; a < j; a++)
					{
						y[a].ISBN = y[a + 1].ISBN;
						y[a].ten_sach = y[a + 1].ten_sach;
						y[a].tac_gia = y[a + 1].tac_gia;
						y[a].nha_xuat_ban = y[a + 1].nha_xuat_ban;
						y[a].nam_xuat_ban = y[a + 1].nam_xuat_ban;
						y[a].the_loai = y[a + 1].the_loai;
						y[a].gia_tien = y[a + 1].gia_tien;
						y[a].so_luong = y[a + 1].so_luong;
					}
				}
			}
		}
		quantity--;
		break;

	}

	sach.open("sach.txt");

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

	cout << "\nThong tin sach da bi xoa" << endl;

	// errno_t sach2 = fopen_s(&sach, "sach.txt", "w");

	// if (sach != NULL)
	// {
	// 	fprintf(sach, "%d\n", quantity);
	// 	for (int i = 0; i < quantity; i++)
	// 	{
	// 		fprintf(sach, "%d,", y[i].ISBN);

	// 		fprintf(sach, "%s,", y[i].ten_sach);

	// 		fprintf(sach, "%s,", y[i].tac_gia);

	// 		fprintf(sach, "%s,", y[i].nha_xuat_ban);

	// 		fprintf(sach, "%d,", y[i].nam_xuat_ban);

	// 		fprintf(sach, "%s,", y[i].the_loai);

	// 		fprintf(sach, "%d,", y[i].gia_tien);

	// 		fprintf(sach, "%d,", y[i].so_luong);

	// 		fprintf(sach, "%d\n", y[i].BookIsBorrowing);

	// 	}
	// 	fclose(sach);
	// 	cout << "\nCap nhat du lieu sach thanh cong...!" << endl;
	// }
	// else {
	// 	cout << "Khong the mo tep tin." << endl;
	// }

	// cout << "\nThong tin sach da bi xoa" << endl;
}

int MaISBN()
{
	srand(static_cast<unsigned>(time(0)));
	int random = rand();
	while (random > 9999)
	{
		random /= 10;
	}
	return random;
}