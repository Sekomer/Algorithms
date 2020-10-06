#include <iostream>
#include <cstdlib>
#include <ctime>

void peak_finder(int* arr, int size);

int main()
{
	srand(time(0));

	int SIZE = 16;
	int array[SIZE];

	for(auto i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 20;
		std::cout << array[i] << " " ;
	}


	peak_finder(array, SIZE);

	return 0;
}

void peak_finder(int* arr, int size)
{
	
	// indices
	int start = 0;
	int mid;
	int end;

	end = size;

	while(start < end)
	{
		mid = (end - start) / 2;

		if( *(arr + mid) <= *(arr + mid - 1))  // checking if left is greater than right
		{
			end = *(arr + mid);  // if it is, updating right pointer
		}

		else if( *(arr + mid) <= *(arr + mid + 1))  // checking if right is greater than left
		{
			start = *(arr + mid);  // if it is, updating left pointer
		}

		else if( *(arr + mid) >= *(arr + mid + 1) && *(arr + mid) >= *(arr + mid - 1))
		{
			break;
		}
		else{
			break;
		}

	}

	std::cout << "peak value: " << arr[mid] << ", location: " <<  mid + 1 << std::endl;
}
