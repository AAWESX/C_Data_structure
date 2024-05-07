#include "LoopSinglyLinkedLis.h"

/* 
 * @brief ???????????? ??????
 * @param *L : ????????
 * @return Bool:true and false??
*/
LoopSyLinkList * InitlinkList(void)
{
    LoopSyLinkList * NewNode = (LoopSyLinkList *)malloc(sizeof(LoopSyLinkList));
    NewNode->data = 0;
    NewNode->next = NewNode;
    return NewNode;
}
/* 
 * @brief ??????¾Þ??
 * @param *L   : ????????
 * @param date : ??????
 * @return Bool:true and false??
*/
Bool InsertAtHeadLinkList(LoopSyLinkList *L,int data)
{
    LoopSyLinkList *Newnode = (LoopSyLinkList *) malloc(sizeof(LoopSyLinkList));
    if (Newnode == NULL) return false;
    Newnode->data = data;
    Newnode->next = L->next;
    L->next = Newnode;
    return true;

}

/* 
 * @brief ????¦Â?¾Þ??
 * @param *L   : ????????
 * @param date : ??????
 * @return Bool:true and false??
*/
Bool InsertAtTailLinkList(LoopSyLinkList *L,int data)
{
    LoopSyLinkList *p = L;
    LoopSyLinkList *NewNode = (LoopSyLinkList *)malloc(sizeof(LoopSyLinkList));
    if(NewNode == NULL)return false;
    NewNode->data = data;
    
    while (p->next != L){
        p = p->next;
    }

    NewNode->next = p->next;
    p->next = NewNode;
    return true;
    
}

/* 
 * @brief ???¦Ë?? ???????
 * @param *L   : ????????
 * @param i    : ????¦Ë?¨¢?
 * @param date : ??????
 * @return Bool:true and false??
*/
Bool InsertLinkList(LoopSyLinkList *L,int i,int Date)
{
    int j = 1;
    LoopSyLinkList *p;

    p = L;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if( !p || j > i)return false;
    
    LoopSyLinkList *NewNode = (LoopSyLinkList *)malloc(sizeof(LoopSyLinkList));
    NewNode->data = Date;
    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

/* 
 * @brief ??????
 * @param *L  : ????????
 * @param i   : ??????¦Ë?¨¢?
 * @param *e  : ??????????
 * @return Bool:true and false??
*/
Bool DeleteLinkList(LoopSyLinkList *L, int i)
{
    int j = 1;
    LoopSyLinkList *p = L;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    
    if(!p || j > i)return false;

    LoopSyLinkList *s = p->next;

    p->next = s->next;
    free(s);
    return true;

}

/* 
 * @brief ?????????????
 * @param *L   : ????????
 * @return Bool:true and false??
*/
Bool ClearLinkList(LoopSyLinkList *L)
{
    LoopSyLinkList *p,*OldNode;
    p = L;
    while (p != L)
    {
        OldNode = p->next;
        free(p);
        p = OldNode;
    }

    L->next = L;

    return true;
}

/* 
 * @brief ???????????§³?
 * @param *L   : ????????
 * @return Bool:true and false??
*/
void PrintfLinkList(LoopSyLinkList *L)  
{  
    printf("\r\n");
    LoopSyLinkList *p = L->next;  
    while (p != L)  
    {  
        printf("%d->", p->data);  
        p = p->next;  
    }  
    printf("NULL\r\n");  
}


int main(int argc, char const *argv[])
{
    LoopSyLinkList *SL;
    printf("Open\r\n");
    SL = InitlinkList();
    printf("Inser List:%d\r\n",InsertAtHeadLinkList(SL,1));
    printf("Inser List:%d\r\n",InsertAtHeadLinkList(SL,2));
    printf("Inser List:%d\r\n",InsertAtHeadLinkList(SL,3));
    printf("Inser List:%d\r\n",InsertAtTailLinkList(SL,4));
    printf("Inser List:%d\r\n",InsertAtTailLinkList(SL,5));
    PrintfLinkList(SL);
    printf("Delete List:%d\r\n",DeleteLinkList(SL,2));
    PrintfLinkList(SL);
    printf("Inser List:%d\r\n",InsertLinkList(SL,3,55));
    PrintfLinkList(SL);
    ClearLinkList(SL);
    PrintfLinkList(SL);
    return 0;
}
