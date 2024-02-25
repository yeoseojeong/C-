# 이진 탐색 트리 (Binary Search Tree, BST)

이진 탐색(binary search) ✚ 연결 리스트(linked list)를 결합한 이진트리

이진 탐색 트리는 각 노드가 최대 두 개의 자식 노드를 가지는 트리 자료 구조

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/af888cf3-0fb4-4a92-85d7-1b869074a323)


## 특징


노드의 왼쪽 하위 트리에는 노드의 키보다 작은 키가있는 노드만 포함

노드의 오른쪽 하위 트리에는 노드의 키보다 큰 키가있는 노드 만 포함

왼쪽 및 오른쪽 하위 트리도 각각 이진 검색 트리여야함

중복된 키를 허용하지 않음

### 기본 연산

#### 검색 (Search)
이진 탐색 트리에서 특정 요소의 위치를 찾음


1. 루트에서 시작
2. 검색 값을 루트와 비교하여 루트보다 작으면 왼쪽에 대해 재귀하고 크다면 오른쪽으로 재귀
3. 일치하는 값을 찾을 때까지 절차를 반복
4. 검색 값이 없으면 null을 반환


![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/1df8dcbd-4824-401b-af40-8c80f1b7604e)

```C

struct node* search (struct node* root, int key)
{
// root값이 null이거나 key값과 같다면 종료한다.
  if (root == NULL || root->data == key)
    return root;

// key가 root->data 보다 작으면 왼쪽 서브트리로 재귀한다.
  if (root->data > key)
    return search(root->left, key)

// key가 root->data 보다 크면 오른쪽 서브트리로 재귀한다. 
  return search(root->left, key)
}

```


#### 삽입

이진 검색트리에 데이터를 삽입하는 작업 (중복은 형용하지않음)

새 키는 항상 리프 노드에 삽입

1.Root에서 시작
2.삽입 값을 루트와 비교합니다. 루트보다 작으면 왼쪽으로 재귀하고 크다면 오른쪽으로 재귀
3.리프 노드에 도달한 후 노드보다 크다면 오른쪽에 작다면 왼쪽에 삽입

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/9153281f-6d43-4da3-9668-0062b93e1c0a)

```C

struct node {
  int data;
  struct node *left, *right;
};

// 새로운 BST node 생성
struct node* newNode (int key) {
  struct node* temp = (struct *node)malloc(sizeof(struct node));
  temp->data = key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node* insert(struct node *root, int key) {
  // 트리가 비어있다면 새로운 노드를 만든다.
  if (root == NULL)
    return newNode(key);

  // 루트값보다 크면 오른쪽으로 재귀하고, 작다면 왼쪽으로 재귀한다.
  if (key > root->data)
    root->right = insert(root->right, key);
  else if (key < root->data)
    root->left = insert(root->left, key); 
  // 같은 값을 가지고 있는 경우 삽입을 하지 않는다.(중복 불가)
  return root;
}

```

#### 삭제


이진 검색 트리에서 특정 노드를 삭제

이진 검색 트리에서 노드를 삭제하는 세 가지 상황이 있음

**1. 삭제할 노드가 리프노드인 경우**

이 경우 노드를 삭제하기만 하면 됨

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/94809047-40f1-41c7-adc4-1a2722073ef3)


**2.삭제할 노드에 자식이 하나만 있는 경우**

노드를 삭제하고 자식 노드를 삭제된 노드의 부모에 직접 연결

![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/6527c7f0-517d-4c69-8bff-6fc4a021d337)

**삭제할 노드에 자식이 둘 있는 경우**

자식이 둘 있는 경우 successor 노드를 찾는 과정이 추가

 

#### surrcessor 노드란?

right subtree에 최소값

즉, inorder 순회에서 다음 노드를 말함

1. 삭제할 노드를 찾음
2. 삭제할 노드의 successor 노드를 찾음
3. 삭제할 노드와 successor 노드의 값을 바꿈
4. successor 노드를 삭제


![image](https://github.com/yeoseojeong/cpp-study/assets/121150215/7271d629-0bc5-4df0-8196-4da8f1d02ef1)


```C

struct node {
  int data;
  struct node *left, *right;
};

// 노드의 최소값을 가져오는 함수
struct node* minValueNode (struct node* node){
  struct node* current = node;
  
  while(current && current->left != NULL)
    current = current->left;

  return current;
}

struct node* deleteNode (struct node* root, int key) {
// base case  
  if(root == NULL)
    return root;
// 삭제할 노드를 찾는다.    
  if (key < root->data)
    root->left = deleteNode(root->left,key);

  else if (key > root->data)
    root->right = deleteNode(root->right, key);

// 삭제할 노드를 찾은 경우
  else {
    struct node* temp;
// 노드에 자식이 하나 이거나 없는 경우
    if (root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    }

// 노드에 자식이 둘 있는 경우
// successor 노드를 찾는다.
    temp = minValueNode(root->right);
// successor 노드 키와 삭제할 노드 키를 바꾼다.
    root->key = temp->key;
// 노드를 삭제한다.
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

```
