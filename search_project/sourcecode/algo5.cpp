#include<iostream>
#include<algorithm>
#include<array>
#include<chrono>
#include<fstream>
#include<array>
#include<string>
using namespace std;
int arr[10000][10000];
int main(int in_word,char** word){
    if(in_word!=1)
        cout <<in_word<<"*******************\nCase " << word[1] <<" :: #"<< word[2]<<" ; Algorithm5\n";
    chrono::high_resolution_clock::time_point v1,v2;
    chrono::duration<double> time_span ;
    int i,j,x,y,range,tmp,t1,t2,d,lowx,highx,lowy,highy;
    cin >> range >> tmp >> x >> y >> d;
    if(range>10000)
    {
        cout << "Segmentation fault (core dumped)\n";
        return 0;
    }
    v1=chrono::high_resolution_clock::now();
    /// Insert
    for(i=0;i<range;i++)
    {
        cin >> t1 >> t2;
        arr[t1][t2]=1;
    }
    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Input time = " << time_span.count() << " Second\n";

    v1=chrono::high_resolution_clock::now();
    /// Searching
    for(i=x-d;i<=x+d;i++)
    {
        for(j=y-d;j<y+d;j++)
        {
            if(arr[i][j]==1){
               // cout << "(" <<i<<","<<j<< ")";
            }
        }
    }
    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Search time = " << time_span.count() << " Second\n";
    /// Memory Dump
    string line;
    ifstream file ("/proc/self/status");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            /*
            if(string("VmRSS:")==line)
            cout << "RAM = " <<   ;
            */
            if(string(line.begin(),line.begin()+7)=="VmSize:")
                cout << "Memory = " << string(line.begin()+7,line.end()) << "\n"   ;
        }
    }

    return 0;
}
