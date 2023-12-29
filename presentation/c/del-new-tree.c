void delete_tree(struct tree* t) {
    free(t->nodes);
}
