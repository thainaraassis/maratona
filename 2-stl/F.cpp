// Digital string maximization

#include <bits/stdc++.h> 
using namespace std;

const int INF = 0x3f3f3f3f;

#define endl '\n';
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<ll> arr(n);
        multiset<ll> ms;
        multiset<ll> ans;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ms.insert(arr[i]);
        }

        for(int i = 0; i < n; i++) {
            auto it = ms.begin();

            if(*it == arr[i]) ans.insert(arr[i]);
            else {
                ans.insert(arr[i] + 1);
                ms.insert(arr[i] + 1);
            }
            auto it2 = ms.find(arr[i]);
            ms.erase(it2);
        }   

        for(auto i:ans) {
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}