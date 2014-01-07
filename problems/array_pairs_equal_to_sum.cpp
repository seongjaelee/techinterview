#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void find_pairs(vector<int> & arr, int sum, vector< pair<int, int> > & ret) {
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;
    while (i < j) {
        int temp_sum = arr[i] + arr[j];
        if (temp_sum < sum) {
            i++;
        }
        else if (temp_sum > sum) {
            j--;
        }
        else {
            ret.push_back(pair<int, int>(arr[i], arr[j]));
            i++;
        }
    }
}

int main(int argc, const char ** argv) {
    int arr[] = {1, 0, 2, 3};
    vector<int> arr_vec(arr, arr + 4);
    vector< pair<int, int> > ret;
    find_pairs(arr_vec, 3, ret);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i].first << ", " << ret[i].second << endl;
    }
    return 0;
}