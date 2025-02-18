#include <iostream>
#include <vector>
using namespace std;
long int f(int n)
{
    long int p=1;
    for(int i=2;i<=n;i++)
        p*=i;
    return p;
}
bool attack(pair<int,int> p1,pair<int,int> p2)
{
    return (p1.first==p2.first || p1.second==p2.second || abs(p1.first-p2.first)==abs(p1.second-p2.second));
}
bool valid(vector<pair<int,int>> vect)
{
    for(int i=0;i<vect.size();i++)
    {
        for(int j=i+1;j<vect.size();j++)
        {
            if(attack(vect[i],vect[j]))
                return false;
        }
    }
    return true;
}
int k;
void rec(int n,vector<pair<int,int>> vect,pair<int,int> p,int& ctr)
{
    vect.push_back(p);
    if(vect.size()==n)
    {
        if(valid(vect))
        {
            ctr++;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            rec(n,vect,{i,j},ctr);
        }
    }
}
int main()
{
    int n,ctr=0;
    cin>>n;
    vector<pair<int,int>> vect;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            rec(n,vect,{i,j},ctr);
        }
    }
    cout<<ctr/f(n);
}