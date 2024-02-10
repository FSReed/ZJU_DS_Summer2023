List Merge(List L1,List L2)
{
    List L=(List)malloc(sizeof(struct Node));
    L->Data=0;
    L->Next=NULL;
    List fill=L;
    List top1,top2;
    top1=L1->Next,top2=L2->Next;
    L1->Next=NULL;
    L2->Next=NULL;
    while(top1 && top2)
    {
        List new=(List)malloc(sizeof(struct Node));
        fill->Next=new;
        fill=new;
        if(top1->Data<top2->Data)
        {
            fill->Data=top1->Data;
            top1=top1->Next;
            if(top1==NULL)
            {
                fill->Next=top2;
                break;
            }
        }
        else
        {
            fill->Data=top2->Data;
            top2=top2->Next;
            if(top2==NULL)
            {
                fill->Next=top1;
                break;
            }
        }
    }
    return L;
}
