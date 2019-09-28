#include <iostream>
int floorSqrt(int x) {
	if (x == 0 || x == 1) return x;
	int start = 1, end = x, ans;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (mid * mid == x) return mid;
		if (mid * mid < x) {
			start = mid + 1;
			ans = mid;
		}
		else end = mid - 1;
	}
	return ans;
}
int *Seive(int n) {
	static int isPrime[100];
	isPrime[0] = isPrime[1] = 1;
	for (int i = 2; i <= floorSqrt(n); i++) {
		for (int j = i + i; j <= n; j+=i) {
			isPrime[j] = 1;
		}
	}
	return isPrime;
}
int main() {
	int n;
	std::cin >> n;
	int *prime = Seive(n);
	for (int i = 0; i < n; i++) {
		if (!prime[i]) std::cout << i << " ";
	}
}
