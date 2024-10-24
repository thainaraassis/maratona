// https://vjudge.net/contest/658444#problem/F
// Cabos de Rede

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;


int LIS(vector<int>& nums) {

    // Binary search approach
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) ans.push_back(nums[i]);
        else {

            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}



int main() {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cabos(m);
    vector<int> pares(m);

    for(int i = 0; i < m; i++) cin >> cabos[i].first >> cabos[i].second;
    
    // caso ai = aj; pegamos o de maior b primeiro
    sort(cabos.begin(), cabos.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) 
            return a.second > b.second; 
        return a.first < b.first;
    });

    for(int i = 0; i < m; i++) pares[i] = cabos[i].second;

    cout << LIS(pares) << endl;

    return 0;
}