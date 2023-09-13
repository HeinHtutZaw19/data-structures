public class LinkedStack<T> implements Stack<T>{
  SLinkedList<T> list;
  public LinkedStack(){
    list = new SLinkedList<T>();
  }
  public boolean isEmpty(){
    return list.isEmpty();
  }
  public int size(){
    return list.getSize();
  }
  public void push(T data){
    list.pushFront(data);
  }
  public T pop(){
    return list.popFront();
  }
  public T top(){
    return list.topFront();
  }
  public void print(){
    list.printList();
  }

  public static void main(String[] args){
    Stack<Integer> S = new LinkedStack<Integer>();
    S.push(5);
    S.push(3);
    System.out.println(S.size());
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
    System.out.println(S.pop());
  }
}
