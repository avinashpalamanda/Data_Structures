#include "binary_tree.h"

template class binary_tree<int>;
template class binary_tree<char>;

/***********************************************************Queue****************************************************************/
template<class T>
struct tree<T>* Queue<T>::pop(){
  if(queue_head!=NULL){
    struct tree<T>* temp=queue_head->node;
    queue_head=queue_head->next;
    return temp;
  }
  return NULL;
}

template<class T>
void Queue<T>::insert_q(struct tree<T>* node){
  struct queue<T>* temp=new struct queue<T>;
  temp->node=node;
  temp->next=NULL;
  if(queue_head == NULL){
    queue_head=temp;
    queue_tail=temp;
    return;
  }
  queue_tail->next=temp;
  queue_tail=temp;
  return;
}
/***************************************************************************************************************************/

/*****************************************************Insert Tree***********************************************************/

template <class T>
void binary_tree<T>::insert(T data){
  struct tree<T>* current=new struct tree<T>;
  struct tree<T>* temp=new struct tree<T>;

  current=head;
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;

  if(head==NULL){
    head=temp;

    return;
  }

  while(1){
    if(current->data > data){
      if(current->left == NULL){
        current->left=temp;
        return;
      }
      current=current->left;
    }
    else{
      if(current->right == NULL){
        current->right=temp;
        return;
      }
      current=current->right;
    }
  }
}
/***************************************************************************************************************************/

template <class T>
void binary_tree<T>::find(T data){
  if(head==NULL){
    cout<<"Tree Empty\n";
    return;
  }
  else if(head->data==data){
    cout<<"Found\n";
    return;
  }
  struct tree<T>* current=new struct tree<T>;
  current=head;

  while(current!=NULL){
    if(current->data==data){
      cout<<"Found\n";
      return;
    }
    else if(current->data<data){
      current=current->right;
    }
    else{
      current=current->left;
    }
  }
  cout<<"Not Found\n";
  return;
}


/*********************************************************8Traversals****************************************************/
template <class T>
void binary_tree<T>::preorder_traversal(struct tree<T>* node){
  if(node!=NULL){
  cout<<node->data<<" ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
  }
}

template <class T>
void binary_tree<T>::inorder_traversal(struct tree<T>* node){
  if(node!=NULL){
  inorder_traversal(node->left);
  cout<<node->data<<" ";
  inorder_traversal(node->right);
  }
}

template <class T>
void binary_tree<T>::postorder_traversal(struct tree<T>* node){
  if(node!=NULL){
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  }
}

template <class T>
void binary_tree<T>::levelorder_traversal(struct tree<T>* node){
  if(node==NULL){
    return;
  }
  Queue<T> q;
  q.insert_q(node);
  while(1){
    if(q.queue_head == NULL || q.queue_tail == NULL){
      break;
    }
    node=q.pop();
    cout<<node->data<<" ";
    if(node->left!= NULL)
      q.insert_q(node->left);
    if(node->right!=NULL)
      q.insert_q(node->right);
  }
}
/***************************************************************************************************************************/

/*------------------------------------------------------Remove---------------------------------------------*/
template <class T>
struct tree<T>* binary_tree<T>::search_remove(T data){
  if(head==NULL){
    return NULL;
  }
  else if(head->data==data){
    return head;
  }
  struct tree<T>* current=new struct tree<T>;
  struct tree<T>* prev=new struct tree<T>;
  current=head;
  prev=NULL;

  while(current!=NULL){
    if(current->data==data){
      return prev;
    }
    else if(current->data<data){
      prev=current;
      current=current->right;
    }
    else{
      prev=current;
      current=current->left;
    }
  }
  return NULL;
}

template <class T>
struct tree<T>*binary_tree<T>::findmin(struct tree<T>* current,struct tree<T>* prev,T data){
  struct tree<T>* min=new struct tree<T>;
  min=current;
  while(1){
    if(current->left!=NULL){
      //if(min->data>current->left->data)
        min=current->left;
    }
    if(current->right==NULL && current->left==NULL)
      return min;
    if(current->right!=NULL)
      current=current->right;
    else if(current->left!=NULL)
      current=current->left;
  }
}

template <class T>
void binary_tree<T>::remove(T data){

  struct tree<T>* current=new struct tree<T>;
  if(head->data==data){
    if(head->left==NULL && head->right==NULL){
      head=NULL;
      return;
    }
    else if(head->left==NULL && head->right!=NULL){
      head=head->right;
      return;
    }
    else if(head->left!=NULL && head->right==NULL){
      head=head->left;
      return;
    }
    else{
      current=findmin(head,head,data);
      int x=current->data;
      remove(x);
      head->data=x;
      return;
    }

  }

  struct tree<T>* prev=search_remove(data);
  if(prev==NULL)
    return;
  if(prev->left->data==data){
    current=prev->left;
    if(current->left==NULL && current->right==NULL){
      prev->left=NULL;
      return;
    }
    else{
      if(current->left==NULL && current->right!=NULL){
        prev->left=current->right;
        return;
      }
      else if(current->left!=NULL && current->right==NULL){
        prev->left=current->left;
        return;
      }
      else{
        current=findmin(current,prev,data);
        int x=current->data;
        remove(x);
        prev->left->data=x;
        return;
      }
    }
  }

  else if(prev->right->data==data){
    current=prev->right;
    if(current->left==NULL && current->right==NULL){
      prev->right=NULL;
      return;
    }
    else{
      if(current->left==NULL && current->right!=NULL){
        prev->right=current->right;
        return;
      }
      else if(current->left!=NULL && current->right==NULL){
        prev->right=current->left;
        return;
      }
      else{
        current=findmin(current,prev,data);
        int x=current->data;
        remove(x);
        prev->right->data=x;
        return;
      }
    }
  }
  return;
}
/***************************************************************************************************************************/


/***************************************************Tree Length*************************************************************/
template <class T>
int binary_tree<T>::tree_length(struct tree<T>* node){
  if(node==NULL)
    return 0;
  int ldepth=tree_length(node->left);
  int rdepth=tree_length(node->right);

  if(ldepth>rdepth)
      return ldepth+1;
  return rdepth+1;
}
/***************************************************************************************************************************/
