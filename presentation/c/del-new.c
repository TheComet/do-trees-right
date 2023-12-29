void delete(
    struct tree* t, int n) {
  int p = find_parent(t, n);

  if (t->nodes[p].left == n)
    t->nodes[p].left = -1;
  if (t->nodes[p].right == n)
    t->nodes[p].right = -1;

  // does not alter structure!
  swap_nodes(n, --t->count);
}
