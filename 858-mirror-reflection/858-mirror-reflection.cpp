class Solution {
public:
    int gcd(int a, int b)
    {
        if(!b) return a;
        return gcd(b, a%b);
    }
    
    // we need to find m and n such that m*p = n*q;
    
    int mirrorReflection(int p, int q) {
        int lcm = (p*q)/gcd(p,q);
        int m = lcm/p; 
        int n = lcm/q;
        
        if(m%2==0 && n%2==1) return 0;
        else if(m%2==1 && n%2==1) return 1;
        else if(m%2==1 && n%2==0) return 2;
        else return -1;
    }
};