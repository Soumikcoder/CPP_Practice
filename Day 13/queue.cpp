class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = -1;
		rear = -1;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if(front==-1) {
			front++;
		}
		arr[++rear]=e;
		// Write your code here.
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(front==-1){
			return -1;
		}
		else if (front==rear){
			front=-1;
			int temp=arr[rear];
			rear=-1;
			return temp;
		}
		else{
			return arr[front++];
		}
		// Write your code here.
	}
};