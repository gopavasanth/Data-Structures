// Solution-1

void reverseInGroups(vector<long long>& arr, int n, int k) {
    
    for (int i=0;i<n;i=i+k){
        int lIndex = i;
        int rIndex = min(i+k-1, n-1);
        
        while (lIndex != rIndex) {
            swap(arr[lIndex], arr[rIndex]);
            lIndex++;
            rIndex--;
        }
    }    
}

// Solution-2

void reverseArray(vector<long long>& temp) {
    reverse(temp.begin(), temp.end());
}

void displayArray(const vector<long long>& temp) {
    for (const auto itr : temp) {
        cout << itr << " ";
    }
    cout << endl;
}

void reverseInGroups(vector<long long>& arr, int n, int k) {

    vector<long long> temp;
    int c=0;
    for (int i=0;i<n;i++) {
        if (c<k){
            temp.push_back(arr[i]);
            c=c+1;
        }
        if (c==k){
            reverseArray(temp);
            for (int j=0;j<k;j++){
                arr[i-k +1 + j] = temp[j];
            }
            temp.clear();
            c=0;
        }
    }
    reverseArray(temp);
    int len = arr.size();
    for (int l=0;l<temp.size();l++){
        arr[len - temp.size() + l] = temp[l];
    }
}