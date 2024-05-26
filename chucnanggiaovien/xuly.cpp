#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "xulyGV.h"
#include "xulySV.h"
#include "dinh_nghia_struct.h"
#include "TV_DH.h"

using namespace std;
accgvblock a[100];
accsvblock b[100];
accnode addHash[100][100] = { "" };
accnode addHashSV[100][100] = { "" };
merkle_tree gv;
merkle_tree sv;

float diem_so(int xem, int stt, int& mon_hoc)
{
    float diem = 0;
    if (a[xem].monhoc == "Toan Hoc")
    {
        diem = b[stt].toan;
        mon_hoc = 1;
    }
    else if (a[xem].monhoc == "Vat Ly")
    {
        diem = b[stt].ly;
        mon_hoc = 2;
    }
    else if (a[xem].monhoc == "Van Hoc")
    {
        diem = b[stt].van;
        mon_hoc = 5;
    }
    else if (a[xem].monhoc == "Sinh Hoc")
    {
        diem = b[stt].sinh;
        mon_hoc = 12;
    }
    else if (a[xem].monhoc == "Hoa Hoc")
    {
        diem = b[stt].hoa;
        mon_hoc = 3;
    }
    else if (a[xem].monhoc == "Lich Su")
    {
        diem = b[stt].su;
        mon_hoc = 9;
    }
    else if (a[xem].monhoc == "Tin Hoc")
    {
        diem = b[stt].tin;
        mon_hoc = 11;
    }
    else if (a[xem].monhoc == "Cong Nghe")
    {
        diem = b[stt].congnghe;
        mon_hoc = 7;
    }
    else if (a[xem].monhoc == "GDCD")
    {
        diem = b[stt].gdcd;
        mon_hoc = 8;
    }
    else if (a[xem].monhoc == "Giao duc quoc phong")
    {
        diem = b[stt].gdqp;
        mon_hoc = 10;
    }
    else if (a[xem].monhoc == "Dia Ly")
    {
        diem = b[stt].dia;
        mon_hoc = 6;
    }
    else
    {
        diem = b[stt].tienganh;
        mon_hoc = 4;
    }
    return diem;
}

void bang_diem(int x, int y, int w, int h, int s_colort, int so_o_doc, int so_o_ngang, int xem, int vaitro, int& mon_hoc)
{
    if (vaitro == 1)
    {
        SetColor(7);
        gotoXY(3, 2);
        cout << a[xem].hoten;
        gotoXY(3, 3);
        cout << a[xem].monhoc;
    }
    else
    {
        SetColor(7);
        gotoXY(3, 2);
        cout << b[xem].hoten;
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
    int stt = 0;
    //SetColor(s_colort);
    int diem = 0;
    for (int i = 1; i <= so_o_doc + 1; i++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {

            if (vaitro == 1)
            {
                if (ix == x + 1)
                {
                    if ((y + (i * 2) - 1) == 1)
                    {
                        SetColor(7);
                        gotoXY(x + 2, y + 1);
                        cout << "STT";
                        gotoXY(x + 15, y + 1);
                        cout << "Ten";
                        gotoXY(x + 37, y + 1);
                        cout << "Diem";
                    }
                    else
                    {
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 9, y + (i * 2) - 1);
                        cout << b[stt].hoten;
                        gotoXY(x + 37, y + (i * 2) - 1);
                        cout << diem_so(xem, stt, mon_hoc);
                        stt++;
                    }
                }
                SetColor(s_colort);
                gotoXY(ix, y + (i * 2));
                cout << char(196);
            }
            else
            {
                if (ix == x + 1)
                {
                    switch (y + (i * 2) - 1)
                    {
                    case 1:
                        SetColor(7);
                        gotoXY(x + 2, y + 1);
                        cout << "STT";
                        gotoXY(x + 15, y + 1);
                        cout << "Mon";
                        gotoXY(x + 35, y + 1);
                        cout << "Diem";
                        continue;
                    case 3:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Toan";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].toan;
                        stt++;
                        continue;
                    case 5:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Vat Ly";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].ly;
                        stt++;
                        continue;
                    case 7:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Hoa Hoc";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].hoa;
                        stt++;
                        continue;
                    case 9:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Sinh Hoc";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].sinh;
                        stt++;
                        continue;
                    case 11:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Ngu Van";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].van;
                        stt++;
                        continue;
                    case 13:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Tieng Anh";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].tienganh;
                        stt++;
                        continue;
                    case 15:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Tin Hoc";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].tin;
                        stt++;
                        continue;
                    case 17:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Lich Su";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].su;
                        stt++;
                        continue;
                    case 19:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Dia Ly";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].dia;
                        stt++;
                        continue;
                    case 21:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "GDCD";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].gdcd;
                        stt++;
                        continue;
                    case 23:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "Cong nghe";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].congnghe;
                        stt++;
                        continue;
                    case 25:
                        SetColor(7);
                        gotoXY(x + 3, y + (i * 2) - 1);
                        cout << stt + 1;
                        gotoXY(x + 12, y + (i * 2) - 1);
                        cout << "GDQP";
                        gotoXY(x + 36, y + (i * 2) - 1);
                        cout << b[xem].gdqp;
                        stt++;
                        continue;
                    }
                }
                SetColor(s_colort);
                gotoXY(ix, y + (i * 2));
                cout << char(196);
            }
        }
    }
    for (int i = 1; i <= so_o_ngang; i++)
    {
        for (int iy = y + 1; iy <= y + h - 1; iy++)
        {
            if (i == 1)
            {
                SetColor(s_colort);
                gotoXY(x + (i * 7), iy);
                cout << char(179);
            }
            if (i == 2)
            {
                SetColor(s_colort);
                gotoXY(x + (i * 16), iy);
                cout << char(179);
            }
        }
    }
}

void thanh_sang2(int x, int y, int w, int colort, string nd)
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

void box_back(int x, int y, int w, int h, int s_colort, string nd)
{
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << nd;
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
    thanh_sang2(x + 1, y + 1, 6, 4, nd);
    while (true)
    {
        if (_kbhit)
        {
            char c = _getch();
            if (c == 13)
            {
                return;
            }
        }
    }
}
void xemdiem(int xem, int vaitro, int huy_enter, int so_hs, int& mon_hoc)
{
    int so_o_doc;
    int so_o_ngang = 3;
    if (vaitro == 1)
    {
        so_o_doc = so_hs + 1;
        bang_diem(35, 0, so_o_ngang * 15, so_o_doc * 2 + 2, 11, so_o_doc, so_o_ngang, xem, vaitro, mon_hoc);
        if (huy_enter == 0)
        {
            box_back(53, 45, 9, 2, 11, "Quay lai");
        }
    }
    else
    {
        so_o_doc = 12;
        bang_diem(35, 0, so_o_ngang * 15, so_o_doc * 2 + 2, 11, so_o_doc, so_o_ngang, xem, vaitro, mon_hoc);
        box_back(53, 27, 9, 2, 11, "Quay lai");
    }
    return;
}

int xuly(int& sgv, int& shs, int vaitro, string ten_dang_nhap, string mat_khau, int sua, int stt, int mon, float ndiem, string npass)
{
    if (sua == 5)
    {
        ifstream input;
        input.open("blockAccGiaoVien.txt");
        int i = -1;

        while (!input.eof()) {
            i++;
            char temp1[255];
            input.getline(temp1, 255);
            a[i].username = temp1;
            input.getline(temp1, 255);
            a[i].pass = temp1;
            input.getline(temp1, 255);
            a[i].hoten = temp1;
            input.getline(temp1, 255);
            a[i].gioitinh = temp1;
            input.getline(temp1, 255);
            a[i].monhoc = temp1;
            if (i == 0)
                for (int f = 0; f < 64; f++) a[i].prehash[f] = '0';
            else
                for (int f = 0; f < 64; f++)
                    a[i].prehash[f] = a[i - 1].hash[f];
            hashfunc(a[i]);

        }
        sgv = i;

        int dem = sgv, l = 0, j = 0;
        for (int i = 0; i <= sgv; i++)
        {
            addHash[0][i].acc = a[i].hash;
            a[i].node = &addHash[0][i];
        }
        i = 1;
        while (dem > 0)
        {
            l = -1; j = 0;
            while (j < dem)
            {
                l++;
                addHash[i][l].acc = Plus2Hash(addHash[i - 1][j].acc, addHash[i - 1][j + 1].acc);
                addHash[i][l].left = &addHash[i - 1][j];
                addHash[i - 1][j].base = &addHash[i][l];
                addHash[i][l].right = &addHash[i - 1][j + 1];
                addHash[i - 1][j + 1].base = &addHash[i][l];
                j += 2;
            }

            if (dem % 2 == 0)
            {
                addHash[i][l + 1].acc = addHash[i - 1][dem].acc;
                addHash[i][l + 1].left = &addHash[i - 1][dem];
                addHash[i - 1][dem].base = &addHash[i][l + 1];
                addHash[i][l + 1].right = NULL;
                dem = l + 1;
            }
            else dem = l;
            i++;
        }

        gv.root = &addHash[i - 1][0];
        input.close();

        input.open("blockAccSinhVien.txt");
        i = -1;
        while (!input.eof()) {
            i++;
            char temp[255];
            input.getline(temp, 255);
            b[i].username = temp;
            input.getline(temp, 255);
            b[i].pass = temp;
            input.getline(temp, 255);
            b[i].hoten = temp;
            input.getline(temp, 255);
            b[i].gioitinh = temp;
            input.getline(temp, 255);
            b[i].toan = atof(temp);
            input.getline(temp, 255);
            b[i].ly = atof(temp);
            input.getline(temp, 255);
            b[i].hoa = atof(temp);
            input.getline(temp, 255);
            b[i].tienganh = atof(temp);
            input.getline(temp, 255);
            b[i].van = atof(temp);
            input.getline(temp, 255);
            b[i].dia = atof(temp);
            input.getline(temp, 255);
            b[i].congnghe = atof(temp);
            input.getline(temp, 255);
            b[i].gdcd = atof(temp);
            input.getline(temp, 255);
            b[i].su = atof(temp);
            input.getline(temp, 255);
            b[i].gdqp = atof(temp);
            input.getline(temp, 255);
            b[i].tin = atof(temp);
            input.getline(temp, 255);
            b[i].sinh = atof(temp);
            if (i == 0)
                for (int f = 0; f < 64; f++) b[i].prehash[f] = '0';
            else
                for (int f = 0; f < 64; f++)
                    b[i].prehash[f] = b[i - 1].hash[f];
            hashfuncSV(b[i]);
        }
        shs = i;

        dem = shs, l = 0, j = 0;
        for (int i = 0; i <= shs; i++)
        {
            addHashSV[0][i].acc = b[i].hash;
            b[i].node = &addHashSV[0][i];
        }
        i = 1;
        while (dem > 0)
        {
            l = -1; j = 0;
            while (j < dem)
            {
                l++;
                addHashSV[i][l].acc = Plus2Hash(addHashSV[i - 1][j].acc, addHashSV[i - 1][j + 1].acc);
                addHashSV[i][l].left = &addHashSV[i - 1][j];
                addHashSV[i - 1][j].base = &addHashSV[i][l];
                addHashSV[i][l].right = &addHashSV[i - 1][j + 1];
                addHashSV[i - 1][j + 1].base = &addHashSV[i][l];
                j += 2;
            }

            if (dem % 2 == 0)
            {
                addHashSV[i][l + 1].acc = addHashSV[i - 1][dem].acc;
                addHashSV[i][l + 1].left = &addHashSV[i - 1][dem];
                addHashSV[i - 1][dem].base = &addHashSV[i][l + 1];
                addHashSV[i][l + 1].right = NULL;
                dem = l + 1;
            }
            else dem = l;
            i++;
        }

        sv.root = &addHashSV[i - 1][0];
        input.close();
    }
    else if (sua == 0)
    {
        if (vaitro == 1) {
            accgvblock dangnhap;
            dangnhap.username = ten_dang_nhap;
            dangnhap.pass = mat_khau;
            int flag = 0;
            for (int i = 0; i <= sgv; i++) {
                if (a[i].username == dangnhap.username) {
                    dangnhap.hoten = a[i].hoten;
                    dangnhap.gioitinh = a[i].gioitinh;
                    dangnhap.monhoc = a[i].monhoc;
                    for (int f = 0; f < 64; f++) dangnhap.prehash[f] = a[i].prehash[f];
                    dangnhap.node = a[i].node;
                    flag = 1;
                    hashfunc(dangnhap);
                    break;
                }
            }
            if (flag == 0)  return 0;
            if (xacnhangv(dangnhap, gv) == 0) return 0;
            return 1;

        }
        else
        {
            accsvblock dangnhapSV;
            dangnhapSV.username = ten_dang_nhap;
            dangnhapSV.pass = mat_khau;
            int flag = 0;
            for (int i = 0; i <= shs; i++) {
                if (b[i].username == dangnhapSV.username) {
                    dangnhapSV.hoten = b[i].hoten;
                    dangnhapSV.gioitinh = b[i].gioitinh;
                    dangnhapSV.toan = b[i].toan;
                    dangnhapSV.ly = b[i].ly;
                    dangnhapSV.hoa = b[i].hoa;
                    dangnhapSV.tienganh = b[i].tienganh;
                    dangnhapSV.van = b[i].van;
                    dangnhapSV.dia = b[i].dia;
                    dangnhapSV.congnghe = b[i].congnghe;
                    dangnhapSV.gdcd = b[i].gdcd;
                    dangnhapSV.su = b[i].su;
                    dangnhapSV.gdqp = b[i].gdqp;
                    dangnhapSV.tin = b[i].tin;
                    dangnhapSV.sinh = b[i].sinh;
                    for (int f = 0; f < 64; f++) dangnhapSV.prehash[f] = b[i].prehash[f];
                    dangnhapSV.node = b[i].node;
                    flag = 1;
                    hashfuncSV(dangnhapSV);
                    break;
                }
            }
            if (flag == 0)  return 0;
            if (xacnhansv(dangnhapSV, sv) == 0)  return 0;
            return 1;
        }
    }
    else if (sua == 1)
    {
        if (mon >= 0 && stt >= 0)
        {
            switch (mon)
            {
            case 1: { b[stt].toan = ndiem; break; }
            case 2: { b[stt].ly = ndiem; break; }
            case 3: { b[stt].hoa = ndiem; break; }
            case 4: { b[stt].tienganh = ndiem; break; }
            case 5: { b[stt].van = ndiem; break; }
            case 6: { b[stt].dia = ndiem; break; }
            case 7: {b[stt].congnghe = ndiem; break; }
            case 8: {b[stt].gdcd = ndiem; break; }
            case 9: {b[stt].su = ndiem; break; }
            case 10: {b[stt].gdqp = ndiem; break; }
            case 11: {b[stt].tin = ndiem; break; }
            case 12: {b[stt].sinh = ndiem; break; }
            }
            for (int i = 0; i <= shs; i++)
            {
                if (i == 0)
                    for (int f = 0; f < 64; f++) b[i].prehash[f] = '0';
                else
                    for (int f = 0; f < 64; f++)
                        b[i].prehash[f] = b[i - 1].hash[f];
                hashfuncSV(b[i]);
            }

            int dem = shs, l = 0, j = 0;
            for (int i = 0; i <= shs; i++)
            {
                addHashSV[0][i].acc = b[i].hash;
                b[i].node = &addHashSV[0][i];
            }
            int i = 1;
            while (dem > 0)
            {
                l = -1; j = 0;
                while (j < dem)
                {
                    l++;
                    addHashSV[i][l].acc = Plus2Hash(addHashSV[i - 1][j].acc, addHashSV[i - 1][j + 1].acc);
                    addHashSV[i][l].left = &addHashSV[i - 1][j];
                    addHashSV[i - 1][j].base = &addHashSV[i][l];
                    addHashSV[i][l].right = &addHashSV[i - 1][j + 1];
                    addHashSV[i - 1][j + 1].base = &addHashSV[i][l];
                    j += 2;
                }

                if (dem % 2 == 0)
                {
                    addHashSV[i][l + 1].acc = addHashSV[i - 1][dem].acc;
                    addHashSV[i][l + 1].left = &addHashSV[i - 1][dem];
                    addHashSV[i - 1][dem].base = &addHashSV[i][l + 1];
                    addHashSV[i][l + 1].right = NULL;
                    dem = l + 1;
                }
                else dem = l;
                i++;
            }
            sv.root = &addHashSV[i - 1][0];
            cin.ignore();
            return 1;
        }
    }
    else
        if (sua == 2)
        {
            int xem = 0;
            if (vaitro == 1)
            {
                while (xem <= sgv)
                {
                    if (a[xem].username == ten_dang_nhap)
                        return xem;
                    xem++;
                }
            }
            else
            {
                while (xem <= shs)
                {
                    if (b[xem].username == ten_dang_nhap)
                        return xem;
                    xem++;
                }
            }
        }
        else
            if (sua == 3)
            {
                if (vaitro == 0)
                {
                    b[stt].pass = npass;
                    for (int i = 0; i <= shs; i++)
                    {
                        if (i == 0)
                            for (int f = 0; f < 64; f++) b[i].prehash[f] = '0';
                        else
                            for (int f = 0; f < 64; f++)
                                b[i].prehash[f] = b[i - 1].hash[f];
                        hashfuncSV(b[i]);
                    }

                    int dem = shs, l = 0, j = 0;
                    for (int i = 0; i <= shs; i++)
                    {
                        addHashSV[0][i].acc = b[i].hash;
                        b[i].node = &addHashSV[0][i];
                    }
                    int i = 1;
                    while (dem > 0)
                    {
                        l = -1; j = 0;
                        while (j < dem)
                        {
                            l++;
                            addHashSV[i][l].acc = Plus2Hash(addHashSV[i - 1][j].acc, addHashSV[i - 1][j + 1].acc);
                            addHashSV[i][l].left = &addHashSV[i - 1][j];
                            addHashSV[i - 1][j].base = &addHashSV[i][l];
                            addHashSV[i][l].right = &addHashSV[i - 1][j + 1];
                            addHashSV[i - 1][j + 1].base = &addHashSV[i][l];
                            j += 2;
                        }

                        if (dem % 2 == 0)
                        {
                            addHashSV[i][l + 1].acc = addHashSV[i - 1][dem].acc;
                            addHashSV[i][l + 1].left = &addHashSV[i - 1][dem];
                            addHashSV[i - 1][dem].base = &addHashSV[i][l + 1];
                            addHashSV[i][l + 1].right = NULL;
                            dem = l + 1;
                        }
                        else dem = l;
                        i++;
                    }
                    sv.root = &addHashSV[i - 1][0];
               
                }
                else
                {
                    a[stt].pass = npass;
                    for (int i = 0; i <= sgv; i++)
                    {
                        if (i == 0)
                            for (int f = 0; f < 64; f++) a[i].prehash[f] = '0';
                        else
                            for (int f = 0; f < 64; f++)
                                a[i].prehash[f] = a[i - 1].hash[f];
                        hashfunc(a[i]);
                    }
                    int dem = sgv, l = 0, j = 0;
                    for (int i = 0; i <= sgv; i++)
                    {
                        addHash[0][i].acc = a[i].hash;
                        a[i].node = &addHash[0][i];
                    }
                    int i = 1;
                    while (dem > 0)
                    {
                        l = -1; j = 0;
                        while (j < dem)
                        {
                            l++;
                            addHash[i][l].acc = Plus2Hash(addHash[i - 1][j].acc, addHash[i - 1][j + 1].acc);
                            addHash[i][l].left = &addHash[i - 1][j];
                            addHash[i - 1][j].base = &addHash[i][l];
                            addHash[i][l].right = &addHash[i - 1][j + 1];
                            addHash[i - 1][j + 1].base = &addHash[i][l];
                            j += 2;
                        }

                        if (dem % 2 == 0)
                        {
                            addHash[i][l + 1].acc = addHash[i - 1][dem].acc;
                            addHash[i][l + 1].left = &addHash[i - 1][dem];
                            addHash[i - 1][dem].base = &addHash[i][l + 1];
                            addHash[i][l + 1].right = NULL;
                            dem = l + 1;
                        }
                        else dem = l;
                        i++;
                    }

                    gv.root = &addHash[i - 1][0];
          
                }
                return 1;

            }
            else
                if (sua == 4)
                {
                    fstream op;
                    op.open("blockAccSinhVien.txt", ios::out, ios::trunc);
                    for (int i = 0; i <= shs; i++)
                    {
                        op << b[i].username << endl;
                        op << b[i].pass << endl;
                        op << b[i].hoten << endl;
                        op << b[i].gioitinh << endl;
                        op << b[i].toan << endl;
                        op << b[i].ly << endl;
                        op << b[i].hoa << endl;
                        op << b[i].tienganh << endl;
                        op << b[i].van << endl;
                        op << b[i].dia << endl;
                        op << b[i].congnghe << endl;
                        op << b[i].gdcd << endl;
                        op << b[i].su << endl;
                        op << b[i].gdqp << endl;
                        op << b[i].tin << endl;
                        op << b[i].sinh;
                        if (i < shs) op << endl;
                    }
                    op.close();
                    op.open("blockAccGiaoVien.txt", ios::out, ios::trunc);
                    for (int i = 0; i <= sgv; i++)
                    {
                        op << a[i].username << endl;
                        op << a[i].pass << endl;
                        op << a[i].hoten << endl;
                        op << a[i].gioitinh << endl;
                        op << a[i].monhoc;
                        if (i < sgv) op << endl;
                    }
                    op.close();
                }
    return 0;
}
