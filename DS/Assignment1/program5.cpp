#include <iostream>
using namespace std;

class Queue
{
	int data[50], n;
	int rear, front;
public:
	Queue()
	{
		cout << "Enter Size: ";
		cin >> n;

		for (int i = 0; i < n; i++)
			data[i] = 0;
		rear = -1;
		front = -1;
	}
	void Enque();
	void Deque();
	void display();
};

void Queue::Enque()
{
	try
	{
		if (front == n - 1)
			throw front;
		else
		{
			cout << "Enter Data: " << endl;
			int d;
			cin >> d;
			data[++front] = d;
		}
	}
	catch (int a)
	{
		cout << "Queue OverFlow\n";
	}
}

void Queue::Deque()
{
	try
	{
		if ((rear == -1 && front == -1) || (rear+1 == front))
			throw rear;
		else
		{
			//cout << "Dequed Data is: " << data[rear] << "\n";
			rear++;
		}
	}
	catch (int a)
	{
		cout << "Queue UnderFlow\n";
	}
}


void Queue::display()
{
	try
	{
		if ((rear == -1 && front==-1) || rear+1 == front)
			throw rear;
		else
		{
			for (int i = front; i !=rear; i--)
				cout << data[i] << " ";
			cout << "\n";
		}
	}
	catch (int a)
	{
		cout << "Queue Empty\n";
	}
}
int main()
{
	Queue q;
	int flag = 0;
	while (flag != 1)
	{
		cout << "1. Enque\n2. Deque\n3. display\n4. exit\n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			q.Enque();
			break;
		case 2:
			q.Deque();
			break;
		case 3:
			q.display();
			break;
		case 4:
			flag = 1;
			break;
		}
	}
	// to stop console from closing
	system("pause");
}
