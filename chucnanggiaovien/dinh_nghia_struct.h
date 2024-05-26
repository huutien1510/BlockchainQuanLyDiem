#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

struct accnode {
    string acc;
    accnode* base;
    accnode* left;
    accnode* right;
};

struct accgvblock {
    string username;
    string pass;
    string hoten;
    string gioitinh;
    string monhoc;
    char hash[64];
    char prehash[64];
    accnode* node;
};

struct accsvblock {
    string username;
    string pass;
    string hoten;
    string gioitinh;
    float toan;
    float ly;
    float hoa;
    float tienganh;
    float van;
    float dia;
    float congnghe;
    float gdcd;
    float su;
    float gdqp;
    float tin;
    float sinh;
    char hash[64];
    char prehash[64];
    accnode* node;
};

struct merkle_tree {
    accnode* root;
};
