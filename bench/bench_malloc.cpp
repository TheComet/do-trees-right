#include <benchmark/benchmark.h>

using namespace benchmark;

struct node {
    struct node* next;
    int a, b, c, d;
};

static void BM_malloc_n(State& state) {
    struct node* tree = NULL;
    for (auto _ : state) {
		for (int i = 0; i != state.range(0); i++) {
			struct node* n = (struct node*)malloc(sizeof *n);
			DoNotOptimize(n);
			ClobberMemory();
			n->next = tree;
			tree = n;
		}

		while (tree) {
			struct node* n = tree->next;
			free(tree);
			tree = n;
		}
    }
}
BENCHMARK(BM_malloc_n)->Args({1000})->Args({100000})->Args({1000000});

struct tree {
    struct node* nodes;
    int count, capacity;
};

static void BM_malloc_logn(State& state) {
    struct tree tree = { NULL, 0, 0 };
    for (auto _ : state) {
		for (int i = 0; i != state.range(0); i++) {
			if (tree.count == tree.capacity) {
				tree.capacity = tree.capacity ? tree.capacity * 2 : 8;
				tree.nodes = (struct node*)realloc(tree.nodes, tree.capacity);
			}

			struct node* n = &tree.nodes[tree.count++];
			DoNotOptimize(n);
			ClobberMemory();
		}
    }
}
BENCHMARK(BM_malloc_logn)->Args({1000})->Args({100000})->Args({1000000});

static void BM_malloc_realloc(State& state) {
	struct tree tree = { NULL, 0, 0 };
	for (auto _ : state) {
		for (int i = 0; i != state.range(0); i++) {
			tree.nodes = (struct node*)realloc(tree.nodes, tree.count+1);

			struct node* n = &tree.nodes[tree.count++];
			DoNotOptimize(n);
			ClobberMemory();
		}
	}
}
BENCHMARK(BM_malloc_realloc)->Args({ 1000 })->Args({ 100000 })->Args({ 1000000 });

BENCHMARK_MAIN();

