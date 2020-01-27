// 递归法
void Probability(vector<int>& records, int end, int curr, int n){
    if(end == 0){
        ++records[curr - n];
    }
    else{
        for(int i = 1; i <= 6; ++i){
            Probability(records, end-1, curr+i, n);
        }
    }
}

void TossProbability(int n){
    vector<int> records(6*n-n+1, 0);
    Probability(records, n, 0, n);
    int total = pow(6, n);
    for(int i = 0; i < 6*n-n+1; ++i){
        cout << "P(" << i+n << ")= " << (float)records[i]*100/total << " %"<< endl;
    }
}

//循环法，据说时间效率搞
void PrintProbility(int n){
    vector<vector<int>> records(2, vector<int>(6*n+1, 0));
    int poi = 0;
    for(int i = 0; i < 6; ++i){
        records[0][i] = 1;
    }
    for(int i = 1; i < n; ++i){
        poi = 1 - poi;
        for(int j = 0; j < i; ++j) records[poi][j] = 0;
        for(int j = i; j < 6*i+6; ++j){
            for(int q = (j-6 > 0 ? j-6 : 0); q < j; ++q){
                records[poi][j] += records[1-poi][q];
            }
            cout << records[poi][j] << endl;
        }
    }
    int total = pow(6,n);
    for(int i = n-1; i < 6*n; ++i){
        cout << i+1 << ": " << (float)records[poi][i]/total << endl;
    }
}
