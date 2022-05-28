#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int src;
    int dest;
}Node;
void init(vector<vector<int>> &adjList, int n)
{
    adjList.resize(n+1);
     for(int i = 0; i <adjList.size(); i++)
     adjList[i].push_back(-1);
}
void addEdge(vector <vector <int>> &adjList, Node &edge)
{
    if(adjList[edge.src][0] == -1) 
       adjList[edge.src].pop_back();
   if(adjList[edge.dest][0] == -1)
       adjList[edge.dest].pop_back();

   adjList[edge.src].push_back(edge.dest);
   adjList[edge.dest].push_back(edge.src);
}
void printGraph(vector <vector <int>> adjList)
{
    int c = 0;
    for(auto i : adjList)
    {
        for(auto j : i)
           cout << c << "  ---  " << j << endl;
        c++;
    }
}
void input(vector <vector<int>> &adjList, Node edge)
{
    int ch = -1;
    do
    {
    cout << "1. Input an Edge.\n";
    cout << "2. Remove an Edge. \n";
    cout << "3. END.\n";
    cout << "Enter Your Choice :\n";
    cin >> ch;
    switch(ch)
    {
        case 1:
        cout << "Enter the Vertices for the edge : \n";
        cin >> edge.src >> edge.dest;
        addEdge(adjList, edge);
        break;

        case 2:
        break;

        case 3:
        cout << "EXITING........\n";
        break;

        default:
        cout << "Enter a valid choice!!!\n";
    }
    }while(ch !=3); 
}

void BFS(vector <vector <int>> adjList, int start, int n)
{
     vector <bool> visited(n+1);
     queue <int> trav;

     trav.push(start);
     visited[start] = true;

     while(!trav.empty())
     {
         int currV = trav.front();
         trav.pop();
         cout << currV << " ";
         for(auto adj : adjList[currV])
         {
             if(!visited[adj])
             {
                 visited[adj] = true;
                 trav.push(adj);
             }
         }
     }
}
void DFS( vector <vector <int>> adjList, int start, int n)
{
        vector <bool> visited(n+1);
        vector <int> trav;

        trav.push_back(start);

        
        while(!trav.empty())
        {
           int currV = trav.back();
           trav.pop_back();

           if(!visited[currV])
           {
              cout << currV << " ";
              visited[currV] = true;
           }
           for(auto tra : adjList[currV])
           {
              if(!visited[tra])
                  trav.push_back(tra);
           }
        }
}
int main()
{
    int n;
    vector <vector <int>> adjList;
    cout << "Enter the number of vertices :\n";
    cin >> n;
    Node edge;

    init(adjList, n);
    printGraph(adjList);
    input(adjList, edge);
    printGraph(adjList);

    int strt;
    cout << "ENTER THE START NODE : ";
    cin >> strt;
    cout << "DFS : \n";
    DFS(adjList, strt, n);
    cout << "\n\n";
    cout << "BFS : \n";
    if(strt <= n+1)
    BFS(adjList, strt, n);
    else
    cout << "NODE DOESNT EXIST..... TERMINATING PROGRAM......";
}