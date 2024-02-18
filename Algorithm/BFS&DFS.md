# BFS&DFS

BFS(너비 우선 탐색)와 DFS(깊이 우선 탐색)는 그래프 탐색 알고리즘

그래프의 모든 노드를 방문하는 방법

---

### 너비 우선 탐색 (BFS)

#### 작동 방식
1. 시작 노드를 큐에 넣고 방문 표시
2. 큐가 비어 있지 않은 동안 다음 단계 반복
   - 큐에서 하나의 노드를 꺼냄
   - 해당 노드의 이웃 노드 중에서 방문하지 않은 노드를 모두 큐에 넣고 방문 표시

#### 특징:
- 시작 노드에서 가까운 노드부터 탐색
- 최단 경로를 찾는 데에 유용
- 큐를 사용하므로 반복문을 통해 탐색을 수행

----


```C++

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); ++i) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 7; // 그래프의 정점 수
    vector<vector<int>> graph(n);

    // 그래프 초기화
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5, 6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};

    cout << "BFS traversal starting from node 0: ";
    bfs(graph, 0);

    return 0;
}

```

---

### 깊이 우선 탐색 (DFS)

#### 작동 방식:
1. 시작 노드를 스택 또는 재귀 호출을 사용하여 방문 표시
2. 현재 노드와 연결된 모든 미방문 이웃 노드를 재귀적으로 방문

#### 특징:
- 한 경로를 완전히 탐색한 후 다음 경로로 넘어감
- 스택을 사용하거나 재귀 호출을 통해 구현할 수 있음
- 깊이 우선 탐색은 더 깊은 단계로 진행하므로 더 많은 메모리를 사용할 수 있음

---

```C++


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;

            for (int i = graph[node].size() - 1; i >= 0; --i) {
                int neighbor = graph[node][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int n = 7; // 그래프의 정점 수
    vector<vector<int>> graph(n);

    // 그래프 초기화
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5, 6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};

    cout << "DFS traversal starting from node 0: ";
    dfs(graph, 0);

    return 0;
}


```

---

### 비교

**탐색 방식**

BFS는 너비 우선으로 탐색하고, DFS는 깊이 우선으로 탐색

**메모리 사용**: 

BFS는 큐를 사용하므로 노드의 수에 따라 메모리 사용량이 증가

DFS는 스택 또는 재귀 호출을 사용하므로 메모리 사용량이 더 적을 수 있음

**시간 복잡도**

그래프의 구조에 따라 다를 수 있지만 일반적으로 BFS는 더 빠른 속도를 가질 수 있음

**적합한 문제**

BFS는 최단 경로 문제나 최단 거리를 구하는 데 적합하고, DFS는 그래프에서 사이클을 찾거나 모든 경로를 탐색하는 데 유용

