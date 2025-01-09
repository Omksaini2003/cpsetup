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