#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

// template <typename _Key>
// int adjust_array(int arr[], int low, int high) {
// 	int left = low, right = high;
// 	int key = arr[left];
// 	while (left < right) {
// 		while (left < right && arr[right] >= key) --right;
// 		arr[left] = arr[right];
// 		while (left < right && arr[left] < key) ++left;
// 		arr[right] = arr[left];
// 	}
// 	arr[left] = key;
// 	return left;
// }

// template <typename _Key>
void quick_sort_base(int arr[], int low, int high) {
	if (low < high) {
		// int i = adjust_array(arr, low, high);
		int left = low, right = high;
		int key = arr[left];
		while (left < right) {
			while (left < right && arr[right] >= key) --right;
			arr[left] = arr[right];
			while (left < right && arr[left] < key) ++left;
			arr[right] = arr[left];
		}
		arr[left] = key;
		quick_sort_base(arr, low, left - 1);
		quick_sort_base(arr, left + 1, high);
	}
}

// template <typename _Key>
void quick_sort(int arr[], int len) {
	quick_sort_base(arr, 0, len - 1);
}

#endif /* _QUICK_SORT_H_ */
