class Solution {
public:
    int partition (vector<int>& arr, int low, int high)
    {
        int pivot = arr[high];
        int index = low-1;
           for(int i = low; i<high; i++)
           {

               if(arr[i]<pivot) {
                   index++;
                   swap(arr[index], arr[i]);
               }
           }
           index++;
           swap(arr[index], arr[high]);
           return index;
       // Your code here
    }
    int findKthLargest(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        int targetIndex = arr.size() - k;
        while(low<=high){
            int pivot = partition(arr, low, high);
            
            if(pivot>targetIndex) high = pivot-1;
            else if (pivot<targetIndex) low = pivot+1;
            else return arr[targetIndex];
            
            
        }
        return INT_MAX;
        
    }
};