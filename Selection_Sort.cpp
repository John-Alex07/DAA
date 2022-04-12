#include <iostream>
#include <vector>

using namespace std;


vector <int> Selection_Sort(vector <int> arr, int n)
{
     for(int i = 0; i < n; i++)
    {
        int s = arr[i];
        int p = i;
         
        for(int j  = i+1; j < n; j++)
              if( s > arr[j])
              {
                 s = arr[j];
                 p = j;
              }
        arr[p] = arr[i];
        arr[i] = s;
    }
    return arr;
}
int main()
{
    vector <int> arr;
    
    int n;
    cout << "ENTER THE NUMBER OF INPUTS :\n";
    cin >> n;
    
    cout << "ENTER THE NUMBERS :\n";
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    arr = Selection_Sort(arr, n);
    
    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";
}