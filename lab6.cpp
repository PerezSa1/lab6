//author: Samuel Perez
#include<iostream>
#include<stdlib.h>
using namespace std;

bool checkOrder(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

void bubble(int arr[], int n, int &swaps, int &comps)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            comps++;
            if(arr[j+1] < arr[j])
            {
                swap(arr[j+1], arr[j]);
                swaps++;
            }
        }
    }
}

/*void selection(int arr[], int n, int &swaps, int &comps)
{
    bool sp = false;
    int pt;
    for(int i=0; i<n-1; i++)
    {
        for(int j=1; j<n-1-i; j++)
        {
            comps++;
            if(arr[j+1] < arr[j])
            {
                pt = j+1;
                sp = true;
            }
            else
                sp =false;     //if sp is false, dont swap
        }
        if(sp)
        {
            swap(arr[i], arr[pt]);
            swaps++;
        }
    }
}
*/
int main()
{
    char sort;
    int y, n, swaps=0, comps = 0;
    cout << "How many elements do you want in your random array?: ";
    cin >> n;

    cout << "\nWhat range do you want your numbers to be in?: ";
    cin >> y;

    cout << endl;

    int arr[n];

    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % y;
    }

    cout << "arr[";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    cout << "\nWhat kind of sorting would you like to use on your array?(b=bubble)";
    cout << " (s=selection) (i=insertion) ";
    cin >> sort;

    if(sort == 'b')
        bubble(arr, n, swaps, comps);
    
   // if(sort == 's')
   //     selection(arr, n, swaps, comps);


    if(checkOrder(arr, n))
        cout << "\narray is ordered\n";
    else
        cout << "\nNOT ordered\n";
    cout << "arr[";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    cout << "swaps: " << swaps << endl;
    cout << "comparisons: " << comps << endl;

    return 0;
}
