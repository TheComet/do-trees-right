struct node* make_node(void) {
  struct node* parent = malloc(...);
  parent->left = NULL;
  parent->right = NULL;
  return parent;
}
