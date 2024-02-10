#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int poly;
	int order;
	struct node* next;
}Node;

Node* sort(Node* node,int length);
Node* noZero(Node* node);
Node* merge(Node* node);
void print_list(Node *node);

int main()
{
	int N1=0,N2=0;
	Node* head_1=(Node*)malloc(sizeof(Node));
	Node* head_2=(Node*)malloc(sizeof(Node));
	Node* fill_1=head_1,*fill_2=head_2;
	scanf("%d",&N1);
	int i=0,j=0;
	if(N1==0)
	{
		N1=1;
		Node* temp_1=(Node*)malloc(sizeof(Node));
		fill_1->next=temp_1;
		fill_1=temp_1;
		fill_1->poly=0;
		fill_1->order=0;
	}
	else
	{
		for(i=1;i<=N1;i++)
		{
			Node* temp_1=(Node*)malloc(sizeof(Node));
			fill_1->next=temp_1;
			fill_1=temp_1;
			scanf("%d %d",&fill_1->poly,&fill_1->order);
		}
	}
	scanf("%d",&N2);
	if(N2==0)
	{
		N2=1;
		Node* temp_2=(Node*)malloc(sizeof(Node));
		fill_2->next=temp_2;
		fill_2=temp_2;
		fill_2->poly=0;
		fill_2->order=0;
	}
	else
	{
		for(i=1;i<=N2;i++)
		{
			Node* temp_2=(Node*)malloc(sizeof(Node));
			fill_2->next=temp_2;
			fill_2=temp_2;
			scanf("%d %d",&fill_2->poly,&fill_2->order);
		}
	}
	//Now We've got two Polynomials----head checked

	Node* Plus=(Node*)malloc(sizeof(Node));
	Plus->next=NULL;
	Node* Mul=(Node*)malloc(sizeof(Node));
	Mul->next=NULL;
	Node* fill_plus=Plus,*fill_mul=Mul;
	Node* find_1=head_1->next,*find_2=head_2->next;
	//Next multiply polynomials----headn checked

	for(i=0;i<N1;i++)
	{
		for(j=0;j<N2;j++)
		{
			Node* temp=(Node*)malloc(sizeof(Node));
			fill_mul->next=temp;
			fill_mul=temp;
			fill_mul->poly=find_1->poly*find_2->poly;
			fill_mul->order=find_1->order+find_2->order;
			find_2=find_2->next;
		}
		find_2=head_2->next;
		find_1=find_1->next;
	}
	find_1=head_1->next;
	//Next plus them

	for(i=0;i<N1;i++)
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		fill_plus->next=temp;
		fill_plus=temp;
		fill_plus->poly=find_1->poly;
		fill_plus->order=find_1->order;
		find_1=find_1->next;
	}
	find_1=head_1->next;
	for(j=0;j<N2;j++)
	{
		Node* temp=(Node*)malloc(sizeof(Node));
		fill_plus->next=temp;
		fill_plus=temp;
		fill_plus->poly=find_2->poly;
		fill_plus->order=find_2->order;
		find_2=find_2->next;
	}
	find_2=head_2->next;
	//Now we need to sort them

	Plus=sort(Plus,N1+N2);
	Mul=sort(Mul,N1*N2);
	Plus=noZero(Plus);
	Mul=noZero(Mul);
	Plus=merge(Plus);
	Mul=merge(Mul);
	print_list(Mul);
	print_list(Plus);
	return 0;
}



Node* sort(Node* node,int length)
{
	int change=0,cnt=0,i=0;
	Node* find_plus=node->next;
	while(cnt<length)
	{
		for(i=0;i<length-cnt-1;i++)
		{
			if(find_plus->order<find_plus->next->order)
			{
				change=find_plus->order;
				find_plus->order=find_plus->next->order;
				find_plus->next->order=change;

				change=find_plus->poly;
				find_plus->poly=find_plus->next->poly;
				find_plus->next->poly=change;

				find_plus=find_plus->next;
			}
			else
			{
				find_plus=find_plus->next;
			}
		}
		find_plus=node->next;
		cnt++;
	}
	return node;
}

Node* noZero(Node* node)
{
	Node* test=node->next;
	Node* former=node;
	while(test->next)
	{
		if(test->poly==0)
		{
			test=test->next;
			free(former->next);
			former->next=test;
		}
		else
		{
			test=test->next;
			former=former->next;
		}
	}
	if(test->poly==0)
	{
		free(test);
		former->next=NULL;
	}
	if(node->next==NULL)
	{
		node->next=(Node*)malloc(sizeof(Node));
		node->next->poly=0;
		node->next->order=0;
		node->next->next=NULL;
	}
	return node;
}

Node* merge(Node* node)
{
	Node* test=node->next;
	Node* former=node;
	while(test->next)
	{
		if(test->order==test->next->order)
		{
			test->next->poly += test->poly;
			if(test->next->poly!=0)
			{
				test=test->next;
				free(former->next);
				former->next=test;
			}
			else if(test->next->poly==0 && test->next->next)
			{
				test=test->next->next;
				free(former->next->next);
				free(former->next);
				former->next=test;
			}
			else if((test->next->poly==0 )&& (test->next->next==NULL))
			{
				free(test->next);
				free(test);
				former->next=NULL;
				break;
			}
		}
		else
		{
			test=test->next;
			former=former->next;
		}
	}
	if(node->next==NULL)
	{
		node->next=(Node*)malloc(sizeof(Node));
		node->next->poly=0;
		node->next->order=0;
		node->next->next=NULL;
	}
	return node;
}

void print_list(Node *node)
{
	Node* print=node->next;
	while(print)
	{
		if(print->next)
		{
			printf("%d %d ",print->poly,print->order);
			print=print->next;
		}
		else
		{
			printf("%d %d",print->poly,print->order);
            break;
		}
	}
	printf("\n");
}
