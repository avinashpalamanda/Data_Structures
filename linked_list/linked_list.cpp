#include"linked_list.h"

template class list<int>;
template class list<char>;
template class list<string>;
template<class T>
void list<T>::insert_first(T key,T data){
  struct linked_list<T>* temp=new struct linked_list<T>;

  temp->key=key;
  temp->data=data;
  temp->next=head;

  head=temp;
  return;
}

template<class T>
void list<T>::insert_last(T key,T data){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* temp=new struct linked_list<T>;

  temp->data=data;
  temp->key=key;
  temp->next=NULL;
  current=head;

  if(current==NULL){
    cout<<"Inserted Data - "<<temp->data;
    head=temp;
    return;
  }

  while(current->next!=NULL){
    current=current->next;
  }
  current->next=temp;
  return;
}

template<class T>
void list<T>::insert_key(T key,T data,T key_refer){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* temp=new struct linked_list<T>;
  struct linked_list<T>* prev=new struct linked_list<T>;

  current=head;
  temp->key=key;
  temp->data=data;

  while(current!=NULL){
    if(current->key==key_refer){
      if(current==head){
        temp->next=current;
        head=temp;
        return;
      }
      else if(current->next==NULL){
        temp->next=current;
        prev->next=temp;
        return;
      }
      temp->next=current;
      prev->next=temp;
      return;
    }
    prev=current;
    current=current->next;
  }

  cout<<"Key_Refer Not found\n";
}

template<class T>
void list<T>::remove_first(){
  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }
  head=head->next;
}

template<class T>
void list<T>::remove_last(){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* prev=new struct linked_list<T>;
  current=head;

  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }

  if(current->next==NULL){
    head=NULL;
    return;
  }

  while(current->next!=NULL){
    prev=current;
    current=current->next;
  }
  prev->next=NULL;
  return;
}

template<class T>
void list<T>::remove(T key){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* prev=new struct linked_list<T>;
  current=head;

  if(current==NULL){
    cout<<"List is Empty\n";
    return;
  }
  while(current!=NULL){
    if(current->key==key){
      cout<<"Data Removed - "<<current->data<<"\n";
      if(current==head)
        head=head->next;
      else if(current->next!=NULL)
        prev->next=current->next;
      else
        prev->next=NULL;
      return;
    }
    prev=current;
    current=current->next;
  }
  cout<<"Data Not Found\n";
  return;
}

template<class T>
void list<T>::find(T key){
  struct linked_list<T>* current=new struct linked_list<T>;
  current=head;

  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }

  while(current!=NULL){
    if(current->key==key){
      cout<<"Key Found,Data - "<<current->data<<"\n";
      return;
    }
    current=current->next;
  }
  cout<<"Key Not Found\n";
}

template<class T>
void list<T>::print_list(){
  struct linked_list<T>* current=new struct linked_list<T>;
  current=head;

  if(current==NULL){
    cout<<"List is Empty";
    return;
  }

  cout<<"[";
  while(current!=NULL){
    cout<<"("<<current->key<<","<<current->data<<");";
    current=current->next;
  }
  cout<<"]\n";
}

template<class T>
void list<T>::reverse(){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* next=new struct linked_list<T>;
  struct linked_list<T>* prev=new struct linked_list<T>;
  current=head;
  prev=NULL;
  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;
  print_list();
  return;
}

template<class T>
void list<T>::sort(){
  struct linked_list<T>* current=new struct linked_list<T>;
  struct linked_list<T>* ref=new struct linked_list<T>;
  struct linked_list<T>* temp=new struct linked_list<T>;

  current=head;
  while(current!=NULL){
    temp=current->next;
    T key_1=current->key;
      while(temp!=NULL){
        if(key_1 > temp->key){
          ref->key=temp->key;
          temp->key=current->key;
          current->key=ref->key;

          ref->data=temp->data;
          temp->data=current->data;
          current->data=ref->data;
          //swap;
        }
        temp=temp->next;
      }
      current=current->next;
  }
}

template<class T>
void list<T>::count(){
  struct linked_list<T>* current=head;
  int count=0;
  while(current!=NULL){
    count++;
    current=current->next;
  }
  cout<<count<<"\n";
}
