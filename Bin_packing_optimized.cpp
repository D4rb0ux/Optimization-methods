#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c;
    cin >> n;
    vector<int> weight(n);
    for (int i  = 0; i < n; i++)
        cin >> weight[i];
    cin >> c;

    int bin_count = 0;
    vector<int> remaining_space(n, c);

    sort(weight.begin(), weight.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bin_count; j++) {
            if (remaining_space[j] >= weight[i]) {
                remaining_space[j] -= weight[i];
                break;
            }
        }
        if (j == bin_count) {
            remaining_space[bin_count] = c - weight[i];
            bin_count++;
        }
    }

    cout << bin_count;
    return 0;
}
