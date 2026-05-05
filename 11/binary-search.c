int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;

    int newLow  = (arr[mid] < target) ? mid + 1 : low;
    int newHigh = (arr[mid] < target) ? high    : mid - 1;

    return binarySearch(arr, newLow, newHigh, target);
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}