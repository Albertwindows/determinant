#include <iostream>

using namespace std;
const int facnum = 4;
int book[facnum +1];
int a[facnum + 10];
int data[facnum+1][facnum+1];
//sum是最终的结果
int sum = 0 ;

bool init()
{
    //cin>>facnum;

    for (int i=0;i<facnum;i++)
        for (int j=0;j<facnum;j++)
			cin>>data[i][j];
	return true;
}
void dfs(int step)
{
    if (step == facnum)
    {
        int unit = 1;
		for (int i=0;i<facnum;i++)
			unit*=data[i][a[i]];
		

		int cnt = step-1;
		int ij = 0;
		for (int i = step -1;i>0;i--)
		{
			for (int j = i-1;j>=0;j--){
				if (a[j]>a[i]) ij++;
			}
        }
		
		if (ij%2 == 1) unit = -unit;
		sum+=unit;
        return ;
    }

    for (int i = 0;i < facnum; i++)
    {
        if (book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    while(init())
	{
		dfs(0);
		cout<<sum<<endl;
		sum=0;
	}
    return 0;
}
