typedef struct meeting{
    int id;
    int start;
    int end;
}meeting;


 bool compare(meeting a ,meeting b){
    if(a.end==b.end) return a.id<b.id;
    else return a.end<b.end;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int N=start.size();
    meeting* meet=new meeting[N];
    for(int i=0;i<N;i++){
        meet[i].id=(i+1);
        meet[i].start=start[i];
        meet[i].end=end[i];
    }
    sort(meet,meet+N,compare);
    int end_time=-1;
    int count=0;
    for(int i=0;i<N;i++){
        if(meet[i].start>end_time){
            end_time=meet[i].end;
            count++;
        }
    }
    return count;
}