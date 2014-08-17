#include<iostream>
#include<fstream>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<map>
using namespace std;
map<int,map<int,int> > check;
string inttostr(int a){
    stringstream sout;
    sout << a;
    return sout.str();
}
int fabs(int a){
    return (a>0)?a:a*-1;
}
int main(){
int range,x,y,i,u;
chrono::high_resolution_clock::time_point t1,t2;
string name_prefix="case_",filename;
cin >> range;
for(u=0;u<10;u++){
filename="";
ofstream file (name_prefix+inttostr(range)+"_"+inttostr(u)+".txt");
if(!file.is_open())
{
        cout << "Error file open failed";
        return 0;
}
file << range << " " << range << "\n" << rand()%range <<" "<< rand()%range<<" "<< rand()%range <<"\n";
t1=chrono::high_resolution_clock::now();
for(i=0;i<range;i++)
{
           while(1)
    {
        x=fabs(rand()%range);
        y=fabs(rand()%range);
        if(check[x][y]==0)
        {
            file << x << " " << y << "\n";
            check[x][y]=1;
            break;
        }
    }
}
t2=chrono::high_resolution_clock::now();
chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
cout << "Generate finished in "<< time_span.count() << "\n";
file.close();
}
return 0;
}
