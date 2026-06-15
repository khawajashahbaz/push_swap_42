push_swap — Program Overview

This document summarizes the program flow, data structures, and core functions of the project.

Data structures
- t_stack: holds `v` (values), `r` (ranks), `size`, `cap`.
- t_bench: benchmarking counters and labels.
- t_data: top-level container with stacks `a` and `b`, total_size, flags, bench.

Program flow (high level)
1. main: initialize `t_data`, parse CLI args, compute disorder, assign ranks, init stack B, run chosen strategy if needed, optionally print benchmark, free resources.
2. parse_args: preallocate stack A, detect flags (e.g., `--bench`, strategy overrides), tokenize number arguments and append to A.
3. assign_ranks: for each element in A compute how many elements are smaller → rank. Algorithms operate on ranks.
4. run_strategy: (selects between adaptive/simple/medium/complex sorting functions based on flags and disorder). Implementations live in `src/sort_*.c`.
5. Primitive operations: `sa/sb/ss`, `pa/pb`, `ra/rb/rr`, `rra/rrb/rrr` — all manipulate arrays in `t_stack` and call `emit` to print op and update bench counters.

Key design notes
- Values are kept in `v[]`, with ranks in parallel `r[]` so sorting algorithms operate on small integers (0..N-1) instead of originals.
- `compute_disorder` measures the fraction of inverted pairs to choose an adaptive strategy.
- `emit` prints operations to stdout (one per line) and tracks counts when benchmarking is enabled.
- Parsing is strict: rejects duplicates, non-integers, and integer overflow.

Files edited with inline comments
- include/push_swap.h — added comments for types and prototypes
- src/main.c — annotated program entryflow
- src/init.c, src/emit.c, src/rank.c, src/disorder.c — annotated
- src/stack.c, src/stack_utils.c — annotated
- src/ops_push.c, src/ops_swap.c, src/ops_rotate.c, src/ops_reverse.c — annotated
- src/parse.c, src/parse_numbers.c, src/parse_utils.c, src/parse_flags.c — annotated

Additional files annotated
- src/bench.c — bench printing and labels (`set_bench`, `print_bench`)
- src/cleanup.c — `free_data` and `error_exit` cleanup behavior
- src/rotate_utils.c — efficient rotate/unrotate helpers (`rotate_a_to_pos`, `rotate_b_to_pos`)
- src/startegy.c — strategy selection (`run_strategy`, `sort_adaptive`)
- src/sort_small.c — deterministic small-N sorting and `sort_three` cases
- src/sort_simple.c — simple min-extraction approach
- src/sort_medium.c — chunked push strategy for medium inputs
- src/sort_complex.c — binary radix on ranks for large inputs
- src/utils.c — low-level helpers and thin `ps_*` wrappers used across the codebase

Next steps
- All core files have been annotated; DOCS.md updated with per-file summary.
- I can run `make` and a smoke test to verify build and runtime behavior, or
- expand DOCS.md into per-file markdown pages with examples and annotated snippets.

Tell me which action you want next: `build`, `more-docs`, or `annotate-more`.
