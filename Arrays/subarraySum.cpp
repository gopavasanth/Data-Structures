// Question: https://www.geeksforgeeks.org/batch/sp-2019/track/sp-arrays-and-searching/problem/subarray-with-given-sum-1587115621

// Sol-1: O(n)
vector<int> subarraySum(vector<int>arr, int n, long long s) {
    
    long long sum=arr[0];
    vector<int> v;
    int start = 0;
    
    for (int i=1;i<=n;i++){
        while (sum > s && start<i-1){
            if (sum > s){
                sum = sum - arr[start];
                start++;
            }
        }
        if (sum == s){
            v.push_back(start+1);
            v.push_back(i);
            return v;
        }
        
        if(i<n){
            sum = sum + arr[i];
        }
    }
    return {-1};
}