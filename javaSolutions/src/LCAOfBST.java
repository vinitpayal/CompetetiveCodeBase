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

class BST{
    public Node rootNode;

    public void insertInBSTWrapper(int data){
        if(this.rootNode == null){
            this.rootNode = new Node(data);
        }
        else{
            insertInBST(rootNode,data);
        }
    }

    public void insertInBST(Node currNode,int data){
        Node nodeToAdd = new Node(data);

       if(currNode.data > data){
            if(currNode.left == null){
                currNode.left = nodeToAdd;
            }
            else{
                insertInBST(currNode.left, data);
            }
        }
        else if(currNode.data < data){
            if(currNode.right == null){
                currNode.right = nodeToAdd;
            }
            else{
                insertInBST(currNode.right, data);
            }
        }
    }

    public void printInOrderWrapper(){
        printInOrder(this.rootNode);
        System.out.println();
    }

    public void printInOrder(Node currNode){
        if(currNode == null) return;
        printInOrder(currNode.left);
        System.out.print(currNode.data+" ");
        printInOrder(currNode.right);
    }
}
class ActualWorker{
    public BST bst;
    public int node1;
    public int node2;

    public ActualWorker(BST bst, int node1, int node2) {
        this.bst = bst;
        this.node1 = node1;
        this.node2 = node2;
    }

    public int getLCAWrapper(){
        return this.getLCA(bst.rootNode);
    }

    public int getLCA(Node currNode){
        if(currNode == null) return -1;
        if(currNode.data > this.node1 && currNode.data > this.node2){
            return getLCA(currNode.left);
        }
        else if(currNode.data < this.node1 && currNode.data < this.node2){
            return getLCA(currNode.right);
        }
        else {
            return currNode.data;
        }
    }
}

public class LCAOfBST{
    public static void main(String[] args) {
        BST bst = new BST();
        bst.insertInBSTWrapper(5);
        bst.insertInBSTWrapper(4);
        bst.insertInBSTWrapper(6);
        bst.insertInBSTWrapper(3);
        bst.insertInBSTWrapper(7);
        bst.insertInBSTWrapper(8);

        bst.printInOrderWrapper();

        System.out.println("LCA is -->"+new ActualWorker(bst, 4,6).getLCAWrapper());

    }
}