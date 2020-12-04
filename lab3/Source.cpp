#include "time.h"
#include "windows.h"
#include "operations.h"

int main()
{
	int count = 6, count_m1 = 6;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Graph* graph1 = init_graph(count);
	Graph* graph2 = init_graph(count);


	generate_matrix(graph1);
	generate_matrix(graph2);
	printf(" ���� G1:\n\n");
	print_graph(graph1);
	printf("\n ���� G2:\n\n");
	print_graph(graph2);

	////////
	Graph* next_graph = NULL;
	printf("\n �������� ���� ��� ���������� �������� (1 ��� 2)");
	char graph_selector = _getch();

	if (graph_selector=='1'){
		next_graph = graph1;}
	else {
		next_graph = graph2;}


	Graph* buffer;
	//A
	int vertex;
	printf("\n ������� ����� �������, ������� �� ������ ���������: ");
	scanf("%d", &vertex);
	vertex--;

	buffer = next_graph;
	next_graph = rasshep(next_graph, vertex);
	free_graph(buffer);
	printf("\n ��������� ����������� �������:\n\n");
	print_graph(next_graph);


	int point_1, point_2;
	printf("\n ������� ������ ������, ������� �� ������ �� ������������ (� ������� �����������) : ");
	scanf("%d%d", &point_1, &point_2);
	point_1--;
	point_2--;

	otojd(next_graph, point_1, point_2);
	printf("\n ���� 1 ����� �������� ��������������:\n\n");
	print_graph(next_graph);
	//A

	//B
	printf("\n ������� ������ ������, ����� ����� �������� �� ������ �� ������� (� ������� �����������) : ");
	scanf("%d%d", &point_1, &point_2);
	point_1--;
	point_2--;

	stag(next_graph, point_1, point_2);
	printf("\n ��������� ���������� ������:\n\n");
	print_graph(next_graph);
	//B


	if (graph_selector == '1') {
		graph1 = next_graph;
	}
	else {
		graph2 = next_graph;
	}

	//A2
	_getch();
	printf("\n ��������� ����� �������� ����������� Mass1 � Mass2:\n\n");
	Graph* graph3 = unionn(graph1, graph2);
	print_graph(graph3);
	//A2

	//B2
	_getch();
	printf("\n ��������� ����� �������� ����������� Mass1 � Mass2:\n\n");
	graph3 = cross(graph1, graph2);
	print_graph(graph3);
	//B2


	//C3
	_getch();
	printf("\n ��������� ����� �������� ���������� ����� Mass1 � Mass2:\n\n");
	graph3 = circle_sum(graph1, graph2);
	print_graph(graph3);
	//C3
	_getch();
}