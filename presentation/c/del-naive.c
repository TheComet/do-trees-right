void delete(struct node* n) {
  struct node* p = find_parent(n);

  if (p->left == p)
    p->left = NULL;
  if (p->right == p)
    p->right = NULL;

  delete_r(n);
}

void delete_r(struct node* n) {
  if (n->left)
    free_node(n->left);
  if (n->right)
    free_node(n->right);

  free_node(n);
}
