#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct Node *next, *prev;
}*head = NULL, *tail = NULL;


struct Node *createNewNode(int value)
{
	struct Node *newEle = (Node*) malloc(sizeof(Node));
	
	newEle->value = value;
	newEle->next = newEle->prev = NULL;
	return newEle;
}

void pushHead(int value)
{
	
	struct Node *newEle = createNewNode(value);
	
	if(head == NULL)
	{
		head = tail = newEle;
		return;
	}
	
	
	newEle->next = head;
	head->prev = newEle;
	head = newEle;
}

void pushTail(int value)
{
	struct Node *newEle = createNewNode(value);
	
	if(tail == NULL)
	{
		head = tail = newEle;
		return;
	}
	
	tail->next = newEle;
	newEle->prev = tail;
	tail = newEle;
}

void pushMid(int value)
{
	struct Node *newEle = createNewNode(value);
	
	if(head == NULL)
	{
		head = tail = newEle;
		return;
	}
	else if(head->value >= value)
	{
		newEle->next = head;
		head->prev = newEle;
		head = newEle;
		return;
	}
	else if(tail->value <= value)
	{
		newEle->prev = tail;
		tail->next = newEle;
		tail = newEle;
		return;
	}
	
	struct Node *curr = head;
	
	while(curr->next != NULL && curr->next->value < value)
	{
		curr = curr->next;
	}
	
	if(curr == NULL)
	{
		return;
	}
	else
	{
		newEle->prev = curr;
		newEle->next = curr->next;
		curr->next->prev = newEle;
		curr->next = newEle;
	}
}

void popHead()
{
	if(head == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		free(head);
		head = tail = NULL;
		return;
	}
	
	head = head->next;
	free(head->prev);
	head->prev = NULL;
}

void popTail()
{
	if(tail == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		free(head);
		head = tail = NULL;
		return;
	}
	
	tail = tail->prev;
	free(tail->next);
	tail->next = NULL;
}


void printAll()
{
	struct Node *curr = head;
	
	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	
	printf("\n");
}

void printReverse()
{
	struct Node *curr = tail;
	
	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->prev;
	}
	
	printf("\n");
}

int main()
{
	pushMid(100);
	printAll();
	pushMid(10);
	printAll();
	pushMid(30);
	printAll();
	pushMid(70);
	printAll();
	pushMid(50);
	printAll();
	pushMid(40);
	printAll();
	
	popTail();
	printAll();
	
	printReverse();

}
