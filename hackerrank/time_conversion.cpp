#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    string hStr = s.substr(0, 2);
    string mStr = s.substr(3, 2);
    string sStr = s.substr(6, 2);
    string timeStr = s.substr(8, 2);
    int h = stoi(hStr);
    
    string a;
    
    if(h == 12 && timeStr == "AM") a = "00:" + mStr + ":" + sStr;
    else if(timeStr == "AM") a = s.substr(0, 8);
    else if(h == 12 && timeStr == "PM") a = s.substr(0, 8);
    else if(timeStr == "PM") {
        h += 12;
        a = to_string(h) + ":" + mStr + ":" + sStr;
    }
    
    return a;
    
}