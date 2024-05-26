#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "dinh_nghia_struct.h"

using namespace std;

void bin(int k, bool h[], int j);
void binrev(int k, bool  h[], int& j);
void bam(string s, char hash_table[]);
string Plus2Hash(string hash1, string hash2);
