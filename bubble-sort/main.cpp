#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "bubble_sort.h"

using namespace std;

#define LEN 80000

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	int data[LEN] = {0};
	for (int i = 0; i < LEN; ++i) {
		data[i] = rand() % 1000;
	}

	struct timeval tpstart, tpend;
	gettimeofday(&tpstart, NULL);
	BubbleSort(data, LEN);
	gettimeofday(&tpend, NULL);
	double timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec)
		+ (tpend.tv_usec - tpstart.tv_usec);
	timeuse /= 1000000;
	cout << "use time: " << timeuse << endl;
    return 0;
}
