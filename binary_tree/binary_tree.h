#include<iostream>

using namespace std;

template <class T>
struct tree{
  T data;
  struct tree<T>* left;
  struct tree<T>* right;
};

template <class T>
struct queue{
  struct tree<T>* node;
  struct queue* next;
};

template <class T>
class binary_tree{
public:
  struct tree<T>* head=NULL;

  void insert(T data);
  void find(T data);

  void preorder_traversal(struct tree<T>*);
  void inorder_traversal(struct tree<T>*);
  void postorder_traversal(struct tree<T>*);
  void levelorder_traversal(struct tree<T>*);

  int tree_length(struct tree<T>*);

  struct tree<T>* search_remove(T);
  void remove(T);
  struct tree<T>* findmin(struct tree<T>*,struct tree<T>*,T);
};

template <class T>
class Queue{
public:
  struct queue<T>* queue_head=NULL;
  struct queue<T>* queue_tail=NULL;
  void insert_q(struct tree<T>*);
  struct tree<T>* pop();
};
