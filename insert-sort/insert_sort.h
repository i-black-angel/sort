#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_

template <typename _Key>
void InsertSort(_Key arr[], int len) {
	int i = 0, j = 0;
	_Key temp;
	for (i = 1; i < len; ++i) {
		temp = arr[i];
		for (j = i; j > 0 && temp < arr[j - 1]; --j)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}


template <typename _Key, typename _Compare>
void InsertSort(_Key arr[], int len, _Compare key_comp) {
	int i = 0, j = 0;
	_Key temp;
	for (i = 1; i < len; ++i) {
		temp = arr[i];
		for (j = i; j > 0 && key_comp(temp, arr[j - 1]); --j)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

#endif /* _INSERT_SORT_H_ */
