# 선택 정렬(Selection Sort)

### 정의
선택 정렬(Selection Sort)은 가장 간단한 정렬 알고리즘 중 하나로, 주어진 배열에서 가장 작은 값을 찾아 첫 번째 위치로 옮기고, 그 다음으로 작은 값을 찾아 두 번째 위치로 옮기는 과정을 반복하여 전체 배열을 정렬하는 알고리즘

---

### 작동 방식
1. 주어진 배열에서 최솟값을 찾음
2. 최솟값을 배열의 맨 앞 요소와 교환
3. 배열의 나머지 부분에서 최솟값을 찾아 그 다음 위치에 옮김
4. 위의 과정을 반복하여 정렬이 완료될 때까지 진행합



1단계 => n개의 원소 비교

2단계 => n-1개의 원소 비교

3단계 => n-2개의 원소 비교

...

를 하여 비교 횟수는

n(n-1)/2가 됨

---

### 시간 복잡도
> 최선, 평균, 최악의 경우 모두 **O(n^2)**
> 
이는 배열을 순회하면서 최솟값을 찾고, 해당 값을 배열의 맨 앞으로 이동시키는 과정에서 발생하는 비교 횟수에 기반

---
```C++

#include <iostream>
#include <vector>
using namespace std;

// 선택 정렬 함수
void selectionSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        // 최솟값을 찾기
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // 최솟값을 현재 위치로 이동
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() 
{
    vector<int> arr = { 2, 6, 4, 1, 3, 5 };

    cout << "Original array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(arr);

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
### 장점
- 구현이 간단하고 이해하기 쉬움
- 작은 크기의 배열에서는 효율적
- 정렬된 배열이 아니더라도 동작

---

### 단점
- 평균 및 최악의 경우에는 비효율적
- 배열의 크기가 큰 경우에는 다른 정렬 알고리즘에 비해 느림


