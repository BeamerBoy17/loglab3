#include "operations.h"

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

Graph* cross(Graph* graph1, Graph* graph2) {
	int max_size = max(graph1->size, graph2->size);
	int min_size = min(graph1->size, graph2->size);

	Graph* graph_max;
	(max_size == graph1->size ? graph_max = graph1 : graph_max = graph2);

	Graph* graph_res = init_graph(max_size);
	for (int i = 0; i < min_size; i++) {
		for (int j = 0; j < min_size; j++) {
			graph_res->matrix[i][j] = graph1->matrix[i][j] & graph2->matrix[i][j];
		}
	}

	if (max_size != min_size) {
		for (int i = min_size; i < max_size; i++) {
			for (int j = 0; j < max_size; j++) {
				graph_res->matrix[i][j] = graph_res->matrix[j][i] = graph_max->matrix[i][j];
			}
		}
	}

	return graph_res;
}

Graph* unionn(Graph* graph1, Graph* graph2) {
	int max_size = max(graph1->size, graph2->size);
	int min_size = min(graph1->size, graph2->size);

	Graph* graph_max;
	(max_size == graph1->size ? graph_max = graph1 : graph_max = graph2);

	Graph* graph_res = init_graph(max_size);
	for (int i = 0; i < min_size; i++) {
		for (int j = 0; j < min_size; j++) {
			graph_res->matrix[i][j] = graph1->matrix[i][j] | graph2->matrix[i][j];
		}
	}

	if (max_size != min_size) {
		for (int i = min_size; i < max_size; i++) {
			for (int j = 0; j < max_size; j++) {
				graph_res->matrix[i][j] = graph_res->matrix[j][i] = graph_max->matrix[i][j];
			}
		}
	}

	return graph_res;
}

int otojd(Graph* graph, unsigned int point_1, unsigned int point_2) {
	if (point_1 < graph->size && point_2 < graph->size) {
		for (int i = 0; i < graph->size; i++) {
			if (graph->matrix[point_1][i] == 1 || graph->matrix[point_2][i] == 1) {
				graph->matrix[point_1][i] = 1;
				graph->matrix[i][point_1] = 1;
			}

		}
		for (int i = point_2; i < graph->size - 1; i++) {
			for (int j = 0; j < graph->size; j++) {
				graph->matrix[i][j] = graph->matrix[i + 1][j];
			}

		}
		for (int i = point_2; i < graph->size - 1; i++) {
			for (int j = 0; j < graph->size; j++) {
				graph->matrix[j][i] = graph->matrix[j][i + 1];
			}
		}
		printf(" (в результирующей матрице номера вершин начинна€ с %d-ой уменьшаютс€ на единицу)\n", point_2 + 2);

		graph->size--;
		return graph->size;
	}

}

int stag(Graph* graph, unsigned int point_1, unsigned int point_2) {
	if (graph->matrix[point_1][point_2] == 0) {
		printf("\n ¬ершины не ицедентны.\n");
		return graph->size;
	}
	else {return otojd(graph, point_1, point_2);}
}

Graph* rasshep(Graph* graph, unsigned int v) {
	if (v < graph->size){
		Graph* new_graph = init_graph(graph->size + 1);

		for (int i = 0; i < graph->size; i++) {
			for (int j = 0; j < graph->size; j++) {
				new_graph->matrix[i][j] = graph->matrix[i][j];
			}
		}

		for (int i = 0; i < graph->size; i++) {
			new_graph->matrix[graph->size][i] = new_graph->matrix[i][graph->size] = graph->matrix[v][i];
		}
		new_graph->matrix[graph->size][graph->size] = 0;
		
		return new_graph;

	}
	return NULL;
}

Graph* circle_sum(Graph* graph1, Graph* graph2) {
	int max_size = max(graph1->size, graph2->size);
	int min_size = min(graph1->size, graph2->size);

	Graph* graph_max;
	(max_size == graph1->size ? graph_max = graph1 : graph_max = graph2);

	Graph* graph_res = init_graph(max_size);
	for (int i = 0; i < min_size; i++) {
		for (int j = 0; j < min_size; j++) {
			graph_res->matrix[i][j] = graph1->matrix[i][j] ^ graph2->matrix[i][j];
		}
	}

	if (max_size != min_size) {
		for (int i = min_size; i < max_size; i++) {
			for (int j = 0; j < max_size; j++) {
				graph_res->matrix[i][j] = graph_res->matrix[j][i] = graph_max->matrix[i][j];
			}
		}
	}

	return graph_res;
}