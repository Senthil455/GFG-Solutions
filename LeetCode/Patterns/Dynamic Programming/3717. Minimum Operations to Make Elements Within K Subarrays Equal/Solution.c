#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3f3f3f3f3f3f3f3fLL

typedef struct {
    int val;
    int idx;
} Pair;

static int cmp_pair(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    if (p1->val < p2->val) return -1;
    if (p1->val > p2->val) return 1;
    return p1->idx - p2->idx;
}

// Fenwick Tree (Binary Indexed Tree)
static void bit_add_count(int *tree, int n, int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        tree[idx] += val;
    }
}

static void bit_add_sum(long long *tree, int n, int idx, long long val) {
    for (; idx <= n; idx += idx & -idx) {
        tree[idx] += val;
    }
}

static int bit_query_count(const int *tree, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree[idx];
    }
    return sum;
}

static long long bit_query_sum(const long long *tree, int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += tree[idx];
    }
    return sum;
}

// Binary search on BIT to find the index corresponding to the k-th smallest element (1-based)
static int bit_find_kth(const int *tree, int n, int k) {
    int idx = 0;
    for (int step = 1 << 18; step > 0; step >>= 1) {
        if (idx + step <= n && tree[idx + step] < k) {
            idx += step;
            k -= tree[idx];
        }
    }
    return idx + 1;
}

long long minOperations(int* nums, int numsSize, int x, int k) {
    int n = numsSize;

    // Coordinate Compression
    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].val = nums[i];
        pairs[i].idx = i;
    }
    qsort(pairs, n, sizeof(Pair), cmp_pair);

    int *rank = (int *)malloc(n * sizeof(int));
    int *orig_val = (int *)malloc((n + 1) * sizeof(int));
    int unique = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || pairs[i].val != pairs[i - 1].val) {
            unique++;
            orig_val[unique] = pairs[i].val;
        }
        rank[pairs[i].idx] = unique;
    }
    free(pairs);

    // Fenwick trees to maintain sliding window statistics
    int *tree_cnt = (int *)calloc(unique + 1, sizeof(int));
    long long *tree_sum = (long long *)calloc(unique + 1, sizeof(long long));
    long long *cost = (long long *)malloc(n * sizeof(long long));

    int target_rank = (x + 1) / 2; // 1-based median rank

    for (int i = 0; i < n; i++) {
        bit_add_count(tree_cnt, unique, rank[i], 1);
        bit_add_sum(tree_sum, unique, rank[i], nums[i]);

        if (i >= x) {
            int out = i - x;
            bit_add_count(tree_cnt, unique, rank[out], -1);
            bit_add_sum(tree_sum, unique, rank[out], -nums[out]);
        }

        if (i >= x - 1) {
            // Find median index in compressed space
            int median_rank = bit_find_kth(tree_cnt, unique, target_rank);
            long long median_val = orig_val[median_rank];

            int cnt_left = bit_query_count(tree_cnt, median_rank);
            long long sum_left = bit_query_sum(tree_sum, median_rank);

            int cnt_right = x - cnt_left;
            long long sum_right = bit_query_sum(tree_sum, unique) - sum_left;

            cost[i] = (median_val * cnt_left - sum_left) + (sum_right - median_val * cnt_right);
        } else {
            cost[i] = INF;
        }
    }

    free(tree_cnt);
    free(tree_sum);
    free(rank);
    free(orig_val);

    // Dynamic Programming: dp[j][i]
    // dp_prev holds min cost for (j - 1) windows
    // dp_curr holds min cost for j windows
    long long *dp_prev = (long long *)malloc((n + 1) * sizeof(long long));
    long long *dp_curr = (long long *)malloc((n + 1) * sizeof(long long));

    // Base case: 0 subarrays requires 0 cost
    for (int i = 0; i <= n; i++) {
        dp_prev[i] = 0;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= n; i++) {
            dp_curr[i] = INF;
        }

        for (int i = j * x; i <= n; i++) {
            // Option 1: Do not pick a window ending at i - 1
            long long best = dp_curr[i - 1];

            // Option 2: Pick the window ending at index i - 1
            if (dp_prev[i - x] != INF && cost[i - 1] != INF) {
                long long take = dp_prev[i - x] + cost[i - 1];
                if (take < best) {
                    best = take;
                }
            }
            dp_curr[i] = best;
        }

        memcpy(dp_prev, dp_curr, (n + 1) * sizeof(long long));
    }

    long long result = dp_curr[n];

    free(dp_prev);
    free(dp_curr);
    free(cost);

    return result;
}