#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "function.h"

using namespace std;

struct Reader {
	int code;
	char ho_ten[50];
	char cccd[50];
	char ngay_sinh[13];
	char gioi_tinh[10];
	char email[50];
	char dia_chi[50];
	char ngay_lap_the[20];
	char ngay_het_han[20];
};

struct Book {
	int ISBN;
	char ten_sach[50];
	char tac_gia[50];
	char nha_xuat_ban[50];
	int nam_xuat_ban;
	char the_loai[50];
	int gia_tien;
	int so_luong;
	int BookIsBorrowing;
};


struct Ticket {
	int MaPhieu;
	char borrowDate[20];
	char expectPayDate[20];
	char actualPayDate[20];
	int codeDGMuon;
	int codeSachMuon[10];
	int SLmuon;
	int SLmat;
	int codeSachMat[10];
	int TongTienPhat;
};