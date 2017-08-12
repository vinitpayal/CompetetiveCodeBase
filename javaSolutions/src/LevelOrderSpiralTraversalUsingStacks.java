import java.util.*;

class Node{
	public int data;
	public Node left;
	public Node right;

	public Node(int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}

}

class ActualSpiralTraversal{
	private Stack<Node> stack1;
	private Stack<Node> stack2;
	private Node rootNode;

	public ActualSpiralTraversal(Node rootNode) {
		this.stack1 = new Stack<Node>();
		this.stack2 = new Stack<Node>();
		this.rootNode = rootNode;

		this.stack1.push(rootNode);
	}

	public void printLevelOrderTraversalInSpiral(){

		while (!this.stack1.empty() || !this.stack1.empty()){
			while (!this.stack1.empty()){
				Node tempElement = this.stack1.pop();
				System.out.print(tempElement.data+" ");

				if(tempElement.right != null) this.stack2.push(tempElement.right);
				if(tempElement.left != null) this.stack2.push(tempElement.left);
			}

			while (!this.stack2.empty()){
				Node tempElement = this.stack2.pop();
				System.out.print(tempElement.data+" ");

				if(tempElement.left != null)  this.stack1.push(tempElement.left);
				if(tempElement.right != null) this.stack1.push(tempElement.right);

			}
		}
		System.out.println("\n");
	}
}

public class LevelOrderSpiralTraversalUsingStacks{

	public static void main(String [] args){
		Node rootNode = new Node(1);

		rootNode.left = new Node(2);
		rootNode.right = new Node(3);

		rootNode.left.left = new Node(7);
		rootNode.left.right = new Node(6);

		rootNode.right.left = new Node(5);
		rootNode.right.right = new Node(4);

		rootNode.left.left.left = new Node(8);
		rootNode.left.left.right = new Node(9);

		rootNode.left.left.left.left = new Node(11);
		rootNode.left.left.left.right = new Node(10);

		new ActualSpiralTraversal(rootNode).printLevelOrderTraversalInSpiral();
	}
}