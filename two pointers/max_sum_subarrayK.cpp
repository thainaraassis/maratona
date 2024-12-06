#include <bits/stdc++.h> 
using namespace std;  
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
 
#define dbg(x) cout << #x << " = " << x << endl
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
#define int long long
 
// Two Pointer Technique (Opposite-directional)
vector<int> twoSum(vector<int> nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	vector<int> result(2);

	while (start < end) {
		int sum = nums[start] + nums[end];
		if (sum == target) {
			result[0] = start + 1;
			result[1] = end + 1;
			break;
		} else if (sum < target) {
			start++;
		} else {
			end--;
		}
	}
	return result;
}

// Two Pointer Technique (Equi-directional)
int getMaxSumSubArrayOfSizeKM2(vector<int>A, int k) {
	int windowSum = 0, maxSum = 0;
	int wStart = 0;
	int wEnd = 0;

	while (wEnd < k) {
		windowSum += A[wEnd++];
	}

	while (wEnd < A.size()) {
		windowSum += A[wEnd++] - A[wStart++];
		maxSum = max(maxSum, windowSum);
	}

	return maxSum;
}
