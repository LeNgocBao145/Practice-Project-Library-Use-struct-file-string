
#include <iostream>
#include "function.h"
#include "Struct.h"
using namespace std;




int main()
{
	char choose{};
	
	int total = 5;
	int quantity = 7;
	int so_Phieu = 5;

	Reader x[20];
	Book y[20];
	Ticket z[20];

	FILE *docgia;
	errno_t docgia2 = fopen_s(&docgia, "docgia.txt", "r");
	
	if (docgia != NULL) {
		
		for (int i = 0; i < total; i++) {
			fscanf_s(docgia, "%d%*[\n]", &x[i].code);

			fgets(x[i].ho_ten, sizeof(x[i].ho_ten), docgia);
			x[i].ho_ten[strlen(x[i].ho_ten) - 1] = '\0';

			fgets(x[i].cccd, sizeof(x[i].cccd), docgia);
			x[i].cccd[strlen(x[i].cccd) - 1] = '\0';

			fgets(x[i].ngay_sinh, sizeof(x[i].ngay_sinh), docgia);
			x[i].ngay_sinh[strlen(x[i].ngay_sinh) - 1] = '\0';

			fgets(x[i].gioi_tinh, sizeof(x[i].gioi_tinh), docgia);
			x[i].gioi_tinh[strlen(x[i].gioi_tinh) - 1] = '\0';

			fgets(x[i].email, sizeof(x[i].email), docgia);
			x[i].email[strlen(x[i].email) - 1] = '\0';

			fgets(x[i].dia_chi, sizeof(x[i].dia_chi), docgia);
			x[i].dia_chi[strlen(x[i].dia_chi) - 1] = '\0';

			fgets(x[i].ngay_lap_the, sizeof(x[i].ngay_lap_the), docgia);
			x[i].ngay_lap_the[strlen(x[i].ngay_lap_the) - 1] = '\0';

			fgets(x[i].ngay_het_han, sizeof(x[i].ngay_het_han), docgia);
			x[i].ngay_het_han[strlen(x[i].ngay_het_han) - 1] = '\0';
		}
		fclose(docgia);
	}

	FILE *sach;
	errno_t sach2 = fopen_s(&sach, "sach.txt", "r");

	if (sach != NULL) {
		
		for (int i = 0; i < quantity; i++) {
			fscanf_s(sach, "%d%*[\n]", &y[i].ISBN);

			fgets(y[i].ten_sach, sizeof(y[i].ten_sach), sach);
			y[i].ten_sach[strlen(y[i].ten_sach) - 1] = '\0';

			fgets(y[i].tac_gia, sizeof(y[i].tac_gia), sach);
			y[i].tac_gia[strlen(y[i].tac_gia) - 1] = '\0';

			fgets(y[i].nha_xuat_ban, sizeof(y[i].nha_xuat_ban), sach);
			y[i].nha_xuat_ban[strlen(y[i].nha_xuat_ban) - 1] = '\0';

			fscanf_s(sach, "%d%*[\n]", &y[i].nam_xuat_ban);

			fgets(y[i].the_loai, sizeof(y[i].the_loai), sach);
			y[i].the_loai[strlen(y[i].the_loai) - 1] = '\0';

			fscanf_s(sach, "%d%*[\n]", &y[i].gia_tien);

			fscanf_s(sach, "%d%*[\n]", &y[i].so_luong);

			fscanf_s(sach, "%d%*[\n]", &y[i].BookIsBorrowing);
		}
		fclose(sach);
	}


	FILE* phieu;
	errno_t phieu2 = fopen_s(&phieu, "phieu.txt", "r");

	if (phieu != NULL) {

		for (int i = 0; i < so_Phieu; i++) {
			fscanf_s(phieu, "%d%*[\n]", &z[i].MaPhieu);

			fgets(z[i].borrowDate, sizeof(z[i].borrowDate), phieu);
			z[i].borrowDate[strlen(z[i].borrowDate) - 1] = '\0';

			fgets(z[i].expectPayDate, sizeof(z[i].expectPayDate), phieu);
			z[i].expectPayDate[strlen(z[i].expectPayDate) - 1] = '\0';

			fgets(z[i].actualPayDate, sizeof(z[i].actualPayDate), phieu);
			z[i].actualPayDate[strlen(z[i].actualPayDate) - 1] = '\0';

			fscanf_s(phieu, "%d%*[\n]", &z[i].codeDGMuon);

			fscanf_s(phieu, "%d%*[\n]", &z[i].SLmuon);

			for (int h = 0; h < z[i].SLmuon; h++)
			{
				fscanf_s(phieu, "%d", &z[i].codeSachMuon[h]);
			}

			fscanf_s(phieu, "%d%*[\n]", &z[i].SLmat);


			for (int h = 0; h < z[i].SLmat; h++)
			{
				fscanf_s(phieu, "%d", &z[i].codeSachMat[h]);
			}

			fscanf_s(phieu, "%d%*[\n]", &z[i].TongTienPhat);
		}
		fclose(phieu);
	}

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
			LapPhieuMuon(x, y, z, so_Phieu, total, quantity, daynow);
			break;
		case  4:
			LapPhieuTra(y,z, so_Phieu, quantity, daynow);
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


		Luachon(x, y, z, n, choose, total, quantity, sach);


		char is_continue;
		cout << "\nBan co muon lua chon tiep khong (y/n)" << endl;
		cin.ignore();
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