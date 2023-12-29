int find(
    struct tree* t,
    int r,
    const void* data) {
  int n;
  if (compare(t->nodes[r].data, data))
    return r;

  if (t->nodes[r].left >= 0)
    if (n = find(t, t->nodes[r].left, data))
      return n;
  if (t->nodes[r].right >= 0)
    if (n = find(t, t->nodes[r].right, data))
      return n;

  return -1;
}
