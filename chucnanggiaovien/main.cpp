#include <iostream>
#include <string>
#include "giaodien.h"
#include "xuly.h"
#include "run.h"
using namespace std;	
void main()
{
	int vaitro = -1;
	string ten_dang_nhap;
	string mat_khau;
	DisableResizeWindow();//Cố định khung màn hình(Không cho kéo).
	DisableCtrButton(0, 1, 1);//Vô hiệu hoá khi ấn phóng tao thu nhỏ khung console.
	run(ten_dang_nhap,mat_khau,vaitro);
	_getch();
}
