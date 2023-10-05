import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static class Pair {
        TreeNode node;
        int num;

        Pair(TreeNode node, int num) {
            this.node = node;
            this.num = num;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        int ans = 0;

        while (!q.isEmpty()) {
            int n = q.size();
            int idx = q.peek().num;
            int first = 0, last = 0;

            for (int i = 0; i < n; i++) {
                int curridx = q.peek().num - idx;
                TreeNode node = q.poll().node;

                if (i == 0) {
                    first = curridx;
                }
                if (i == n - 1) {
                    last = curridx;
                }

                if (node.left != null) {
                    q.add(new Pair(node.left, curridx * 2 + 1));
                }
                if (node.right != null) {
                    q.add(new Pair(node.right, curridx * 2 + 2));
                }
            }

            ans = Math.max(last - first + 1, ans);
        }

        return ans;
    }
}
