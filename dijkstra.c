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



int shortestPath(p_node head, int src, int dest)
{
    p_dijkstra dijkstraHead = createDijkstra(head, src);
    p_dijkstra ver = NULL;
    while (dijkstraHead != NULL)
    {
        if (!dijkstraHead->tag && dijkstraHead->weight < INFINITY && (ver == NULL || ver->weight < dijkstraHead->weight))
        {
            ver = dijkstraHead;
        }
        dijkstraHead = dijkstraHead->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
    p_dijkstra u = ver;
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
          p_dijkstra ver = NULL;
    while (dijkstraHead != NULL)
    {
        if (!dijkstraHead->tag && dijkstraHead->weight < INFINITY && (ver == NULL || ver->weight < dijkstraHead->weight))
        {
            ver = dijkstraHead;
        }
        dijkstraHead = dijkstraHead->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
        u = ver;
    }
    int distance = getPointerDijkstra(dijkstraHead, dest)->weight;
    if (distance == INFINITY)
    {
        distance = -1;
    }
    deleteDijkstra(dijkstraHead);
    return distance;
}