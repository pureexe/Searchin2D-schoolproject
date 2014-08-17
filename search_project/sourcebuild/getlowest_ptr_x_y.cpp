#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct box{
    int x,y;
    box(int a,int b)
    {
        x=a;
        y=b;
    }
};
vector<box> vex;
int getXLowestAddr(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(mid==0)
        return 0;
    else if(mid==vex.size()-1)
        return mid;
    else if(vex.at(mid).x>=var&&vex.at(mid-1).x<var)
        return mid;
    else if(vex.at(mid).x==var)
        return getXLowestAddr(start,mid,var);
    else if(vex.at(mid).x>var)
        return getXLowestAddr(start,mid,var);
    else if(vex.at(mid).x<var)
        return getXLowestAddr(mid,ends,var);
}
int getXHighestAddr(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(mid==0)
	return 0;
    else if(mid==vex.size()-1)
        return mid;
    if(vex.at(mid).x<=var&&vex.at(mid+1).x>var)
        return mid;
    else if(vex.at(mid).x==var)
        return getXHighestAddr(mid,ends,var);
    else if(vex.at(mid).x>var)
        return getXHighestAddr(start,mid,var);
    else if(vex.at(mid).x<var)
        return getXHighestAddr(mid,ends,var);
}
int getYLowestAddr(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(mid==0)
	return 0;
    else if(mid==vex.size()-1)
        return mid;
    if(vex.at(mid).y<var&&vex.at(mid).y>=var)
        return mid+1;
    else if(vex.at(mid).y>=var&&vex.at(mid-1).y<var)
        return mid;
    else if(vex.at(mid).y==var)
        return getYLowestAddr(start,mid,var);
    else if(vex.at(mid).y>var)
        return getYLowestAddr(start,mid,var);
    else if(vex.at(mid).y<var)
        return getYLowestAddr(mid,ends,var);
}
int getYHighestAddr(int start,int ends,int var){
    int mid=(start+ends)/2;
    if(mid==0)
	return 0;
    else if(mid==vex.size()-1)
        return mid;
    if(vex.at(mid).y<=var&&vex.at(mid+1).y>var)
        return mid;
    else if(vex.at(mid).y==var)
        return getYHighestAddr(mid,ends,var);
    else if(vex.at(mid).y>var)
        return getYHighestAddr(start,mid,var);
    else if(vex.at(mid).y<var)
        return getYHighestAddr(mid,ends,var);
}
bool sortminx(box a,box b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool sortminy(box a,box b){
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
int main(){
    int i,n,t1,t2;
    int lowx,highx,lowy,highy;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> t1 >> t2;
        vex.push_back(box(t1,t2));
    }
    sort(vex.begin(),vex.begin()+n,sortminy);
    lowx=getXHighestAddr(0,n,9);
    cout << vex[lowx].x << " " << vex[lowx].y;
    cout << "\n\n\n";
    return 0;
}
