double binExpo(long a, int n){
  double res = 1; 
  for(int i = 0; i < n; i++){
    res = res * a; 
  }
  return res;
}
int NthRoot(int n, int m) {
  // Write your code here.
  long low = 0, high = m, ans = -1;
  while(low <= high){
    long mid = low + (high - low)/2; 
    double x = binExpo(mid, n); 
    if(x == m){
      ans = mid; 
      break; 
    }else if(x < m) low = mid + 1;
    else high = mid - 1; 
  }
  return ans;
}
