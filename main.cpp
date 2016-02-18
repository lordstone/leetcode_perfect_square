class Solution {
public:
    int upper;
    unordered_map<int, int> myMap;
    int numSquares(int n) {
        if(n == 1) return 1;
        upper = 1;
        while((upper * upper) <= n){
            upper ++;
        }
        return helper(n);
    }
    
    int helper(int n){
        if(n < 0) return -1;
        if(n <= 1) return n;
        int counter = INT_MAX;
        for(int i = upper; i > 0; i --){
            int res; 
            if(n == i * i) return 1;
            if(myMap.find(n - i * i) != myMap.end()){
                res = myMap[n - i * i];
            }else{
                res = helper(n - i * i);
                myMap[n - i * i] = res;
            }
            if(res == -1) continue;
            if(res < counter) {
                counter = res;
            }
        }
        return (counter == INT_MAX) ? -1 : counter + 1 ;
    }
};
