#pragma once
#include <string>
#include <iostream>
#include <time.h>

int N = 10;
int m = 12;
std::string* Hash_table;


int h(std::string str) {
	int res = 0;
	for (int i = 0; i < str.length(); ++i) {
		res += int(str[i]);
	}
	return res % N;
}


int Add(std::string str, std::string* A = Hash_table) {
	int res = h(str);
	int compare = 0;
	if (A[res] == "") {
		compare++;
		A[res] = str;
		return compare;
	}
	else {
		compare++;
		for (int i = 0; i < m - 2; ++i) {
			compare++;
			res = (h(str) + i) % m + 1;
			if (A[res] == "") { A[res] = str; return compare; }
		}
		return -1;
	}
}

int Search(std::string str, std::string* A = Hash_table) {
	int res = h(str);
	int compare = 0;
	if (A[res] == str) {
		compare++;
		return compare;
	}
	else {
		compare++;
		for (int i = 0; i < m - 2; ++i) {
			compare++;
			res = (h(str) + i) % m + 1;
			if (A[res] == str) { return compare; }
		}
		return -1;
	}
}