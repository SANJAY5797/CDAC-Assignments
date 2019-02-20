#include <iostream>
using namespace std;

class CQueue
{
	int data[50], n;
	int front, rear;
public:
	CQueue()
	{
		cout << "Enter Size: ";
		cin >> n;

		for (int i = 0; i < n; i++)
			data[i] = 0;
		front = -1;
		rear = -1;
	}
	void Enque();
	void Deque();
	void display();
};

void CQueue::Enque()
{
	if ((rear == 0 && front == n - 1) || (rear == front + 1))
		cout << "Queue Overflow\n";
	else
	{
		cout << "Enter Data: ";
		int d;
		cin >> d;
		if (rear == -1)
			rear = 0;
		front = (front + 1) % n;
		data[front] = d;
	}
}

void CQueue::Deque()
{
	if (rear == -1)
		cout << "Queue Underflow\n";
	else
	{
		int d;
		d = data[rear];
		if (rear == front)
		{
			rear = -1;
			front = -1;
		}
		else
		{
			rear = (rear + 1) % n;
		}
		cout << "Deleted Element is: " << d << "\n";
	}
}


void CQueue::display()
{
	if (rear == -1)
	{
		cout << "Queue is Empty\n";
	}
	else
	{
		int i;
		for (i = rear; i != front; i = (i + 1) % n)
			cout << data[i] << " ";
		cout << data[i] << "\n";
	}
}


int main()
{

	CQueue cq;
	int flag = 0;
	while (flag != 1)
	{

		cout << "\n1-Enque\n2-Deque  \n3-display \n4-exit\n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			cq.Enque();
			break;
		case 2:
			cq.Deque();
			break;
		case 3:
			cq.display();
			break;
		case 4:
			flag = 1;
			break;
		}
	}
	system("pause");
}
