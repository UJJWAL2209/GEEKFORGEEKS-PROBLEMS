#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    // Push the first K elements into a stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Enqueue the remaining elements
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> result = modifyQueue(q, k);

    // Print the modified queue
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}
