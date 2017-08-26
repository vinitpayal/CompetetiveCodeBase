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

    public boolean treeSymmetryCheck(Node leftNode, Node rightNode){

        if(leftNode == null && rightNode == null) return true;
        else if(leftNode == null || rightNode == null) return false;
        else if(leftNode.data != rightNode.data) return false;

        return treeSymmetryCheck(leftNode.left, rightNode.right) && treeSymmetryCheck(leftNode.right, rightNode.left);
    }
}

class TreeSymmetric{
    public static void main(String[] args) {
        Node rootNode = new Node(1);

        rootNode.left = new Node(2);
        rootNode.right = new Node(2);

        rootNode.left.left = new Node(3);
        rootNode.left.right = new Node(4);

        rootNode.left.left.left = new Node(5);
        rootNode.left.left.right = new Node(6);

        rootNode.right.left = new Node(4);
        rootNode.right.right = new Node(3);

        rootNode.right.right.right = new Node(5);
        rootNode.right.right.left= new Node(6);

        Node rootNode1 = new Node(100);

        rootNode1.left = new Node(10);
        rootNode1.right = new Node(10);

        rootNode1.left.left = new Node(20);
        rootNode1.left.right = new Node(20);

        rootNode1.right.left = new Node(20);
        rootNode1.right.right = new Node(20);

        BinaryTree bt = new BinaryTree(rootNode1);

        System.out.println(new ActualWorker(rootNode1).treeSymmetryCheck(bt.rootNode.left, bt.rootNode.right));

    }
}