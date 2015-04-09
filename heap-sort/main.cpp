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
#include <sys/time.h>
#include "heap_sort.h"

using namespace std;

#define ELEMENTS(x) sizeof((x)) / sizeof((x)[0])


void building(int data[], int len) {
	for (int i = 0; i < len; ++i) {
		data[i] = rand() % 1000;
	}
}

void sorting(int data[], int len) {
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

	heap_sort(data, len);
    
    gettimeofday(&tend, NULL);
    double timeuse = (tend.tv_sec - tstart.tv_sec) * 1000000
        + (tend.tv_usec - tstart.tv_usec);
    timeuse /= 1000000;
	printf("heap sort %6d data used: %f sec\n", len, timeuse);
}

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	int data[20];

	building(data, ELEMENTS(data));
	sorting(data, ELEMENTS(data));

	for (int i = 0; i < ELEMENTS(data); ++i) {
		cout << data[i] << " ";
	}
	cout << endl;
    return 0;
}
