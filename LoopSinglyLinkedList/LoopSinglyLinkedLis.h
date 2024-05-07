#ifndef _LoopSingLinkedList_
#define _LoopSingLinkedList_

#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    false = 0,
    true,
}Bool;

typedef struct LoopSyLinkList
{
    int data;
    struct LoopSyLinkList * next;
}LoopSyLinkList;

LoopSyLinkList * InitlinkList(void);    /*��ʼ�� ����*/
Bool InsertAtHeadLinkList(LoopSyLinkList *L,int data);  /*���� ͷ�巨*/
Bool InsertAtTailLinkList(LoopSyLinkList *L,int data);  /*���� β�巨*/
Bool InsertLinkList(LoopSyLinkList *L,int i,int Date);  /*���� ָ������巨*/
Bool DeleteLinkList(LoopSyLinkList *L, int i);  /*���� ɾ��������*/
Bool ClearLinkList(LoopSyLinkList *L);  /*���� ����ɾ��*/
void PrintfLinkList(LoopSyLinkList *L); /*���� ����*/


#endif // !_LoopSingLinkedList_