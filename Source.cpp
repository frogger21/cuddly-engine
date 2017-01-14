#include <iostream>
using namespace std;
int medianFind(double l, double r, double m, int lp, int rp, int mp);
void printarray(double *arr, int l, int r);

//quicksort of the median of 3: first element, middle element & last element (median of this is the pivot)
void QuickSortMedian3(double *arr, int l, int r)
{
	int lengthArray = r - l + 1; 
	if (lengthArray > 1)
	{
		int mid1 = 0; 
		if (lengthArray % 2 == 0)
		{
			//if array is even
			mid1 = l + (lengthArray / 2) - 1;
		}
		else
		{
			//if array is odd
			mid1 = l + (lengthArray / 2);
		}
		
		int median = medianFind(arr[l], arr[r], arr[mid1], l, r, mid1);
			//printarray(arr, l, r);
			//cout << "L: " << arr[l] << ", M: " << arr[mid1] << ", R: " << arr[r] << ", Median: " << arr[median] << endl;
		//swap first element with median element
		double temp1 = arr[median];
		arr[median] = arr[l];
		arr[l] = temp1;

		//partition
		double pivot = arr[l];
		int i = l + 1;
		for (int j = i; j <= r; j++)
		{
			if (arr[j] < pivot)
			{
				//swap
				double tempVar = arr[j];
				arr[j] = arr[i];
				arr[i] = tempVar;
				i++;
			}
		}

		//swap 
		temp1 = arr[l];
		arr[l] = arr[i - 1];
		arr[i - 1] = temp1;
			//printarray(arr, l, r);
			//cout << endl;
		QuickSortMedian3(arr, l, i - 2);
		QuickSortMedian3(arr, i, r);
	}
}

int medianFind(double l, double r, double m, int lp, int rp, int mp)
{
	double smallest;
	double biggest;
	double median;
	double *arr = new double[3];
	double *arr2 = new double[3];
	//values
	arr[0] = l;
	arr[1] = r;
	arr[2] = m;
	//position
	arr2[0] = lp;
	arr2[1] = rp;
	arr2[2] = mp;

	smallest = arr[0]; //initialize
	biggest = arr[0]; //initialize
	for (int i = 1; i < 3; i++)
	{
		if (smallest > arr[i])
		{
			smallest = arr[i];
		}
		if (biggest < arr[i])
		{
			biggest = arr[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i] >= smallest && arr[i] <= biggest)
		{
			median = arr2[i];
		}
	}
	delete[] arr2;
	delete[] arr;

	return median;
}

void printarray(double *arr, int l, int r)
{
	cout << "(";
	for (int i = l; i < r; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[r] << ")" << endl;

}

int main()
{
	//testing
	double *arr = new double[8];
	int l = 0;
	int r = 7;
	arr[0] = 3.0;
	arr[1] = 8.0;
	arr[2] = 2.0;
	arr[3] = 5.0;
	arr[4] = 1.0;
	arr[5] = 4.0;
	arr[6] = 7.0;
	arr[7] = 6.0;
	cout << "Before!\n";
	printarray(arr, l, r);
	QuickSortMedian3(arr, l, r);
	cout << "After!\n";
	printarray(arr, l, r);

	//just to pause command prompt
	int userExit;
	cout << "Exiting...\n";
	cin >> userExit;
}