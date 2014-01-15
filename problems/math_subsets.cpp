// returns all subsets of a set
#include <set>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

// a crazy idea. only works when arrsize < 32
template <typename T>
void get_subsets_crazy(const vector<T> & arr, vector< vector<T> > & ret) {
    assert(arr.size() < sizeof(int) * 8);
    unsigned int max_size = 1 << arr.size();
    for (int i = 0; i < max_size; ++i) {
        vector<T> temp;
        for (int j = 0; j < arr.size(); ++j) {
            if (i & (1 << j)) {
                temp.push_back(arr[j]);
            }
        }
        ret.push_back(temp);
    }
}

template <typename T>
void get_subsets(const vector<T> & arr, vector< vector<T> > & ret) {
    if (arr.size() == 0) {
        vector<T> empty;
        ret.push_back(empty);
        return;
    }

    vector<T> arr_copy(arr.begin(), arr.end() - 1);
    vector< vector<T> > ret_temp;
    get_subsets(arr_copy, ret_temp);

    for (int j = 0; j < ret_temp.size(); ++j) {
        ret.push_back(ret_temp[j]);

        vector<T> ret_copy(ret_temp[j]);
        ret_copy.push_back(arr[arr.size() - 1]);
        ret.push_back(ret_copy);
    }
}

int main(int argc, const char ** argv) {
    int arr[] = {};
    vector<int> arr_vec(arr, arr + sizeof(arr)/sizeof(int));
    vector< vector<int> > ret;
    // get_subsets<int>(arr_vec, ret);
    get_subsets_crazy<int>(arr_vec, ret);
    for (int i = 0; i < ret.size(); ++i) {
        cout << "{";
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j];
            if (j != ret[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
    return 0;
}