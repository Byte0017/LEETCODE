class CustomStack {
public:
    int size;
    int* arr;
    int top;
    int i;
    CustomStack(int maxSize) {
        this->size=maxSize;
        arr = new int[maxSize];
        top=-1;
        i=0;
    }
    
    void push(int x) {
        if(top==size-1){
            //st is full
            return;
        }
        else if(top==-1) top=0;
        else top++;
        arr[top]=x;
    }
    
    int pop() {
      if(top>-1){
         int t=arr[top];
         arr[top]=-1;
         top--;
         return t;
      }
      return -1;   
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k;i++){
            arr[i]+=val;
            if(i==size-1) break;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */