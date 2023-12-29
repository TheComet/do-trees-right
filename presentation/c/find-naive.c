struct node* find(
    struct node* r,
    const void* data) {
  struct node* n;

  if (compare(r->data, data))
    return r;

  if (r->left)
    if (n = find(r->left, data))
      return n;
  if (r->right)
    if (n = find(r->right, data))
      return n;

    return NULL;
}
