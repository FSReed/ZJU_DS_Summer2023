#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int Address;
	int Num;
	int Point;
	struct node* next;
}Node;

Node* getInput(Node*);
Node* getList(Node*);
Node* K_sort(Node*,int);
void printList(Node*);
void swap(int*,int*);

int main()
{
	Node* input=(Node*)malloc(sizeof(Node));
	input=getInput(input);
	int K=input->Point;

	//Next create List.
	Node* list=NULL;
	list=getList(input);
	//Next sort and print
	list=K_sort(list,K);
	printList(list);
	return 0;
}


Node* getInput(Node* input)
{
	Node* fill=input;
	input->next=NULL;
	scanf("%d %d %d",&input->Address,&input->Num,&input->Point);
	int cnt=0;
	for(cnt=0;cnt<input->Num;cnt++)
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		fill->next=temp;
		fill=temp;
		scanf("%d %d %d",&fill->Address,&fill->Num,&fill->Point);
	}
	return input;
}

Node* getList(Node* input)
{
	Node* fill=input;
	while(fill->next)
	{
		int find=0;
		find=(fill==input)?fill->Address:fill->Point;
		Node* search=fill->next;
		while(search->Address!=find)
		{
			search=search->next;
		}
		swap(&search->Address,&fill->next->Address);
		swap(&search->Num,&fill->next->Num);
		swap(&search->Point,&fill->next->Point);
		if(fill->next->Point==-1)
		{
			fill->next->next=NULL;
			break;
		}
		fill=fill->next;
	}
	return input;
}

Node* K_sort(Node* head,int K)
{
	if(K==1) return head;
	Node* move=head;
	while(move->next)
	{
		Node* check=move;
		int cnt=0;
		for(cnt=0;cnt<K;cnt++)
		{
			check=check->next;
			if(check==NULL) break;
		}
		if(cnt!=K) break;
		if(K>2)
		{
			Node* done=move->next;
			Node* old=done->next;
			Node* tmp=old;
			int count=1;
			for(count=1;count<K;count++)
			{
				tmp=old->next;
				old->next=done;
				old->Point=old->next->Address;
				done=old;
				old=tmp;
			}
			tmp=move->next;
			tmp->next=old;
			if(tmp->next) tmp->Point=tmp->next->Address;
			Node* save=move->next;
			move->next=done;
			move->Point=move->next->Address;
			move=save;
		}
		else if(K==2)
		{
			Node* front=move->next;
			Node* back=front->next;
			move->next=back;
			move->Point=back->Address;
			front->next=back->next;
			if(front->next) front->Point=back->next->Address;
			back->next=front;
			back->Point=front->Address;
			move=front;
		}
	}
	return head;
}

void printList(Node* head)
{
	Node* print=head->next;
	while(print->next)
	{
		printf("%05d %d %05d\n",print->Address,print->Num,print->Point);
		print=print->next;
	}
	printf("%05d %d %d",print->Address,print->Num,-1);
}

///////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node {
//    int address;
//    int num;
//    int point;
//    struct node* next;
//}Node;
//
//
//void swap(int* num1,int* num2);
//Node* K_sort(Node* head,int K);
//void print(Node* node);
//Node* list_free(Node *);
//
//
//int main()
//{
//	Node* head=(Node*)malloc(sizeof(Node));
//	scanf("%d %d %d",&head->address,&head->num,&head->point);
//	int N=head->num;
//	int K=head->point;
//	Node* fill=head;
//	int i=0;
//	for(i=0;i<N;i++)
//	{
//		Node* temp=(Node*)malloc(sizeof(Node));
//		fill->next=temp;
//		fill=fill->next;
//		scanf("%d %d %d",&fill->address,&fill->num,&fill->point);
//	}
//	// creating finished
//	//next to sort them
//
//	fill=head;
//	while(fill->next)
//	{
//		int find=0;
//		find=(fill==head)?fill->address:fill->point;
//		Node* search=fill->next;
//		while(search->address!=find)
//		{
//			search=search->next;
//		}
//		swap(&search->address,&fill->next->address);
//		swap(&search->num,&fill->next->num);
//		swap(&search->point,&fill->next->point);
//		if(fill->next->point==-1)
//		{
//			fill->next->next=NULL;
//			break;
//		}
//		fill=fill->next;
//	}
//	//sort finished
//	//next use K-sort
//
//	head=K_sort(head,K);
//	print(head);
//    return 0;
//}
//
void swap(int* num1,int* num2)
{
	int t=0;
	t=*num1;
	*num1=*num2;
	*num2=t;
}
//
//Node* K_sort(Node* head,int K)
//{
//	Node* position=head->next;
//	Node* stack=(Node*)malloc(sizeof(Node));
//	stack->next=NULL;
//	Node* fill_stack=stack;
//	Node* position_stack=stack;
//	int count=0;
//	int isBreak=0;
//	while(position->next)
//	{
//		Node* check=position;
//		for(count=0;count<K-1;count++)
//		{
//			check=check->next;
//			if(check==NULL)
//			{
//				isBreak=1;
//				break;
//			}
//		}
//		if(isBreak)
//		{
//			break;
//		}
//		for(count=0;count<K;count++)
//		{
//			Node* temp=(Node*)malloc(sizeof(Node));
//			if(count==0)
//			{
//				position_stack=temp;
//			}
//			if(fill_stack->next==NULL)
//			{
//				temp->next=NULL;
//				fill_stack->next=temp;
//			}
//			else
//			{
//				temp->next=fill_stack->next;
//				fill_stack->next=temp;
//			}
//			temp->address=position->address;
//			temp->num=position->num;
//			temp->point=position->point;
//			position=position->next;
//		}
//		fill_stack=position_stack;
//		if(position==NULL)
//		{
//			break;
//		}
//	}
//	while(position)
//	{
//		fill_stack->next=(Node*)malloc(sizeof(Node));
//		fill_stack=fill_stack->next;
//		fill_stack->address=position->address;
//		fill_stack->num=position->num;
//		fill_stack->point=position->point;
//		position=position->next;
//	}
//	//Now we've finished sorting without handling point
//	//next change the points
//
//	fill_stack=stack->next;
//	while(fill_stack->next)
//	{
//		fill_stack->point=fill_stack->next->address;
//		fill_stack=fill_stack->next;
//	}
//	return stack;
//}
//
//void print(Node* head)
//{
//	Node* print=head->next;
//	while(print->next)
//	{
//		printf("%05d %d %05d\n",print->address,print->num,print->point);
//		print=print->next;
//	}
//	printf("%05d %d %d\n",print->address,print->num,-1);
//}
//
//Node* list_free(Node* list)
//{
//	while(list)
//	{
//		Node* del=list;
//		list=list->next;
//		free(del);
//	}
//	return list;
//}
