import java.util.ArrayList;
import java.util.Scanner;

public class USED_GRAPH_Problem_489B_BerSU_Ball {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        USED_GRAPH_Problem_489B_BerSU_Ball graph = new USED_GRAPH_Problem_489B_BerSU_Ball();

        int n = sc.nextInt(); // num of boys
        ArrayList<Node> boys = new ArrayList<Node>(); // skills of the boy dancers
        for (int i = 0; i < n; i++)
            boys.add(graph.new Node(sc.nextInt()));

        int m = sc.nextInt(); // num of girls
        ArrayList<Node> girls = new ArrayList<Node>(); // skills of the girl dancers
        for (int i = 0; i < m; i++) {
            int skill = sc.nextInt();
            Node N = graph.new Node(skill);
            girls.add(N);
            for (Node node : boys)
                node.connect(N); // connect to all possible partners (wont connect if skill imbalenced)
        }
        sc.close();
        ArrayList<Node> dancers = new ArrayList<Node>();

        // only consider boys and girls who have connections
        for (Node node : girls) {
            if (node.numFriends > 0)
            dancers.add(node);
        }
        for (Node node : boys) { 
            if (node.numFriends > 0)
                dancers.add(node);
        }

        // Collections.sort(dancers); // sort the dancers in ascending order based on # of connections
        
        int pairs = 0, i = 0, minfriend = 1; // number of pairs and the starting minimum number of friends allowed
        boolean noPair = false;

        while (dancers.size() > 0) {
            if (i >= dancers.size()) {
                if (noPair)
                    minfriend += 1;
                i = 0;
            }
            Node node = dancers.get(i);
            if (node.numFriends == minfriend) { // the dancer has the minimum number of possible partners
                dancers.remove(node);
                dancers.remove(node.friends.get(0));
                node.friends.get(0).disconnectAll();
                node.disconnectAll();
                pairs++;
                noPair = false;
                minfriend = 1;
            } else if (node.numFriends == 0) { // remove from list if no friends
                dancers.remove(node);
                i++;
            } else {
                i++;
                noPair = true;
            }
        }
        

        System.out.println(pairs);
    }

    public class Node {
        public ArrayList<Node> friends;
        public int numFriends, skill;
        
        public Node (int s) {
            skill = s;
            friends = new ArrayList<Node>();
        }

        /**
         * Stores a reference of node {@code f} in this node and stores a reference of
         * {@code this} node in node {@code f}.
         * 
         * @param f
         */
        public void connect(Node f) {
            if (f.skill >= skill - 1 && f.skill <= skill + 1) { // only connect if skill differs by no more than 1
                friends.add(f);
                f.friends.add(this);
                f.numFriends++;
                numFriends++;
            }
        }

        /**
         * Removes this nodes reference from {@code f} and then removes this nodes
         * reference to node f.
         * 
         * @param f the node to disconnect from
         * @return returns true if successful.
         */
        public boolean disconnect(Node f) {
            f.friends.remove(f);
            numFriends--;
            f.numFriends--;
            return friends.remove(f);
        }

        /**
         * Removes all references from other nodes and removes this nodes reference from
         * all other nodes.
         * 
         * returns an array of all the nodes removed.
         */
        public void disconnectAll() {
            for (Node friend : friends)
                friend.disconnect(this);
            numFriends = 0;
        }
    }
}
