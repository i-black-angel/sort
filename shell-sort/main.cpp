#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <cstdio>
#include "shell_sort.h"

using namespace std;

#define ELEMENTS(x) sizeof((x)) / sizeof((x)[0])

bool comp(int _x, int _y) {
	return _x > _y;
}

void building(int data[], int len) {
	for (int i = 0; i < len; ++i) {
		data[i] = rand();
	}
}

void sorting(int data[], int len) {
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

	shell_sort(data, len);
    
    gettimeofday(&tend, NULL);
    double timeuse = (tend.tv_sec - tstart.tv_sec) * 1000000
        + (tend.tv_usec - tstart.tv_usec);
    timeuse /= 1000000;
	printf("shell's sort %6d data used: %f sec\n", len, timeuse);
}

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	int data_small[9] = {9, 7, 6, 4, 5, 1, 3, 2, 8};
	// int data_mid[800];
	// int data_large[800000] = {1, 2};

	// building(data_small, ELEMENTS(data_small));
	// building(data_mid, ELEMENTS(data_mid));
	// building(data_large, ELEMENTS(data_large));
	
	sorting(data_small, ELEMENTS(data_small));
	// sorting(data_mid, ELEMENTS(data_mid));
	// sorting(data_large, ELEMENTS(data_large));
    return 0;
}

