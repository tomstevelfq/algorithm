//n皇后问题
//回溯算法

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
//#define TEST

using namespace std;

const int M=15;

int m[M][M];

int now[M];

vector<string> result;

string Now;

int n;

void put()
{
    printf("\n\n\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    printf("\n\n\n");
}

int test(int x,int y)
{
    for(int i=0;i<=n;i++)
    {
        if((m[x][i]&&i!=y)||(m[i][y]&&i!=x))
        return 0;
    }

    int k=y-x;
    int u=x+y;
    int _x,_y;

    for(int i=0,_x=0,_y=k;i<=n;i++,_x=i,_y=i+k)
    {
        //cout<<x<<"   "<<y<<"  "<<_x<<"  "<<_y<<endl;
        if(_y>n||_y<0||_x==x)
        continue;
        if(m[_x][_y])
        return 0;
    }

    for(int i=0,_x=0,_y=u;i<=n;i++,_x=i,_y=u-i)
    {
        //cout<<x<<"   "<<y<<"  "<<_x<<"  "<<_y<<endl;
        if(_y<0||_y>n||_x==x)
        continue;
        if(m[_x][_y])
        return 0;
    }
    //cout<<x<<","<<y<<"是符合的点"<<endl;
    return 1;
}

int flag;

void dfs(int len,int sum)
{
    cout<<flag<<"  "<<len<<"  "<<sum<<endl;

    flag++;
    if(len==n)
    {
        cout<<"success"<<flag<<"   "<<Now<<endl;
        result.insert(result.begin(),Now);
        return;
    }
    if(sum>2*n)
    {
        return;
    }
    dfs(len,sum+1);
    for(int i=0,x=i,y=sum-x;i<=n;i++,x=i,y=sum-x)
    {
        cout<<"xy"<<x<<"  "<<y<<endl;
        if(y>n||y<0)
        continue;
        string str=Now;
        if(test(x,y))
        {
            put();
            Now+=" ("+to_string(x)+","+to_string(y)+") ";
            cout<<"Now"<<Now<<endl;
            cout<<"NNow"<<len<<"  "<<sum<<endl;
            m[x][y]=1;
            cout<<"m[x][y]=1"<<endl;
            dfs(len+1,sum+1);
            m[x][y]=0;
            cout<<"m[x][y]=0"<<endl;
            Now=str;
        }
    }
    return;
}

int main()
{
    #ifdef TEST
    freopen("/home/tom/Desktop/cpp/test.txt","rw",stdin);
    #endif

    cin>>n;
    dfs(0,0);
    cout<<"end"<<endl;
    sort(result.begin(),result.end());
    for(auto it:result)
    cout<<it<<endl;
}
   