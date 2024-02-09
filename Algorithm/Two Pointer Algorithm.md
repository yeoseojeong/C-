# 투 포인터 알고리즘(Two Pointer Algorithm)


### 정의
투 포인터 알고리즘(Two Pointer Algorithm)은 배열 또는 리스트에서 두 개의 포인터를 사용하여 원하는 조건을 만족하는 구간을 찾거나 값을 계산하는 알고리즘

대개 배열이나 리스트가 정렬되어 있을 때 사용되며, 배열의 시작과 끝 지점을 가리키는 두 개의 포인터를 이용하여 특정한 조건을 만족하는 부분을 찾음

---

### 동작 방식

N칸의 1차원 배열이 있을 때, 부분 배열 중 그 원소의 합이 M이 되는 경우의 수를 구하는 것이다. 모든 경우의 수를 다 테스트 해보면 구간 합을 구간 배열로 O(1)만에 구한다고 해도 경우의 수는 O(N^2)이 된다. 따라서 문제를 풀 수 없다. N의 최대 범위가 너무 크기 때문이다.

이 문제에서 각 원소는 자연수이고 M 또한 자연수인데, 이 조건이 성립하면 사용할 수 있는 알고리즘은 다음과 같다.

포인터 2개를 준비한다. 시작과 끝을 알 수 있도록 start, end 라고 한다.
맨 처음에는 start = end = 0이며, 항상 start<=end을 만족해야 한다.
2개의 포인터는 현재 부분 배열의 시작과 끝을 가리키는 역할을 한다.
s=e일 경우 그건 크기가 0인, 아무것도 포함하지 않는 부분 배열을 뜻한다. 다음의 과정을 s < N인 동안 반복한다.

만약 현재 부분합이 M 이상이거나, 이미 e = N이면 s++
그렇지 않다면 e++
현재 부분합이 M과 같으면 결과 ++
쉽게 이해하자면, start와 end 를 무조건 증가시키는 방향으로만 변화시켜가면서 도중에 부분 배열의 합이 정확히 M이 되는 경우를 세는 것이다.

Ex) M = 5인 경우를 살펴보자.



![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/ad2755ef-ea1e-4e77-ab37-6f098b62f4cd)

초기 상태이며, 빨간색 포인터 : start, 파란색 포인터 : end이다. S : 합

end가 뒤로 움직일 때는 새로 포함한 원소를 S에 더하고, start가 뒤로 움직일 때는 새로 넘긴 원소를 S에서 빼는 식으로 현재 [start, end)의 합 S를 매번 쉽게 구할 수 있음


![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/b54e4de2-a5ad-44b1-8664-2765d1cd5024)

처음에는 이렇게 end만 증가하게 된다. S가 계속 M보다 작기 때문! 마지막엔 S>=M이 되었으므로 아래와 같다.


![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/863ee281-183e-4847-940a-c7fcaf266997)

start를 한 칸 옮겼는데, 동시에 S = 5인 경우를 만났다. 이때 결과를 1 증가시켜 준다.

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/fe135122-f38c-4a7e-bafe-ac30010172b7)

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/afcd22e0-0057-49c9-a7c4-b4819c0d82ad)


이런 식으로 포인터들이 움직이게 된다. 여기서 2번째로 S = 5인 지점을 만났으므로 결과를 1 증가시켜 준다.

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/ce2629e9-1525-4468-bcfa-ff90d38e9f8d)

그 직후, start가 1 증가하면서 start = end인 경우가 나온다.

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/c5a314a3-1269-412f-8c3f-cfab665ffd94)

계속 가다 보면 세 번째로 S = 5인 지점을 만난다.

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/783e8eac-e8c4-4138-90d7-b444549ca433)


그 이후 조건에 맞춰 포인터를 증가시키다 보면, end가 배열 끝을 가리키게 되어 더이상 증가할 수 없는 상태가 된다.

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/b90c4c18-cb77-4c92-9eeb-4f10738eb34f)

그렇게 되면 그냥 start만 증가시켜 가다가 start 역시 배열 끝에 다다르면 종료해도 되고, 그냥 그 자리에서 루프를 끝내버려도 된다. 이렇게 해서 S = 5인 경우는 3개 발견되었다.



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
