# 힙 정렬(Heap Sort)

### 정의
힙 정렬(Heap Sort)은 완전 이진 트리(Complete Binary Tree)를 기반으로 하는 정렬 알고리즘

특정한 상태를 만족하는 힙(Heap) 자료구조를 사용하여 정렬

---

### 동작 방식
1. 주어진 배열을 힙 자료구조로 변환
2. 최대 힙(Max Heap)을 구성하거나 최소 힙(Min Heap)을 구성
3. 최상위 노드(루트 노드)를 루트로부터 제거하고 이를 배열의 마지막 요소와 교환
4. 배열의 크기를 줄이고 다시 힙 속성을 유지하도록 재구성
5. 위의 과정을 반복하여 정렬이 완료될 때까지 진행

---

### <Heap Sort가 유용할 때>

가장 크거나 가장 작은 값을 구할 때 :

최소 힙 or 최대 힙의 루트 값이기 때문에 한 번의 힙 구성을 통해 구하는 것이 가능

최대 k 만큼 떨어진 요소들을 정렬할 때 :

삽입 정렬보다 더욱 개선된 결과를 얻어낼 수 있음

---

```C++

#include <iostream>
#include <vector>
using namespace std;

// 힙을 구성하는 함수
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i; // 최대 힙의 루트 인덱스 설정
    int left = 2 * i + 1; // 왼쪽 자식 노드 인덱스
    int right = 2 * i + 2; // 오른쪽 자식 노드 인덱스

    // 왼쪽 자식이 루트보다 크면 largest를 왼쪽 자식으로 변경
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 루트보다 크면 largest를 오른쪽 자식으로 변경
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // largest가 변경되었을 경우 해당 노드와 교환하고 재귀적으로 힙을 구성
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 힙 정렬 함수
void heapSort(vector<int>& arr) 
{
    int n = arr.size();

    // 최대 힙 구성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 힙에서 하나씩 요소를 추출하여 정렬
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // 최대 힙의 루트를 현재 범위의 마지막 요소와 교환
        heapify(arr, i, 0); // 남은 요소들을 힙으로 재정렬
    }
}

int main() 
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

```

---

### 시간 복잡도
> 최선, 평균, 최악의 경우 모두 **O(N log N)**
  
이는 힙을 구성하는 과정에서 log n의 시간이 걸리고, 각 요소를 힙에서 제거하고 재구성하는 과정에서 n번의 비교 및 이동이 발생

---

### 장점
- 평균적으로 빠른 속도
- 안정적인 정렬 알고리즘 중 하나
- 추가 메모리가 필요하지 않음

---

### 단점
- 불안정한 정렬 알고리즘 중 하나
- 배열의 크기가 클 경우에는 다른 정렬 알고리즘보다 느림

.
