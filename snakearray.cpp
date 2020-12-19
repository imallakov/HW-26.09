#include<bits/stdc++.h>

void snakearray(int** M,int n,int x,int y,int x1,int y1,int k)
{
	M[x][y]=k;
	if(x==n-1&&y==n-1)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				std::cout<<std::setw(4)<<M[i][j];
			std::cout<<std::endl;
		}
		return;
	}
	else
	{
		if(x-x1==1&&y1==y)
		{
			if(y==0)
				snakearray(M,n,x-1,y+1,x,y,k+1);
			else
				snakearray(M,n,x+1,y-1,x,y,k+1);
		}
		else
		{
			if(x1==x&&y-y1==1)
			{
				if(x==0)
					snakearray(M,n,x+1,y-1,x,y,k+1);
				else
					snakearray(M,n,x-1,y+1,x,y,k+1);
			}
			else
			{
				if(x1-x==1&&y-y1==1)
				{
					if(x-1>=0&&y+1<n)
						snakearray(M,n,x-1,y+1,x,y,k+1);
					else
						if(y+1<n)
							snakearray(M,n,x,y+1,x,y,k+1);
						else
							snakearray(M,n,x+1,y,x,y,k+1);
				}
				else
				{
					if(x-x1==1&&y1-y==1)
					{
						if(x+1<n&&y-1>=0)
							snakearray(M,n,x+1,y-1,x,y,k+1);
						else
							if(x+1<n)
								snakearray(M,n,x+1,y,x,y,k+1);
							else
								snakearray(M,n,x,y+1,x,y,k+1);
					}
				}
			}
		}
	}
	return;
}

int main()
{
	int n;
	std::cout<<"N=";
	std::cin>>n;
	int** M = new int* [n];
	for (int i = 0; i < n; ++i)
		M[i] = new int[n];
	M[0][0]=1;
	snakearray(M, n,1,0,0,0,2);
	for (int i = 0; i < n; ++i)
		delete[] M[i];
	delete[] M;
	return 0;
}
