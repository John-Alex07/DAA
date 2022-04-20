#include <iostream>
#include <vector>

using namespace std;

vector <int> Insertion_Sort(vector <int> arr, int n)
{
    /*for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        int p = i+1;

        while( p > 0 && arr[p] < key )
        {
            arr[p-1] = arr[p];
            p--; 
        }
        if( arr[p] < key)
        arr[i+1] = key;
 
    }*/
    for(int i = 1; i < n; i++)
    {
        int key =  arr[i];
        int p = i - 1;
        while( p >= 0 && arr[p] > key)
        {
            arr[p+1] = arr[p];
            p--;
        }

        arr[p+1] = key;
    }
    return arr;
}

int main()
{
    vector <int> arr;

    int n;
    cout << "ENTER THE NUMBER OF INPUTS :\n";
    cin >> n;
     
    cout << "ENTER THE NUMBERS: \n";
    for( int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    arr = Insertion_Sort(arr, n);

    for( int i = 0; i < n; i++)
      cout << arr[i] << "  ";
}