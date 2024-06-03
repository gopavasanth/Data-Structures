vector <int> countDistinct (int A[], int n, int k) {
    vector<int> v;
    
    unordered_map<int, int> m;

    for (int i=0;i<k;i++) {
        m[A[i]]++;   
    }
    
    v.push_back(m.size());
    
    for (int j=k;j<n;j++){
        int l = j-k;
        m[A[j]]++;
        m[A[l]]--;
        if (m[A[l]] == 0) {
            m.erase(A[l]);                
        }
        v.push_back(m.size());
    }
    
    return v;
}