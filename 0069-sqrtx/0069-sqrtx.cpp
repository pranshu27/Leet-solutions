class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        // int ans;
        while(low<=high){
            long long mid = (low+high)>>1;
            if(mid*mid==x) return mid;
            else if(mid*mid < x) low = mid+1;
            else high = mid - 1;
        }
        return floor(high);
    }
};