#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// void uniq(vector <int> vec);
// void rev(vector <int> vec);
void linear_search(vector <int> vec);
int main()
{
    int value;
    vector <int> vec;
    cout<<"Enter elements (-1 to stop)"<<endl;
    while (cin>>value && value != -1)
    {
        vec.push_back(value);
    }

    // uniq(vec);
    // rev(vec);
    linear_search(vec);
    
}

void uniq(vector <int> vec)
{
    int ans=0;
    for (int i: vec){
        ans ^= i;
    }
    cout<<"uniq no: "<<ans;
}

void rev(vector <int> vec)
{
    reverse(vec.begin(),vec.end());

    for(int i : vec)
    {
        cout<<i << " ";
    }
}

void linear_search(vector <int> vec)
{
    int value ;
    cout<<"enter value to search: ";
    cin>>value;
    int size = sizeof(vec)/sizeof(int);
    for(int i =0 ; i<size; i++)
    {
        if (value != vec[i]){
            continue;
        }
        else
            cout<<"location "<<i;
            break;

    }
}