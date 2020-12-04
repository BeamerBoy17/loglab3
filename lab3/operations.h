#pragma once
#include "conio.h"
#include "Matrix_Graph.h"
#pragma warning (disable : 4996)

Graph* cross(Graph* graph1, Graph* graph2);
Graph* unionn(Graph* graph1, Graph* graph2);
int otojd(Graph* graph, unsigned int point_1, unsigned int point_2);
int stag(Graph* graph, unsigned int point_1, unsigned int point_2);
Graph* rasshep(Graph* graph, unsigned int v);
Graph* circle_sum(Graph* graph1, Graph* graph2);