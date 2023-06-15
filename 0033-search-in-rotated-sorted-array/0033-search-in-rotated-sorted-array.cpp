class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start=0;
        int end=arr.size()-1;
        // if(arr.size()==2){
        //     if(arr[start]==target) return start;
        //     if(arr[end]==target) return end;
        // }
        while(start<=end){
            int mid= (start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            
            //right half sorted
            if(arr[start]>arr[mid]){
                 if(arr[mid]<=target && arr[end]>=target){
                     start=mid+1;
                 }
                 else{
                     end=mid-1;
                 }
            }

            //left half is sorted
            else{
                if(arr[mid]>=target && arr[start]<=target){
                     end=mid-1;
                 }
                 else{
                     start=mid+1;;
                 }
            }
        }
        return -1;
    }
};