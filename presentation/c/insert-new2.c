int make_node(struct tree* t) {
  reserve(t);
  t->nodes[t->count].left = -1;
  t->nodes[t->count].right = -1;

  return t->count++;
}

void reserve(struct tree* t) {
  if (t->count == t->capacity) {
    t->capacity = t->capacity ?
      t->capacity*2 : 8;
    t->nodes = realloc(
      t->nodes, t->capacity);
  }
}
