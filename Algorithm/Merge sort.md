# 병합 정렬(Merge Sort)

### 정의
병합 정렬(Merge Sort)은 분할 정복(divide and conquer) 알고리즘의 하나로, 주어진 배열을 반으로 나누고 각각을 재귀적으로 정렬한 후 병합하여 전체를 정렬하는 알고리즘입니다.

---

### 로직
1. 주어진 배열을 반으로 나눔
2. 각 배열을 재귀적으로 정렬
3. 정렬된 배열을 병합하여 하나의 정렬된 배열로 만듦
4. 최종적으로 정렬된 배열을 반환

---

```C++
#include <iostream>
#include <vector>
using namespace std;

// 두 개의 정렬된 배열을 합병하는 함수
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // 왼쪽 배열의 크기
    int n2 = right - mid; // 오른쪽 배열의 크기

    // 임시 배열 생성
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // 왼쪽과 오른쪽 배열에 값 복사
    for (int i = 0; i < n1; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // 두 배열을 합병하여 정렬된 결과를 원래 배열에 저장
    int i = 0, j = 0, k = left;
   
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // 남은 요소들 복사
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// 병합 정렬 함수
void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // 중간 지점 계산

        // 왼쪽과 오른쪽 부분 배열 정렬
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 정렬된 두 배열 합병
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = { 6, 4, 1, 2, 3, 5 };
    
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

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
> 최선, 평균, 최악의 경우 모두 **O(n log n)**

이는 배열을 반으로 나누고 병합하는 과정에서 발생하는 비교 횟수에 기반

---

### 장점
- 안정적인 정렬 알고리즘으로, 동일한 값에 대해서는 입력 순서가 유지
- 대부분의 경우 효율적인 정렬 알고리즘
- 병합 정렬은 배열을 반으로 나누기 때문에  LinkedList와 같은 순차적인 데이터 구조에서도 효율적으로 작동

---

### 단점
- 추가적인 메모리가 필요함
- 배열을 반으로 나누고 재귀적으로 정렬하기 때문에 원래 배열과는 별도의 메모리를 사용
- 레코드의 크기가 큰 경우에는 이동 횟수가 많으므로 상대적으로 다른 정렬 알고리즘에 비해 조금 느림

---



