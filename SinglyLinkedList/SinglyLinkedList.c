#include "SinglyLinkedList.h"

/* 
 * @brief ��ʼ������ ��ͷ��㡣
 * @param *L : ��������
 * @return Bool:true and false��
*/
Bool InitLinkList(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(SyLinkList)); /*�����ڴ�*/
    if((*L) == NULL)
    {
        return false;   /*�ڴ治��*/
    }
    (*L)->data = 0;
    int (*ptr)(int,int) = NULL;
    (*L)->next = NULL;     /*ͷ�ڵ���ʱָ��NULL*/
    return true;
}

/* 
 * @brief ����ͷ�巨��
 * @param *L   : ��������
 * @param date : ������
 * @param *ptr : ����ָ�롣
 * @return Bool:true and false��
*/
Bool InsertAtHeadLinkList(LinkList L,int date, int (*ptr)(int,int))
{
    LinkList NewNode,p;
    p = L;
    NewNode = (LinkList)malloc(sizeof(SyLinkList));
    if (NewNode == NULL)
    {       
        return false;
    }
    NewNode->ptr = ptr;
    NewNode->data = date;
    NewNode->next = p->next;
    p->next = NewNode;
    return true;
}


/* 
 * @brief ����β�巨��
 * @param *L   : ��������
 * @param date : ������
 * @param *ptr : ����ָ�롣
 * @return Bool:true and false��
*/
Bool InsertAtTailLinkList(LinkList L,int date,int (*ptr)(int,int))
{
    LinkList NewNode,p;

    NewNode = (LinkList)malloc(sizeof(SyLinkList));
    if(NewNode == NULL)
    {
        return false;
    }
    NewNode->ptr  = ptr;
    NewNode->data = date;
    NewNode->next = NULL;
    
    p = L;
    while (p->next != NULL)
    {
        p = L->next;
    }
    
    p->next = NewNode;
    return true;
}

/* 
 * @brief ָ��λ�� ������롣
 * @param *L   : ��������
 * @param i    : ����λ�á�
 * @param date : ������
 * @param *ptr : ����ָ�롣
 * @return Bool:true and false��
*/
Bool InsertLinkList(LinkList L,int i,int Date,int (*ptr)(int,int))
{
    int j = 1;
    LinkList p;

    p = L;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if( !p || j > i)return false;
    
    LinkList NewNode = (LinkList)malloc(sizeof(SyLinkList));
    NewNode->data = Date;
    NewNode->ptr = ptr;
    NewNode->next = p->next;
    p->next = NewNode;

    return true;
}

/* 
 * @brief ɾ����㡣
 * @param *L  : ��������
 * @param i   : ɾ�����λ�á�
 * @param *e  : ����������
 * @return Bool:true and false��
*/
Bool DeleteLinkList(LinkList L, int i,int *e)
{
    int j;
    LinkList p;

    p = L;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    
    if(!p || j > i) return false;

    LinkList s = p->next;
    *e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

/* 
 * @brief ��������ɾ����
 * @param *L   : ��������
 * @return Bool:true and false��
*/
Bool ClearLinkList(LinkList L)
{
    LinkList p,OldNode;
    p = L;
    while (p)
    {
        OldNode = p->next;
        free(p);
        p = OldNode;
    }

    L->next = NULL;

    return true;
}



/* 
 * @brief �����������С�
 * @param *L   : ��������
 * @return Bool:true and false��
*/
void PrintfLinkList(LinkList L)
{
    LinkList p = L->next;
    int i = 0;
    printf("open\r\n");
    while (p != NULL)
    {
        printf("List:%d ",i++);
        printf("Data:%d ",p->data);
        printf("ptr:%d \r\n",p->ptr(152,72));
        p = p->next;
    }
    printf("\r\n");
    return;
}



int addr_1(int x,int y)
{
    return x < y ? x : y;
}

int addr_2(int x,int y)
{
    return x > y ? x : y;
}

int addr_3(int x,int y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    int (*ptr1)(int,int) = &addr_1;
    int add1 = (*ptr1)(56,34);
    printf("\r\n %d \r\n",add1);
    int (*ptr2)(int,int) = &addr_2;
    int add2 = (*ptr2)(56,34);
    printf("\r\n %d \r\n",add2);
    int (*ptr3)(int,int) = &addr_3;
    int add3 = (*ptr3)(152,72);
    printf("\r\n %d \r\n",add3);

    int el;

    LinkList SL ;
    
    printf("Init List: %d\r\n",InitLinkList(&SL));
    printf("Head Inser List: %d\r\n",InsertAtHeadLinkList(SL,5,&addr_1));
    printf("Tail Inser List: %d\r\n",InsertAtTailLinkList(SL,6,&addr_2));
    printf("Link Inser List: %d\r\n",InsertLinkList(SL,2,4,&addr_3));
    PrintfLinkList(SL);
    printf("Delete List: %d\r\n",DeleteLinkList(SL,0,&el));
    printf("Delete Data: %d\r\n",el);
    PrintfLinkList(SL);
    ClearLinkList(SL);
    PrintfLinkList(SL);
    return 0;
}


