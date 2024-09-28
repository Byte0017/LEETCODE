class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;
    MyCircularDeque(int k) {
       this->size=k;
       arr=new int[k];
       front=-1;
       rear=-1;
    }
    
    bool insertFront(int value) {
        if((front==0 && rear==size-1) || (front-rear==1)){
            //queue is full
            return false;
        }
         else{
            if(front==-1) front=rear=0; //if dq is empty then front and rear update to 0
            else if(front==0 && rear!=size-1) front=size-1;//to make circular update front to size-1
            else front--; //if front>0 then simply front--
        }
        arr[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if((front==0 && rear==size-1) || (front-rear==1)){
            //queue is full
            return false;
        }
        else{
            if(front==-1) front=rear=0; //if dq is empty then front and rear update to 0
            else if(rear==size-1 && front!=0) rear=0;//to make circular update rear to 0
            else rear++; //if rear<size-1 then simply rear++
        }
        arr[rear]=value;// update tha data into rear
        return true;
    }
    
    bool deleteFront() {
        if(front==-1){
            //dq is empty
            return false;
        }
        else{
            if(front==rear){
                //single element
                arr[front]=-1;
                front=-1;
                rear=-1;
            }
            else if(front==size-1){
                arr[front]=-1;
                front=0;//after deletion front ko aage le gye so update size-1 to 0 for circular nature
            }
            else{
                arr[front]=-1;
                front++;
            }
        }
        return true;
    }
    
    bool deleteLast() {
        if(front==-1){
            //dq is empty
            return false;
        }
        else{
            if(front==rear){
                //single element
                arr[front]=-1;
                front=-1;
                rear=-1;
            }
            else if(rear==0){
                arr[rear]=-1;
                rear=size-1;//after deletion rear ko back le gye so update 0 to size-1 for circular nature
            }
            else{
                arr[rear]=-1;
                rear--;
            }
        }
        return true;
    }
    
    int getFront() {
        if(front==-1){
            //dq empty
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int getRear() {
        if(front==-1){
            //dq empty
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front==-1) return true;
        else return false;
    }
    
    bool isFull() {
        if(front==0 && rear==size-1) return true;
        else if(rear+1==front) return true;
        else return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */