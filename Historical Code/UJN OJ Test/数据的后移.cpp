#include<iostream>
#define maxn 25
using namespace std;
int main()
{
    int n,m;
    int a[maxn];
    while(cin >> n >> m)
    {
        for(int i=0;i<n;i++)
            cin >> a[i];
        while(m--)
        {
            int x=a[n-1];
            int j=n-1;
            while(j>=0)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=x;
        }
        cout << a[0];
        for(int i=1;i<n;i++)
            cout << " " << a[i];
        cout << endl;
    }
    return 0;
}
