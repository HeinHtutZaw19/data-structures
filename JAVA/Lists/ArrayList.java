public class ArrayList<E> {
  E[] data;
  int size = 0;

  public ArrayList(int capacity){
    this.data = (E[]) new Object[capacity];
  }
  public void grow(){
    int oldcapacity = data.length;
    int newcapacity = oldcapacity + (oldcapacity>>1);
    E[] oldData = data;
    data = (E[])new Object[newcapacity];
    System.arraycopy(oldData,0,data,0,oldcapacity);
  }
  public boolean add(E e){
    if(size==data.length){
      grow();
    }
    data[size++] = e;
    return true;
  }
  public void add(int index, E e){
    //RANGE CHECK
    Object[] elementData;
    if(size==data.length){
      System.out.println("here");
      grow();
    }
    System.arraycopy(data, index, data, index+1, size-index);
    data[index] = e;
    size++;
  }
  public E remove(int index){
    if(index<0 || index>size){
      throw new IndexOutOfBoundsException();
    }

    E oldData = data[index];
      //there are more numbers of elements in array
    if(size-1>index){
      System.arraycopy(data, index+1, data, index, size-index);
    }
    data[size-1] = null;
    size--;
    return oldData;
}
  public void print(){
    for(E d: data){
      System.out.print(d);
    }
  }

  public static void main(String[] args){
    ArrayList<Integer> test = new ArrayList<Integer>(4);
    test.add(1);
    test.add(2);
    test.add(1);
    test.add(2,9);
    test.add(3);

    //test.print();
    System.out.println("REMOVED" + test.remove(0));
    test.print();
  }
}
