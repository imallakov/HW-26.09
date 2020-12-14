#include <iostream>
void shiftArray(int A[], int n, int k) {
    int* M = new int[n];
    if(k>0)
    {
    	k=-(n-k);
	}
	for(int i=0;i<-k;++i)
	{
		M[i]=A[n+k+i];
	}
	for(int i=-k;i<n;++i)
	{
		M[i]=A[i+k];
	}
	for(int i=0;i<n;++i)
	A[i]=M[i];
	return;
}

void printArray(const int A[],int n) {
    for(int i=0;i<n;++i)
    {
    	std::cout<<A[i]<<' ';
	}
    std::cout<<std::endl;
}

int main()
{
    int n = 10;
    int* M = new int[n];
    for(int i=0;i<n;++i)
    {
    	M[i] = i;
	}
    
    shiftArray(M, n, 3);
    printArray(M, n);
    delete[] M;
    return 0;
}
