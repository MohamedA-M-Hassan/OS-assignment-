#include <iostream>
#include <string>
using namespace std;
class Node
{
private:
	double data;
	Node* next;
public:
	Node() { data = 0; next = nullptr; }
	Node(double d) { data = d; next = nullptr; }
	void setData(int d) { data = d; }
	double getData() { return data; }
	void setNext(Node* n) { next = n; }
	Node* getNext() { return next; }
	friend class LinkedList;
	};
class LinkedList
{
private:
	Node* head;

	string name;
	int arrival_time;
	int burst;
public:
	
	LinkedList() { head = nullptr; }
	bool isEmpty() 
	{ 
	if (head == nullptr)
		return true; 
	return false;
	}
	void Add(int item) 
	{
		if (isEmpty())
		{
			Node* nw = new Node(item);
			nw->next = head;
			head = nw;
		}
		else
		{
			Node* tmp = head;
			while (tmp->next != nullptr)
			{
				tmp = tmp->getNext();
			}
			Node* nw = new Node(item);
			tmp->setNext(nw);
		}
	}
	void sort()
	{
     Node *ptr, *s;
    int value;
    if (head == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = head;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }

	}
	void printAll()
	{
		Node* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data<<endl;
			tmp = tmp->getNext();
		}
	}


	// the process functions
	void set_name_of_process (string n)
	{
		name=n;
	}
	string get_name_of_process ()
	{
		return name;
	}
	void set_arrival_time (int t)
	{
		arrival_time=t;
	}
	double get_arrival_time ()
	{
		return arrival_time;
	}
	void set_burst (int b)
	{
		burst=b;
	}
	int get_burst ()
	{
		return burst;
	}
};
/*class Processing 
{
private:
	string name;
	double arrival_time;
	int burst;
public:
	void set_name_of_process (string n)
	{
		name=n;
	}
	string get_name_of_process ()
	{
		return name;
	}
	void set_arrival_time (double t)
	{
		arrival_time=t;
	}
	double get_arrival_time ()
	{
		return arrival_time;
	}
	void set_burst (int b)
	{
		burst=b;
	}
	int get_burst ()
	{
		return burst;
	}
};
*/
int main()
{		
		int choice;
		int no_of_processes;
		LinkedList arrivaltime;
		LinkedList burst;
		//Processing process;
		cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Types of schedulers supported:"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.FCFS"<<endl;
        cout<<"2.SJF (Preemptive and Non Preemptive)"<<endl;
        cout<<"3.Priority (Preemptive and Non Preemptive) (the smaller the priority number the higher the priority)"<<endl;
        cout<<"4.Round Robin"<<endl;
		cout<<"------------------------------------"<<endl;
        cout<<"Enter your choice : ";
        cin>> choice;
		// ��� ��� ���� ������ ���� ���� ���
		

		// let's tke the input ( arrival time & burst ) from the user 
		cout << "Please insert the number of processes\n ";
			cin >> no_of_processes;
			for (int i = 1; i <= no_of_processes; i++)
			{
				int x,y;
				cout <<  "insert the arrival time of process number: " << i << endl;
				cin >> x ;
				arrivaltime.Add(x);
				cout << "-----------------------------------" << endl;
				cout <<  "insert the burst of process number: " << i << endl;
				cin >> y;
				burst.Add(y);
				cout << "-----------------------------------" << endl;
			}
			arrivaltime.sort();
			arrivaltime.printAll();

        switch(choice)
        {
        case 1:
            cout<<"FCFS: "<<endl;
			break;
		case 2:
			cout<<"2";
			break;
		case 3:
			cout<<"3";
			break;

		case 4:
			cout<<"4";
			break;

			
		}
		return 0;
}
