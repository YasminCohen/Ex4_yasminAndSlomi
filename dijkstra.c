#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

p_dijkstra createDijkstra(p_node start, int src)
{
    p_dijkstra head = NULL;
    p_dijkstra *index = &head;
    while (start != NULL)
    {
        (*index) = (p_dijkstra)malloc(sizeof(dijkstra));
        if ((*index) == NULL)
        exit(1);

        (*index)->node = start;
        if (start->nodeId == src)
        {
            (*index)->weight = 0;
        }
        else
        {
            (*index)->weight = INFINITY;
        }
        (*index)->tag = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}

void deleteDijkstra(p_dijkstra dijkstra)
{
    while (dijkstra != NULL)
    {
        p_dijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

p_dijkstra getPointerDijkstra(p_dijkstra head, int id)
{
    while (head != NULL)
    {
        if (head->node->nodeId == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

p_dijkstra minVertical(p_dijkstra head)
{
    p_dijkstra ver = NULL;
    while (head != NULL)
    {
        if ((head->tag)!=1 && (ver == NULL || ver->weight < head->weight) && head->weight < INFINITY)
        {
            ver = head;
        }
        head = head->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
    return ver;
}

int shortestPath(p_node head, int src, int dest)
{
    p_dijkstra dijkstraHead = createDijkstra(head, src);

    p_dijkstra u = minVertical(dijkstraHead);
    while (u != NULL)
    {
        p_edge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
            // relax
            p_dijkstra v = getPointerDijkstra(dijkstraHead, edgeIndex->dest->nodeId);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minVertical(dijkstraHead);
    }
    int distance= -1;
    while (dijkstraHead != NULL)
    {
        if (dijkstraHead->node->nodeId == dest)
        {
            distance  =  dijkstraHead->weight;
        }
        dijkstraHead = dijkstraHead->next;
    }
    if (distance == INFINITY)
    {
        distance = -1;
    }
    deleteDijkstra(dijkstraHead);
    return distance;
}