#include <iostream>
using namespace std;
class Node
{
private:
	int data;
	Node* next;
public:
	Node() { data = 0; next = nullptr; }
	Node(int d) { data = d; next = nullptr; }
	void setData(int d) { data = d; }
	int getData() { return data; }
	void setNext(Node* n) { next = n; }
	Node* getNext() { return next; }
	friend class LinkedList;
	};
class LinkedList
{
private:
	Node* head;
public:
	LinkedList() { head = nullptr; }
	Node* getHead() { return head; }
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
	void printAll()
	{
		Node* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data<<endl;
			tmp = tmp->getNext();
		}
	}

};
bool AddLocker(char c) 
{
	if (c == 'd') return true; 
	return false; 
}
int main()
{
	LinkedList ArrivingTime,brustTime;
	char AddLock; 
	char closer='\n';
	cout << "Click d to Add a process"<<endl;
	cin >> AddLock;
	cout << endl;
	int count = 1;
	char Arrivetime,BrustTime;
	while (AddLocker(AddLock))
	{
		
		if (count == 1)
		{
			cout << "enter arrival Time then brust time" << "           " << "enter f to finish adding process" << endl << endl;
			count++;
		}
		
		cin >> Arrivetime;
	    if (Arrivetime == 'f')
			{
				count = 1;
				break;
			}
		ArrivingTime.Add(Arrivetime-'0');
		cin >> BrustTime;
		brustTime.Add(BrustTime - '0');

		}
	ArrivingTime.printAll();
	system("pause");
}