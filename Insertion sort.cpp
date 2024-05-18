#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,x,k;
    cin>>n;
    vector<int> v(n);
    for(i=0; i<n; i++) cin>>v[i];
    //*Insertion sort
    for(i=1; i<n; i++)
    {
        int temp = v[i],ptr = i-1;
        while(temp < v[ptr] && ptr>=0)
        {
            v[ptr + 1] = v[ptr];
            ptr--;
        }
        v[ptr+1] = temp;
    }
    //*
    for(i=0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
}

