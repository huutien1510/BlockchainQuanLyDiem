#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "hamxuly.h"
#include "dinh_nghia_struct.h"

using namespace std;

void tohexSV(accsvblock& t, bool h[]);
void hashfuncSV(accsvblock& t);
bool xacnhansv(accsvblock dangnhap, merkle_tree sv);