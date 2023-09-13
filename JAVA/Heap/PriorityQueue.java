public class PriorityQueue{
  //For Min-Heap
  int[] data;
  int index = 0;
  public PriorityQueue(){

  }
  public void insert(int d){
    data[index++] = d;
  }
  private void percolateUp(){
    int i = index-1;
    while(i>0 && parent(i)>=data[i]){
      int tmp = parent(i);
      data[(i-1)/2] = data[i];
      data[i] = tmp;
      i = (i-1)/2;
    }
  }
  public void remove(){
    int i = index-1;
    int tmp = data[0];
    data[0] = data[i];
    data[i] = tmp;
    perlocateDown();
    index--;
  }
  private void perlocateDown(){
    int i = 0;
    boolean changed = false;
    do{
      int compare = (left(i)<right(i))?left(i):right(i);
      int comparedIndex = (left(i)<right(i))?2*i+1:2*i+2;
      if( compare < data[i]){
        int tmp = compare;
        data[comparedIndex] = data[i];
        data[i] = tmp;
        changed = true;
        i = comparedIndex;
      }
    }while(i<index-1 && changed);
  }
  private int parent(int i){
    return data[(i-1)/2];
  }
  private int left(int i){
    return data[2*i+1];
  }
  private int right(int i){
    return data[2*i+2];
  }
  public String toString(){
    String result = "";
    for(int i:data){
      result += i + " ";
    }
    return result;
  }
  public static void main(String[] args){
    PriorityQueue test = new PriorityQueue();
    test.insert(1);
    test.insert(2);

    System.out.println(test);
  }
}
