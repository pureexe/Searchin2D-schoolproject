#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<string>
using namespace std;
struct box{
    int x,y;
    box(int a,int b)
    {
        x=a;
        y=b;
    }
};
int fabs(int a)
{
    return (a>0)?a:a*-1;
}
int main(int in_word,char** word){
    if(in_word!=1)
        cout <<in_word<<"*******************\nCase " << word[1] <<" :: #"<< word[2]<<" ; Algorithm1\n";
    chrono::high_resolution_clock::time_point v1,v2;
    chrono::duration<double> time_span ;
    int i,x,y,range,tmp,t1,t2,d;
    vector<box> vex,out;
    cin >> range >> tmp >> x >> y >> d;
    v1=chrono::high_resolution_clock::now();
    /// Insert
    for(i=0;i<range;i++)
    {
        cin >> t1 >> t2;
        vex.push_back(box(t1,t2));
    }
    ///
    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Input time = " << time_span.count() << " Second\n";

    v1=chrono::high_resolution_clock::now();
    /// Searching
    for(box a:vex){
        if(fabs(x-a.x)<=d&&fabs(y-a.y)<=d){
            out.push_back(a);
        }
    }
    ///

    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Search time = " << time_span.count() << " Second\n";
    /*for(box a:out)
    {
        cout << "(" << a.x << "," << a.y << ") ";
    }*/
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

/*
vector<int> data3;
int data2[100];
int* data1=(int*)malloc(sizeof(int)*100);
*/
