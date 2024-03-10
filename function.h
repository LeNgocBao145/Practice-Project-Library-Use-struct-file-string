#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include "Struct.h"
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

//Doc du lieu tu file docgia.txt va luu vao bien chua cac thong tin cua doc gia 
void ReadFileDocGia(fstream& docgia, Reader x[20], int &total);

//Doc du lieu tu file sach.txt va luu vao bien chua cac thong tin cua sach trong thu vien 
void ReadFileSach(fstream& sach, Book y[20], int& quantity);

//Doc du lieu tu file phieu.txt va luu vao bien chua cac thong tin cua phieu muon tra 
void ReadFilePhieu(fstream& phieu, Ticket z[20], int& so_Phieu);

//Ham de nhap ngay thang nam hien tai luc chay chuong trinh
void InputDayNow(string daynow);

//Xuat ra man hinh console giao dien menu
int show_menu();

//Them thong tin doc gia moi
void addDocgia(Reader x[20], int& j, fstream& docgia);

//Xuat ra man hinh console danh sach doc gia
void printDocgia(Reader x[20], int j);

//Tim kiem doc gia theo so cccd/cmnd
void searchDocgia(Reader x[20], int j);

//Chinh sua thong tin doc gia
void editDocgia(Reader x[20], int j, fstream& docgia);

//Tim kiem thong tin doc gia bang ho va ten
void searchTenDocGia(Reader x[20], int j);

//Xoa thong tin doc gia thong qua cccd
void deleteDocgia(Reader x[20], int& j, fstream& docgia);

//Random ma so doc gia
int MaDocGia();

//Them thong tin sach moi
void addSach(Book y[20], int& quantity, fstream& sach);

//Xuat ra man hinh console danh sach cua cac sach trong thu vien
void printSach(Book y[20], int quantity);

//Tim kiem sach thong qua ma ISBN 
void searchISBNSach(Book y[20], int quantity);

//Chinh sua thong tin sach qua ma ISBN
void editSach(Book y[20], int quantity, fstream& sach);

//Tim kiem thong tin sach thong qua ten sach
void searchTenSach(Book y[20], int quantity);

//Xoa thong tin sach thong qua ma ISBN
void deleteSach(Book y[20], int& quantity, fstream& sach);

//Random ma sach ISBN
int MaISBN();

//Lap phieu muon sach
void LapPhieuMuon(Reader x[20], Book y[20], Ticket z[20], int& n, int j, int quantity, string daynow, fstream& phieu, fstream& sach);

//Lap phieu tra sach
void LapPhieuTra(Book y[20], Ticket z[20], int n, int j, string daynow, fstream& phieu, fstream& sach);

//In ra man hinh console phieu muon gom co thoi gian muon va tra
void InPhieuMuonTra(Ticket z[20], int n);

//Random ma phieu
int CodeTicket();

//Kiem tra ma doc gia hay ma ISBN cua sach co trong danh sach doc gia hay trong danh sach cua sach trong thu vien khong
bool codeInListMaPhieu(int n, int j, Ticket z[20]);

//Ham kiem tra xem du lieu ma doc gia nhap vao co ton tai hay nam trong danh sach doc gia hay khong 
bool codeInListDGMuon(int n, int j, Reader x[20]);

//Ham kiem tra xem du lieu ma sach ISBN nhap vao co ton tai hay nam trong danh sach cac sach trong thu vien hay khong
bool codeInListSachMuon(int n, int j, Book y[20]);

//Thong ke so luong sach trong thu vien
void statistic_quantity_book(Book y[20], int quantity);

//Thong ke so luong sach theo the loai
void statsitic_quantity_category(Book y[20], int quantity);

//Thong ke so luong doc gia
void statistic_quantity_reader(Reader x[20], int total);

//Thong ke doc gia theo gioi tinh
void statistic_quantity_gender(Reader x[20], int total);

//Thong ke so luong sach dang duoc muon
void statistic_quantity_borrow(Book y[20], int quantity);

//Thong ke danh sach doc gia dang tre han
void statistic_listReaders_late(Ticket z[20], Reader x[20], int n, int total);

//Nhap lua chon sau khi xuat ra man hinh console menu
void Luachon(Reader x[20], Book y[20], Ticket z[20], int n, char choose, int& total, int& quantity, fstream& sach, fstream& docgia);

//Kiem tra dinh dang cua ngay thang nam theo (dd/mm/yyyy)
bool checkFormatDate(string date);

//Kiem tra so cccd/cmnd co du 12 so hay khong
bool checkCCCD(string cccd);

//Kiem tra xem email co ki tu @ hay khong
bool checkEmail(string email);

//Kiem tra xem gioi tinh co khac tu Nam va Nu hay khong
bool checkGender(string gender);

//Kiem tra CCCD/CMND cua doc gia hay ten sach cua sach co trong danh sach doc gia hay trong danh sach cua sach trong thu vien khong
bool cccdInListReader(string n, int j, Reader x[20]);

//Ham kiem tra xem du lieu ten doc gia nhap vao co ton tai hay nam trong danh sach doc gia trong thu vien hay khong
bool nameInListReader(string n, int j, Reader x[20]);

//Ham kiem tra xem du lieu ten sach nhap vao co ton tai hay nam trong danh sach cac sach trong thu vien hay khong
bool nameInListBook(string n, int j, Book y[20]);

//Ham kiem tra xem du lieu ma sach ISBN nhap vao co ton tai hay nam trong danh sach cac sach trong thu vien hay khong
bool codeInListBook(int code, int j, Book y[20]);

//In ra man hinh console cac lua chon chuc nang trong muc quan li doc gia
void ReaderManager();

//In ra man hinh console cac lua chon chuc nang trong muc quan li sach
void BookManager();

//In ra man hinh console cac lua chon chuc nang trong muc thong ke
void BasicStatistic();

//Tinh khoang cach giua ngay tra thuc te va ngay tra du kien de tinh tien phat
int Distance2Date(string expectPayDate, string actualPayDate);

//Kiem tra xem khi nhap vao sach mat thi ma ISBN sach mat co nam trong danh sach muon ko
bool checkDsMuon(int n, int code[20]);

//Kiem tra xem phieu muon hay tra da ton tai hay chua
bool checkIsExistTicket(int ma, int n, Ticket z[20]);

//Kiem tra xem CCCD/CMND cua doc gia da ton tai hay chua
bool checkIsExistCCCD(string cmnd, int n, Reader x[20]);

//Kiem tra xem ten sach da ton tai hay chua
bool checkIsExistBook(string book, int n, Book y[20]);

//Ham in hoa cac chu cai dau cua ho ten doc gia hay ten sach
void upperName(string s);

//Ham in hoa tat ca cac chu cai cua ten tac gia, ten nha xuat ban, ten the loai
void upperAllName(string s);

//Ham kiem tra xem thong tin ten dang nhap va mat khau co khop voi tai khoan Admin quan li thu vien hay khong
bool Login(string tendangnhap, string matkhau, fstream& Account);

void updateFileSach(Book y[20], int quantity, fstream& sach);

void updateFileDocGia(Reader x[20], int total, fstream& docgia);

void updateFilePhieu(Ticket z[20], int n, fstream& phieu);