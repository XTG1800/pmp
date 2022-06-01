#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * initList()
{
    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));
    pHead->next = NULL;
    return pHead;
}

struct Node * createNode(int data)
{
    struct Node *pNewNode = (struct Node *)malloc(sizeof(struct Node));
    pNewNode->data = data;
    pNewNode->next = NULL;
    return pNewNode;
}

void insertNodeFromHead(struct Node *pList, int data)
{
    struct Node *pNewNode = createNode(data);
    pNewNode->next = pList->next;
    pList->next = pNewNode;
}

void insertNodeFromEnd(struct Node *pList, int data)
{
    struct Node *pNewNode = createNode(data);
    while(pList->next)
    {
        pList = pList->next;
    }
    pList->next = pNewNode;
    pNewNode->next = NULL;
}

void deleteNode(struct Node *pList, int data)
{
    struct Node * pNodePre = pList;
    struct Node * pNode = pList->next;
    if(NULL == pNode)
    {
        printf("Null list.");
        return;
    }
    else
    {
        while(data != pNode->data)
        {
            pNodePre = pNode;
            pNode = pNode->next;
            if(NULL == pNode)
            {
                printf("There is no node to delete.");
                return;
            }
        }
        pNodePre->next = pNode->next;
        free(pNode);
    }
}

void printList(struct Node *pHead)
{
    struct Node *pNode = pHead->next;
    if(NULL == pNode)
    {
        printf("This list is null.\n");
        return;
    }
    while(pNode)
    {
        printf("%d ",pNode->data);
        pNode=pNode->next;
    }
    printf("\n");
}

int main()
{
    struct Node *pList = initList();
    printList(pList);
    for(int i=0;i<10;i++)
    {
        insertNodeFromHead(pList, i);
        //insertNodeFromEnd(pList, i);
    }
    printList(pList);
    deleteNode(pList,5);
    printList(pList);
    return 0;
}
