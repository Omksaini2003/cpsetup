#include <bits/stdc++.h>
using namespace std;

#ifndef PRINT_H
#define PRINT_H

#define JAI_SHRI_RAAM ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Define the path for the debug output file
const string debug_file_path = ".\\files\\debug.txt";
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

void solve(){
    print(1);
    cout<<"hello";
}

int main() {
    JAI_SHRI_RAAM;
    #ifndef ONLINE_JUDGE
    initialize_debug_file();    
    #endif
/////////

    int t; 
    cin>>t;
    while(t--) solve();


////////// Close debug file
    #ifndef ONLINE_JUDGE
    close;
    #endif
    return 0;
}
