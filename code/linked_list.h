template<typename t>
class node
{
  public:
    node(t value, node* next)
    {
      this->value=value;
      this->next=next;
    }
    t value;
    node<t>* next;
    ~node()
    {
      delete next;
    };
};

template<typename t>
class llist
{
  public:
    llist()
    {
      head=nullptr;
    }
    
    ~llist()
    {
      delete head;
    }
    
    void append(t value)
    {
      if (!head)
      {
        head=new node<t>(value, nullptr);
        return;
      }
      node<t>* node_ptr=head;
      while (node_ptr->next)
      {
        node_ptr=node_ptr->next;
      }
      node_ptr->next=new node<t>(value, nullptr);
      length++;
    }

    void to_arr(t arr[])
    {
      node<t>* node_ptr=head;
      int i=0;
      while(node_ptr)
      {
        arr[i]=node_ptr->value;
        i++;
        node_ptr=node_ptr->next;
      }
    }

    int length=0;
    node<t>* head=nullptr;
};
