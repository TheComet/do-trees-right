int make_node(struct tree* t) {
  reserve(t);
  t->nodes[t->count].left = -1;
  t->nodes[t->count].right = -1;

  return t->count++;
}
