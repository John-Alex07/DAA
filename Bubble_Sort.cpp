#include <iostream>
#include <vector>

using namespace std;
void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}
vector <int> Bubble_sort(vector <int> arr, int n)
{
    for(int i = 0; i<n-1; i++)
        for(int j = 0; j < n-i-1; j++)
           if(arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
    return arr;
}
int main()
{
    vector <int> arr;
    int num,n;
    cout << "Enter the Number of inputs :\n";
    cin >> n;

    cout << "ENTER THE NUMBERS : \n";
    for( int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    arr = Bubble_sort(arr, n);

    cout << "SORTED ARRAY : \n";
    for( auto i = 0; i < n; i++)
         cout << arr[i] << " ";

}