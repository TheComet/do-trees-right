void serialize(
    struct node* n) {
  FILE* fp = fopen(...);
  /* (create hashmap of indices <-> pointers -- left as an exercise to the user) */
  fwrite(&hashmap->count, sizeof(int), 1, fp);
  serialize_r(fp, n, &hashmap);
  fclose(fp);
}

void serialize_r(
    FILE* fp,
    struct node* n,
    hashmap* hm) {
  int left_idx = hm_find(&hm, n->left);
  int right_idx = hm_find(&hm,n->right);
  fwrite(&left_idx, sizeof(int), 1, fp);
  fwrite(&right_idx, sizeof(int), 1, fp);

  if (n->left)
    serialize_r(fp, n->left, &hm);
  if (n->right)
    serialize_r(fp, n->right, &hm);
}
