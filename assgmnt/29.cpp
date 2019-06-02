/*
29. Design, develop and implement a program in C++ f or the f ollowing operations on Graph(G) of
Cities
    a. Create a Graph of N cities using Adjacency Matrix.
    b. Print all the nodes reachable f rom a given starting node in a digraph using BFS method
    c. Check whether a given graph is connected or not using DFS method.
*/

//c -> incomplete 

#include<bits/stdc++.h>
using namespace std;

int graph[10][10], i, j, k, n;
int queue[10], front, rear, stack[10], stackTop;
int city, visit[10], visited[10];

void BFS(int city, int n)
{
    cout << "\nBFS Traversal : " << city << " ";
    k = 1;
    while(k<n)
    {
        for(j=1; j<=n; j++)
            if(graph[city][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                ::queue[rear++]=j;
            }
        city=::queue[front++];
        cout<<city <<" ";
        k++;
        visit[city]=0;
        visited[city]=1;
    }
}

void DFS(int city, int n)
{
    cout << "\nDFS traversal : " << city << " ";
    k = 1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(graph[city][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                ::stack[stackTop]=j;
                stackTop++;
            }
        city=::stack[--stackTop];
        cout<<city << " ";
        k++;
        visit[city]=0;
        visited[city]=1;
    }
}

int main()
{
    int m;
    cout <<"Enter no. of cities : ";
    cin >> n;
    cout <<"Enter no. of roads connecting all cities : ";
    cin >> m;
    cout <<"\nEnter the roads between cities, e.g. 1 2 or 2 3 etc.\n";
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        graph[i][j]=1;
    }
    cout <<"Enter the starting city : ";
    cin >>city;
    visited[city] = 1;
    BFS(city, n);
    // To check if graph is connected or not
    //DFS(city, n);
    return 0;
}