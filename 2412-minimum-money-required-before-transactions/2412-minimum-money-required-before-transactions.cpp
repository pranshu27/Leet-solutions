class Solution {
public:
	long long minimumMoney(vector<vector<int>>& transactions) {
		int opt1, opt2;
		sort(begin(transactions), end(transactions),
		     [&](vector<int>& a, vector<int>& b)
        { 
			opt1 = min(-a[0], -a[0] + a[1] - b[0]); //a->b
			opt2 = min(-b[0], -b[0] + b[1] - a[0]); //b->a
			if (opt1 != opt2)
				return opt1 < opt2;
			return a[0] > b[0];
		});
		long long currMoney = 0;
		long long ans = 0;
		for (vector<int>& currTaransaction : transactions)
		{
			currMoney -= currTaransaction[0];
			ans = min(ans, currMoney);
			currMoney += currTaransaction[1];
		}
		return abs(ans);
	}
};