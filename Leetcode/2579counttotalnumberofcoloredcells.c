long long coloredCells(int n) {
    long long value=1;
    if (n==1){
        return value;
    }
    for (int i=1;i<n;i++){
        value+=(4*i);
    }
    return value;
    
}
