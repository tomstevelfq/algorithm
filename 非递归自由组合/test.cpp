//不用递归方法输出所有组合
//类似N进制数，确定如何进位
#include<iostream>
#include<vector>

using namespace std;

const int M=25;
int m[M];
int Next[M];

int n,r;

int next(int num[])
{
    //cout<<"next"<<endl;
    int last=m[n]+1;
    for(int i=r-1;i>=0;i--)
    {
        //cout<<last-1<<"   "<<num[i]<<endl;
        if(num[i]<last-1)
        {
            num[i]++;
            for(int j=i+1;j<=r-1;j++)
            {
                num[j]=num[j-1]+1;
            }
            //cout<<"num++"<<endl;
            return 1;
        }
        else
        {
            last=num[i];
        } 
    }
    return 0;
}

void put(int t[])
{
    for(int i=0;i<r;i++)
    {
        cout<<t[i]<<"   ";
    }
    cout<<endl;
}

int main()
{
    cin>>n>>r;
    int test[M];
    for(int i=1;i<=n;i++)
    {
        m[i]=i;
    }
    for(int i=0;i<r;i++)
    {
        test[i]=m[i+1];
    }
    test[r-1]=r-1;
    int flag=0;
    while(next(test))
    {
        put(test);
        flag++;
    }
    cout<<flag<<endl;
}