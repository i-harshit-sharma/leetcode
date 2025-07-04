// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space. 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {1,1,2,3,3,4,4,6,6};
	//Brute Force
	int n = sizeof(arr)/sizeof(int);
	for(int i = 0; i< n; i++) {
		int count = 0;
		for(int j = 0; j<n; j++) {
			if(arr[i] == arr[j]) {
				count++;
			}
		}
		if(count ==1) {
			cout << "Brute: "<<arr[i] << endl;
		}
	}
	// Better
	int maxi = INT_MIN;
	for(int num : arr) {
		maxi = max(num,maxi);
	}
	int count[maxi+1] ={0};
	for(int num: arr){
	    count[num]++;
	}
	for(int i = 0;i<maxi+1;i++){
	    if (count[i] == 1){
	        cout << "Better Approach: " << i << endl;
	    }
	}
	// Much better using hashmap
	map <int, int> mpp;
	for(int num: arr){
	    mpp[num]++;
	}
	for(auto it: mpp){
	    if(it.second == 1){
	        cout << "Much better: " << it.first << endl;
	    }
	}

    // Best solution
    int x = 0;
    for(int num: arr){
      x = x^num;  
    } 
    cout << "Best Approach: " << x<< endl;
	return 0;
}