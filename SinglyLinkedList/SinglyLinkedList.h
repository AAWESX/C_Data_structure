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

/* SyLinkList, 结构体类型名，描述链表中的结点类型*/
/* LinkList ，结构体指针类型名，用来说明“单链表类型的”变量*/
/*基础知识：：小细节
SyLinkList *p;  (p 为单链表结点的指针(p指向结点))
LinkList L; L 标记一具体的单链表。*/
typedef struct SinglyLinkedList
{
    int data;       //数据域
    int (*ptr)(int,int);// 函数指针
    struct SinglyLinkedList *next;//指针域
}SyLinkList, *LinkList;


Bool InitLinkList(LinkList *L); /*初始化 链表*/
Bool InsertAtHeadLinkList(LinkList L,int date, int (*ptr)(int,int)); /*链表 头插法*/
Bool InsertAtTailLinkList(LinkList L,int date,int (*ptr)(int,int));  /*链表 尾插法*/
Bool InsertLinkList(LinkList L,int i,int Date,int (*ptr)(int,int));  /*链表 指定插入插法*/
Bool DeleteLinkList(LinkList L, int i,int *e);  /*链表 删除链表结点*/
Bool ClearLinkList(LinkList L);     /*链表 整表删除*/
void PrintfLinkList(LinkList L);    /*链表 运行*/


#endif 

