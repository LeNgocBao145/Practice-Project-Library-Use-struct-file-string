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
	string ho_ten;
	string cccd;
	string ngay_sinh;
	string gioi_tinh;
	string email;
	string dia_chi;
	string ngay_lap_the;
	string ngay_het_han;
};

struct Book {
	int ISBN;
	string ten_sach;
	string tac_gia;
	string nha_xuat_ban;
	int nam_xuat_ban;
	string the_loai;
	int gia_tien;
	int so_luong;
	int BookIsBorrowing;
};


struct Ticket {
	int MaPhieu;
	string borrowDate;
	string expectPayDate;
	string actualPayDate;
	int codeDGMuon;
	int codeSachMuon[10];
	int SLmuon;
	int SLmat;
	int codeSachMat[10];
	int TongTienPhat;
};