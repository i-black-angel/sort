#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

template <typename _Key>
void shift(_Key arr[], int index, int len) {
	// 置 i 为要筛选的节点
	int i = index;

	int child = (i << 1) + 1;		// left child

	while (child < len) {
		// 如果要筛选的节点既有左孩子又有右孩子并且左孩子小于右孩子
		// 从二者中选出较大的并记录
		if (child + 1 < len && arr[child] < arr[child + 1])
			++child;
		// 如果要筛选的节点中的值大于左右孩子的较大值则退出
		if (arr[child] < arr[i]) break;

		std::swap(arr[child], arr[i]);
		i = child;
		child = (i << 1) + 1;
	}
}

template <typename T>
void heap_sort(T arr[], int len) {
	// 初始化建堆，i 从最后一个非叶子节点开始
	for (int i = (len - 2) / 2; i >= 0; --i) {
		shift(arr, i, len);
	}	
	for (int i = 0; i < len; ++i) {
		std::swap(arr[0], arr[len - i - 1]);
		shift(arr, 0, len - i - 1);
	}
}

#endif /* _HEAP_SORT_H_ */
