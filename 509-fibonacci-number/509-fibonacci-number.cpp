class Solution {
public:
    int f[31];
    int fib(int n) {
        if(n==0 || n == 1) return f[n] = n;
        
        return f[n] = fib(n-1)+fib(n-2);
    }
};