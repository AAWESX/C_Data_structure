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

LoopSyLinkList * InitlinkList(void);    /*初始化 链表*/
Bool InsertAtHeadLinkList(LoopSyLinkList *L,int data);  /*链表 头插法*/
Bool InsertAtTailLinkList(LoopSyLinkList *L,int data);  /*链表 尾插法*/
Bool InsertLinkList(LoopSyLinkList *L,int i,int Date);  /*链表 指定插入插法*/
Bool DeleteLinkList(LoopSyLinkList *L, int i);  /*链表 删除链表结点*/
Bool ClearLinkList(LoopSyLinkList *L);  /*链表 整表删除*/
void PrintfLinkList(LoopSyLinkList *L); /*链表 运行*/


#endif // !_LoopSingLinkedList_