#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "hamxuly.h"
#include "dinh_nghia_struct.h"

using namespace std;

bool xacnhangv(accgvblock dangnhap, merkle_tree gv);
void tohex(accgvblock& t, bool h[]);
void hashfunc(accgvblock& t);