// Remove Duplicates

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> v(n+1);
    vector<int> duplicate(1010);
    vector<int> res;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++) {
        duplicate[v[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(duplicate[v[i]] == 1) res.push_back(v[i]);
        else if(duplicate[v[i]] > 1) duplicate[v[i]]--;
    }

    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}