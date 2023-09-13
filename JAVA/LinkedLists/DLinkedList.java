public class DLinkedList<T> {
  //head and tail sentinels
	private Node<T> header, trailer;
	private int size;
	private class Node<T>{
		T data;
		Node<T> next;
    Node<T> prev;
		public Node(T data) {
			this.data = data;
		}
	}

	public DLinkedList(){
		header = trailer = new Node<T>(null);
    header.next = trailer;
    trailer.prev  = header;
  }

  private void pushBetween(T data, Node predecessor, Node successor){
    Node<T> newNode = new Node<T>(data);
		predecessor.next = newNode;
    newNode.prev = predecessor;
    successor.prev = newNode;
    newNode.next = successor;
		size++;
  }

  private void remove(Node node){
    node.prev.next = node.next;
    node.next.prev = node.prev;
    size--;
  }

	public void pushFront(T data){
    pushBetween(data, header, header.next);
	}

	public T topFront() {
		return header.next.data;
	}

	public void popFront() {
    remove(header.next);
	}

	public void pushBack(T data) {
    pushBetween(data,trailer.prev,trailer);
	}

	public T topBack() {
		return trailer.prev.data;
	}

	public void popBack() {
    remove(trailer.prev);
	}

	public void printList() {
		Node<T> node = header.next;
		while(node!=trailer){
			System.out.print(node.data + " ");
			node = node.next;
		}
		System.out.print("\n");
	}

	public int getSize(){
		return size;
	}
	public static void main(String args[]){
		DLinkedList<Character> test = new DLinkedList<Character>();
    test.printList();
		test.pushFront(7);
		test.printList();
		test.pushBack(8);
		test.printList();
		test.printList();
		test.popFront();
		test.printList();
		test.popBack();
		test.printList();

	}

}
