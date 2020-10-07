#include <iostream>
#include <cstdlib>
#include <ctime>

void peak_finder(int* arr, int size);

int main()
{
	srand(time(0));

	int SIZE = 10;
	//int array[SIZE]{2,3,4,8,3,6,7,6,3,2};
	int array[SIZE];
	for(auto i = 0; i < SIZE; ++i)
	{
		array[i] = rand() % 10;
		printf("%d ", array[i]);
	}

	peak_finder(array, SIZE);

	return 0;
}

void peak_finder(int* arr, int size)
{
	// indices
	int start = 0;
	int mid;
	int end = size - 1;

	while(true)
	{
		if(end - start == 1)
		{
			mid = (arr[start] > arr[end] ? start : end);
			break;
		}

		else
			mid = (end + start) / 2;


		if( arr[mid] <= arr[mid - 1])  // checking if left is greater than right
		{
			end = mid;  // if it is, updating right pointer
		}

		else if( arr[mid] <= arr[mid + 1])  // checking if right is greater than left
		{
			start = mid;  // if it is, updating left pointer
		}

		else if( arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
		{
			break;
		}
	}
	
	std::cout << "peak value: " << arr[mid] << ",  location: " <<  mid + 1 << std::endl;
}

