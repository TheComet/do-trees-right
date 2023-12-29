void serialize(struct tree* t) {
  FILE* fp = fopen(...);
  fwrite(&t->count, sizeof(int), 1, fp);
  fwrite(t->nodes, 1,
      sizeof(*t->nodes),
      t->count);
  fclose(fp);
}
