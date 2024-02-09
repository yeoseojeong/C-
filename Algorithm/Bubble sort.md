# 거품 정렬(Bubble sort)



### 정의

인접한 두 요소를 비교하여 필요에 따라 서로 위치를 교환하는 과정을 반복하여 정렬을 수행하는 알고리즘

---

### 작동 방식

1. 배열의 첫 요소부터 시작하여 인접한 두 요소를 비교
2. 첫 번째 요소가 두 번째 요소보다 크다면, 두 요소의 위치를 서로 바꿈
3. 배열의 끝까지 이 과정을 반복
4. 이제 가장 큰 요소는 배열의 마지막 위치
5. 배열의 마지막 요소를 제외하고 위의 과정을 다시 반복
6. 배열의 크기만큼 위의 과정을 반복하면, 정렬 완료

---

``` C++
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
        cout << "Step " << i + 1 << ": ";
        
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = { 5, 1, 4, 6, 3, 2 };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted array: ";
   
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



 단계별 결과
Original array: 5 1 4 6 3 2
Step 1: 1 4 5 3 2 6
Step 2: 1 4 3 2 5 6
Step 3: 1 3 2 4 5 6
Step 4: 1 2 3 4 5 6
Step 5: 1 2 3 4 5 6
Sorted array: 1 2 3 4 5 6

```

---

### 시간 복잡도

버블 정렬은 정렬이 되어있건, 안되어있건 2개의 원소를 비교하기 때문에 최악의 경우, 최선의 경우, 평균의 경우 모두 시간 복잡도가 **O(N^2)** 으로 동일


---

### 장점

- 구현이 간단하고 소스코드가 직관적
- 이미 정렬된 데이터를 정렬할 때, 가장 빠름
- 정렬하고자 하는 배열 안에서 정렬하는 방식이므로, 다른 메모리 공간을 필요로 하지 않음
- 안정 정렬

---

### 단점


- 시간 복잡도가 최악, 최선, 평균 모두 O(N^2)이므로 비효율적
- 다른 정렬에 비해 정렬 속도가 느림
- 교환 횟수가 많음
- 역순배열을 정렬할 때 가장 느림

---
