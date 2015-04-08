#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

//
// 冒泡排序时间复杂度最好的情况为O(n), 最坏情况是O(n^2)
// 基本思想是：两两比较相信记录的关键字，如果反序则交换
template <typename _Key>
void BubbleSort(_Key arr[], int len) {
	// set flag, if there's no changes, means arr is ok
	bool swap_flag = false;

	for (int m = 0; m < len - 1; ++m) {
		swap_flag = false;
		for (int i = 0; i < len - m - 1; ++i) {
			if (arr[i + 1] < arr[i]) {
				std::swap(arr[i], arr[i + 1]);
				swap_flag = true;
			} // if greater
		} // fori
		if ( !swap_flag ) break;
	} // form
}


template <typename _Key, typename _Compare>
void BubbleSort(_Key arr[], int len, _Compare key_comp) {
	// set flag, if there's no changes, means arr is ok
	bool swap_flag = false;

	for (int m = 0; m < len - 1; ++m) {
		swap_flag = false;
		for (int i = 0; i < len - m - 1; ++i) {
			// if (arr[i] > arr[i + 1]) {
			if ( key_comp(arr[i + 1], arr[i]) ) {
				std::swap(arr[i], arr[i + 1]);
				swap_flag = true;
			} // if greater
		} // fori
		if ( !swap_flag ) break;
	} // form
}

#endif /* _BUBBLE_SORT_H_ */
