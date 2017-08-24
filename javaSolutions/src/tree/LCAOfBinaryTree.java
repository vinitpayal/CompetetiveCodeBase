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

class ActualWorker{
    public Node rootNode;

    public ActualWorker(Node rootNode) {
        this.rootNode = rootNode;
    }

    public Node getLCA(Node currNode, int n1,int n2){
        if(currNode == null) return null;
//        System.out.println("Calling for "+currNode.data);
        if(currNode.data == n1 || currNode.data == n2) return currNode;

        Node leftSubTreeLca = getLCA(currNode.left,n1,n2);
        Node rightSubTreeLca = getLCA(currNode.right,n1,n2);

        if(leftSubTreeLca == null && rightSubTreeLca == null) return  null;
        else if(leftSubTreeLca != null && rightSubTreeLca != null) return currNode;
        else return leftSubTreeLca == null?rightSubTreeLca:leftSubTreeLca;
    }
}

public class LCAOfBinaryTree{
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

        Node lcaNode = new ActualWorker(rootNode).getLCA(rootNode,4,3);

        System.out.println("LCA is "+lcaNode.data);

    }
}