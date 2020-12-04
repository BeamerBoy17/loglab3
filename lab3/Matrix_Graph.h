#pragma once
#include "stdlib.h"
#include "stdio.h"

typedef struct Graph 
{
    int** matrix;
    int size;
}Graph;

int** matrix(int size);
void generate_matrix(Graph* graph);

Graph* init_graph(int size);
void free_graph(Graph* graph);
void print_graph(Graph* graph);

