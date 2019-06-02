/*
19. Write C++ programs f or implementing the f ollowing graph traversal algorithms:
    a. Depth f irst traversal
    b. Breadth f irst traversal
*/

#include<bits/stdc++.h>
using namespace std;

int graph[10][10], i, j, k, n;
int queue[10], front, rear, stack[10], stackTop;
int vertex, visit[10], visited[10];

void BFS(int vertex, int n)
{
    cout << "\nBFS Traversal : " << vertex << " ";
    k = 1;
    while(k<n)
    {
        for(j=1; j<=n; j++)
            if(graph[vertex][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                ::queue[rear++]=j;
            }
        vertex=::queue[front++];
        cout<<vertex <<" ";
        k++;
        visit[vertex]=0;
        visited[vertex]=1;
    }
}

void DFS(int vertex, int n)
{
    cout << "\nDFS traversal : " << vertex << " ";
    k = 1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(graph[vertex][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                ::stack[stackTop]=j;
                stackTop++;
            }
        vertex=::stack[--stackTop];
        cout<<vertex << " ";
        k++;
        visit[vertex]=0;
        visited[vertex]=1;
    }
}

int main()
{
    int m;
    cout <<"Enter no. of vertices : ";
    cin >> n;
    cout <<"Enter no. of edges : ";
    cin >> m;
    cout <<"\nEnter the edges between these vertices, e.g. 1 2 or 2 3 etc.\n";
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        graph[i][j]=1;
    }
    cout <<"Enter initial vertex to traverse from : ";
    cin >>vertex;
    visited[vertex]=1;
    cout << "1. BFS Traversal\n2. DFS Traversal\nSelect one : ";
    cin >> m;
    if(m == 1)
        BFS(vertex, n);
    else if(m == 2)
        DFS(vertex, n);
    else
        cout << "Wrong input";
    return 0;
}