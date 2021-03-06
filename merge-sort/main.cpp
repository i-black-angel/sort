#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <cstdio>
#include "merge_sort.h"

using namespace std;

#define ELEMENTS(x) sizeof((x)) / sizeof((x)[0])

bool comp(int _x, int _y) {
	return _x > _y;
}

void building(int data[], int len) {
	for (int i = 0; i < len; ++i) {
		data[i] = rand() % 100;
	}
}

void sorting(int data[], int len) {
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

	merge_sort(data, len);
    
    gettimeofday(&tend, NULL);
    double timeuse = (tend.tv_sec - tstart.tv_sec) * 1000000
        + (tend.tv_usec - tstart.tv_usec);
    timeuse /= 1000000;
	printf("shell's sort %6d data used: %f sec\n", len, timeuse);
}

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	int data_small[80];
	int data_mid[800];
	int data_large[800000];

	building(data_small, ELEMENTS(data_small));
	building(data_mid, ELEMENTS(data_mid));
	building(data_large, ELEMENTS(data_large));
	
	sorting(data_small, ELEMENTS(data_small));
	sorting(data_mid, ELEMENTS(data_mid));
	sorting(data_large, ELEMENTS(data_large));
	// for (int i = 0; i < ELEMENTS(data_small); ++i) {
	// 	cout << data_small[i] << " ";
	// }
	// cout << endl;
    return 0;
}

