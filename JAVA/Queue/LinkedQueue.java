public class LinkedQueue<T> implements Queue<T>{
  private SLinkedList<T> list;
  public LinkedQueue(){
    list = new SLinkedList<T>();
  }
  public int getSize(){
    return list.getSize();
  }
  public boolean isEmpty(){
    return list.isEmpty();
  }
  public void enqueue(T data){
    list.pushBack(data);
  }
  public T dequeue(){
    return list.popFront();
  }
  public T top(){
    return list.topFront();
  }
  public void print(){
    list.printList();
  }

  public static void main(String[] args){
    Queue<Integer> q = new LinkedQueue<Integer>();
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
