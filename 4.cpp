#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <functional>
using namespace __gnu_pbds;
// PBDS MULTISET USING LESS_EQUAL
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set<T>;
#ifndef PRINT_H
#define PRINT_H
#define int long long
#define double long double

#define JAI_SHRI_RAAM ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Define the path for the debug output file
const string debug_file_path = "./files/debug.txt";
ofstream debug_file;

// Function to initialize the debug file stream
void initialize_debug_file() {
    if (ifstream(debug_file_path)) {
        debug_file.open(debug_file_path, ios::app); // Open in append mode
        if (!debug_file.is_open()) {
            cerr << "Failed to open debug file: " << debug_file_path << endl;
        }
    }
}

// General template function for printing various data types
template <typename T>
void debug_print(const T &value) {
    debug_file << value;
}

// Specialization for double with fixed precision
template <>
void debug_print(const double &value) {
    debug_file << fixed << setprecision(6) << value;
}

// Specialization for string
template <>
void debug_print(const string &value) {
    debug_file << value;
}

// Function to print a vector
template <typename T>
void debug_print(const vector<T> &vec) {
    debug_file << "[ ";
    for (const auto &elem : vec) {
        debug_print(elem);
        debug_file << " ";
    }
    debug_file << "]";
}

// Function to print a pair
template <typename T1, typename T2>
void debug_print(const pair<T1, T2> &p) {
    debug_file << "(";
    debug_print(p.first);
    debug_file << ", ";
    debug_print(p.second);
    debug_file << ")";
}

// Function to print a set
template <typename T>
void debug_print(const set<T> &s) {
    debug_file << "{ ";
    for (const auto &elem : s) {
        debug_print(elem);
        debug_file << " ";
    }
    debug_file << "}";
}

// Function to print an unordered set
template <typename T>
void debug_print(const unordered_set<T> &s) {
    debug_file << "{ ";
    for (const auto &elem : s) {
        debug_print(elem);
        debug_file << " ";
    }
    debug_file << "}";
}

// Function to print a map
template <typename K, typename V>
void debug_print(const map<K, V> &m) {
    debug_file << "{ ";
    for (const auto &pair : m) {
        debug_print(pair.first);
        debug_file << " -> ";
        debug_print(pair.second);
        debug_file << " ";
    }
    debug_file << "}";
}

// Function to print an unordered map
template <typename K, typename V>
void debug_print(const unordered_map<K, V> &m) {
    debug_file << "{ ";
    for (const auto &pair : m) {
        debug_print(pair.first);
        debug_file << " -> ";
        debug_print(pair.second);
        debug_file << " ";
    }
    debug_file << "}";
}

// Function to print a range of values (useful for arrays or segments)
template <typename Iter>
void debug_print(Iter begin, Iter end) {
    debug_file << "[ ";
    for (Iter it = begin; it != end; ++it) {
        debug_print(*it);
        debug_file << " ";
    }
    debug_file << "]";
}

// Overloaded function to handle printing multiple arguments
template <typename T, typename... Args>
void debug_print(const T &first, const Args&... args) {
    debug_print(first);
    debug_file << " ";
    debug_print(args...);
}

// Define the print macro for conditional debug printing
#ifdef ONLINE_JUDGE
#define print(...) // No-op if ONLINE_JUDGE is defined
#else
#define print(...) do { if (debug_file.is_open()) { debug_print(__VA_ARGS__); debug_file << "\n"; debug_file.flush(); } } while (0)
#endif

#endif // PRINT_H

#define close if (debug_file.is_open()) {debug_file.close();}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T> 
T pw(T a, T n, T md = numeric_limits<T>::max()) {
    a %= md;
    T res = 1;
    while (n) {
        if (n % 2) {
            res = (res * a) % md;
            n--;
        } else {
            a = (a * a) % md;
            n /= 2;
        }
    }
    return res;
}

int gcd(int a, int b) {
while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
}
return a;
}

int minv(int a, int m){
    if(gcd(a,m) != 1) return -1;
    return pw(a,m-2,m);
}

int madd(int a, int b, int m){
    return ((a%m) + (b%m))%m;
}

int msub(int a, int b, int m){
    return ((a%m) - (b%m) + m)%m;
}

int mmul(int a, int b, int m){
    return ((a%m) * (b%m))%m;
}

int mdiv(int a, int b, int m){
    int c = minv(b,m);
    if(c == -1) return -1;
    return ((a%m) * (c%m))%m;
}

string decimaltobinary(int n){
    string ans = "";
    while(n){
        if(n&1) ans += '1';
        else ans += '0';
        n = n>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int binarytodecimal(string &s){
    int ans = 0;
    for(char c : s){
        ans <<= 1;
        if(c == '1') ans |= 1;
    }
    return ans;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// Segment Tree Node: Stores data of type T (e.g., vector<int>, pair, struct, etc.)
class SegmentTreeNode {
public:
    vector<int> value;  // Stores the value (can be of any type: int, pair, struct, etc.)

    // Constructor to initialize with a value
    SegmentTreeNode(const vector<int>& value = vector<int>()) : value(value) {}

    // Assign a new value to the node (useful for leaf nodes)
    void assignLeaf(const vector<int>& newValue) {
        value = newValue;
    }
};


// Segment Tree class definition
template<typename T>  // T will be the type of the node (e.g., vector<int>)
class SegmentTree {
private:
    std::vector<SegmentTreeNode> tree;  // Store the segment tree nodes
    int N;

public:
    // Constructor: Initialize the segment tree with an array of data and a merge function
    SegmentTree(const std::vector<T>& arr, std::function<T(const T&, const T&)> mergeFunc) {
        N = arr.size();
        int size = getSegmentTreeSize(N);
        tree.resize(size);
        buildTree(arr, 0, 0, N - 1, mergeFunc);
    }

    // Query the range [lo, hi]
    T getValue(int lo, int hi, std::function<T(const T&, const T&)> mergeFunc) {
        return getValue(0, 0, N - 1, lo, hi, mergeFunc);
    }

    // Update the value at index `index`
    void update(int index, const T& value, std::function<T(const T&, const T&)> mergeFunc) {
        update(0, 0, N - 1, index, value, mergeFunc);
    }

private:
    // Helper function to build the segment tree
    void buildTree(const std::vector<T>& arr, int node, int start, int end, std::function<T(const T&, const T&)> mergeFunc) {
        if (start == end) {
            tree[node].assignLeaf(arr[start]);
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid, mergeFunc);
            buildTree(arr, 2 * node + 2, mid + 1, end, mergeFunc);
            tree[node].value = mergeFunc(tree[2 * node + 1].value, tree[2 * node + 2].value);
        }
    }

    // Recursive function to get the value in the range [lo, hi]
    T getValue(int node, int start, int end, int lo, int hi, std::function<T(const T&, const T&)> mergeFunc) {
        if (hi < start || lo > end) {
            return T();  // Return a default value if the range is out of bounds
        }
        if (lo <= start && end <= hi) {
            return tree[node].value;
        }
        int mid = (start + end) / 2;
        T leftResult = getValue(2 * node + 1, start, mid, lo, hi, mergeFunc);
        T rightResult = getValue(2 * node + 2, mid + 1, end, lo, hi, mergeFunc);
        return mergeFunc(leftResult, rightResult);
    }

    // Helper function to update a value at a specific index
    void update(int node, int start, int end, int index, const T& value, std::function<T(const T&, const T&)> mergeFunc) {
        if (start == end) {
            tree[node].assignLeaf(value);  // Update the leaf node
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(2 * node + 1, start, mid, index, value, mergeFunc);  // Update left child
            } else {
                update(2 * node + 2, mid + 1, end, index, value, mergeFunc);  // Update right child
            }
            tree[node].value = mergeFunc(tree[2 * node + 1].value, tree[2 * node + 2].value);  // Merge the updated values
        }
    }

    // Helper function to calculate the required size of the segment tree
    int getSegmentTreeSize(int N) {
        int size = 1;
        while (size < N) size <<= 1;  // Find the nearest power of 2 greater than N
        return size * 2;  // Size of full binary tree (including leaves and internal nodes)
    }
};

/////////////////////////////////////////////

// vector<int> mergeFunc(vector<int>& l, vector<int>& r) {
vector<int> mergeFunc(const vector<int>& l, const vector<int>& r) {
    vector<int> out(5);

    out[0] = min(l[0],r[0]);
    out[1] = max(l[1],r[1]);
    out[2] = min(l[2],r[2]);
    out[3] = max(l[3],r[3]);

    out[4] = max(l[4],r[4]);

    out[4] = max(out[4], r[1]-l[0]);
    out[4] = max(out[4], l[3]-r[2]);


    return out;
}

void solve(){
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<pair<int,int>> px(q);
    for(int i=0; i<q; i++) cin>>px[i].first>>px[i].second;

    vector<vector<int>> base(n);
    for(int i=0; i<n; i++){
        base[i]={a[i]-i,a[i]-i,a[i]+i,a[i]+i,0};
    }

    SegmentTree<vector<int>> segTree(base,  mergeFunc);
    print(a);

    int ans = segTree.getValue(0,n-1,mergeFunc)[4];
    cout<<ans<<endl;

    for(int j=0; j<q; j++){
        int i = px[j].first-1;
        a[i] = px[j].second;
        vector<int> val = {a[i]-i,a[i]-i,a[i]+i,a[i]+i,0};
        segTree.update(i, val, mergeFunc);
        ans = segTree.getValue(0,n-1,mergeFunc)[4];
        cout<<ans<<endl;
        print(a);
    }

    cout<<"pass"<<endl;

}

signed main() {
    JAI_SHRI_RAAM;
    #ifndef ONLINE_JUDGE
    initialize_debug_file();
    #endif
/////////////////////

    int t; 
    cin >> t;
    while (t--) solve();

/////////////////////
    #ifndef ONLINE_JUDGE
    close;
    #endif
    return 0;
}