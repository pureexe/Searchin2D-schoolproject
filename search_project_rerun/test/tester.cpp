#include<iostream>
#include<cstdlib>
#include<string.h>
#include<sstream>
#include<cmath>
#include<fstream>
#include<chrono>
using namespace std;
string inttostr(int a){
    stringstream b;
    b << a;
    return b.str();
}
int main(){
    int i,j,k;
    //ofstream file ("output.txt");
    string prefix="case_",ch="";
    chrono::high_resolution_clock::time_point v1,v2;
    chrono::duration<double> time_span ;

    for(i=1;i<=4;i++)
    {
        cout << "########################################\n";
        cout << "Case" << pow(10,i) << "\n";
        //system((char*)(ch+"echo Case "+inttostr(pow(10,i))+" >> output.txt").c_str());
        //system((char*)(ch="###################################### >> output.txt").c_str());
        for(j=0;j<10;j++)
        {
            cout <<"-----------------------------------\n";
            cout << "Case" << pow(10,i) << " :: #"<< j <<"\n";
             //system((char*)("echo Case "+inttostr(pow(10,i))+" ::  #"+inttostr(j)+" >> output.txt").c_str());
            // system((char*)(ch+"echo --------------------------------- >> output.txt").c_str());
             // "echo Case "+pow(10,i) << " ::  #" << j << "\n";
            //file << "------------------------------------------ \n";
            for(k=1;k<=5;k++)
            {
                //cout << "\n************\nCase " << pow(10,i) <<" ::  #" << j <<  " -> Algorithm" << k <<" ...";

                cout << "\nCase " << pow(10,i) <<" ::  #" << j <<  " -> Algorithm" << k <<" ...";
                //system((char*)(ch+"echo ********** >> output.txt").c_str());
                //system((char*)(ch+"echo Case "+inttostr(pow(10,i))+" :: #"+inttostr(j)+" -> Algorithm"+inttostr(k)+".... >> output.txt").c_str());
               if(k==4)
               {
                   cout << "segment fault";
               }
               else
               {
                v1=chrono::high_resolution_clock::now();
                system((char*)("./algo"+inttostr(k)+" "+inttostr(pow(10,i))+" "+inttostr(j)+" <"+prefix+inttostr(pow(10,i))+"_"+inttostr(j)+".txt"+" >> output.txt").c_str());
                v2=chrono::high_resolution_clock::now();
                time_span = chrono::duration_cast<chrono::duration<double>>(v2 - v1);
                cout << "Finished in  " << time_span.count() << " Second\n";
               }
            }
        }
    }
    return 0;
}
