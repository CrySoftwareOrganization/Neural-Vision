#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;

void runTest(const vector<int>& input) {
    int n = input.size();

    if (n < 1 || n > 50) {
        cout << "Input: ";
        for (int val : input) {
            cout << val << " ";
        }
        cout << endl;
        cout << "Expected output: 0" << endl;
        cout << "Actual output: 0" << endl;
        cout << endl;
        return;
    }

    vector<int> arr(n);
    size_t sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = input[i];
        if (abs(arr[i]) > 10000) {
            cout << "Input: ";
            for (int val : input) {
                cout << val << " ";
            }
            cout << endl;
            cout << "Expected output: 0" << endl;
            cout << "Actual output: 0" << endl;
            cout << endl;
            return;
        }
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    const double Avg = static_cast<double>(sum) / n;
    int start = 0, end = n - 1;
    size_t currSum = sum, currCount = n;
    size_t maxRemoved = 0;
    const double eps = 1e-8;

    while (start <= end) {
        double currAvg = static_cast<double>(currSum) / currCount;

        if (abs(currAvg - Avg) < eps) {
            maxRemoved = max(maxRemoved, n - currCount);
            currSum -= arr[start++];
            currCount--;
        }
        else if (currAvg < Avg) {
            currSum -= arr[start++];
            currCount--;
        }
        else {
            currSum -= arr[end--];
            currCount--;  
        }
    }

    cout << "Input: ";
    for (int val : input) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Expected output: " << maxRemoved << endl;
    cout << "Actual output: " << maxRemoved << endl;
    cout << endl;
}


int main()
{
    // Test cases
    runTest({1, 2, 3, 4, 5});
    runTest({10, 20, 30, 40});
    runTest({2, 4, 6, 8});
    runTest({3, 5, 7, 9});
    runTest({5, 5, 5, 5, 5});
    runTest({1, 3, 5, 7});
    runTest({100, 200, 300, 400, 500});
    runTest({10, 20, 30, 40, 50});
    runTest({1, 1, 1, 1});
    runTest({2, 2, 2, 2});
    runTest({0, 0, 0, 0, 0});
    runTest({7, 7, 7, 7});
    runTest({11, 13, 17, 19});
    runTest({2, 3, 5, 7, 11});
    runTest({1, 1, 2, 2, 3, 3});
    runTest({10, 20, 30, 30});
    runTest({1, 2, 2, 3, 3, 3});
    runTest({2, 2, 3, 3, 3, 4});
    runTest({1, 1, 1, 2, 2, 2, 3, 3, 3});
    runTest({4, 5, 6, 7, 8, 9});
    runTest({1, 2, 6, 7, 7, 1});

    return 0;
}
