#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node* next;
} Node;

Node* CreateNode(Node* list, int num)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	list->num = num;
	list->next = temp;
	return temp;
}

Node* combine_lists(Node* list1, Node* list2)
{
	int flag1 = 1, flag2 = 1, i=0;
	Node *start1, *start2;
	Node* newList = (Node*)malloc(sizeof(Node));
	Node* temp = newList;
	if (!(list1 && list2))
		return NULL;
	start1 = list1;
	start2 = list2;
	
	while (flag1 || flag2)
	{
		//printf("point\n");
		if (start1->next == list1)
			flag1 = 0;
		if (start2->next == list2)
			flag2 = 0;
		
		if (i % 2 && list1 != NULL)
			CreateNode(temp,start1->num);
		else
			if (list2 != NULL)
				CreateNode(temp, start2->num);

		start1 = start1->next;
		start2 = start2->next;
		temp = temp->next;
		i++;
	}
	temp->next = newList;
	return newList;


}

int main()
{
	int i;
	Node *list = (Node*)malloc(sizeof(Node));
	Node *list2 = (Node*)malloc(sizeof(Node));
	Node* ans;
	list->num = 12;
	list2->num = -12;

	Node* temp1 = list, *temp2 = list2;
	for (i = 0; i < 20; i++)
	{
		if (i < 12)
		{
			CreateNode(temp1, i);
			temp1 = temp1->next;
		}
		CreateNode(temp2, -i);
		temp2 = temp2->next;
	}
	temp1->num = 1;
	temp2->num = -1;
	temp1->next = list;
	temp2->next = list2;
	ans = combine_lists(list, list2);
	temp1 = ans;
	while (temp1->next != ans)
	{
		printf("%d ", temp1->num);
		temp1 = temp1->next;
	}
	return 0;
}
