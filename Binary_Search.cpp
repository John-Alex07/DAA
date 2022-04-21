#include <iostream>
#include "Sort_Algos.h"

using namespace std;

int Binary_Search(int a[], int l, int h, int key)
{
    if( l <= h)
    {
        int mid = l+(h-l)/2;
        if(a[mid] == key)
        return mid;
        else
        if(a[mid] > key)
        return Binary_Search(a, l, mid-1, key);
        else
        if(a[mid < key])
        return Binary_Search(a, mid+1, h, key);
    }
    return -1;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF INPUTS :\n";
    cin >> n;

    int a[n];
    cout << "ENTER THE NUMBERS :\n";
    for( int i = 0; i < n; i++)
    cin >> a[i];

    Quick_Sort(a, 0, n-1);

    cout << "SORTED ARRAY :\n";
    for(int i = 0; i < n; i++)
    cout << a[i] << " ";

    int pos = Binary_Search(a, 0, n-1, 4);
    cout << "\nNUMBER AT : " << pos;
}