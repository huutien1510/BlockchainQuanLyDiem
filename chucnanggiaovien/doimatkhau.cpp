#include <iostream>
#include <string>
#include "TV_DH.h"
using namespace std;
//==================================================

void box_doi_mat_khau(int x, int y, int w, int h, int s_color, string nd, int x_nd, int y_nd)
{
	SetColor(7);
	gotoXY(x_nd, y_nd);
	cout << nd;
	SetColor(s_color);
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + w, y);
	cout << char(191);
	gotoXY(x, y + h);
	cout << char(192);
	gotoXY(x + w, y + h);
	cout << char(217);
}

void thanh_sang_mat_khau(int x, int y, int w, int s_color, string nd)
{
	textcolor(s_color * 16);
	for (int ix = x; ix <= x + w - 1; ix++)
	{
		gotoXY(ix, y);
		cout << " ";
	}
	SetColor(7);
	gotoXY(x, y);
	cout << nd;
}

void nhap_vao_box_mat_khau(int xp, int yp, string box_1, string& box_2, string& matkhau)
{
	box_2 = matkhau = "";
	char c;
	SetColor(8);
	gotoXY(49, 11);
	int nhap1 = 0;
	int nhap2 = 0;
	while (true)
	{
		if (whereX() == 49)
		{
			if (whereY() == 11)
			{
				if (nhap1 == 0)
				{
					ShowCur(2);
					getline(cin, box_2);
					gotoXY(xp, 11);
					for (int i = 1; i <= box_2.length(); i++)
					{
						cout << "*";
					}
					gotoXY(49, 14);
					nhap1 = 1;
				}
				SetColor(8);
			}
			if (whereY() == 14)
			{
				if (nhap2 == 0)
				{
					ShowCur(2);
					getline(cin, matkhau);
					gotoXY(xp, yp + 3);
					for (int i = 1; i <= matkhau.length(); i++)
					{
						cout << "*";
					}
					gotoXY(57, 19);
					nhap2 = 1;
				}
			}
		}
		//bắt sự kiện khi ấn phím.
		if (whereX() == 57)
		{
			thanh_sang_mat_khau(57, 19, 9, 12, "Xac nhan");
			ShowCur(0);
		}
		if (_kbhit())
		{
			c = _getch();
			if (c == 13)	
				return;
		}
	}
}

	void doi_mat_khau(string nd1, string & nd2, string & matkhau)
	{
		system("cls");
		gotoXY(55, 6);
		SetColor(4);
		cout << "DOI MAT KHAU";
		gotoXY(37, 9);
		SetColor(8);
		cout << "Ten dang nhap: " << nd1;
		box_doi_mat_khau(48, 10, 30, 2, 11, "Xac nhan mat khau ", 30, 11);
		box_doi_mat_khau(48, 13, 30, 2, 11, "Nhap mat khau moi ", 30, 14);
		box_doi_mat_khau(55, 18, 12, 2, 11, "Xac nhan", 57, 19);
		nhap_vao_box_mat_khau(49, 11, nd1, nd2, matkhau);
		return;
	}