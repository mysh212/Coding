// Author : ysh
// 02/19/2022 Sat 17:44:17.25
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[0];
        int ans = 0;
        for(int i = 1;i<n;i++) {
            while(1) {
            if(nums[i] == tmp) {
                nums.erase(nums.begin() + i);
                ans++;
                n--;
            } else {
                tmp = nums[i];
                break;
            }
            }
        }
        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f;
    f.push_back(1);
    f.push_back(1);
    f.push_back(2);
    int tmp = removeDuplicates(f);
    for(int i : f) {
        cout<<i<<" ";
    }
    return 0;
}