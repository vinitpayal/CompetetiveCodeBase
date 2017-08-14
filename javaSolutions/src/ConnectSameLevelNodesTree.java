/**
 solution at http://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
 **/

import java.util.LinkedList;
import java.util.Queue;

class Node{
    public int data;
    public Node left;
    public Node right;
    public Node nextRight;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
        this.nextRight = null;
    }

}
class NodeLevelPair{
    public Node node;
    public int level;

    public NodeLevelPair(Node node, int level) {
        this.node = node;
        this.level = level;
    }
}

class ActualWorker{
    private Node rootNode;
    private Queue<NodeLevelPair> q;

    public ActualWorker(Node rootNode) {
        this.q = new LinkedList<NodeLevelPair>();
        this.rootNode = rootNode;

        this.q.add(new NodeLevelPair(rootNode,0));
    }

    public void connectSameLevelNodes(){
        NodeLevelPair tempNode = null;
        NodeLevelPair nextNode = null;
        int currLevel;
        while (q.peek() != null){
            tempNode = q.poll();
            currLevel = tempNode.level;

            nextNode = q.peek();
            if(nextNode != null) {

                if (nextNode.level == currLevel) {
                    tempNode.node.nextRight = nextNode.node;
                }
            }

            if(tempNode.node.left != null) q.add(new NodeLevelPair(tempNode.node.left,currLevel+1));
            if(tempNode.node.right != null) q.add(new NodeLevelPair(tempNode.node.right,currLevel+1));
        }
    }


}

public class ConnectSameLevelNodesTree{

    public static void inOrder(Node rootNode){
        if(rootNode == null) return;

        inOrder(rootNode.left);
        System.out.print(rootNode.data+" ");

        inOrder(rootNode.right);

    }

    public static void main(String[] args){
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


        Node rootNode1 = new Node(10);
        rootNode1.left = new Node(20);
        rootNode1.right = new Node(30);
        rootNode1.left.left = new Node(40);
        rootNode1.left.right = new Node(60);


        System.out.println("Inorder Before ");
        inOrder(rootNode1);

        new ActualWorker(rootNode1).connectSameLevelNodes();

        System.out.println("\nInorder AFter ");

    }
}