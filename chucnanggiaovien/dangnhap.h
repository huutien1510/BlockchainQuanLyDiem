#pragma once
#include <iostream>
#include <string>
#include "TV_DH.h"
using namespace std;
//==================================================
void background(int x, int y, int w, int h, int s_color);
void box(int x, int y, int w, int h, int s_color, string nd, int x_nd, int y_nd);
void thanh_sang(int x, int y, int w, int s_color, string nd);
void nhap(string& nd, int& nhap1);
void nhap_vao_box(int xp, int yp, string& box_1, string& box_2, int& vaitro);
void box_dang_nhap(string& nd1, string& nd2, int& vaitro);