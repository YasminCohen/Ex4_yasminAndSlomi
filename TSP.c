#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void swap(int *i, int *j){
    int temp=*i;
     *i =*j;
    *j=temp;
}

void TSP(p_node head)
{
	int arrlen = -1;
    scanf("%d", &arrlen);
    
    p_node graph = head;

    int *arr = (int *)malloc(arrlen*sizeof(int));
    for (int i = 0; i < arrlen; i++)
    {
        scanf("%d", arr+i);
    }
    

    int j, i;
    int best_path, current_path;
    int existsPath, pathFound; 
    pathFound = 0;
    best_path = 999999;

    for(j=1; j <= arrlen; j++){

        for(i=0; i < arrlen-1; i++){

         swap(arr+i, arr+i+1);
              
            current_path = 0;
            existsPath = 1;
            for(int node = 0; node < arrlen-1;  node++){
                int dijk = shortestPath(graph, *(arr+node), *(arr+(node+1)));
                if (dijk == -1){
                    existsPath = 0;
                }
                    current_path += dijk;
            }

            if (existsPath && (current_path < best_path)){
                best_path = current_path;
                pathFound = 1;
            }
        }
    }
    if(!pathFound){
        best_path = -1;
    }  

    printf("TSP shortest path: %d \n",best_path);

    free(arr);
}
