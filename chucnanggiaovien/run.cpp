#include <iostream>
#include <string>
#include "giaodien.h"
#include "xuly.h"

void run(string ten_dang_nhap, string mat_khau, int& vaitro)
{
	int sgv = -1, shs = -1;
	xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 5, 0, 0, 0, "");
	while (true)
	{		
		box_dang_nhap(ten_dang_nhap, mat_khau, vaitro);
		if (xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 0, 0, 0, 0,"") == 0)
		{
			textcolor(0 * 16);
			SetColor(4);
			gotoXY(48, 16);
			cout << "Ten dang nhap hoac mat khau sai";
			ShowCur(0);
			Sleep(1300);
		}
		else
		{
			break;
		}
	}
	Giaodien(sgv, shs, ten_dang_nhap, mat_khau, vaitro);
}