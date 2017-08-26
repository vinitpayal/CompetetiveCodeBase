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

class BoolWrap{
    boolean flag;
}

class ActualWorker{
    public Node rootNode;

    public ActualWorker(Node rootNode) {
        this.rootNode = rootNode;
    }

    public int heightBalanceCheck(Node rootNode, BoolWrap isBalanced){
        if(rootNode == null) return 0;

        int ld = heightBalanceCheck(rootNode.left,isBalanced);
        int rd = heightBalanceCheck(rootNode.right,isBalanced);
//        System.out.println("For "+rootNode.data+" ld :"+ld+" rd: "+rd);
        if(ld >= rd && ld-rd > 1) {
//            System.out.println("False for1 "+rootNode.data);
            isBalanced.flag = false;
            return 0;
        }
        else if(ld < rd && rd-ld > 1) {
//            System.out.println("False for2 "+rootNode.data);
            isBalanced.flag = false;
            return 0;
        }

        return 1+ Math.max(ld, rd);
    }

}


public class TreeHeightBalanceCheck{
    public static void main(String[] args) {
        Node rootNode = new Node(-15);

        rootNode.left = new Node(5);
        rootNode.right = new Node(6);

        rootNode.left.left = new Node(-8);
        rootNode.left.right = new Node(1);

        rootNode.left.left.left = new Node(2);
        rootNode.left.left.right = new Node(-3);

        rootNode.right.left = new Node(3);
        rootNode.right.right = new Node(9);

        rootNode.right.right.right = new Node(0);
        rootNode.right.right.right.left= new Node(4);
        rootNode.right.right.right.right= new Node(-1);

        rootNode.right.right.right.right.left = new Node(1);
        rootNode.right.right.right.right.right = new Node(10);

        Node rootNode1 = new Node(1);
        rootNode1.left = new Node(2);
        rootNode1.left.left = new Node(3);
        rootNode1.left.right = new Node(4);
        rootNode1.left.right.right = new Node(5);
        rootNode1.left.right.right.right = new Node(6);

        rootNode1.right = new Node(6);
        rootNode1.right.right = new Node(7);
        rootNode1.right.right = new Node(8);
        rootNode1.right.right.right = new Node(9);



        BinaryTree bt = new BinaryTree(rootNode1);

        BoolWrap isBalanced = new BoolWrap();
        isBalanced.flag = true;

        new ActualWorker(rootNode1).heightBalanceCheck(bt.rootNode,isBalanced);

       if(isBalanced.flag == false) System.out.println("Tree is not balanced");
       else System.out.println("Tree is balanced");
    }
}