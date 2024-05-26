#include "TV_DH.h"
#include <iostream>
#include <string>
using namespace std;

void box(int x, int y, int w, int h, int s_colort, string nd, string nd2, string nd3,string nd4, int& dem)
{

	SetColor(7);
	if (dem == 1)
	{
		gotoXY(x + 1, y + 1);
		cout << nd;
	}
	if (dem == 2)
	{
		gotoXY(x + 1, y + 1);
		cout << nd2;
	}
	if(dem==3)
	{
		gotoXY(x + 1, y + 1);
		cout << nd3;
	}
	if (dem==4)
	{
		gotoXY(x + 1, y + 1);
		cout << nd4;
	}
	SetColor(s_colort);
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

void thanh_sang1(int x, int y, int w, int colort, string nd)
{
	textcolor(colort * 16);
	for (int iy = y; iy <= y; iy++)
	{
		for (int ix = x; ix <= x + w; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x, y);
	cout << nd;
	ShowCur(0);
}

void chuc_nang(string ND1, string ND2, string ND3,string ND4, int so_o_menu,int &chucnang)
{
	int x = 45;
	int y = 7;
	int dem = 1;
	chucnang = 0;
	for (int i = 0; i < so_o_menu; i++)
	{
		box(x, y + (i * 2), 30, 2, 11, ND1, ND2, ND3,ND4, dem);
		dem++;
	}
	for (int i = 1; i < so_o_menu; i++)
	{
		gotoXY(x, y + (i * 2));
		cout << char(195);
		gotoXY(x + 30, y + (i * 2));
		cout << char(180);
	}
	int xp = x + 1; int yp = y + 1;
	int xcu = xp; int ycu = yp;
	bool kt = true;
	string ndbox = " ";
	string ndboxcu;
	while (true)
	{
		if (kt == true)
		{
			if (ycu == y + 1)
			{
				ndboxcu = ND1;
			}
			if (ycu == y + 3)
			{
				ndboxcu = ND2;
			}
			if(ycu==y+5)
			{
				ndboxcu = ND3;
			}
			else
			{
				if (ycu == y + 7)
				{
					ndboxcu = ND4;
				}
			}
			if (yp == y + 1)
			{
				ndbox = ND1;
			}
			if (yp == y + 3)
			{
				ndbox = ND2;
			}
			if (yp == y + 5)
			{
				ndbox = ND3;
			}
			else
			{
				if (yp == y + 7)
				{
					ndbox = ND4;
				}
			}
			gotoXY(xcu, ycu);
			thanh_sang1(xcu, ycu, 28, 0, ndboxcu);
			xcu = xp; ycu = yp;
			thanh_sang1(xp, yp, 28, 4, ndbox);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (whereY() == y + 1)
					{
						if (so_o_menu == 4)
						{
							yp = y + 7;
						}
						else
						{
							yp = y + 5;
						}
					}
					else
					{
						yp -= 2;
					}
				}
				if (c == 80)
				{
					if (whereY() == y + 7)
					{
						yp = y + 1;
					}
					else
					{
						if (whereY() == y + 5)
						{
							if (so_o_menu == 3)
							{
								yp = y + 1;
							}
							else
							{
								yp += 2;
							}
						}
						else
						{
							yp += 2;
						}
					}
				}
			}
			if (c == 13)
			{
				if (whereY() == y + 1)
				{
					chucnang = 1;
					textcolor(0 * 16);
					break;
				}
				if (whereY() == y + 3)
				{
					if (so_o_menu == 4)
					{
						chucnang = 2;
						textcolor(0 * 16);
						break;
					}
					if (so_o_menu == 3)
					{
						chucnang = 3;
						textcolor(0 * 16);
						break;
					}
				}
				if (whereY() == y + 5)
				{
					if (so_o_menu == 4)
					{
						chucnang = 3;
						textcolor(0 * 16);
						break;
					}
					if (so_o_menu == 3)
					{
						chucnang = 4;
						textcolor(0 * 16);
						break;
					}
				}
				if (whereY() == y + 7)
				{
					chucnang = 4;
					textcolor(0 * 16);
					break;
				}
			}
		}
	}
	//_getch();
}
void box_menu_chuc_nang(int vaitro, int& chucnang)
{
	textcolor(0 * 16);
	system("cls");
	if (vaitro == 1)
	{
		gotoXY(50, 6);
		cout << "Giao vien dang nhap";
		chuc_nang("Xem diem", "Sua diem","Doi mat khau", "Dang xuat", 4, chucnang);
	}
	if (vaitro == 0)
	{
		gotoXY(50, 6);
		cout << "Hoc sinh dang nhap";
		chuc_nang("Xem diem","Doi mat khau", "Dang xuat","", 3, chucnang);
	}
}