// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 6, 5, 9, 11};
    int target = 15;
    int n = sizeof(arr)/sizeof(int);
    // Brute force
    for (int i = 0; i <n;i++){
        for(int j = i+1;j< n;j++){
            if(arr[i] + arr[j] == target){
                cout << "Brute Fore: " << i << " " << j << endl;
            }
        }
    }
    // Better approach using hashmap
    map <int, int> mpp;
    for(int i = 0; i < n;i++){
        int required = target - arr[i];
        
    }
}