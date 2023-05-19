

/*

5 5
1 2
2 3
3 1
3 4
4 5
2
1 0
5 2

 */

import java.util.Scanner;
import java.util.ArrayList;

public class E {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int nodeCount = input.nextInt();
        int sideCount = input.nextInt();

        Node[] node = new Node[nodeCount+1];
        for (int i = 1;i <= nodeCount;i++) node[i] = new Node(nodeCount,i);

        int sideA,sideB;
        for (int i = 0;i < sideCount;i++){
            sideA = input.nextInt();
            sideB = input.nextInt();

            node[sideA].setDist(sideB);
            node[sideB].setDist(sideA);
        }

        int termsCount = input.nextInt();

        if (termsCount == 0){
            System.out.println("Yes");

            StringBuilder output = new StringBuilder();
            for (int i = 0;i < nodeCount;i++) output.append("1");
            System.out.println(output);
            return;
        } 
        ArrayList<Integer> termNodes = new ArrayList<>();
        for (int i = 0;i < termsCount;i++){
            int nodeNumber = input.nextInt();
            int dist = input.nextInt();
            
            node[nodeNumber].setTerm(dist);
            termNodes.add(nodeNumber);
        }

        ArrayList<Node> searchingNode = new ArrayList<>();
        for (Node x : node) searchingNode.add(x);

        for (int currentIdx = 1;currentIdx < searchingNode.size();currentIdx++){
            Node currentNode = searchingNode.get(currentIdx);

            int targetNode = 1;
            while (targetNode <= nodeCount){
                if (currentNode.distNode[targetNode] == Node.MAX_NODE_COUNT){
                    currentNode.searchRoute(targetNode,node,currentNode,searchingNode);
                }
                targetNode++;
            }
        }

        
        for (int term : termNodes){
            node[term].setTermStates();
        }

        ArrayList<Integer> choosingNodes = new ArrayList<>();
        if (node[termNodes.get(0)].checkTerm(node, termNodes,1,choosingNodes)){
            System.out.println("Yes");

            StringBuilder output = new StringBuilder();
            for (int i = 1;i <= nodeCount;i++){
                if (choosingNodes.contains(i)){
                    output.append("1");
                }else{
                    output.append("0");
                }
            }
            System.out.println(output);
        }else{
            System.out.println("No");
        }
    }
}
class Node{
    int id;
    int[] distNode;
    ArrayList<Integer> neighborNode = new ArrayList<>();
    int neighborIdx = 0;
    char isBlack = "0".charAt(0);
    boolean isOk = true;
    int termDist;
    final public static int MAX_NODE_COUNT = 2001;
    ArrayList<Integer> visitedNode = new ArrayList<Integer>();
    // final int CAN_NOT_ACCESS = 2002;

    ArrayList<Integer> possibleNodes = new ArrayList<>();
    ArrayList<Integer> tabooNodes = new ArrayList<>();


    public Node(int nodeCount,int selfIdx){
        this.id = selfIdx;
        this.distNode = new int[nodeCount+1];
        for (int i = 1;i <= nodeCount;i++) distNode[i] = MAX_NODE_COUNT;
        distNode[selfIdx] = 0;
    }

    public void setDist(int node){
        distNode[node] = 1;
        neighborNode.add(node);
    }

    public void setTerm(int dist){
        termDist = dist;
        isOk = false;
    }

    public void searchRoute(int target,Node[] node,Node currentNode,ArrayList<Node> searchingNode){
        int neighborSize = neighborNode.size();
        int[] distCache = new int[neighborSize];
        for (int i = 0;i < neighborSize;i++) distCache[i] = MAX_NODE_COUNT;
        int neighborIdx = 0;

        while (neighborIdx < neighborSize){
            int neighbor = neighborNode.get(neighborIdx);

            if (node[neighbor].distNode[target] == MAX_NODE_COUNT){
                neighborIdx++;
            }else{
                distCache[neighborIdx] = node[neighbor].distNode[target] + distNode[neighbor];
                neighborIdx++;
            }
        }
        int min = MAX_NODE_COUNT;
        for (int x : distCache){
            if (x < min) min = x;
        }
        if (min != MAX_NODE_COUNT){
            distNode[target] = min;
        }else{
            searchingNode.add(currentNode);
        }
    }

    public void setTermStates(){
        for (int i = 1,size = distNode.length;i < size;i++){
            if (distNode[i] == termDist){
                possibleNodes.add(i);
            }else if (distNode[i] < termDist){
                tabooNodes.add(i);
            }
        }
    }

    public boolean checkTerm(Node[] node,ArrayList<Integer> termNodes,int termIdx,ArrayList<Integer> choosingNodes){
        boolean isSuccess = false;

        for (int x : choosingNodes){
            if (tabooNodes.contains(x)) return false;
        }
        
        for (int choose : possibleNodes){
            if (!choosingNodes.contains(choose)){
                choosingNodes.add(choose);
            }

            // 条件の数 + 1になったとき
            if (termIdx == termNodes.size()) return true;
            isSuccess = node[termNodes.get(termIdx)].checkTerm(node,termNodes, ++termIdx, choosingNodes);

            if (isSuccess){
                return true;
            }else{
                choosingNodes.remove(choosingNodes.indexOf(choose));
            }
        }
        return false;
    }
}