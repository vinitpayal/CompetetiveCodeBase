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

class BinaryTree{
    public Node rootNode;

    public BinaryTree(Node rootNode) {
        this.rootNode = rootNode;
    }

    public BinaryTree() {
    }

    public void printInOrder(Node rootNode){
        if(rootNode == null) return;

        printInOrder(rootNode.left);
        System.out.print(rootNode.data+" ");
        printInOrder(rootNode.right);

    }
}

class ActualWorker{
    public Node rootNode;

    public ActualWorker(Node rootNode) {
        this.rootNode = rootNode;
    }

    public void mirrorBinaryTree(Node currNode){
        if(currNode == null) return;

        Node temNode;

        temNode = currNode.left;

        currNode.left = currNode.right;
        currNode.right = temNode;

        mirrorBinaryTree(currNode.left);
        mirrorBinaryTree(currNode.right);
    }
}

public class MirrorOfBinaryTree{
    public static void main(String[] args) {
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

        Node rootNode1 = new Node(1);
        rootNode1.left = new Node(2);
        rootNode1.right = new Node(3);

        rootNode1.left.left= new Node(4);
        rootNode1.left.right= new Node(5);



        System.out.println("Before Mirroring ");
        BinaryTree bt = new BinaryTree();
        bt.printInOrder(rootNode1);
        new ActualWorker(rootNode).mirrorBinaryTree(rootNode1);
        System.out.println("\nAfter Mirroring");
        bt.printInOrder(rootNode1);
    }
}