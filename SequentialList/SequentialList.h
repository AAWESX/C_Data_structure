#ifndef _SQLIST_
#define _SQLIST_

#include <stdio.h>

enum {
    ERROR = 0,
    OK = 1,
}ComStatus;

typedef int ElemType;

#define MAX_SIZE 10  //顺序表大小

typedef struct
{
    ElemType Data[MAX_SIZE];  //顺序表数据
    int length;               //顺序表长度
    int size;                 //顺序表大小
}SqList;

void InitSqList(SqList* L);                         //初始化顺序表
int CreatSqList(SqList* L ,ElemType arr[],int n);   //创建顺序表
int LenghtSqList(SqList *L);                        //计算顺序表长度
int LocateSqList(SqList *L,ElemType Date);          //按值查找元素
int GetSqList(SqList *L ,int i ,ElemType *ptr);     //按位查找元素
int SearcMaxSqList(SqList *L);                      //查询最大值
int SearcMinSqList(SqList *L);                      //查询最小值
int InsertSqList(SqList *L , int i , ElemType Date);//插入元素
int DeleteSqList(SqList *L , int i,ElemType *ptr);  //删除元素
void PrintfSqList(SqList *L);                       //打印顺序表元素

#endif 


