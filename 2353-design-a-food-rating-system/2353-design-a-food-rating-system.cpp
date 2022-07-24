class FoodRatings {
public:

    
    typedef pair<string, int> pi;
    class cmp {
    public:
        bool operator()(const pi& a, const pi& b)const {
            return (a.second == b.second ? a.first < b.first : a.second > b.second);
        }
    };
    unordered_map<string, pi>foods;
    unordered_map<string, set<pi, cmp>>cus;
    
public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n = f.size();
        for (int i = 0;i < n;++i) {
            foods[f[i]] = pi(c[i], r[i]);
            cus[c[i]].insert(pi(f[i], r[i]));
        }
    }

    void changeRating(string food, int newRat) {
        string c = foods[food].first;
        int oldRat = foods[food].second;
        foods[food].second = newRat;
        cus[c].erase({ food, oldRat });
        cus[c].insert({ food, newRat });
    }

    string highestRated(string c) {
        return cus[c].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */