class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    //for achieving O(n) we need to use either hashmap or countarray
    //we gonna store 1 if we have the element and 0 if not, then we gonna traverse the countarray and return the first element that has a zero
    //but this approach uses extra space 
    //so next approach could be sort the array and traverse it till we got the positive number once we have the positive number then see which one is missing
    //but this approach also use nlogn TC
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0; i<n; i++){
            int CI = arr[i] - 1;
            while(arr[i]>0 && arr[i] <= n && arr[i] != arr[CI]){
                swap(arr[i], arr[CI]);
                CI = arr[i] - 1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        
        return n+1;
    } 
};