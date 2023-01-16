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
        if (temp->nodeId != id)
        {
            temp = temp->next;
        }
        else
        {
            return temp;
        }
    }
    return NULL;
}

/* add node in the graph and also its edges if we get them in input else add only the node */
void addNode(p_node *head, int src)
{

    int dest,weight;
    dest =-1;
    weight =-1;
    p_node temp;
    temp = getNode(src, head);
    while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
    {
        if (isalpha(dest) || isalpha(weight))
        {
            return;
        }
        addEdge(temp, dest, weight, head);
    }
}

void addNode_B(p_node *head)
{
    int src;
    scanf("%d", &src);
    int dest, weight;
    dest = -1;
    weight =-1;
    p_node temp;
    temp = getNode(src, head);
    if (temp != NULL)
    {
         if (temp->edges != NULL)
    {
        p_edge temp1 = temp->edges;

        while (temp1 != NULL)
        {
            p_edge p1 = NULL;
            p1 = temp1;
            temp1 = temp1->next;
            free(p1);
        }
    }

    else{ // if it was no edges
        free(temp->edges);
    }
        temp->edges = NULL;
        
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                return;
            }
            addEdge(temp, dest, weight, head);
        }
        
    }
    else
    {
        p_node inGraph = *head;
        while (inGraph->next != NULL)
        {
            inGraph = inGraph->next;
        }
        p_node newNode = (p_node)(malloc(sizeof(node)));
        if (newNode == NULL)
        exit(1);
        inGraph->next = newNode;
        newNode->nodeId = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        
        
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                return;
            }
            addEdge(newNode, dest, weight, head);
        }
    }
}

void deleteNode(p_node *head)
{
    int D = -1;
    if (scanf("%d", &D)!=EOF){
    deleteEdge(head, D);
    p_node tempNode = *head;
    node *p = NULL;
    if (tempNode->nodeId == D)
    {
        p = *head;
        *head = p->next;
    if (p->edges != NULL)
    {
        p_edge temp = p->edges;

        while (temp != NULL)
        {
            p_edge p1 = NULL;
            p1 = temp;
            temp = temp->next;
            free(p1);
        }
    }

    else{ // if it was no edges
        free(p->edges);
    }
        free(p); 
    }
    else
    {
     while (tempNode->next->nodeId != D)
        {
            tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next = tempNode->next->next;
        if (p->edges != NULL)
    {
        p_edge temp = p->edges;

        while (temp != NULL)
        {
            p_edge p1 = NULL;
            p1 = temp;
            temp = temp->next;
            free(p1);
        }
    }

    else{ // if it was no edges
        free(p->edges);
    }
        free(p);   
    }
    }
}
