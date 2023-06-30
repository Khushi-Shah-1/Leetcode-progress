//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            double fraction= arr[i].value / (arr[i].weight *1.0);
            pq.push({fraction,i});
        }
        
        int total_val=0;
        double count=0.0;
        while(total_val<W && !pq.empty()){
            
            int i= pq.top().second;
            double frac= pq.top().first;
            pq.pop();
            
            if(arr[i].weight<= (W-total_val)){
                total_val+=arr[i].weight;
                count+=arr[i].value;
            }
            
            else{
                count+= (frac*(W-total_val));
                total_val= W;
            }
            
        }
        return count;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends