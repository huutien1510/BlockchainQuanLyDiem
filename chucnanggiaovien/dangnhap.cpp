#include <iostream>
#include <string>
#include "TV_DH.h"
#include "xuly.h"
using namespace std;
//==================================================
void background(int x, int y, int w, int h, int s_color)
{
	SetColor(7);
	gotoXY(56, y + 1);
	cout << "QUAN LI DIEM";
	gotoXY(34, y + 3);
	cout << "DANG NHAP";
	gotoXY(53, y + 3);
	cout << "Giao vien";
	gotoXY(68, y + 3);
	cout << "Hoc sinh";
	gotoXY(57, 19);
	cout << "Dang nhap";
	SetColor(11);
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y + 2);
		cout << char(196);
		gotoXY(ix, y + 4);
		cout << char(196);
	}

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

void box(int x, int y, int w, int h, int s_color, string nd, int x_nd, int y_nd)
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
void thanh_sang(int x, int y, int w, int s_color, string nd)
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

void nhap_vao_box(int xp, int yp, string& box_1, string& box_2, int& vaitro)
{
	box_1 = box_2 = "";
	char c;
	SetColor(8);
	gotoXY(53, 8);
	int nhap1 = 0;
	int nhap2 = 0;
	int nhap3 = 0;
	int nhap4 = 0;
	while (true)
	{
		if (whereX() == 49)
		{
			if (whereY() == 11)
			{
				//do
				//{
				if (nhap1 == 0)
				{
					ShowCur(2);
					getline(cin, box_1);
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
					getline(cin, box_2);
					gotoXY(xp, yp + 3);
					for (int i = 1; i <= box_2.length(); i++)
					{
						cout << "*";
					}
					gotoXY(57, 19);
					nhap2 = 1;
				}
			}
		}
		//bắt sự kiện khi ấn phím.
		if (whereX() == 53)
		{
			gotoXY(66, 8);
			cout << " ";
			gotoXY(51, 8);
			cout << char(004);
			ShowCur(0);
			vaitro = 1;
			nhap3 = 0;

		}
		if (whereX() == 68)
		{
			gotoXY(51, 8);
			cout << " ";
			gotoXY(66, 8);
			cout << char(004);
			ShowCur(0);
			vaitro = 0;
		}
		if (whereX() == 57)
		{
			thanh_sang(57, 19, 9, 12, "Dang nhap");
			ShowCur(0);
			//break;
		}
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();

				if (c == 77)
				{
					gotoXY(68, 8);
				}
				if (c == 75)
				{
					gotoXY(53, 8);
				}
				if (c == 72)
				{
					gotoXY(xp, yp);
				}
				if (c == 80)
				{
					if (whereY() == 8 )
					{
						gotoXY(xp, yp);
					}
					else
					{
						gotoXY(57, 19);
					}
				}
			}
			if (c == 13)
			{
				if (whereY() == 19)
				{
					return;
				}
			}
		}
	}
}
void box_dang_nhap(string& nd1, string& nd2, int& vaitro)
{
	system("cls");
	background(20, 5, 80, 17, 11);
	box(48, 10, 30, 2, 11, "Ten dang nhap: ", 34, 11);
	box(48, 13, 30, 2, 11, "Mat khau: ", 39, 14);
	box(55, 18, 12, 2, 11, "", 57, 19);
	nhap_vao_box(49, 11, nd1, nd2, vaitro);
}