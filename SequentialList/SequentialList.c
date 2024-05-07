#include "SequentialList.h"

/*
 * @brief 初始化顺序表。
 * @param *L : 顺序表句柄。
 * @return NULL
 */
void InitSqList(SqList* L)
{
    L->length = 0;
    L->size   = MAX_SIZE;
}

/*
 * @brief 创建顺序表。
 * @param *L  : 顺序表句柄。
 * @param arr : 传入顺序表数据。
 * @param n   : 传入顺序表数据长度。
 * @return NULL
 */
int CreatSqList(SqList* L ,ElemType arr[],int n)
{
    if(n > L->size) return ERROR;
    if(n < 0)       return ERROR;
    for (int i = 0; i < n; i++)
    {
        L->Data[i] = arr[i];
    }

    L->length = n;

    return OK;

}

/*
 * @brief 计算顺序表的数据长度
 * @param *L : 顺序表句柄
 * @return 顺序表长度
*/
int LenghtSqList(SqList *L)
{
    return L->length;
}

/*
 * @brief 按值查找
 * @param *L   : 顺序表句柄
 * @param Date : 查询元素
 * @return 查询成功返回元素序号 失败 ERROR
*/
int LocateSqList(SqList *L,ElemType Date)
{
    for (int i = 0; i < L->length; i++)
    {
        if(L->Data[i] == Date)return i + 1;
    }
    
    return ERROR;
    
}
/*
 * @brief 按位查找
 * @param *L   : 顺序表句柄。
 * @param i    : 顺序表数据下标位。
 * @param *ptr : 指针参数ptr返回查找到的元素值。
 * @return 失败 ERROR 成功 OK。
*/
int GetSqList(SqList *L ,int i ,ElemType *ptr)
{
    if(i > L->size || i < 0) 
        return ERROR;
    else
    {
        *ptr = L->Data[i];
        return OK;
    }

}

/*
 * @brief 查询最大值
 * @param *L : 顺序表句柄。
 * @return 最大值下标 失败 ERROR
 */
int SearcMaxSqList(SqList *L)
{
    if(L->length == 0)return ERROR;
    int Max = L->Data[0] , MaxSum;
    for (int i = 1; i < L->length; i++)
    {
        if(L->Data[i] > Max)
        {
            Max = L->Data[i];
            MaxSum = i;
        }
    }
    
    return MaxSum;
}


/*
 * @brief 查询最小值
 * @param *L : 顺序表句柄。
 * @return 最小值下标 失败 ERROR
 */
int SearcMinSqList(SqList *L)
{
    if(L->length == 0)return ERROR;
    int Min = L->Data[0] , MinSum;
    for (int i = 1; i < L->length; i++)
    {
        if(L->Data[i] < Min)
        {
            Min = L->Data[i];
            MinSum = i;
        }
    }
    
    return MinSum;

}


/*
 * @brief 插入元素
 * @param *L   : 顺序表句柄。
 * @param i    : 插入元素的序号。
 * @param Date : 插入的元素值。
 * @return 失败 ERROR 成功 OK。
*/
int InsertSqList(SqList *L , int i , ElemType Date)
{
    if(i < 0 || i > L->length || L->length >= L->size) return ERROR;
    for (int j = L->length ; j > i; j--)
    {
        L->Data[j] = L->Data[j - 1];
    }
    L->Data[i - 1] = Date;
    L->length++;
    return OK;
}

/*
 * @brief 删除元素
 * @param *L   : 顺序表句柄。
 * @param i    : 删除元素的序号。
 * @param *ptr : 删除的元素值。
 * @return 失败 ERROR 成功 OK。
*/
int DeleteSqList(SqList *L , int i,ElemType *ptr)
{
    if(i < 0 || i > L->length || L->length == 0) return ERROR;

    *ptr = L->Data[i - 1];

    for (int j = i; j < L->length; j++)
    {
        L->Data[j - 1] = L->Data[j];
    }
    L->length--;
    return OK;
}

/*
 * @brief 打印顺序表数据。
 * @param *L : 顺序表句柄。
 * @return NULL
 */
void PrintfSqList(SqList *L)
{
    printf("Run\r\n");
    for (int i = 0; i < L->length; i++)
    {
        printf(" %4d",L->Data[i]);
    }
    printf("\r\nStop");
}


int main(int argc, char const *argv[])
{
    SqList List;
    SqList *Sq;
    ElemType ptr;
    
    Sq = &List;

    ElemType arr[6] = {455,987,1,86,5,6};

    InitSqList(Sq);
    CreatSqList(Sq,arr, 6 );
    PrintfSqList(Sq);
    InsertSqList(Sq,5,(ElemType)999);
    PrintfSqList(Sq);
    DeleteSqList(Sq,5,&ptr);
    PrintfSqList(Sq);
    int Max = SearcMaxSqList(Sq);
    int Min = SearcMinSqList(Sq);
    printf("\r\nMin: %d,MinValue: %d",Min,Sq->Data[Min]);
    printf("\r\nMax: %d,MaxValue: %d",Max,Sq->Data[Max]);
    printf("\r\nD: %d",ptr);
    GetSqList(Sq,2,&ptr);


    printf("\r\n %d",ptr);

    printf("\r\n %d",LenghtSqList(Sq));
    printf("\r\n %d",LocateSqList(Sq, 6));


    return 0;
}


