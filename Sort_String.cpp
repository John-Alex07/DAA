#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "ENTER THE NUMBER OF INPUTS:\n";
    cin >> n;

    string s[n];

    cout << "ENTER THE NAMES :\n";
    for(int i = 0; i < n; i++)
    cin >> s[i];

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i; i++)
        {
            if(a[j].compare(a[j+1]) )
            {
                string s = a[j];
                a[j] = a[j+1];
                a[j+1] = s;
            }
        }
    }
      
}