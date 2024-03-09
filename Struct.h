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
	string ho_ten[50];
	string cccd[50];
	string ngay_sinh[13];
	string gioi_tinh[10];
	string email[50];
	string dia_chi[50];
	string ngay_lap_the[20];
	string ngay_het_han[20];
};

struct Book {
	int ISBN;
	string ten_sach[50];
	string tac_gia[50];
	string nha_xuat_ban[50];
	int nam_xuat_ban;
	string the_loai[50];
	int gia_tien;
	int so_luong;
	int BookIsBorrowing;
};


struct Ticket {
	int MaPhieu;
	string borrowDate[20];
	string expectPayDate[20];
	string actualPayDate[20];
	int codeDGMuon;
	int codeSachMuon[10];
	int SLmuon;
	int SLmat;
	int codeSachMat[10];
	int TongTienPhat;
};