//dfs输出自由组合

#include<iostream>

using namespace std;

const int M=25;
int v[M];

int now[M];

int m,n;

void put(int now[])
{
    for(int i=1;i<=n;i++)
    {
        cout<<now[i]<<" ";
    }
    cout<<endl;
}

void dfs(int len)
{
    if(len>n)
    {
        put(now);//输出当前数组
        return;
    }
    for(int i=1;i<=m;i++)
    {
        if(v[i]==0&&i>now[len-1])
        {
            v[i]=1;
            now[len]=i;
            dfs(len+1);
            v[i]=0;
        }
    }
    return;
}

int main()
{
    cin>>m>>n;
    dfs(1);
    return 0;
}