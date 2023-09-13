public class SLinkedList<T> implements Cloneable {
	private Node<T> headPointer, tailPointer;
	private int size;
	private class Node<T>{
		T data;
		Node<T> next;
		public Node(T data) {
			this.data = data;
		}
	}

	public SLinkedList(T data){
		headPointer = tailPointer = new Node<T>(data);
	}
	public SLinkedList(){
	}

	public void pushFront(T data){
		Node<T> newNode = new Node<T>(data);
		if(headPointer == null) {
			headPointer = newNode;
			tailPointer = newNode;
		}
		else {
			newNode.next = headPointer;
			headPointer = newNode;
		}
		size++;
	}

	public T topFront() {
		return headPointer.data;
	}

	public T popFront() {
		if(headPointer == null) {
			return null;
		}
		else {
			T result = headPointer.data;
			headPointer = headPointer.next;
			size--;
			return result;
		}
	}

	//append(data)
	public void pushBack(T data) {
		Node<T> newNode = new Node<T>(data);
		if(headPointer==null) {
			headPointer = newNode;
			tailPointer = newNode;
		}
		else {
			tailPointer.next = newNode;
			tailPointer = newNode;
			tailPointer.next = null;
		}
		size++;
	}

	public T topBack() {
		return tailPointer.data;
	}

	public T popBack() {
		if(headPointer == null) {
			return null;
		}
		else {
			T result = tailPointer.data;
			Node<T> node = headPointer;
			if(node==tailPointer){
				headPointer = tailPointer = null;
				size--;
				return result;
			}
			while(node.next != tailPointer) {
				node = node.next;
			}
			node.next = null;
			tailPointer = node;
			size--;
			return result;
		}
	}

	public void printList() {
		Node<T> node = headPointer;
		while(node!=null){
			System.out.print(node.data + " ");
			node = node.next;
		}
		System.out.print("\n");
	}

	public boolean equals(Object obj){
			if(obj == null){
				return false;
			}
			if(getClass() != obj.getClass()){
				return false;
			}
			SLinkedList list = (SLinkedList) obj;
			if(size != list.size) {
				return false;
			}
			Node nodeA = headPointer;
			Node nodeB = list.headPointer;
			while(nodeA != null){
				if(nodeA.data != nodeB.data ){
					return false;
				}
				nodeA = nodeA.next;
				nodeB = nodeB.next;
			}
			return true;
	}

	public int getSize(){
		return size;
	}

	public SLinkedList<T>clone() throws CloneNotSupportedException{
		SLinkedList<T> other = (SLinkedList<T>)super.clone();
		if(size>0){
			other.headPointer = new Node<T>(headPointer.data);
			Node<T> nodeA = headPointer;
			Node<T> nodeB = other.headPointer;
			while(nodeA.next!=null){
				Node<T> newNode = new Node<T>(nodeA.next.data);
				nodeB.next = newNode;
				nodeA = nodeA.next;
				nodeB = nodeB.next;
			}
		}
		return other;
	}

	public static void main(String args[]){
		SLinkedList<Integer> test = new SLinkedList<Integer>(6);
		test.pushBack(7);
		test.pushBack(8);

		SLinkedList<Integer> test2 = new SLinkedList<Integer>(6);
		test2.pushBack(7);
		test2.pushBack(8);

		System.out.println(test.equals(test2));

		try{
			SLinkedList<Integer> cl = test.clone();
			test.printList();
			System.out.println(cl.equals(test));

		}
		catch(Exception e){
			System.out.println("ERROR");
		}
	}

}
