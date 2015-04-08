#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

// Shell's sort
// 希尔排序是基于插入排序的一种改进，也称之为增量插入排序算法
template <typename _Key>
void ShellSort(_Key arr[], int len) {
	int i = 0, j = 0, gap = 0;
	_Key temp;
	// 初始步长 len/2, 并对步长取半直到 1
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		// 以下为插入排序
		for (i = gap; i < len; ++i) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && temp < arr[j]; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}

template <typename _Key, typename _Compare>
void ShellSort(_Key arr[], int len, _Compare key_comp) {
	int i = 0, j = 0, gap = 0;
	_Key temp;
	// 初始步长 len/2, 并对步长取半直到 1
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		// 以下为插入排序
		for (i = gap; i < len; ++i) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && key_comp(temp, arr[j]); j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}

#endif /* _SHELL_SORT_H_ */
