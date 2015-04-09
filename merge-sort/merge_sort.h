#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

template <typename _Key>
void merge(_Key arr[], _Key temp[], int low, int mid, int high) {
	int begin1 = low, end1 = mid;
	int begin2 = mid + 1, end2 = high;
	for (int k = low; k <= high; ) {
		if (begin1 > end1)
			temp[k++] = arr[begin2++];
		else if (begin2 > end2)
			temp[k++] = arr[begin1++];
		else {
			if (arr[begin1] <= arr[begin2])
				temp[k++] = arr[begin1++];
			else
				temp[k++] = arr[begin2++];
		}
	}
}

template <typename _Key>
void merge_pass(_Key a[], _Key b[], int seg, int len) {
	int i = 0;
	// len - (seg + seg) 的意思是滿足可兩兩歸併的最低臨界值
	for (i = 0; i <= len - (seg + seg); i += (seg + seg)) {
		merge(a, b, i, i + seg - 1, i + seg + seg - 1);
	}
	// 如果一段是正好可归并的数量而另一段则少于正好可归并的数量
	if (i + seg < len) {
		merge(a, b, i, i + seg - 1, len - 1);
	} else {
		for (int j = i; j < len; ++j) {
			b[j] = a[j];
		}
	}
}


template <typename _Key>
void merge_sort(_Key arr[], int size) {
	_Key *temp = new _Key[size];
	for (int seg = 1; seg < size; seg += seg) {
		merge_pass(arr, temp, seg, size);
		seg += seg;
		merge_pass(temp, arr, seg, size);
	}
	delete [] temp;
}

#endif /* _MERGE_SORT_H_ */
