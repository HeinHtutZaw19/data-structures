public class CLinkedList<T> {
	private Node<T> tailPointer;
	private int size=0;
	private class Node<T>{
		T data;
		Node<T> next;
		public Node(T data) {
			this.data = data;
		}
	}

	public CLinkedList(T data){
		tailPointer = new Node<T>(data);
		tailPointer.next = tailPointer;
		size++;
	}

	public void pushFront(T data){
		Node<T> newNode = new Node<T>(data);
		if(tailPointer == null) {
			tailPointer = newNode;
			tailPointer.next = tailPointer;
		}
		else {
			newNode.next = tailPointer.next;
			tailPointer.next = newNode;
		}
		size++;
	}

	public T topFront() {
		return tailPointer.next.data;
	}

	public void popFront() {
		if(tailPointer == null) {

		}
		else {
			tailPointer.next = tailPointer.next.next;
			size--;
		}
	}

	//append(data)
	public void pushBack(T data) {
		pushFront(data);
		tailPointer = tailPointer.next;
	}

	public T topBack() {
		return tailPointer.data;
	}

	public void popBack() {
		if(tailPointer == null) {

		}
		else {
			Node<T> node = tailPointer.next;
			while(node.next != tailPointer) {
				node = node.next;
			}
			node.next = tailPointer.next;
			tailPointer = node;
			size--;
		}
	}

	public void printList() {
		Node<T> node = tailPointer.next;
		//linkhopping
		do{
			System.out.print(node.data + " ");
			node = node.next;
		}	while(node!=tailPointer.next);
		System.out.println();
	}


	public int getSize(){
		return size;
	}

  public void rotate(){
    if(tailPointer!=null){
      tailPointer=tailPointer.next;
    }
  }
	public static void main(String args[]){
		CLinkedList<Integer> test = new CLinkedList<Integer>(6);
		test.printList();
		test.pushFront(7);
		test.printList();
		test.pushBack(8);
		test.printList();
		test.rotate();
		test.printList();
		test.popFront();
		test.printList();
		test.popBack();
		test.printList();
	}

}
