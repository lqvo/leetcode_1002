#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int length = A.size();
        if (length == 1)return A;
        vector<string>ans;
        for (char c = 'a'; c <= 'z'; c++) {
            int repeat = 100;
            for (string i : A) {
                int temp=check(i, c);
                if (temp == 0) { repeat = 0; break; }
                else repeat = min(repeat, temp);
            }
            if (repeat == 0)continue;
            else {
                string s;
                s.push_back(c);
                for (int i = 1; i <= repeat; i++)
                    ans.push_back(s);
            }
        }
        return ans;
    }
    int check(string str, char c) {
        int ans = 0;
        for (char i : str)
            if (i == c)ans++;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string>s = { "bella","label","roller" };
    vector<string>ans = sol.commonChars(s);
    for (string i : ans)cout << i << endl;
    return 0;
}