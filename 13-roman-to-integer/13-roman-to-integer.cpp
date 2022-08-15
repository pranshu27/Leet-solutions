class Solution {
public:
    int prior(char &ch)
    {
        if(ch=='M') return 7;
        if(ch=='D') return 6;
        if(ch=='C') return 5;
        if(ch=='L') return 4;
        if(ch=='X') return 3;
        if(ch=='V') return 2;
        return 1;
    }
    
    int val(char &ch)
    {
        if(ch=='M') return 1000;
        if (ch=='D') return 500;
        if(ch=='C') return 100;
        if(ch=='L') return 50;
        if(ch=='X') return 10;
        if(ch=='V') return 5;
        return 1;
        
        
    }
    int romanToInt(string str) {
        
        int n = str.length();
        int sum = 0;
        
        stack<int> st;
        
        st.push(val(str[n-1]));
        
        for(int i=n-2; i>=0; i--)
        {
           // cout<<sum<<endl;
            int tmp_sum=0;
            if(prior(str[i])>=prior(str[i+1]) || st.empty()) {
                st.push(val(str[i]));
                //cout<<"pushed "<<val(str[i])<<endl;
            }
            
            else {
 
                tmp_sum = st.top()-val(str[i]);
                st.pop();
                
                //sum+=tmp_sum;
                st.push(tmp_sum);
                //cout<<"pushed "<<tmp_sum<<endl;
            }
            
        }

        
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    
        
        
    }
};