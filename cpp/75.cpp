class Solution {
public:
    void sortColors(int A[], int n) {
  		for(int r=0,w=0,b=n;w<b;){
  			if(A[w]==0)
  				swap(A[r++],A[w++]);
  			else if(A[w]==2)
  				swap(A[--b],A[w]);
  			else w++;
  		}      
    }
};

// quick_sort 
// | < 0  (1)
// | = 0  (2)
// | > 0  (3)
// result is (1) (2) (3)

/* 思路就是链表的快速排序
struct Node   
{  
    int key;  
    Node* next;  
    Node(int nKey, Node* pNext)  
        : key(nKey)  
        , next(pNext)  
    {}  
};  
  
  
Node* GetPartion(Node* pBegin, Node* pEnd)  
{  
    int key = pBegin->key;  
    Node* p = pBegin;  
    Node* q = p->next;  
  
    while(q != pEnd)  
    {  
        if(q->key < key)  
        {  
            p = p->next;  
            swap(p->key,q->key);  
        }  
  
        q = q->next;  
    }  
    swap(p->key,pBegin->key);  
    return p;  
}  
  
void QuickSort(Node* pBeign, Node* pEnd)  
{  
    if(pBeign != pEnd)  
    {  
        Node* partion = GetPartion(pBeign,pEnd);  
        QuickSort(pBeign,partion);  
        QuickSort(partion->next,pEnd);  
    }  
}  

**/