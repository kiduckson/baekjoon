#include <stdio.h>

int binarySearch(int arr[], int target){
	int low = 0;
	int high = arr.length - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid]>target)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

int reculsiveBinarySearch(int arr[], int target, int low, int high){
	if (low > high)
		return -1;
	int mid = (low - high) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid]>target)
		return reculsiveBinarySearch(arr, target, low, mid-1);
	else
		return reculsiveBinarySearch(arr, target, mid+1, high);

}
