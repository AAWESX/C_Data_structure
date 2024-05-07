#ifndef _SQLIST_
#define _SQLIST_

#include <stdio.h>

enum {
    ERROR = 0,
    OK = 1,
}ComStatus;

typedef int ElemType;

#define MAX_SIZE 10  //˳����С

typedef struct
{
    ElemType Data[MAX_SIZE];  //˳�������
    int length;               //˳�����
    int size;                 //˳����С
}SqList;

void InitSqList(SqList* L);                         //��ʼ��˳���
int CreatSqList(SqList* L ,ElemType arr[],int n);   //����˳���
int LenghtSqList(SqList *L);                        //����˳�����
int LocateSqList(SqList *L,ElemType Date);          //��ֵ����Ԫ��
int GetSqList(SqList *L ,int i ,ElemType *ptr);     //��λ����Ԫ��
int SearcMaxSqList(SqList *L);                      //��ѯ���ֵ
int SearcMinSqList(SqList *L);                      //��ѯ��Сֵ
int InsertSqList(SqList *L , int i , ElemType Date);//����Ԫ��
int DeleteSqList(SqList *L , int i,ElemType *ptr);  //ɾ��Ԫ��
void PrintfSqList(SqList *L);                       //��ӡ˳���Ԫ��

#endif 


