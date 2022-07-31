class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = 0; // count
        priority_queue<int,vector<int>,greater<int>> pq; /// min heap
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = __gcd(op,numsDivide[i]); // as it will be the maximum number that will divide              all the numbers 
        }
        for(const int &i : nums){
            pq.push(i); // pushing all elements in the heap
        } 
        while(!pq.empty()){ 
            int temp = pq.top();
            pq.pop();
            if(op%temp == 0){ // if the minimum element divides the gcd return count at that time
                return c;
            }

            c++;
            
        }
        return -1;
    }
};