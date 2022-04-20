#include <iostream>
using namespace std;

void Merge(int a[], int l, int m, int h)
{
    int a_n = m - l + 1;
    int b_n = h - m;

     int arr_a[a_n];
     int arr_b[a_n];
    for(int i = 0; i < a_n; i++)
          arr_a[i] = a[l+i];
    for(int i = 0; i < b_n; i++)
          arr_b[i] = a[m+i+1];

    int a_i = 0, b_i = 0, arr_i = l;
    while(a_i < a_n && b_i < b_n)
    {
        if(arr_a[a_i] < arr_b[b_i])
          a[arr_i++] = arr_a[a_i++];
        else
          a[arr_i++] = arr_b[b_i++];
    }  

    while(a_i < a_n)
    a[arr_i++] = arr_a[a_i++];

    while(b_i < b_n)
    a[arr_i++] = arr_b[b_i++];
}

void Merge_Sort(int a[], int l, int h)
{
    if(l < h)
    {
       int mid = (l + h)/2;
       Merge_Sort(a, l , mid);
       Merge_Sort(a, mid+1, h);
       Merge(a, l, mid, h);
    }
}

int main()
{
    int n;
    cout << "Enter the number of inputs : \n";
    cin >> n;

    int a[n];
    cout << "Enter the inputs :\n";
    for( int i = 0; i < n; i++)
      cin >> a[i];

    Merge_Sort(a, 0, n-1);

    cout << "SORTED ARRAY : \n";
    for( int i = 0; i < n; i++)
       cout << a[i];
}