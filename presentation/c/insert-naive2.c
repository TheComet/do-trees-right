struct node* make_node(void) {
  struct node* parent = malloc(...);
  parent->left = NULL;
  parent->right = NULL;
  return parent;
}

struct node* a = make_node();
struct node* b = make_node();
struct node* c = make_node();
a->left = b;
a->right = c;
