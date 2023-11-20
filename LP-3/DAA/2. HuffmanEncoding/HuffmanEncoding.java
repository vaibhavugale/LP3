import java.util.*;

class Node implements Comparable<Node> {
    int freq;
    String symbol;
    Node left;
    Node right;

    public Node(int freq, String symbol, Node left, Node right) {
        this.freq = freq;
        this.symbol = symbol;
        this.left = left;
        this.right = right;
    }

    public int compareTo(Node other) {
        return Integer.compare(this.freq, other.freq);
    }
}

public class HuffmanEncoding {

    public static void printNodes(Node root, String val) {
        if (root.left == null && root.right == null) {
            System.out.println(root.symbol + " -> " + val);
        } else {
            printNodes(root.left, val + "0");
            printNodes(root.right, val + "1");
        }
    }

    public static Node buildHuffmanTree(String input) {
        /////////////////////////////
        Map<Character, Integer> freqMap = new HashMap<>();

        for (char c : input.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();

        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pq.offer(new Node(entry.getValue(), entry.getKey().toString(), null, null));
        }
        //////////////////////////
        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            pq.offer(new Node(left.freq + right.freq, left.symbol + right.symbol, left, right));
        }

        return pq.poll();
    }

    public static void main(String args[]) {
        String input = "aaaaaaaabbbbbbbbccccccccdd";
        Node root = buildHuffmanTree(input);
        printNodes(root, " ");
    }
}
