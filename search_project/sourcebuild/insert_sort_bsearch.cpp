#include<iostream>
#include<vector>
using namespace std;
vector<int> vex;
int getLowAddr(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(vex.empty())
        return 0;
    else if(vex.at(mid)==var)
        return mid;
    else if(start==mid||ends==mid){
        if(vex[mid]<var)
            return mid+1;
        else
            return mid;
    }
    else if(vex.at(mid)>=var&&vex.at(mid-1)<var)
        {

            return mid;
        }
    else if(vex.at(mid)>var)
        return getLowAddr(start,mid,var);
    else if(vex.at(mid)<var)
        return getLowAddr(mid,ends,var);
}
using namespace std;
int display(){
    for(int a:vex){
        cout << a << " ";
    }
    cout << "\n";
}
int main(){
    int b[]={0,3,1,8,6,3,0,1,4,9};
    for(int x:b)
    {
    vex.insert(vex.begin()+getLowAddr(0,vex.size(),x),x);
    display();
    }
    return 0;
}
