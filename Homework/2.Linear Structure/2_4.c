#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node* next;
}Node;

Node* list_free(Node* list)
{
	while(list)
	{
		Node* del=list;
		list=list->next;
		free(del);
	}
	return list;
}

Node* getList(int N)
{
	Node* list=(Node*)malloc(sizeof(Node));
	list->next=NULL;
	Node* fill=list;
	int count=0;
	for(count=0;count<N;count++)
	{
		fill->next=(Node*)malloc(sizeof(Node));
		fill=fill->next;
		scanf("%d",&fill->num);
	}
	return list;
}

Node* create_list(int N,int isZero)
{
	Node* create=(Node*)malloc(sizeof(Node));
	Node* fill=create;
	int i;
	for(i=0;i<N;i++)
	{
		fill->next=(Node*)malloc(sizeof(Node));
		fill=fill->next;
		fill->num=(i+1)*(1-isZero);
	}
	return create;
}

int test(Node* list,int M,int N)
{
	int isTrue=1;
	int cnt=0;
	Node* input=create_list(N,0);
	Node* output=list;
	Node* Stack=(Node*)malloc(sizeof(Node));
	Stack->next=NULL;
	
	Node* p_in=input->next;
	Node* p_out=output->next;
	
	while(p_in && p_out)
	{
		//Fill in the current p_in,count++
		if(p_in->num<=p_out->num)
		{
			if(Stack->next==NULL)
			{
				Node* temp=(Node*)malloc(sizeof(Node));
				Stack->next=temp;
				temp->next=NULL;
			}
			else
			{
				Node* temp=(Node*)malloc(sizeof(Node));
				temp->next=Stack->next;
				Stack->next=temp;
			}
			Stack->next->num=p_in->num;
			cnt++;
			if(p_in->next)
			{
				p_in=p_in->next;
			}
		}
		//If stack has exploded,it's False
		if(cnt>M)
		{
			isTrue=0;
			break;
		}
		
		//If it's smaller than the p_out,then continue
		if(Stack->next->num<p_out->num)
		{
			continue;
		}

		//If we need to pop,move p_out
		else if(Stack->next->num==p_out->num)
		{
			if(Stack->next->next==NULL)
			{
				free(Stack->next);
				Stack->next=NULL;
			}
			else
			{
				Node* position=Stack->next;
				Stack->next=Stack->next->next;
				free(position);
			}
			p_out=p_out->next;
			cnt--;
		}
		
		//If it's bigger than p_out,it's False
		else if(Stack->next->num>p_out->num)
		{
			isTrue=0;
			break;
		}
	}
	return isTrue;
}

int main()
{
	int M=0,N=0,T=0;
	scanf("%d %d %d",&M,&N,&T);
	Node* list[T];
	int count=0;
	for(count=0;count<T;count++)
	{
		list[count]=getList(N);
	}
	
	for(count=0;count<T;count++)
	{
		int tmp=test(list[count],M,N);
		if(tmp)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
