public class ArrayStack<E> implements Stack<E>{
  private final int capacity = 1000;
  private int index = 0;
  private E[] arr;
  public ArrayStack(){
    arr = (E[]) new Object[capacity];
  }
  public boolean isEmpty(){
    return index==0;
  }

  /*public int size(){
    return index;
  }*/
  public int size(){
    ArrayStack<E> tmp = new ArrayStack<E>();
    tmp = this;
    int size= 0;
    while(!tmp.isEmpty()){
      size++;
    }
    return size;
  }
  public void push(E data) throws IllegalStateException{
    if(index>=capacity){
      throw new IllegalStateException("Stack is Full");
    }
    arr[index++] = data;
  }
  public E pop(){
     if(index==0){
       return null;
     }
     E node = arr[index-1];
     for(int i=1;i<index;i++){
       arr[i]=arr[i-1];
     }
     index--;
     return node;
  }
  public E top(){
    return arr[index];
  }
  public void print(){
    for(int i=0;i<index;i++){
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }
  public static void main(String[] args){
    Stack<Integer> S = new ArrayStack<Integer>();
    S.push(5);
    S.push(3);
    System.out.println(S.size());

    /*System.out.println(S.size());
    System.out.println(S.pop());
    System.out.println(S.isEmpty());
    System.out.println(S.pop());
    System.out.println(S.isEmpty());
    System.out.println(S.pop());
    S.push(7);
    S.push(9);
    System.out.println(S.top());
    S.push(4);
    System.out.println(S.size());
    System.out.println(S.pop());
    S.push(6);
    S.push(8);
    System.out.println(S.pop());*/
  }
}
