#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "xulyGV.h"
#include "xulySV.h"
#include "dinh_nghia_struct.h"

using namespace std;

float diem_so(int xem, int stt, int& mon_hoc);
void bang_diem(int x, int y, int w, int h, int s_colort, int so_o_doc, int so_o_ngang, int xem, int vaitro, int& mon_hoc);
void thanh_sang2(int x, int y, int w, int colort, string nd);
void box_back(int x, int y, int w, int h, int s_colort, string nd);
void xemdiem(int xem, int vaitro, int huy_enter, int so_hs, int& mon_hoc);
int xuly(int &sgv,int &shs,int vaitro, string ten_dang_nhap, string mat_khau,int sua,int stt, int mon, float ndiem,string npass);
