#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "hamxuly.h"
#include "dinh_nghia_struct.h"

using namespace std;

void tohexSV(accsvblock& t, bool h[]) {
    int i = 127, j = 511;
    int hasht[128];
    while (i >= 0) {
        int s = 0, x = 1;
        for (int k = 0; k < 4; k++) {
            if (h[j] == true) s += x;
            x *= 2;
            j--;
        }
        hasht[i] = s;
        i--;
    }
    for (int k = 0; k < 64; k++) hasht[k] = (hasht[k] + hasht[k + 64]) % 16;
    for (i = 0; i < 64; i++)
        if (hasht[i] < 10) t.hash[i] = char(hasht[i] + 48);
        else switch (hasht[i])
        {
        case 10: { t.hash[i] = 'A'; break; }
        case 11: { t.hash[i] = 'B'; break; }
        case 12: { t.hash[i] = 'C'; break; }
        case 13: { t.hash[i] = 'D'; break; }
        case 14: { t.hash[i] = 'E'; break; }
        case 15: { t.hash[i] = 'F'; break; }
        }
}
void hashfuncSV(accsvblock& t) {
    char hash_table[70];
    bool h[512];
    //chuan hoa
    int i, j = 0;
    string s = "";

    int len = t.username.length() + t.pass.length() + t.hoten.length();

    for (i = 0; i < t.username.length(); i++) s += t.username[i];
    for (i = 0; i < t.pass.length(); i++) s += t.pass[i];
    if (t.gioitinh == "Nam ") s += "1"; else s += "0";
    for (i = 0; i < t.hoten.length(); i++) s += t.hoten[i];
    float diem = t.toan + t.congnghe + t.dia + t.gdcd + t.gdqp + t.hoa + t.ly + t.sinh + t.su + t.tienganh + t.tin + t.van;
    s += to_string(diem);
    for (i = 0; i < s.size(); i++) s[i] = (s[i] + t.prehash[i]) % 127 + 1;
    for (i = s.size(); i < 64; i++) s += t.prehash[i];


    bam(s, hash_table);

    for (i = 0; i < 70; i++) {
        int k = (int)hash_table[i];
        binrev(k, h, j);
    }
    bin(len, h, 255);
    bool a[128], b[128], c[128], d[128];
    for (i = 0; i < 128; i++)
    {
        a[i] = h[i];
        b[i] = h[i + 128];
        c[i] = h[i + 256];
        d[i] = h[i + 384];
    }
    for (i = 0; i < 80; i++) {
        bool tam[128];
        for (j = 0; j < 128; j++) tam[j] = a[j];
        for (j = 0; j < 128; j++) {

            a[j] = d[j] + ((b[j] + c[j]) - ((b[j]) + d[j]));
            b[j] = tam[j];
            d[j] = c[j];
            c[j] = b[(j + 30) % 128];
        }
    }
    for (i = 0; i < 128; i++)
    {
        h[i] = a[i];
        h[i + 128] = b[i];
        h[i + 256] = c[i];
        h[i + 384] = d[i];
    }
    tohexSV(t, h);
}
bool xacnhansv(accsvblock dangnhap, merkle_tree sv) {
    accnode t, tam;
    t.acc = dangnhap.hash;
    t.base = dangnhap.node->base;
    t.left = dangnhap.node->left;
    t.right = dangnhap.node->right;
    while (t.base != NULL)
    {
        if (t.base->right != NULL)
        {
            if (t.base->left == dangnhap.node)
                t.acc = Plus2Hash(t.acc, t.base->right->acc);
            else
                t.acc = Plus2Hash(t.acc, t.base->left->acc);
            dangnhap.node = t.base;
        }

        tam = *t.base;
        tam.acc = t.acc;
        t = tam;
    }
    if (t.acc == sv.root->acc)
        return 1;
    return 0;
}