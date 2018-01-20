#include <iostream>
#include <algorithm> 
#include <iomanip>
using namespace std;

int ParentIndex(long int i)
{
	return (i-1)/2;
}

int LeftChildIndex(long int i)
{
	return 2*i + 1;
}

int RightChildIndex(long int i)
{
	return 2*i + 2;
}

void MaxHeapifyUp(long int arr[], long int N)
{
	int i=N-1;

	while(ParentIndex(i) > -1 and arr[ParentIndex(i)] < arr[i])
	{
		//cout<<endl<<ParentIndex(i)<<endl;
        swap(arr[ParentIndex(i)], arr[i]);
		i=ParentIndex(i);
	}
}

void MinHeapifyUp(long int arr[], long int N)
{
	int i=N-1;

	while(ParentIndex(i) > -1 and arr[ParentIndex(i)] > arr[i])
	{
		swap(arr[ParentIndex(i)], arr[i]);
		i=ParentIndex(i);
	}
}

void MaxHeapifyDown(long int arr[], long int N)
{
	int i=0;

	while(LeftChildIndex(i) < N)
	{
		int BiggerChildIndex = LeftChildIndex(i);

		if(RightChildIndex(i) < N and arr[RightChildIndex(i)] > arr[LeftChildIndex(i)])
		BiggerChildIndex=RightChildIndex(i);

		if(arr[i] >= arr[BiggerChildIndex])
		{
			break;
		}
		else swap(arr[i],arr[BiggerChildIndex]);

		i=BiggerChildIndex;
		
	}
	
}
void MinHeapifyDown(long int arr[],long int N)
{
	int i=0;


	while(LeftChildIndex(i) < N)
	{
		int SmallerChildIndex = LeftChildIndex(i);

		if(RightChildIndex(i) < N and arr[RightChildIndex(i)] < arr[LeftChildIndex(i)])
		SmallerChildIndex=RightChildIndex(i);

		if(arr[i] <= arr[SmallerChildIndex])
		{
			break;
		}
		else swap(arr[i],arr[SmallerChildIndex]);

		i=SmallerChildIndex;
		
	}
	
}

float Median(long int a[], long int b[], long int size_a, long int size_b)
{
	if(size_a == size_b)  return ((float)a[0] + (float)b[0])/(float)2;

    if(size_a < size_b) return (float)b[0];

    if(size_a > size_b) return (float)a[0];	

    return 0;
}


    
    int main( )
    {
        long int n, number;
        cin>>n;

        long int smaller[100000], bigger[100000];
        long int a[100000];
        long int N_smaller=0, N_bigger=0;

        for (int i = 0; i < n; ++i)
        {
        	cin>>a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            number=a[i];

            if(N_smaller==0 and N_bigger==0)
            {
                ++N_smaller;
                smaller[0]=number;
                cout<<fixed<<setprecision(1)<<Median(smaller, bigger, N_smaller, N_bigger)<< endl;
                
                continue;
            }
            if(N_bigger <= N_smaller and number >= smaller[0])
            {

                ++N_bigger;
                bigger[N_bigger-1]=number;
                MinHeapifyUp(bigger, N_bigger);
                cout<<fixed<<setprecision(1)<<Median(smaller, bigger, N_smaller, N_bigger)<<endl;
                
                continue;
            }
            if(N_smaller <= N_bigger and number <= bigger[0])
            {
                ++N_smaller;
                smaller[N_smaller-1]=number;
                MaxHeapifyUp(smaller, N_smaller);
                cout<<fixed<<setprecision(1)<<Median(smaller, bigger, N_smaller, N_bigger)<<endl;
                
                continue;
            }
            if(N_smaller > N_bigger and number < smaller[0])
            {
                ++N_bigger;
                bigger[N_bigger-1]=smaller[0];
                smaller[0]=number;
                MinHeapifyUp(bigger, N_bigger);
                MaxHeapifyDown(smaller, N_smaller);
                cout<<fixed<<setprecision(1)<<Median(smaller, bigger, N_smaller, N_bigger)<<endl;
               
                continue;
            }
            if(N_bigger > N_smaller and number > bigger[0])
            {
                ++N_smaller;
                smaller[N_smaller-1]=bigger[0];
                bigger[0]=number;
                MaxHeapifyUp(smaller, N_smaller);
                MinHeapifyDown(bigger,N_bigger);
                cout<<fixed<<setprecision(1)<<Median(smaller, bigger, N_smaller, N_bigger)<<endl;
               
                continue;
            }
        }


        return 0;
        

    }
