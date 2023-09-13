public class ArrayQueue<T> implements Queue<T>{
  private T[] arr;
  private int capacity = 10;
  private int size, index;
  public ArrayQueue(){
    arr =  (T[]) new Object[capacity];
  }
  public boolean isEmpty(){
    return size==0;
  }
  public int getSize(){
    return size;
  }
  public void enqueue(T data) throws IllegalStateException{
    if(size>capacity){
      throw new IllegalStateException("Stack is Full!");
    }
    arr[(size+index) % capacity] = data;
    size++;
  }
  public T dequeue(){
    if(isEmpty()){
      return null;
    }
    T result = arr[index];
    arr[index] = null;
    index = (index+1) % capacity;
    size--;
    return result;
  }
  public T top(){
    if(isEmpty()){
      return null;
    }
    return arr[index];
  }
  public void print(){
    for(int i=0;i<size;i++){
      System.out.print(arr[(index+i)%capacity] + " ");
    }
    System.out.println();
  }
  public static void main(String[] args){
    Queue<Integer> q = new ArrayQueue<Integer>();
    q.enqueue(5);
    q.enqueue(3);
    System.out.println(q.getSize());
    System.out.println(q.dequeue());
    System.out.println(q.isEmpty());
    System.out.println(q.dequeue());
    System.out.println(q.isEmpty());
    System.out.println(q.dequeue());
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    System.out.println(q.top());
    q.print();
  }
}
