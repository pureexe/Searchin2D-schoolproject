#include<cstdio>
#include<algorithm>
using namespace std;
int *getLowestPtr(int* start,int* ends,int var){
    int* mid=((ends-start)/2)+start;
    if(*mid<var&&*(mid+1)>=var)
        return mid+1;
    else if(*mid>=var&&*(mid-1)<var)
        return mid;
    else if(*mid>var)
        return getLowestPtr(start,mid,var);
    else if(*mid<var)
        return getLowestPtr(mid,ends,var);
}
int *getHighestPtr(int* start,int* ends,int var){
    int* mid=((ends-start)/2)+start;
    printf("[%d]",*mid);
    if(*mid<=var&&*(mid+1)>var)
        return mid;
    else if(*mid>var&&*(mid-1)<=var)
        return mid-1;
    else if(*mid>var)
        return getHighestPtr(start,mid,var);
    else if(*mid<var)
        return getHighestPtr(mid,ends,var);
}
int main(){
    int a[]={1,1,2,2,3,4,5,6,7,9,11,13,15,17};
    int* u=getHighestPtr(a,a+13,9);
    printf("Node = %d , value = %d",u-a,*u);
    return 0;
}
