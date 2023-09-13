public interface List<E>{
  int size();
  boolean isEmpty();
  E get();
  boolean set(i,e) throws IndexOutOfBoundException;
  void add(i,e) throws IndexOutOfBoundException;
  E remove(i) throws IndexOutOfBoundException;
}
