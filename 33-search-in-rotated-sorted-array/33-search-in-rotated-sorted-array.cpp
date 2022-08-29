class Solution {
public:
    int search(vector<int>& arr, int K) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low<=high)
        {
            int mid = (low+high)>>1;

            if(arr[mid] == K) return mid;

            if(arr[mid] >= arr[low])
            {
                if(K<arr[low] || K>arr[mid]) low = mid+1;
                else high = mid-1;
            }
            else
            {
                if(K>arr[high]|| K<arr[mid]) high = mid-1;
                else low = mid+1;
            }
        }

        return -1;
    }
};