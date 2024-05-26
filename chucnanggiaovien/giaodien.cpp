#include <iostream>
#include "dangnhap.h"
#include "chucnang.h"
#include "xuly.h"
#include "run.h"
#include "doimatkhau.h"
using namespace std;

void Giaodien(int sgv, int shs, string ten_dang_nhap, string mat_khau, int vaitro)
{
	int chucnang, stt = -1, mon = -1;
	float ndiem = -1;
	string npass;
	int mon_hoc;
	box_menu_chuc_nang(vaitro, chucnang);
	SetColor(7);
	//chuc nang=1 => xet vai tro gv: xemdiemgv else xemdiemhs;
		while (chucnang < 4)
		{
			if (chucnang == 1)
			{
				if (vaitro == 1)
				{
					system("cls");
					SetColor(7);
					gotoXY(3, 1);
					cout << "Giao vien xem diem";
					xemdiem(xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 2, -1, -1, -1,""), vaitro, 0, shs, mon_hoc);
					box_menu_chuc_nang(vaitro, chucnang);
				}
				else
				{
					system("cls");
					SetColor(7);
					gotoXY(3, 1);
					cout << "Xem diem";
					xemdiem(xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 2, -1, -1, -1,""), vaitro, 0, shs, mon_hoc);
					box_menu_chuc_nang(vaitro, chucnang);
				}
			}
			if (chucnang == 2)
			{
				system("cls");
				SetColor(7);
				gotoXY(3, 1);
				cout << "Sua diem";
				//goi ham xem diem mới có chức năng chọn học sinh+ sửa điểm
				xemdiem(xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 2, -1, -1, -1,""), vaitro, 1, shs, mon_hoc);
				SetColor(4);
				gotoXY(0, 5);
				cout << "An backspace de sua diem";
				gotoXY(0, 6);
				cout << "An enter de chot diem vua nhap";
				gotoXY(0, 7);
				cout << "An esc de quay lai";
				int mon = mon_hoc;
				//gotoXY(0, 8);
				//cout << mon;
				int stt;
				float ndiem;
				int xp = 81; int yp = 3;
				int xcu = xp; int ycu = yp;
				bool kt = true;
				string ndbox = "<-";
				string ndboxcu = "  ";
				while (true)
				{
					if (kt == true)
					{
						gotoXY(xcu, ycu);
						thanh_sang1(xcu, ycu, 1, 0, ndboxcu);
						xcu = xp; ycu = yp;
						thanh_sang1(xp, yp, 1, 0, ndbox);
						kt = false;
					}
					if (_kbhit)
					{
						char c = _getch();
						if (c == -32)
						{
							kt = true;
							c = _getch();
							if (c == 72)
							{
								if (whereY() == 3)
								{
									yp = ((shs + 2) * 2) - 1;
								}
								else
								{
									yp -= 2;
								}
							}
							if (c == 80)
							{
								if (whereY() == ((shs + 2) * 2) - 1)
								{
									yp = 3;
								}
								else
								{
									yp += 2;
								}
							}
						}
						if (c == 8)
						{
							thanh_sang1(35 + 37, whereY(), 3, 0, " ");
							gotoXY(35 + 37, whereY());
							ShowCur(2);
							cin >> ndiem;
							stt = ((whereY() - 1) / 2) - 1;
							xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 1, stt, mon, ndiem,"");
							ShowCur(0);
						}
						if (c == 27)
						{

							break;
						}
					}
				}
				box_menu_chuc_nang(vaitro, chucnang);
			}
			if (chucnang == 3)
			{
				//goi ham đổi matkhau => trả về stt, vaitro, npass;
				system("cls");
				string matkhaucu;
				string npass;
				int stt = xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 2, -1, -1, -1, "");
				while (true)
				{
					doi_mat_khau(ten_dang_nhap, matkhaucu, npass);
					if (xuly(sgv, shs, vaitro, ten_dang_nhap, matkhaucu, 0, 0, 0, 0, "") == 0)
					{
						textcolor(0 * 16);
						SetColor(4);
						gotoXY(48, 16);
						cout << "Sai mat khau";
						ShowCur(0);
						Sleep(1300);
						cin.ignore();
					}
					else
					{
						xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 3, stt, mon, ndiem, npass);
						Sleep(1000);
						break;
					}
				}
				// else xuất thông báo sai mk giống đăng nhập  
				box_menu_chuc_nang(vaitro, chucnang);
			}
		}
	if (chucnang == 4)
	{
		system("cls");
		xuly(sgv, shs, vaitro, ten_dang_nhap, mat_khau, 4, stt, mon, ndiem,"");
		run(ten_dang_nhap, mat_khau, vaitro);
	}
}