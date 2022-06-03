#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph_Algo
{
    public:
    vector <vector <int>> adjList;
    vector <vector<pair<int,int>>> W_adjList;

    Graph_Algo(int n)
    {
        adjList.resize(n+1);
        for(int i = 0; i < adjList.size(); i++)
           adjList[i].push_back(-1);               
    }
    Graph_Algo(int n, int w)
    {
        W_adjList.resize(n+1);

        for(int i = 0; i < W_adjList.size(); i++)
           W_adjList[i].push_back(make_pair(-1,0));
    }
    int Menu()
    {
       int ch = -1;
       cout << "0. INPUT FOR WEIGHTED GRAPH.\n";
       cout << "1. INPUT AN EDGE.\n";
       cout << "2. DELETE AN EDGE.\n";
       cout << "3. BFS\n";
       cout << "4. DFS\n";
       cout << "5. PRINT GRAPH\n";
       cout << "6. END\n";

       cout << "ENTER YOUR CHOICE :\n";

       cin >> ch;
       return ch;
    }
    void createGraph()
    {
        int ch;
       do
       {
        ch = Menu();

         switch(ch)
         {
             case 0:
                int p1,p2,w;
                cout << "INPUT THE VERTICES AND THE WEIGHT FOR THE EDGE :\n";
                cin >> p1 >> p2 >> w;
                W_addEdge(p1,p2,w);
                break;
             case 1:
                 cout << "INPUT THE VERTICES FOR THE EDGE :\n";
                 cin >> p1 >> p2;
                addEdge(p1,p2);
                break;
             case 2:
                cout << "INPUT THE VERTICES TO REMOVE THE EDGE FROM :\n";
                cin >> p1 >> p2;
                removeEdge(p1, p2);
                break;
            case 3:
                BFS(1);
                break;
            case 4:
                DFS(1);
                break;
            case 5:
                printGraph();
                break;
            case 6:
                cout << "TERMINATION IN PROGRESS......\n";
                break;
            default:
                cout << "ENTER VALID CHOICE.";
         }
       } while (ch != 6);
    cout << "TERMINATED ^_^\n ";
    }
    void addEdge(int p1, int p2)
    {
        if(adjList[p1][0] == -1)
        adjList[p1].pop_back();
        if(adjList[p2][0] == -1)
        adjList[p2].pop_back();

        adjList[p1].push_back(p2);
        adjList[p2].push_back(p1);
    }
    void removeEdge(int p1, int p2)
    {
        auto it1 = find(adjList[p1].begin(), adjList[p1].end(), p2);
        auto it2 = find(adjList[p2].begin(), adjList[p2].end(), p1);

        adjList[p1].erase(it1);
        adjList[p2].erase(it2);
    }
    void BFS(int start)
    {
        queue <int> que;
        vector <bool> visited(adjList.size());

        int currV;
        que.push(start);
        visited[start] = true;

        while(!que.empty())
        {
            currV = que.front();
            que.pop();
            cout << currV << " ";
            for( auto i : adjList[currV])
                if(!visited[i])
                {
                    que.push(i);
                    visited[i] = true;
                }
        }

    }
    void DFS(int start)
    {
         stack <int> stk;
         vector <bool> visited(adjList.size());
         
         stk.push(start);

         while(!stk.empty())
         {
             int currV = stk.top();
             stk.pop();

             if(!visited[currV])
             {
                 visited[currV] = true;
                 cout << currV << " ";
             }

             for(auto trav : adjList[currV])
             {
                 if(!visited[trav])
                    stk.push(trav);
             }
         }
    }
    
    void printGraph()
    {
        int c = 0;
    for(auto i : adjList)
    {
        for(auto j : i)
        if(j != -1)
           cout << c << "   ---   " << j << endl;
        c++;
    }
    }

    void printW_Graph()
    {
        int c = 0;
        for(auto i : W_adjList)
            {
                for(auto j : i)
                   if(j.first != -1)
                     cout << c << "  --[" <<  j.second << "]--  " << j.first << endl;
               c++;  
            }
    }

    void W_addEdge(int p1, int p2, int w)
    {
       if(W_adjList[p1][0].first == -1)
         W_adjList[p1].pop_back();
       if(W_adjList[p2][0].first == -1)
         W_adjList[p2].pop_back();

       W_adjList[p1].push_back(make_pair(p2,w));
       W_adjList[p2].push_back(make_pair(p1,w));

    }
};
int main()
{
    int n;
     cout << "ENTER THE NUMBER OF VERTICES : \n";
     cin >> n;
    //Graph_Algo g1(n);
    Graph_Algo g2(n, 0);
    g2.createGraph();
    g2.printW_Graph();
}