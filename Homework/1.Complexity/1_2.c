#include <stdio.h>
#include <stdlib.h>

typedef struct index {
    int left_label;
    int right_label;
}Index;

typedef struct node{
    Index index;
    int Maxsum;
    int isMax;
    struct node* next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}List;
int main()
{
    int K=0;
    scanf("%d",&K);
    int* a=(int*)malloc(sizeof(int)*K);
    int cnt=0;
    int number;
    while(cnt<K)
    {
        scanf("%d",&number);
        a[cnt++]=number;
    }
    int i=0;
    int MaxSum=0;
    int ThisSum=0;
    int isNew=1;
	int isStarter=1;
	List list;
	list.head=NULL;
    list.tail=NULL;
    for(i=0;i<K;i++)
    {
        ThisSum += a[i];
        //建立一个新的子列，放入list表中
        if(ThisSum>0 && isNew)
        {
        	Node* new=(Node*)malloc(sizeof(Node));
        	new->index.left_label=i;
        	new->index.right_label=i;
        	new->Maxsum=ThisSum;
			new->isMax=(new->Maxsum>=MaxSum?1:0);
			new->next=NULL;
			MaxSum=ThisSum>MaxSum?ThisSum:MaxSum;
			if(isStarter)
			{
				list.head=new;
				list.tail=new;
				isStarter=0;
			}
			else
			{
				list.tail->next=new;
				list.tail=new;
			}
			isNew=0;
		}
		//已有的子列之和仍然为正，判断子列是否为最大子列
		else if(ThisSum>0 && !isNew)
		{
			//如果更大了，更新右标与子列和
			if(ThisSum>MaxSum)
			{
				list.tail->Maxsum=ThisSum;
				list.tail->isMax=1;
				list.tail->index.right_label=i;
				MaxSum=ThisSum;
			}
			//如果不如MaxSum大，那么右标与最大值均不变化
		}
		else if(ThisSum<0)
		{
			ThisSum=0;
			isNew=1;
		}
        
        
//        if(ThisSum>MaxSum)
//        {
//            MaxSum=ThisSum;
//            if(isNew)
//            {
//				new_count++;
//				isNew=0;
//				Node* new=(Node*)malloc(sizeof(Node));
//                new->index.left_label=i;
//                new->index.right_label=i;
//                new->Maxsum=ThisSum;
//                new->count=new_count;
//                if(new->count==1)
//                {
//                    list.head=new;
//                    list.tail=new;
//                }
//                else
//                {
//                    list.tail->next=new;
//                    list.tail=new;
//                }
//            }
//            else
//            {
//                list.tail->index.right_label=i;
//                list.tail->Maxsum=ThisSum;
//            }
//        }
//        else if(ThisSum<0)
//        {
//            ThisSum=0;
//            isNew=1;
//        }
//        else if((ThisSum==MaxSum)&&(MaxSum>0)&&(isNew==0))
//        {
//            list.tail->index.right_label=i;
//        }
    }
    
    
    if(MaxSum>0)
    {
	    Node* find=list.head;
	    while(find->Maxsum!=MaxSum)
	    {
	        find=find->next;
	    }
	    printf("%d %d %d\n",find->Maxsum,a[find->index.left_label],a[find->index.right_label]);
	}
 	else if(MaxSum==0)
	{
		int i=0;
        int isZero=0;
        for(i=0;i<K;i++)
        {
            if(a[i]==0)
            {
                isZero=1;
                break;
            }
        }
        if(isZero)
        {
            printf("%d %d %d\n",0,0,0);
        }
        else
        {
            printf("%d %d %d\n",MaxSum,a[0],a[K-1]);
        }
    }
	return 0;
}
