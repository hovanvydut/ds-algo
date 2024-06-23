#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct Interval {
    int start;
    int end;
    
    Interval(int s, int e) : start(s), end(e) {}
};

struct Node {
    Interval interval;
    int max_end;
    Node* left;
    Node* right;
    
    Node(Interval i) : interval(i), max_end(i.end), left(nullptr), right(nullptr) {}
};

class ITTree {
private:
    Node* root;

    Node* buildTree(vector<Interval>& intervals, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        Node* node = new Node(intervals[mid]);
        
        node->left = buildTree(intervals, start, mid - 1);
        node->right = buildTree(intervals, mid + 1, end);
        
        if (node->left) {
            node->max_end = max(node->max_end, node->left->max_end);
        }
        if (node->right) {
            node->max_end = max(node->max_end, node->right->max_end);
        }
        
        return node;
    }
    
    void queryHelper(Node* node, int ci, int di, vector<Interval>& result) {
        if (node == nullptr) return;
        
        vector<Node*> stack;
        stack.push_back(node);
        
        while (!stack.empty()) {
            Node* current = stack.back();
            stack.pop_back();
            
            if (current->interval.start <= di && current->interval.end >= ci) {
                if (current->interval.start >= ci && current->interval.end <= di) {
                    result.push_back(current->interval);
                }
                if (current->left) {
                    stack.push_back(current->left);
                }
                if (current->right) {
                    stack.push_back(current->right);
                }
            } else if (current->left && current->left->max_end >= ci) {
                stack.push_back(current->left);
            }
        }
    }
    
public:
    ITTree(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        root = buildTree(intervals, 0, intervals.size() - 1);
    }
    
    vector<Interval> query(int ci, int di) {
        vector<Interval> result;
        queryHelper(root, ci, di, result);
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<Interval> intervals;
    intervals.reserve(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        intervals.push_back(Interval(a, b));
    }
    
    ITTree intervalTree(intervals);
    
    ll res = 0;
    for (int i = 1; i <= m; ++i) {
        int ci, di;
        scanf("%d %d", &ci, &di);
        
        vector<Interval> result = intervalTree.query(ci, di);
        res = max(res, static_cast<ll>(result.size()));
    }

    printf("%lld\n", res);
    
    return 0;
}