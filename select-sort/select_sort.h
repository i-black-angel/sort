#ifndef _SELECT_SORT_H_
#define _SELECT_SORT_H_

template <typename _Key>
void SelectionSort(_Key arr[], int len) {
	int min_index = 0;
	for (int i = 0; i < len; ++i) {
		min_index = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		if (i != min_index)
			std::swap(arr[min_index], arr[i]);
	}
}

template <typename _Key, typename _Compare>
void SelectionSort(_Key arr[], int len, _Compare key_comp) {
	int min_index = 0;
	for (int i = 0; i < len; ++i) {
		min_index = i;
		for (int j = i + 1; j < len; ++j) {
			if ( key_comp(arr[j], arr[min_index]) )
				min_index = j;
		}
		if (i != min_index)
			std::swap(arr[min_index], arr[i]);
	}
}

#endif /* _SELECT_SORT_H_ */
