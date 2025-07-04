// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 1, 0,1, 0, 1, 1, 1, 4, 2, 3};
    int target = 3;
    int n = sizeof(arr) / sizeof(int);
    // Brute force O(n^3)
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > target)
            {
                break;
            }
            if (sum == target)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << "Brute Force (O(n^3)): " << ans << endl;
    // Brute Force O(n^2)
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                ans = max(ans, j - i + 1);
            }
            if (sum > target)
            {
                break;
            }
        }
    }
    cout << "Brute Force O(n^2): " << ans << endl;
    // hash map solution
    map<int, int> mpp;
    ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == target)
        {
            ans = max(i, ans);
        }
        if (!mpp.empty() && mpp.find(sum - target) != mpp.end())
        {
            auto it = mpp.find(sum - target);
            ans = max(i - it->second, ans);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    cout << "Hashmap Solution: " << ans << endl;

    ans = 0;
    int l = 0;
    int r = 0;
    sum = arr[0];
    while (r < n)
    {
        if(sum == target) {
            ans = max(ans, r-l+1);
            l++;
            sum-=arr[l];
        }
        else if(sum > target){
            l++;
            sum-=arr[l];
        } else {
            r++;
            sum+=arr[r];
        }
    }
    cout << "Two Pointer Solution: " << ans << endl;
}