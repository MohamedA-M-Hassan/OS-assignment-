#include "linkedList.h"
#include "node.h"
#include "processes.h"
void main()
{
	linkedList l1;
	processes::create_Process(l1);
	l1.printAll();
	system("pause");
}