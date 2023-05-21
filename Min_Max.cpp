#include <iostream>
#include<omp.h>
#include<time.h>
#include<climits>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int sum1(int a[],int n)  // Find sum of numbers
{
int sum=0;
#pragma omp parallel for reduction(+:sum)
for(int i=0;i<n;i++)
{
sum=sum+a[i];
}
return sum;

}

int min1(int a[],int n){  // Find min of number
int minn=INT_MAX;

#pragma omp parallel for reduction(min:minn)

for(int i=0;i<n;i++){

if(a[i]<minn)
{
minn=a[i];
}

}
return minn;
}

int max1(int a[],int n){   // Find max of numbers
int maxx=INT_MIN;

#pragma omp parallel for reduction(max:maxx)

for(int i=0;i<n;i++){

if(a[i]>maxx)
{
maxx=a[i];
}

}
return maxx;
}

float avg1(int a[],int n){  // Find average of number

return sum1(a,n)/n;
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout<<" " <<arr[i];
	}
	cout<<"\n";
}

int main(){

int n;
cout<<"Enter no of inputs : ";
cin>>n;
int a[n];

for(int i=0;i<n;i++)   // Taking input of numbers
{

a[i]=rand()%n;

}

print_arr(a,n);
// Time taken for sum

auto beg=high_resolution_clock::now();
int s=sum1(a,n);
auto end =high_resolution_clock::now();
auto sd = duration_cast<microseconds>(end - beg);

// Time taken for average

beg = high_resolution_clock::now();
int a1 = avg1(a,n);
end = high_resolution_clock::now();
auto ad = duration_cast<microseconds>(end - beg);

// Time taken for min

beg = high_resolution_clock::now();
int min = min1(a,n);
end = high_resolution_clock::now();
auto mi = duration_cast<microseconds>(end - beg);

// Time taken by max

beg = high_resolution_clock::now();
int max = max1(a,n);
end = high_resolution_clock::now();
auto ma = duration_cast<microseconds>(end - beg);

cout<<"Sum of given numbers :  " <<sum1(a,n)<<endl;
cout<<"Time for sum is :  " <<sd.count()<<endl;
cout<<"Min from numbers is :  "<<min1(a,n)<<endl;
cout<<"Time for min is : "<<mi.count()<<endl;
cout<<"max from numbers is :  "<<max1(a,n)<<endl;
cout<<"Time for max is : "<<ma.count()<<endl;
cout<<"Average of given numbers is : "<<avg1(a,n)<<endl;
cout<<"Time for average : "<<ad.count()<<endl;

return 0;

}