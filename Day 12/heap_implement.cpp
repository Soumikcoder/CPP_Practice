#include <bits/stdc++.h> 
void meanheapify(vector<int> &heap,int index){
    int lc=index*2+1;
    int rc=index*2+2;
    int minimum=index;
    if(lc<heap.size() && heap[lc]<heap[minimum]){
        minimum=lc;
    }
    if(rc<heap.size() && heap[rc]<heap[minimum]){
        minimum=rc;
    }
    if(minimum!=index){
        swap(heap[minimum],heap[index]);
        meanheapify(heap,minimum);
    }
}
void insert(vector<int> &heap,int value){
    heap.push_back(value);
    int n=(heap.size()-1);
    int parent=(n-1)/2;
    while(heap[parent]>heap[n] && n>0){
        swap(heap[parent],heap[n]);
        n=parent;
        parent=(n-1)/2;
    }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> minheap;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i][0]==0){
            insert(minheap,q[i][1]);
        }
        else{
            ans.push_back(minheap[0]);
            swap(minheap[0],minheap[minheap.size()-1]);
            minheap.pop_back();
            meanheapify(minheap, 0);
        }
    }
    return ans;
}
