#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<string>
#include<array>
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
vector<box> in;
array<array<array<vector<box>,1000>,1000>,100> vex;
int main(int in_word,char** word){
    if(in_word!=1)
        cout <<in_word<<"*******************\nCase " << word[1] <<" :: #"<< word[2]<<" ; Algorithm4\n";
    chrono::high_resolution_clock::time_point v1,v2;
    chrono::duration<double> time_span ;
    int i,j,k,m,x,y,range,tmp,t1,t2,d;
    cin >> range >> tmp >> x >> y >> d;
    if(range>100)
    {
        cout << "Segmentation fault (core dumped)\n";
        return 0;
    }
    v1=chrono::high_resolution_clock::now();
    /// Insert
    for(i=0;i<range;i++)
    {
        cin >> t1 >> t2;
        in.push_back(box(t1,t2));
    }
    for(i=0;i<range;i++)
    {
        for(j=0;j<range;j++)
        {
            for(k=0;k<range;k++)
            {
                for(struct box a:in){
                        if(fabs(i-a.x)<=k&&fabs(j-a.y)<=k)
                            vex[i][j][k].push_back(a);
                }
            }
        }
    }
     v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Input time = " << time_span.count() << " Second\n";
    v1=chrono::high_resolution_clock::now();
    /// Searching
    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Search time = " << time_span.count() << " Second\n";
    /// Output
    /*for(struct box a:vex[x][y][d])
        cout << "(" <<a.x <<"," <<a.y<< ") ";
    */


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
