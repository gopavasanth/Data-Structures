// Question: https://www.geeksforgeeks.org/batch/sp-2019/track/sp-arrays-and-searching/problem/find-transition-point-1587115620

int transitionPoint(int arr[], int n) {
    int l = 0;
    int h = n-1;
    int m = l + (h - l) / 2;
    int i = -1;
    
    while (l <= h) {
        int m = l+(h-l)/2;
        if (arr[m] == 1) {
            i = m;
            h = m-1;
        } else {
            l = m +1;
        }
    }
    
    return i;
}