# 힙 (Heap)

### 정의
- 힙(Heap)은 완전 이진 트리(Complete Binary Tree)의 일종으로, 부모 노드와 자식 노드 간의 대소 관계가 정해져 있는 자료 구조
- 일반적으로 힙은 최대 힙(Max Heap)과 최소 힙(Min Heap)으로 구분



### 최대 힙(Max Heap)과 최소 힙(Min Heap)
- **최대 힙**: 부모 노드는 항상 자식 노드보다 크거나 같은 값을 가짐
- **최소 힙**: 부모 노드는 항상 자식 노드보다 작거나 같은 값을 가짐



### 주요 연산
1. **삽입(Insertion)**: 힙에 원소를 추가합니다. 추가된 원소는 힙의 규칙에 따라 적절한 위치에 삽입
2. **삭제(Deletion)**:
    - 최대 힙의 경우, 최대값(루트 노드)를 삭제
    - 최소 힙의 경우, 최소값(루트 노드)를 삭제
3. **힙 구성(Heapify)**: 주어진 배열을 힙으로 구성합니다. 힙 구조를 유지하면서 배열을 정렬하는 데 사용
4. **최대값 또는 최소값 반환**: 최대 힙에서는 최대값(루트 노드), 최소 힙에서는 최소값(루트 노드)을 반환



### 활용
- 힙은 우선순위 큐(Priority Queue)를 구현하는 데 자주 사용
- 힙 정렬(Heap Sort) 알고리즘은 배열을 힙으로 구성한 뒤 루트 노드를 반복적으로 삭제하여 정렬하는 알고리즘



### 시간 복잡도
삽입 : O(logN)
삭제 : O(logN)


![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/47db9c8c-5ee8-4b68-b2c6-9aebfe8f2345)

---

### 부모 노드와 자식 노드의 관계

**왼쪽 자식 index :** (부모 index) * 2

**오른쪽 자식 index :** (부모 index) * 2 + 1

**부모 index :** (자식 index) / 2




### 힙의 삽입

힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 삽입

새로운 노드를 검사해서 부모 노드와 교환


### 힙의 삭제

최대 힙에서 최대값은 루트 노드이므로 루트 노드가 삭제 (최대 힙에서 삭제 연산은 최대값 요소를 삭제하는 것이다.)

삭제된 루트 노드에서는 힙의 마지막 노드를 가져옴

힙을 재구성 

```C++

#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // 부모 노드 인덱스를 반환하는 함수
    int parent(int i) { return (i - 1) / 2; }

    // 왼쪽 자식 노드 인덱스를 반환하는 함수
    int leftChild(int i) { return (2 * i + 1); }

    // 오른쪽 자식 노드 인덱스를 반환하는 함수
    int rightChild(int i) { return (2 * i + 2); }

    // 힙을 재구성하여 최대 힙 속성 유지하는 함수
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // 힙을 재구성하여 최대 힙 속성 유지하는 함수
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap.size() && heap[left] > heap[i])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // 삽입 연산
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    // 최대값 반환 및 삭제 연산
    int extractMax() {
        if (heap.empty()) {
            cerr << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // 힙의 크기 반환
    int size() { return heap.size(); }

    // 힙이 비어 있는지 확인하는 함수
    bool isEmpty() { return heap.empty(); }
};

int main() {
    MaxHeap maxHeap;

    // 최대 힙에 데이터 추가
    maxHeap.insert(10);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(50);
    maxHeap.insert(40);

    cout << "최대값: " << maxHeap.extractMax() << endl;
    cout << "최대값: " << maxHeap.extractMax() << endl;

    return 0;
}

```
