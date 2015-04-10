#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

// #include <utility>
// using std::swap;
 
int partition(int* array, int left, int right)
{
	int index = left;
	int pivot = array[index];	
	std::swap(array[index], array[right]);
	for (int i = left; i < right; i++)
	{
		if (array[i] > pivot)    // 降序
			std::swap(array[index++], array[i]);
	}
	std::swap(array[right], array[index]);
	return index;
}
 
void qsort(int* array, int left, int right)
{
	if (left >= right) 
		return;
	int index = partition(array, left, right);
	qsort(array, left, index - 1);
	qsort(array, index + 1, right);
}

void quick_sort(int *array, int len) {
	qsort(array, 0, len - 1);
}

#endif /* _QUICK_SORT_H_ */
