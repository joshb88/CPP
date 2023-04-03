int countDigits(string str, int n) {
    if (n == 0) {
        return 0;
    }
    int count = countDigits(str, n-1);
    if (isdigit(str[n-1])) {
        count++;
    }
    return count;
}

int recursiveSumPositiveEven(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    int sum = recursiveSumPositiveEven(arr, n-1);
    if (arr[n-1] > 0 && arr[n-1] % 2 == 0) {
        sum += arr[n-1];
    }
    return sum;
}