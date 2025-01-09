#ifndef PRINT_H
#define PRINT_H

#include <bits/stdc++.h>

using namespace std;

// Define the path for the debug output file
extern const string debug_file_path;
extern ofstream debug_file;

// // Helper macros for conditional debug printing
#ifdef ONLINE_JUDGE
#define print(...) // No-op if ONLINE_JUDGE is defined
#else
#define print(...) do { if (debug_file.is_open()) { debug_print(__VA_ARGS__); debug_file << "\n"; debug_file.flush(); } } while (0)
#endif


// Function to initialize the debug file stream
void initialize_debug_file();

// General template function for printing various data types
template <typename T>
void debug_print(const T &value);

// Specialization for double with fixed precision
template <>
void debug_print(const double &value);

// Specialization for string
template <>
void debug_print(const string &value);

// Function to print a vector
template <typename T>
void debug_print(const vector<T> &vec);

// Function to print a pair
template <typename T1, typename T2>
void debug_print(const pair<T1, T2> &p);

// Function to print a set
template <typename T>
void debug_print(const set<T> &s);

// Function to print an unordered set
template <typename T>
void debug_print(const unordered_set<T> &s);

// Function to print a map
template <typename K, typename V>
void debug_print(const map<K, V> &m);

// Function to print an unordered map
template <typename K, typename V>
void debug_print(const unordered_map<K, V> &m);

// Function to print a range of values (useful for arrays or segments)
template <typename Iter>
void debug_print(Iter begin, Iter end);

// Overloaded function to handle printing multiple arguments
template <typename T, typename... Args>
void debug_print(const T &first, const Args&... args);


#include "print_impl.h"  // Include implementation file
#endif // PRINT_H
