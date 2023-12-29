struct node {
  int left;
  int right;
};

struct tree {
  struct node* nodes;
  int count, capacity;
};
