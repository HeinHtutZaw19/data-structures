public interface Queue<T>{
  int getSize();
  boolean isEmpty();
  void enqueue(T data);
  T dequeue();
  T top();
  void print();
}
