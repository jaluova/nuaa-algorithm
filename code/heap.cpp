#include <bits/stdc++.h>
using namespace std;

void sift_up(vector<int>& a, int i, int n) {
    while (i > 1) {
        if (a[i] > a[i / 2]) {
            swap(a[i], a[i / 2]);
            i = i / 2;
        } else {
            break;
        }
    }
}

void sift_down(vector<int>& a, int i, int n) {
    while (i * 2 <= n) {
        i = i * 2;
        if (i + 1 <= n && a[i + 1] > a[i]) {
            i = i + 1;
        }
        if (a[i / 2] < a[i]) {
            swap(a[i / 2], a[i]);
        } else {
            break;
        }
    }
}

void insert(vector<int>& a, int x, int& n) {
    n = n + 1;
    a[n] = x;
    sift_up(a, n, n);
}

void remove(vector<int>& a, int i, int& n) {
    int x = a[n];
    int y = a[i];
    a[i] = x;
    n = n - 1;
    if (x >= y) {
        sift_up(a, i, n);
    } else {
        sift_down(a, i, n);
    }
}

int remove_max(vector<int>& a, int& n) {
    int x = a[1];
    remove(a, 1, n);
    return x;
}

void make_heap(vector<int>& a, int& n) {
    for (int j = n / 2; j >= 1; --j) {
        sift_down(a, j, n);
    }
}

void heap_sort(vector<int>& a, int n) {
    make_heap(a, n);
    for (int j = n; j >= 1; --j) {
        swap(a[1], a[j]);
        sift_down(a, 1, j - 1);
    }
}

int main() {
    vector<int> heap(100);
    vector<int> a = {3, 4, 2, 1, 5};
    int n = a.size();
    for (int i = 1; i <= a.size(); ++i) {
        heap[i] = a[i - 1];
    }
    heap_sort(heap, n);
    for (int i = 1; i <= n; ++i) {
        cout << heap[i] << ' ';
    }
    cout << endl;
    cout << n << endl;
}