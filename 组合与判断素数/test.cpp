//组合与判断素数

#include<iostream>
#include<vector>
#define TEST

using namespace std;

const int M=25;

int m[M];

int now[M];

int n,k;

int flag;

int sum(int now[])
{
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=now[i];
    }
    return sum;
}

int isprime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}


void put()
{
    for(int i=1;i<=k;i++)
    {
        cout<<now[i]<<"   ";
    }
    cout<<endl;
}

void dfs(int len,int p)
{
    if(len>k)
    {
        int s=sum(now);
        if(isprime(s))
        {
            flag++;
            //put();
        }
        return;
    }
    for(int i=p+1;i<=n;i++)
    {
        now[len]=m[i];
        dfs(len+1,i);
    }
    return;
}

int main()
{
    #ifdef TEST
    freopen("/home/tom/Desktop/cpp/test.txt","rw",stdin);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
    }
    dfs(1,0);
    cout<<flag<<endl;
}