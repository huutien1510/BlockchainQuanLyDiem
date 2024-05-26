#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "dinh_nghia_struct.h"

using namespace std;

void bin(int k, bool h[], int j) {
    while (k > 0) {
        h[j] = k % 2;
        j--;
        k /= 2;
    }
}

void binrev(int k, bool  h[], int& j) {
    while (k > 0) {
        h[j] = k % 2;
        j++;
        k /= 2;
    }
}
void bam(string s, char hash_table[]) {
    for (int i = 0; i < 70; i++)
        hash_table[i] = ' ';
    for (int i = 0; i < s.size(); i++) {
        int index = (int)s[i] % 70;
        for (int j = index;; j = (j + 1) % 70) {

            if (hash_table[j] == ' ') {
                hash_table[j] = s[i];
                break;
            }
        }
    }
}

string Plus2Hash(string hash1, string hash2) {
    string result = "";
    for (int i = 0; i < 64; i++) {
        int s = ((int)hash1[i] + (int)hash2[i]) % 16;
        if (s < 10) result += char(s + 48);
        else switch (s)
        {
        case 10: { result += 'A'; break; }
        case 11: { result += 'B'; break; }
        case 12: { result += 'C'; break; }
        case 13: { result += 'D'; break; }
        case 14: { result += 'E'; break; }
        case 15: { result += 'F'; break; }
        }
    }
    return result;
}