#include <iostream>
#include <vector>

using namespace std;


void Input(vector<int>& Out)
{
    cout << "Please enter an integer : ";
    int n;
    cin >> n;
    
    Out.clear();
    Out.resize(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> Out[i];
    }

    [&Out, n]()
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += Out[i];
        }
        cout << "Sum : " << sum << "\n" << "Avg : " << (float)sum / Out.size() << "\n";   
    }();
}

int Partition(vector<int>& List, int Left, int Right)
{
    int Pivot = List[Left];

    int lo = Left;
    int hi = Right + 1;

    while(true)
    {
        do
        {
            ++lo;
        }while(lo <= Right && List[lo] <= Pivot);

        do
        {
            --hi;
        }while(hi >= Left && List[hi] > Pivot);

        if(lo < hi)
        {
            swap(List[lo], List[hi]);
        }
        else
        {
            break;
        }
    }

    swap(List[Left], List[hi]);
    
    return hi;
}

void QuickSort(vector<int>& List, int Left, int Right, int Opt)
{
    if(Left < Right)
    {
        int PivotPos = Partition(List, Left, Right);

        QuickSort(List, Left, PivotPos - 1, Opt);
        QuickSort(List, PivotPos + 1, Right, Opt);
    }
}

// int main()
// {
//     vector<int> Nums;
//     Input(Nums);
//
//     QuickSort(Nums, 0, Nums.size() - 1, 1);
//
//     for (int i = 0; i < Nums.size(); ++i)
//     {
//         cout << Nums[i] << " ";
//     }
//
//     return 0;
// }
