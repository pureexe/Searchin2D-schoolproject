#include<iostream>
#include<algorithm>
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
bool sortx(struct box a,struct box b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool sorty(struct box a,struct box b){
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;

}
vector<box> vex,out;
int getYLow(int start,int ends,int var){
    int mid=(start+ends)/2;
     if(mid==0&&var<=vex[0].y)
            return 0;
    else if(mid+1==ends) // old (mid+1==vex.size)
        return -1;
    else if(vex[mid].y<var&&vex[mid+1].y>=var)
            return mid+1;
    else if(vex[mid].y==var)
            return getYLow(start,mid,var);
    else if(vex[mid].y<var)
        return getYLow(mid,ends,var);
    else if(vex[mid].y>var)
            return getYLow(start,mid,var);
}

int getYHigh(int start,int ends,int var){

    int mid=(start+ends)/2;
    if(mid==0&&var<=vex[0].y)
            return -1;
    else if(mid+1==vex.size()) // old (mid+1==vex.size)
         return mid;
    else if(vex[mid].y<=var&&vex[mid+1].y>var)
            return mid;
    else if(vex[mid].y==var)
                return getYHigh(mid,ends,var);
    else if(vex[mid].y<var)
        return getYHigh(mid,ends,var);
    else if(vex[mid].y>var)
            return getYHigh(start,mid,var);
}

int getXLow(int start,int ends,int var){
    int mid=(start+ends)/2;
     if(mid==0&&var<=vex[0].x)
            return 0;
    else if(mid+1==vex.size())
        return -1;
    else if(vex[mid].x<var&&vex[mid+1].x>=var)
            return mid+1;
    else if(vex[mid].x==var)
            return getXLow(start,mid,var);
    else if(vex[mid].x<var)
        return getYLow(mid,ends,var);
    else if(vex[mid].x>var)
            return getXLow(start,mid,var);
}

int getXHigh(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(mid==0&&var<=vex[0].x)
            return -1;
    else if(mid+1==vex.size())
         return mid;
    else if(vex[mid].x<=var&&vex[mid+1].x>var)
            return mid;
    else if(vex[mid].x==var)
            return getXHigh(mid,ends,var);
    else if(vex[mid].x<var)
        return getXHigh(mid,ends,var);
    else if(vex[mid].x>var)
            return getXHigh(start,mid,var);
}

int main(int in_word,char** word){
    if(in_word!=1)
        cout <<in_word<<"*******************\nCase " << word[1] <<" :: #"<< word[2]<<" ; Algorithm2\n";
    chrono::high_resolution_clock::time_point v1,v2;
    chrono::duration<double> time_span ;
    int i,x,y,range,tmp,t1,t2,d,lowx,highx,lowy,highy,tmpx;

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
    sort(vex.begin(),vex.end(),sortx);
    lowx=getXLow(0,vex.size(),x-d);
     highx=getXHigh(0,vex.size(),x+d);

    if(lowx>highx)
    {
        tmpx=lowx;
        lowx=highx;
        highx=tmpx;
    }
    sort(vex.begin()+lowx,vex.begin()+highx,sorty);

   // lowy=getYLow(lowx,highx,y-d);
    //highy=getYHigh(lowx,highx,y+d);
    ///
    v2=chrono::high_resolution_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
    cout << "Search time = " << time_span.count() << " Second\n";

    /// output
    /*
    for(i=lowy;i<=highy;i++)
    {
        cout << "|(" << vex[i].x << "," << vex[i].y << ") ";
    }
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

/*
vector<int> data3;
int data2[100];
int* data1=(int*)malloc(sizeof(int)*100);
*/
