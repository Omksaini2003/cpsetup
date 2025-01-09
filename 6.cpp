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

void solve(){

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