class MyCalendarThree {
public:
    int ans = 0;
    map<int, int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int tmp=0;
        for(auto &[l,r]: mp){
            tmp += r;
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */