#ifndef _SyLinkedList_
#define _SyLinkedList_

#include <stdio.h>
#include <stdlib.h>


typedef enum bool
{
    false = 0,
    true,
}Bool;

typedef int DataType;

/* SyLinkList, �ṹ�������������������еĽ������*/
/* LinkList ���ṹ��ָ��������������˵�������������͵ġ�����*/
/*����֪ʶ����Сϸ��
SyLinkList *p;  (p Ϊ���������ָ��(pָ����))
LinkList L; L ���һ����ĵ�����*/
typedef struct SinglyLinkedList
{
    int data;       //������
    int (*ptr)(int,int);// ����ָ��
    struct SinglyLinkedList *next;//ָ����
}SyLinkList, *LinkList;


Bool InitLinkList(LinkList *L); /*��ʼ�� ����*/
Bool InsertAtHeadLinkList(LinkList L,int date, int (*ptr)(int,int)); /*���� ͷ�巨*/
Bool InsertAtTailLinkList(LinkList L,int date,int (*ptr)(int,int));  /*���� β�巨*/
Bool InsertLinkList(LinkList L,int i,int Date,int (*ptr)(int,int));  /*���� ָ������巨*/
Bool DeleteLinkList(LinkList L, int i,int *e);  /*���� ɾ��������*/
Bool ClearLinkList(LinkList L);     /*���� ����ɾ��*/
void PrintfLinkList(LinkList L);    /*���� ����*/


#endif 

