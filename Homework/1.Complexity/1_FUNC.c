Position BinarySearch(List L,ElementType X)
{
    int mid,sub,sup;
    int position=NotFound;
    sub=1;
    sup=L->Last;
    mid=(sup+sub)/2;
    while(sub<=sup)
    {
        if(L->Data[mid]<X)
        {
            sub=mid;
        }
        else if(L->Data[mid]>X)
        {
            sup=mid;
        }
        else
        {
            position=mid;
            break;
        }
        mid=(sup+sub)/2;
        if((sup-sub)==1)
        {
            if(L->Data[sub]==X)
            {
                position=sub;
                break;
            }
            else if(L->Data[sup]==X)
            {
                position=sup;
                break;
            }
            else if(L->Data[sub]!=X && L->Data[sup]!=X)
            {
                break;
            }
        }
    }
    return position;
}