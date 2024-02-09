# 퀵 정렬(Quick Sort)

### 정의
퀵 정렬(Quick Sort)은 분할 정복(divide and conquer) 알고리즘

평균적으로 가장 빠른 정렬 알고리즘 중 하나

주어진 배열을 기준 원소(pivot)를 중심으로 작은 요소는 pivot의 왼쪽, 큰 요소는 오른쪽으로 분할하고 각 부분 배열에 대해 재귀적으로 정렬하는 알고리즘

---

### 동작 방식
1. 배열에서 하나의 원소를 선택하여 기준 원소(pivot)로 정함
2. pivot을 기준으로 배열을 분할합니다. pivot보다 작은 요소는 pivot의 왼쪽에, 큰 요소는 pivot의 오른쪽에 위치하도록 함
3. 각 부분 배열에 대해 재귀적으로 위의 과정을 반복
4. 부분 배열의 크기가 1 이하가 될 때까지 분할과 정렬을 진행

---

```C++

#include <iostream>
#include <vector>
using namespace std;

// 퀵 정렬 함수
void quickSort(vector<int>& arr, int left, int right)
{
    if (left >= right) return; // 기저 조건: 부분 배열의 크기가 1 이하일 때

    int pivot = arr[(left + right) / 2]; // 중간 지점의 원소를 기준으로 선택
    int i = left, j = right;

    // pivot을 기준으로 배열을 분할
    while (i <= j) 
    {
        while (arr[i] < pivot) i++; // pivot보다 작은 원소 찾기
        while (arr[j] > pivot) j--; // pivot보다 큰 원소 찾기
        if (i <= j) 
        
        {
            swap(arr[i], arr[j]); // 원소 교환
            i++;
            j--;
        }
    }

    // 분할된 두 부분 배열에 대해 재귀적으로 퀵 정렬 수행
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main()
{
    vector<int> arr = { 7, 9, 12, 10, 8, 11};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

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
> 평균 및 최선의 경우(Best cases) : **O(nlog₂n)**
- 배열을 반으로 나누는 과정이 log n번 발생하고, 각 분할에서 n번의 비교 및 이동이 발생
> 최악의 경우(Worst cases) : **O(n^2)**
- pivot을 선택하는 방식에 따라 배열이 균등하게 분할되지 않을 때 발생

---

### 장점
- 평균적으로 빠른 속도
- 추가 메모리가 필요하지 않음

---

### 단점
- 최악의 경우에는 성능이 저하될 수 있음
- 구현이 복잡할 수 있음


