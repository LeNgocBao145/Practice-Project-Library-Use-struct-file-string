#pragma once
#include <iostream>
#include <string>
#include "string.h"
#include <stdio.h>
#include "Struct.h"
#include <fstream>
#include <cctype>
using namespace std;

void ReadFileDocGia(FILE* docgia, Reader x[20], int &total);

void ReadFileSach(FILE* sach, Book y[20], int& quantity);

void ReadFilePhieu(FILE* phieu, Ticket z[20], int& so_Phieu);

void InputDayNow(char daynow[20]);

//Xuat ra man hinh console giao dien menu
int show_menu();

//Them thong tin doc gia moi
void addDocgia(Reader x[20], int& j, FILE* docgia);

//Xuat ra man hinh console danh sach doc gia
void printDocgia(Reader x[20], int j);

//Tim kiem doc gia theo so cccd/cmnd
void searchDocgia(Reader x[20], int j);

//Chinh sua thong tin doc gia
void editDocgia(Reader x[20], int j, FILE* docgia);

//Tim kiem thong tin doc gia bang ho va ten
void searchTenDocGia(Reader x[20], int j);

//Xoa thong tin doc gia thong qua cccd
void deleteDocgia(Reader x[20], int& j, FILE* docgia);

//Random ma so doc gia
int MaDocGia();

//Them thong tin sach moi
void addSach(Book y[20], int& quantity, FILE* sach);

//Xuat ra man hinh console danh sach cua cac sach trong thu vien
void printSach(Book y[20], int quantity);

//Tim kiem sach thong qua ma ISBN 
void searchISBNSach(Book y[20], int quantity);

//Chinh sua thong tin sach qua ma ISBN
void editSach(Book y[20], int quantity, FILE* sach);

//Tim kiem thong tin sach thong qua ten sach
void searchTenSach(Book y[20], int quantity);

//Xoa thong tin sach thong qua ma ISBN
void deleteSach(Book y[20], int& quantity, FILE* sach);

//Random ma sach ISBN
int MaISBN();

//Lap phieu muon sach
void LapPhieuMuon(Reader x[20], Book y[20], Ticket z[20], int& n, int j, int quantity, char daynow[20], FILE* phieu, FILE* sach);

//Lap phieu tra sach
void LapPhieuTra(Book y[20], Ticket z[20], int n, int j, char daynow[20], FILE* phieu, FILE* sach);

//In ra man hinh console phieu muon gom co thoi gian muon va tra
void InPhieuMuonTra(Ticket z[20], int n);

//Random ma phieu
int CodeTicket();

//Kiem tra ma doc gia hay ma ISBN cua sach co trong danh sach doc gia hay trong danh sach cua sach trong thu vien khong
bool codeInListMaPhieu(int n, int j, Ticket z[20]);
bool codeInListDGMuon(int n, int j, Reader x[20]);
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
void statistic_listReaders_late(Ticket z[20], int n);

//Nhap lua chon sau khi xuat ra man hinh console menu
void Luachon(Reader x[20], Book y[20], Ticket z[20], int n, char choose, int& total, int& quantity, FILE* sach, FILE* docgia);

//Kiem tra dinh dang cua ngay thang nam theo (dd/mm/yyyy)
bool checkFormatDate(char date[20]);

//Kiem tra so cccd/cmnd co du 12 so hay khong
bool checkCCCD(char cccd[50]);

//Kiem tra xem email co ki tu @ hay khong
bool checkEmail(char email[50]);

//Kiem tra xem gioi tinh co khac tu Nam va Nu hay khong
bool checkGender(char gender[10]);

//Kiem tra CCD/CMND cua doc gia hay ten sach cua sach co trong danh sach doc gia hay trong danh sach cua sach trong thu vien khong
bool cccdInListReader(char n[100], int j, Reader x[20]);


bool nameInListReader(char n[100], int j, Reader x[20]);


bool nameInListBook(char n[100], int j, Book y[20]);


bool codeInListBook(int code, int j, Book y[20]);


//In ra man hinh console cac lua chon chuc nang trong muc quan li doc gia
void ReaderManager();

//In ra man hinh console cac lua chon chuc nang trong muc quan li sach
void BookManager();

//In ra man hinh console cac lua chon chuc nang trong muc thong ke
void BasicStatistic();

//Tinh khoang cach giua ngay tra thuc te va ngay tra du kien de tinh tien phat
int Distance2Date(char expectPayDate2[20], char actualPayDate2[20]);

//Kiem tra xem khi nhap vao sach mat thi ma ISBN sach mat co nam trong danh sach muon ko
bool checkDsMuon(int n, int code[20]);

//Kiem tra xem phieu muon hay tra da ton tai hay chua
bool checkIsExistTicket(int ma, int n, Ticket z[20]);

//Kiem tra xem CCCD/CMND cua doc gia da ton tai hay chua
bool checkIsExistCCCD(char cmnd[50], int n, Reader x[20]);

//Kiem tra xem ten sach da ton tai hay chua
bool checkIsExistBook(char book[50], int n, Book y[20]);


void upperName(char s[50]);

void upperAllName(char s[50]);

bool Login(char tendangnhap[100], char matkhau[100], FILE* Account);