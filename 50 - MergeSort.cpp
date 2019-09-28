#include <iostream>
const int MAX = 100;
void Merge(int arr[MAX], int l, int m, int r) {
	int L = (m - l) + 1;
	int R = r - m;
	int left[MAX], right[MAX];
	for (int i = 0; i < L; i++) {
		left[i] = arr[l + i];
	}
	for (int i = 0; i < R; i++) {
		right[i] = arr[m + i + 1];
	}
	int i, j, k;
	i = j = 0;
	k = l;
	while (i<L && j<R) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			++k;
			++i;
		}
		else {
			arr[k] = right[j];
			++k;
			++j;
		}
	}
	while (i < L) {
		arr[k] = left[i];
		++i;
		++k;
	}
	while (j < R) {
		arr[k] = right[j];
		++j;
		++k;
	}
}
void MergeSort(int arr[MAX], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}
int main() {
	int n;
	std::cin >> n;
	int arr[MAX];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	MergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
