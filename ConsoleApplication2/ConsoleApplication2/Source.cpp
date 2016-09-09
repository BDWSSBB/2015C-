#include <iostream>

using namespace std;

int simpleSearch(int target, int searchList[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (searchList[i] == target)
			return i;
	}
	return -1;
}

int binarySearch(int target, int searchList[], int len)
{
	int lo = 0;
	int hi = len;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (searchList[mid] == target)
			return mid;
		if (searchList[mid] < target)
			lo = mid + 1;
		if (searchList[mid] > target)
			hi = mid - 1;
	}
	return -1;
}
int main()
{
	int len = 20;
	int searchList[20] = { 1, 3, 5, 6, 7, 8, 10, 13, 14, 15, 20, 21, 22, 23, 25, 26, 29, 30, 33, 38 };
	int target;

	cout << "What number would you like to find?" << endl;
	cin >> target;
	target = binarySearch(target, searchList, len);
	if (target == -1)
		cout << "Element not found." << endl;
	else
		cout << "Element found at position: " << target << endl;

	return 0;
}
