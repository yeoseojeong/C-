# 투 포인터 알고리즘(Two Pointer Algorithm)

### 정의
배열 또는 리스트에서 두 개의 포인터를 사용하여 원하는 조건을 만족하는 구간을 찾거나 값을 계산하는 알고리즘
대개 배열이나 리스트가 정렬되어 있을 때 사용되며, 배열의 시작과 끝 지점을 가리키는 두 개의 포인터를 이용하여 특정한 조건을 만족하는 부분을 찾음

---

### 동작 방식
1. 배열이나 리스트가 정렬되어 있을 때, 각각의 포인터를 시작과 끝 지점에 위치시킴
2. 두 포인터가 가리키는 값을 비교하여 원하는 조건을 만족하는지 확인
3. 조건을 만족하면 필요한 작업을 수행하고, 조건을 만족하지 않으면 포인터를 이동하여 새로운 구간을 탐색
4. 모든 조건이 만족할 때까지 위의 과정을 반복

---

```C++

#include <iostream>
#include <vector>
using namespace std;

// 투 포인터 알고리즘을 사용하여 합이 target이 되는 두 요소의 인덱스를 찾는 함수
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0; // 왼쪽 포인터 초기화
    int right = nums.size() - 1; // 오른쪽 포인터 초기화

    while (left < right) {
        int sum = nums[left] + nums[right]; // 현재 두 요소의 합 계산
        if (sum == target) {
            return {left, right}; // 합이 target과 일치하는 경우 현재 인덱스 반환
        } else if (sum < target) {
            left++; // 합이 target보다 작으면 왼쪽 포인터를 오른쪽으로 이동
        } else {
            right--; // 합이 target보다 크면 오른쪽 포인터를 왼쪽으로 이동
        }
    }

    // 합이 target과 일치하는 두 요소가 없는 경우 빈 벡터 반환
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices of the two elements whose sum is equal to target:" << endl;
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No such elements found!" << endl;
    }

    return 0;
}

```

---

### 시간 복잡도

> 일반적으로 **O(n)** 의 시간 복잡도를 가짐

투 포인터 알고리즘의 시간 복잡도는 주로 배열이나 리스트의 길이에 선형적으로 의존

---

### 장점
- 투 포인터 알고리즘은 선형 시간에 작동하기 때문에 효율적
- 배열이나 리스트의 특정한 조건을 만족하는 부분을 빠르게 찾을 수 있음

---

### 단점
- 투 포인터 알고리즘은 주로 정렬된 배열이나 리스트에 대해 사용되므로, 정렬되어 있지 않은 경우에는 사용하기 어려움
- 투 포인터 알고리즘은 모든 상황에 적용할 수 없으며, 특정한 조건이 필요한 경우가 있음






## 참고

- [투 포인터(Two Pointers Algorithm), 슬라이딩 윈도우(Sliding Window) (수정: 2019-09-09)](https://m.blog.naver.com/kks227/220795165570)
