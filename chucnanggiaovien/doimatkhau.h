#pragma once
#include <iostream>
#include <string>
#include "TV_DH.h"
using namespace std;

void box_doi_mat_khau(int x, int y, int w, int h, int s_color, string nd, int x_nd, int y_nd);
void thanh_sang_mat_khau(int x, int y, int w, int s_color, string nd);
void nhap_vao_box_mat_khau(int xp, int yp, string box_1, string &box_2, string& matkhau);
void doi_mat_khau(string nd1, string &nd2, string& matkhau);


