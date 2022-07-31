class Solution {
public:
    int findGCD(int a, int b) //Euclids GCD algo
    {
        if(b==0) return a;
        return findGCD(b, a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = 0;
        priority_queue<int,vector<int>,greater<int>> pq; 
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = (op>numsDivide[i])? findGCD(op,numsDivide[i]): findGCD(numsDivide[i], op); 
        }
        for(const int &i : nums){
            pq.push(i); 
        } 
        while(!pq.empty()){ 
            int temp = pq.top();
            pq.pop();
            if(op%temp == 0){ 
                return c;
            }

            c++;
            
        }
        return -1;
    }
};