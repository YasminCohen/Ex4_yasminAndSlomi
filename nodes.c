#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

/* returns node in the graph with given id */
p_node getNode(int id, p_node *head)
{
    p_node temp = *head;

    while (temp != NULL)
    {
        if (temp->nodeId == id)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

/* add node in the graph and also its edges if we get them in input else add only the node */
void addNode(p_node *head, int src)
{

    int dest;
    int weight;
    p_node temp = getNode(src, head);
    while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
    {
        if (isalpha(dest) || isalpha(weight))
        {
            break;
        }
        addEdge(temp, dest, weight, head);
    }
}

void addNode_B(p_node *head)
{
    int src;
    scanf("%d", &src);
    int dest;
    int weight;
    p_node temp = getNode(src, head);
    if (temp == NULL)
    {
        p_node inGraph = *head;
        while (inGraph->next != NULL)
        {
            inGraph = inGraph->next;
        }
        p_node newNode = (p_node)(malloc(sizeof(node)));
        if (newNode == NULL)
        {
            perror("there is no enough space to add node, sorry\n");
            exit(0);
        }
        newNode->nodeId = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        inGraph->next = newNode;
        
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            addEdge(newNode, dest, weight, head);
        }
    }
    else
    {
        freeEdges(temp);
        temp->edges = NULL;
        
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            addEdge(temp, dest, weight, head);
        }
    }
}

void deleteNode(p_node *head)
{
    int D = 0;
    scanf("%d", &D);
    deleteEdge(head, D);
    p_node tempNode = *head;
    node *p = NULL;
    if (tempNode->nodeId != D)
    {
        while (tempNode->next->nodeId != D)
        {
            tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next = tempNode->next->next;
        freeEdges(p);
        free(p);
    }
    else
    {
        p = *head;
        *head = p->next;
        freeEdges(p);
        free(p);
    }
}
