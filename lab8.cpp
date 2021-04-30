#include <iostream>
#include<clocale>
#include<iomanip>
#include<vector>
#include <Windows.h>

using std::setw;
using namespace std;

void dijkstra(vector<vector<int>> graph, int start) {

    int distance[6], count, index, i, u, m = start + 1;
    bool visited[6];
    for (i = 0; i < 6; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[start] = 0;
    for (count = 0; count < 5; count++)
    {
        int min = INT_MAX;
        for (i = 0; i < 6; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i]; 
                index = i;
            }
        u = index;
        visited[u] = true;
        for (i = 0; i < 6; i++)
            if (!visited[i] && graph[u][i] && distance[u] != INT_MAX &&
                distance[u] + graph[u][i] < distance[i])
                distance[i] = distance[u] + graph[u][i];
    }
    cout << "Довжини шляхів з одної вершини до інших:\t\n";
    for (i = 0; i < 6; i++) if (distance[i] != INT_MAX)
        cout << m << " > " << i + 1 << " = " << distance[i] << endl;
    else cout << m << " > " << i + 1 << " = " << "Маршрут відсутній" << endl;       
}

void floyd(vector<vector<int>> graph) {
	for (int k = 0; k < 6; k++)
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (graph[i][k] != 0 && graph[k][j] != 0 && i != j)
					if (graph[i][k] + graph[k][j] < graph[i][j] || graph[i][j] == 0)
						graph[i][j] = graph[i][k] + graph[k][j];
	
	cout << "\n a  b  c  d  f  g" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			i == j ? cout << " 0 " : graph[i][j] == 0 ? cout << " - " : cout << setw(2) << graph[i][j] << " ";
		cout << endl;
	}
}

int main() {   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   
    vector<vector<int>> graph = {
        {0, 5, 3, 0, 0, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 2, 5},
        {0, 0, 0, 0, 7, 2},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "Алгоритм Дейкстри:" << endl;
    dijkstra(graph, 0);

    cout << endl << "Алгоритм Флойда Уоршела:" << endl;
    floyd(graph);

    return 0;
}
