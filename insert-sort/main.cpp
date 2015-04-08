#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <locale>
#include "insert_sort.h"

using namespace std;

#define LEN 8000

bool comp(int _x, int _y) {
	return _x > _y;
}

int main(int argc, char *argv[])
{
    // int data[] = {3, 23, 9, 21, 22, 8, 98, 6, 10, 67};
	srand((unsigned int)time(NULL));
	int data[LEN] = {0};
	for (int i = 0; i < LEN; ++i) {
		data[i] = rand();
	}
	
	// from less to large
	// InsertSort(data, sizeof(data) / sizeof(data[0]));
	// for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
	// 	cout << data[i] << " ";
	// }
	// cout << endl;

	clock_t start = clock();
	// reverse sort
	InsertSort(data, sizeof(data) / sizeof(data[0]), comp);
	clock_t end = clock();
	double usetime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "use time: " << usetime << endl;
	
	// for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
	// 	cout << data[i] << " ";
	// }
	// cout << endl;

    return 0;
}
