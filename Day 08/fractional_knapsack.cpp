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
    bool static compare(Item a,Item b){
        double value1=(1.0*a.value)/a.weight;
        double value2=(1.0*b.value)/b.weight;
        return value1>value2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        double price=0;
        int i;
        for(i=0;i<n;i++){
            if(W<arr[i].weight){
                break;
            }
            else{
                W-=arr[i].weight;
                price+=arr[i].value;
            }
        }
        if(W!=0.0f && i!=n){
            price+=(1.0*arr[i].value*W)/arr[i].weight;
        }
        return price;
        // Your code here
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