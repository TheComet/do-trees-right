int find(
    struct tree* t,
    const void* data) {
  for (int n = 0; n != t->count; ++n) {
    if (compare(
        t->nodes[n].data, data))
      return n;
  }
  return -1;
}
