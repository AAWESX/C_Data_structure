#include "SequentialList.h"

/*
 * @brief ��ʼ��˳���
 * @param *L : ˳�������
 * @return NULL
 */
void InitSqList(SqList* L)
{
    L->length = 0;
    L->size   = MAX_SIZE;
}

/*
 * @brief ����˳���
 * @param *L  : ˳�������
 * @param arr : ����˳������ݡ�
 * @param n   : ����˳������ݳ��ȡ�
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
 * @brief ����˳�������ݳ���
 * @param *L : ˳�����
 * @return ˳�����
*/
int LenghtSqList(SqList *L)
{
    return L->length;
}

/*
 * @brief ��ֵ����
 * @param *L   : ˳�����
 * @param Date : ��ѯԪ��
 * @return ��ѯ�ɹ�����Ԫ����� ʧ�� ERROR
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
 * @brief ��λ����
 * @param *L   : ˳�������
 * @param i    : ˳��������±�λ��
 * @param *ptr : ָ�����ptr���ز��ҵ���Ԫ��ֵ��
 * @return ʧ�� ERROR �ɹ� OK��
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
 * @brief ��ѯ���ֵ
 * @param *L : ˳�������
 * @return ���ֵ�±� ʧ�� ERROR
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
 * @brief ��ѯ��Сֵ
 * @param *L : ˳�������
 * @return ��Сֵ�±� ʧ�� ERROR
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
 * @brief ����Ԫ��
 * @param *L   : ˳�������
 * @param i    : ����Ԫ�ص���š�
 * @param Date : �����Ԫ��ֵ��
 * @return ʧ�� ERROR �ɹ� OK��
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
 * @brief ɾ��Ԫ��
 * @param *L   : ˳�������
 * @param i    : ɾ��Ԫ�ص���š�
 * @param *ptr : ɾ����Ԫ��ֵ��
 * @return ʧ�� ERROR �ɹ� OK��
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
 * @brief ��ӡ˳������ݡ�
 * @param *L : ˳�������
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


