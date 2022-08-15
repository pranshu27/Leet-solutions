class Solution {
public:
    int prior(char ch)
    {
        if(ch=='M') return 7;
        else if(ch=='D') return 6;
        else if(ch=='C') return 5;
        else if(ch=='L') return 4;
        else if(ch=='X') return 3;
        else if(ch=='V') return 2;
        return 1;
    }
    
    int val(char ch)
    {
        if(ch=='M') return 1000;
        else if(ch=='D') return 500;
        else if(ch=='C') return 100;
        else if(ch=='L') return 50;
        else if(ch=='X') return 10;
        else if(ch=='V') return 5;
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