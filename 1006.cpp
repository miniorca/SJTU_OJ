#include<iostream>

using namespace std;

/*
	�����á�������������С��������һ��㡣��Ϊ��������������С��õ��Ľ������ֻ��һ����
	���������Ҫ�����Ҫȡ��������������Ҳ��������Ҫ��������������
*/

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	// arr[0] = 0;

	//int t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		// arr[i] = arr[i - 1] + t;
	}

	/*
		��Ȼ����д��bf��������ʱ ʱ�临�Ӷ�Ӧ����n����
		(��Ȼ��ʱ�� 70��)
	*/

	//int ans = -101, t = 0;

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		for (int k = i; k <= j; k++) {
	//			t += arr[k];
	//		}
	//		ans = t > ans ? t : ans;
	//		t = 0;
	//	}
	//}

	/*
		��������ǰ׺�� ʱ�临�Ӷ�Ӧ�ý�����nƽ��
		(�ֳ�ʱ��... ����70��)
	*/

	//int ans = -101;
	//t = 0;

	//for (int i = 1; i < n; i++) {
	//	for (int j = i + 1; j <= n; j++) {
	//		t = arr[j] - arr[i - 1];

	//		ans = t > ans ? t : ans;
	//		t = 0;
	//	}
	//	
	//}

	int ans = -101, dp = 0, predp = 0;

	for (int i = 0; i < n; i++) {
		predp = dp;

		if (dp > 0) {
			dp += arr[i];
			ans = dp > ans ? dp : ans;
		}
		else {
			dp = arr[i];
			if (dp > 0) {
				ans = (dp + predp) > ans ? (dp + predp) : ans;
			}
		}
	}

	if (ans > 0) {
		cout << ans;
	}
	else {
		cout << "Game Over";
	}

	return 0;
}