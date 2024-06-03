// Question: https://geeksforgeeks.org/batch/sp-2019/track/sp-arrays-and-searching/problem/equilibrium-point-1587115620


// Sol-1: O(n^2)
int equilibriumPoint(long long a[], int n) {
    for (int i=0;i<n;i++) {
        long long leftSum = 0;
        long long rightSum = 0;
        
        for (int j=0;j<i;j++) {
            leftSum = leftSum + a[j];
        }
        
        for (int k=i+1;k<n;k++) {
            rightSum = rightSum + a[k];
        }
        
        if (leftSum == rightSum) {
            return i+1;
        }
    }
    
    return -1;
}

// Sol-2: O(nlogn)
int equilibriumPoint(long long a[], int n) {
    int l = 0;
    int h = n;

    while (l<h) {
        int m = l + (h-l)/2;
        int sl = 0;
        int sh = 0;
        for (int i = 0 ; i< m; i++){
            sl = sl + a[i];        
        }
        for (int j = m+1 ; j< n; j++){
            sh = sh + a[j];
        }
        
        if (sl == sh) {
            return m+1;
        }
        
        if (sh > sl) {
            l++;   
        }
        if (sh < sl) {
            h--;   
        }
    }
    
    return -1;
}

// Sol-2: O(n)
int equilibriumPoint(long long a[], int n) {
    
    long long totalSum =0;
    
    for (int i=0;i<n;i++){
        totalSum = totalSum + a[i];
    }
    
    long long leftSum = 0;
    
    for (int j=0;j<n;j++) { 
        leftSum = leftSum + a[j];
        
        if ((totalSum - leftSum) + a[j] == leftSum) { 
            return j+1;
        }
            
    }
    
    return -1;
}