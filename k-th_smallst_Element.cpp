#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int arr[] = {12, 3, 5, 7, 4, 19, 26};
int n = sizeof(arr)/sizeof(arr[0]), k = 3;
int randomPartition(int arr[], int l, int r);

void printArray(int l, int r){
    cout<<"The array from l = "<<l<<" to r = "<<r<<" is: ";
    for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int kthSmallest(int arr[], int l, int r, int k)
{

    cout<<"kthSmallest function is called with "<<"l = "<<l<<" r = "<<r<<" and k = "<<k<<endl;
    printArray(l,r);
	if (k > 0 && k <= r - l + 1)
	{
		cout<<"Call randomPartition with "<<"l = "<<l<<" r = "<<r<<endl;
		int pos = randomPartition(arr, l, r);
        cout<<"\tpos = "<<pos<<", pos-l = "<<pos-l<<" and k-1 = "<<k-1<<endl;
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1){
            cout<<"\tCalled Left sub Array."<<endl;
            return kthSmallest(arr, l, pos-1, k);
		}

		cout<<"\t\tCalled Right sub Array"<<endl;
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

void swap(int *a, int *b)
{
    cout<<"Swap function is called for a = "<<*a<<" and b= "<<*b<<endl;
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r)
{
    cout<<"\tIn partition function "<<"l = "<<l<<" and r = "<<r<<endl;
	int x = arr[r], i = l;
	cout<<"\t\t x = "<<x<<endl;
	for (int j = l; j <= r - 1; j++)
	{
	    cout<<" In loop j = "<<j<<" and arr["<<j<<"] = "<<arr[j]<<" and x = "<<x<<endl;
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

int randomPartition(int arr[], int l, int r)
{
    cout<<"In randomPartition with "<<"l = "<<l<<" r = "<<r<<endl;
	int n = r-l+1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	printArray(l,r);
	return partition(arr, l, r);
}

int main()
{
	int val = kthSmallest(arr, 0, n-1, k);
	cout << "K'th smallest element is " <<val;
	return 0;
}