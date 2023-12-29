int make_node(struct tree* t) {
  reserve(t);
  t->nodes[t->count].left = -1;
  t->nodes[t->count].right = -1;

  return t->count++;
}

int a = make_node(tree);
int b = make_node(tree);
int c = make_node(tree);
tree->nodes[a].left = b;
tree->nodes[a].right = c;
