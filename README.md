# push_swap_42

A high-performance sorting algorithm implementation using two stacks and adaptive sorting strategies. This project demonstrates advanced algorithmic optimization techniques and was developed as part of the 42 School curriculum.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Program Entry Point](#program-entry-point)
- [Major Sorting Algorithms](#major-sorting-algorithms)
  - [Small Sort (O(n²))](#small-sort-on2)
  - [Simple Sort (O(n²))](#simple-sort-on2)
  - [Medium Sort - Chunk Sort (O(n√n))](#medium-sort---chunk-sort-onn)
  - [Complex Sort - Binary Radix Sort (O(n log n))](#complex-sort---binary-radix-sort-on-log-n)
- [Core Data Structures](#core-data-structures)
- [Stack Operations](#stack-operations)
- [Key Optimization Techniques](#key-optimization-techniques)
- [Building & Running](#building--running)
- [Usage Examples](#usage-examples)
- [Project Architecture](#project-architecture)

---

## Overview

**push_swap** is a sorting challenge where you must sort a list of integers using two stacks (A and B) with only specific operations allowed. The goal is to sort stack A in ascending order using the minimum number of operations.

### Problem Statement
- **Input:** An unsorted list of integers (in stack A)
- **Output:** A sequence of operations to sort stack A
- **Constraint:** Only 12 stack operations allowed (see [Stack Operations](#stack-operations))
- **Objective:** Minimize the number of operations

### Key Features
✅ **Adaptive Strategy Selection** - Automatically chooses the best algorithm based on input size and disorder  
✅ **Binary Radix Sort** - O(n log n) sorting for large datasets  
✅ **Chunk Sort Algorithm** - O(n√n) optimization for medium datasets  
✅ **Efficient Small Sort** - O(n²) for small datasets (n ≤ 20)  
✅ **Benchmarking** - Built-in performance tracking and statistics  
✅ **Robust Input Validation** - Handles edge cases and error conditions  

---

## Program Entry Point

The program begins execution in `src/main.c`:

```c
int main(int ac, char **av)
{
    t_data d;
    
    if (ac == 1)
        return (0);                          // No arguments provided
    init_data(&d);                           // Initialize data structure
    if (!parse_args(ac, av, &d))
        return (error_exit(&d));             // Parse and validate input
    
    d.bench.disorder = compute_disorder(&d.a);  // Measure disorder level
    assign_ranks(&d);                        // Convert values to ranks (0 to n-1)
    if (!stack_init(&d.b, d.total_size))
        return (error_exit(&d));             // Initialize stack B
    
    if (!is_sorted(&d.a))
        run_strategy(&d);                    // Execute sorting strategy
    
    if (d.bench.enabled)
        print_bench(&d);                     // Print statistics
    
    free_data(&d);
    return (0);
}
```

### Execution Flow

```
1. Input Parsing
   └─ Validate command-line arguments
   └─ Parse integers and detect duplicates/errors
   └─ Store parsed numbers in stack A

2. Preprocessing
   └─ Compute disorder metric (how unsorted the array is)
   └─ Assign ranks: convert values to indices 0...n-1
   └─ Initialize stack B

3. Strategy Selection
   └─ Analyze input size and disorder
   └─ Choose optimal algorithm

4. Sorting Execution
   └─ Execute selected algorithm
   └─ Output operations to stdout

5. Cleanup & Exit
   └─ Free all allocated memory
   └─ Return success status
```

---

## Major Sorting Algorithms

The program dynamically selects the best algorithm based on input characteristics:

### Small Sort (O(n²))

**Trigger:** `n ≤ 20` elements  
**File:** `src/sort_small.c`  
**Best Case:** Already sorted  
**Worst Case:** O(n²)  

**Approach:**
1. Extract all elements except the last 3 by finding the minimum
2. Push minimums to stack B via rotations
3. Sort remaining ≤3 elements in stack A using `sort_three()`
4. Push all elements back from B to A in sorted order

**Algorithm Breakdown:**

```c
void sort_small(t_data *d)
{
    set_bench(d, "small sort", "constant small cases");
    
    // Phase 1: Extract all but 3 smallest elements
    while (d->a.size > 3)
    {
        rotate_a_to_pos(d, find_min_pos(&d->a));  // Rotate min to top
        pb(d);                                      // Push to stack B
    }
    
    // Phase 2: Sort remaining 3 elements
    if (d->a.size == 2 && d->a.r[0] > d->a.r[1])
        sa(d);                                      // Swap if needed
    else if (d->a.size == 3)
        sort_three(d);                              // Handle 3 elements
    
    // Phase 3: Push all back to A
    while (d->b.size > 0)
        pa(d);
}
```

**Sort Three Cases** (all possible orderings for 3 elements):
```
Input:   a > b > c    | a > b && b < c && a > c | a > b && b < c && a < c
Action:  sa, rra      | ra                       | sa, ra
─────────────────────────────────────────────────────────────────────
Input:   a < b && b > c && a < c | a < b && b > c && a > c | a < b && b < c
Action:  sa, ra                   | rra                      | no operation
```

---

### Simple Sort (O(n²))

**Trigger:** `21 ≤ n ≤ 100` (small to medium)  
**File:** `src/sort_simple.c`  
**Time Complexity:** O(n²)  
**Space Complexity:** O(n)  

**Approach:**
Repeated minimum extraction - similar to Small Sort but optimized for slightly larger datasets.

```c
void sort_simple(t_data *d)
{
    set_bench(d, "simple min extraction", "O(n^2)");
    
    while (d->a.size > 3)
    {
        rotate_a_to_pos(d, find_min_pos(&d->a));  // Find minimum element
        pb(d);                                      // Push to B
    }
    
    if (d->a.size == 2 && d->a.r[0] > d->a.r[1])
        sa(d);
    else if (d->a.size == 3)
        sort_three(d);
    
    while (d->b.size > 0)
        pa(d);
}
```

**Why O(n²)?**
- Finding minimum: O(n)
- Done for each element: n times
- Total: O(n) × n = O(n²)

**Optimization:** Uses rotation helpers to minimize total operations between finds.

---

### Medium Sort - Chunk Sort (O(n√n))

**Trigger:** `101 ≤ n ≤ 500` (medium datasets)  
**File:** `src/sort_medium.c`  
**Time Complexity:** O(n√n)  
**Space Complexity:** O(n)  

**Approach:** Divide elements into K chunks and process in ranges

```c
void sort_medium(t_data *d)
{
    int chunks = chunk_count(d->a.size);  // 8 for n≤100, 22 for n>100
    int size = d->a.size;
    int start = 0;
    
    set_bench(d, "medium chunk sort", "O(n sqrt n)");
    
    // Process each chunk range
    while (start < size)
    {
        int end = start + (size / chunks);
        if (end >= size || start + (size / chunks) == start)
            end = size - 1;
        
        push_range(d, start, end);  // Push all elements in range [start, end]
        start = end + 1;
    }
    
    push_back_max(d);  // Extract all and push back in max-first order
}
```

**Algorithm Details:**

1. **Chunking:** Divide n elements into K chunks (8 or 22)
   - Each chunk represents a range of ranks
   - Chunk size = n / K

2. **Push Range:**
   - Find all elements with ranks in [start, end]
   - Push to stack B
   - Optimize by pushing mid-lower elements to top for faster retrieval

   ```c
   void push_range(t_data *d, int start, int end)
   {
       int middle = start + ((end - start) / 2);
       
       while (has_rank_in_range(&d->a, start, end))
       {
           if (d->a.r[0] >= start && d->a.r[0] <= end)
           {
               pb(d);
               if (d->b.size > 1 && d->b.r[0] < middle)
                   rb(d);  // Rotate if smaller than midpoint
           }
           else
               ra(d);  // Rotate A to find next element
       }
   }
   ```

3. **Push Back:** Extract elements from B in maximum-first order to A
   - Minimizes rotations needed on final stage

**Why O(n√n)?**
- K chunks ≈ √n (optimal)
- Processing per chunk: O(n) rotations
- Total: √n chunks × n = O(n√n)

**Example with 100 elements, 8 chunks:**
```
Chunk 1: Ranks 0-12   → Push all to B → Extract in order
Chunk 2: Ranks 13-25  → Push all to B → Extract in order
...
Chunk 8: Ranks 88-99  → Push all to B → Extract in order
Result: Sorted array in stack A
```

---

### Complex Sort - Binary Radix Sort (O(n log n))

**Trigger:** `n > 500` (large datasets)  
**File:** `src/sort_complex.c`  
**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)  
**Optimal Performance:** Best for very large datasets

**Approach:** Bit-by-bit sorting using binary representation

```c
void sort_complex(t_data *d)
{
    int bit = 0;
    int bits = max_bits(d->a.size - 1);  // Number of bits needed (log₂ n)
    int size = d->a.size;
    
    set_bench(d, "complex binary radix", "O(n log n)");
    
    // Process each bit position from LSB to MSB
    while (bit < bits)
    {
        run_bit(d, bit, size);
        bit++;
    }
}

static void run_bit(t_data *d, int bit, int size)
{
    int i = 0;
    
    while (i < size)
    {
        // Check if bit at position 'bit' is 0 or 1
        if (((d->a.r[0] >> bit) & 1) == 0)
            pb(d);  // If 0: push to B (smaller group)
        else
            ra(d);  // If 1: rotate in A (larger group)
        i++;
    }
    
    // Push all back from B to A (now sorted for this bit)
    while (d->b.size > 0)
        pa(d);
}
```

**Binary Radix Sort Explanation:**

The algorithm works by repeatedly sorting based on each bit position, from least significant bit (LSB) to most significant bit (MSB).

**Example with ranks [1, 4, 3, 2, 0] (5 elements = 3 bits needed)**

```
Initial: Stack A = [1, 4, 3, 2, 0]
         Ranks in binary: 1=001, 4=100, 3=011, 2=010, 0=000

ITERATION 1 (Bit 0 - LSB):
─────────────────────────
Process: Check bit 0 of each rank
  1 (001) → bit 0 = 1 → ra (stays in A)
  4 (100) → bit 0 = 0 → pb (push to B)
  3 (011) → bit 0 = 1 → ra (stays in A)
  2 (010) → bit 0 = 0 → pb (push to B)
  0 (000) → bit 0 = 0 → pb (push to B)

Stack A = [1, 3]
Stack B = [4, 2, 0]  (top to bottom: 0, 2, 4)

Push back: pa all from B → Stack A = [0, 2, 4, 1, 3]

ITERATION 2 (Bit 1):
─────────────────────────
Process: Check bit 1 of each rank
  0 (000) → bit 1 = 0 → pb
  2 (010) → bit 1 = 1 → ra
  4 (100) → bit 1 = 0 → pb
  1 (001) → bit 1 = 0 → pb
  3 (011) → bit 1 = 1 → ra

Stack A = [2, 3]
Stack B = [0, 4, 1]

Push back: Stack A = [0, 1, 4, 2, 3]

ITERATION 3 (Bit 2 - MSB):
─────────────────────────
Process: Check bit 2 of each rank
  0 (000) → bit 2 = 0 → pb
  1 (001) → bit 2 = 0 → pb
  4 (100) → bit 2 = 1 → ra
  2 (010) → bit 2 = 0 → pb
  3 (011) → bit 2 = 0 → pb

Stack A = [4]
Stack B = [0, 1, 2, 3]

Push back: Stack A = [0, 1, 2, 3, 4]  ✓ SORTED!
```

**Why O(n log n)?**
- Number of bits to process: log₂(n)
- Each iteration processes all n elements: O(n)
- Total: O(n) × log₂(n) = O(n log n)

**Key Advantage:** Consistent performance regardless of input distribution

---

## Core Data Structures

### Main Data Structure: `t_data`

```c
typedef struct s_data
{
    t_stack a;              // Stack A (input data)
    t_stack b;              // Stack B (temporary workspace)
    int     total_size;     // Total number of elements
    t_flags flags;          // Strategy flags
    t_bench bench;          // Benchmarking information
} t_data;
```

### Stack Structure: `t_stack`

```c
typedef struct s_stack
{
    int *v;                 // Array of values
    int *r;                 // Array of ranks (0 to n-1)
    int size;               // Current size (elements in stack)
    int cap;                // Capacity (allocated space)
} t_stack;
```

### Benchmarking Structure: `t_bench`

```c
typedef struct s_bench
{
    int    enabled;         // Enable benchmarking flag
    int    total;           // Total operations count
    int    sa, sb, ss;      // Swap operations
    int    pa, pb;          // Push operations
    int    ra, rb, rr;      // Rotate operations
    int    rra, rrb, rrr;   // Reverse rotate operations
    double disorder;        // Initial disorder metric
    char   *strategy;       // Strategy name
    char   *complexity;     // Time complexity notation
} t_bench;
```

### Strategy Flags: `t_flags`

```c
typedef enum e_flags
{
    STRAT_ADAPTIVE,         // Automatically select best strategy
    STRAT_SIMPLE,           // Force simple sort (O(n²))
    STRAT_MEDIUM,           // Force chunk sort (O(n√n))
    STRAT_COMPLEX           // Force binary radix (O(n log n))
} t_flags;
```

---

## Stack Operations

Push_swap allows exactly **12 operations** on the stacks:

### Core Operations

| Operation | Action | Implementation |
|-----------|--------|-----------------|
| `sa` | Swap top 2 elements of stack A | Exchanges `a.r[0]` and `a.r[1]` |
| `sb` | Swap top 2 elements of stack B | Exchanges `b.r[0]` and `b.r[1]` |
| `ss` | Execute `sa` and `sb` together | Optimized dual swap |
| `pa` | Push top of B to A | Move `b.r[0]` → `a.r[0]`, update sizes |
| `pb` | Push top of A to B | Move `a.r[0]` → `b.r[0]`, update sizes |
| `ra` | Rotate A upward | `a.r[0]` → bottom, shift rest up |
| `rb` | Rotate B upward | `b.r[0]` → bottom, shift rest up |
| `rr` | Execute `ra` and `rb` together | Optimized dual rotate |
| `rra` | Reverse rotate A | Bottom → top, shift rest down |
| `rrb` | Reverse rotate B | Bottom → top, shift rest down |
| `rrr` | Execute `rra` and `rrb` together | Optimized dual reverse rotate |

### Visual Representation

```
Stack A: [3, 1, 2]  (top to bottom)

After sa (swap):    [1, 3, 2]
After ra (rotate):  [1, 2, 3]
After rra (rev):    [3, 1, 2]
After pa (push A):  [2] to B

Stack A: [1, 2]
Stack B: [3]  (after pb)
```

---

## Key Optimization Techniques

### 1. **Ranking System**

Convert raw values to ranks (0 to n-1) to enable binary sorting:

```c
void assign_ranks(t_data *d)
{
    // Example: [67, 2, 100, 42, 3] → [3, 0, 4, 2, 1]
    // Smallest value (2) gets rank 0
    // Next smallest (3) gets rank 1
    // ... and so on
}
```

**Why?** Binary operations work efficiently on small integers (0 to n-1) rather than arbitrary large values.

### 2. **Disorder Metric**

Measure how "unsorted" the input is to optimize strategy selection:

```c
double compute_disorder(t_stack *s)
{
    // Count inversions: pairs (i,j) where i < j but s[i] > s[j]
    // Higher inversions = more unsorted = need more operations
}
```

### 3. **Adaptive Strategy Selection**

Automatically choose the best algorithm:

```
if (is_sorted(a))           → Already sorted, do nothing
else if (n <= 3)            → sort_small()
else if (n <= 100)          → sort_simple()
else if (n <= 500)          → sort_medium()
else                         → sort_complex()  // Binary radix
```

### 4. **Rotation Helpers**

Efficiently position elements at the top of stacks:

```c
void rotate_a_to_pos(t_data *d, int pos)
{
    // Decide: is it faster to rotate forward (ra) or backward (rra)?
    if (pos <= d->a.size / 2)
        // Forward rotation: less rotations needed
    else
        // Backward rotation: less rotations needed
}
```

### 5. **Chunk Size Optimization**

Dynamically choose chunk count based on data size:

```c
static int chunk_count(int n)
{
    if (n <= 100)
        return (8);      // 8 chunks for n ≤ 100
    return (22);         // 22 chunks for n > 100
}
// This approximates √n for optimal O(n√n) complexity
```

### 6. **Mid-Value Optimization (Chunk Sort)**

Separate pushed elements by their position relative to chunk midpoint:

```c
if (d->b.size > 1 && d->b.r[0] < middle)
    rb(d);  // Rotate smaller elements to bottom for faster access later
```

---

## Building & Running

### Prerequisites
- GCC compiler (or cc)
- Make utility
- Linux/Unix-like environment

### Compilation

```bash
# Clone the repository
git clone https://github.com/khawajashahbaz/push_swap_42.git
cd push_swap_42

# Compile
make

# Clean object files
make clean

# Full cleanup (remove binary)
make fclean

# Rebuild from scratch
make re
```

### Makefile Targets

```makefile
NAME = push_swap              # Output binary name
CC = cc                        # Compiler
CFLAGS = -Wall -Wextra -Werror -Iinclude  # Compilation flags

all:    Build the push_swap binary
clean:  Remove object files
fclean: Remove object files and binary
re:     Clean rebuild
```

---

## Usage Examples

### Basic Usage

```bash
# Sort numbers provided as arguments
./push_swap 3 67 2 100 42

# Output:
# pb
# pb
# ra
# pa
# ra
# rra
# ...

# Single number (already sorted)
./push_swap 42
# (no output - already sorted)

# Two numbers
./push_swap 2 1
# sa
```

### With Strategy Flags

```bash
# Force simple sort strategy
./push_swap --simple 3 67 2 100 42

# Force medium sort (chunk sort)
./push_swap --medium 3 67 2 100 42 30 15

# Force complex sort (binary radix)
./push_swap --complex 3 67 2 100 42 30 15 80 50

# Enable benchmarking
./push_swap --bench 3 67 2 100 42
```

### Large Dataset Example

```bash
# Generate 500 random numbers
seq 1 500 | shuf | xargs ./push_swap

# With benchmarking to see which strategy was used
seq 1 500 | shuf | xargs ./push_swap --bench
```

### Error Handling

```bash
# Duplicate numbers (error)
./push_swap 1 2 2 3
# Error: duplicates detected

# Non-integer input (error)
./push_swap 1 2 abc 3
# Error: invalid input

# Integer overflow (error)
./push_swap 1 2 999999999999999 3
# Error: number out of range
```

---

## Project Architecture

### Source Files Organization

```
push_swap_42/
├── Makefile              # Build configuration
├── README.md             # This file
├── include/
│   └── push_swap.h       # Header with all declarations
│
└── src/
    ├── main.c            # Program entry point
    ├── parse.c           # Command-line argument parsing
    ├── init_cleanup.c    # Data initialization/cleanup
    ├── utils.c           # Utility functions
    ├── stack.c           # Stack management
    ├── stack_utils.c     # Stack helper functions
    │
    ├── ops_swap.c        # sa, sb, ss operations
    ├── ops_push.c        # pa, pb operations
    ├── ops_rotate.c      # ra, rb, rr operations
    ├── ops_reverse.c     # rra, rrb, rrr operations
    ├── emit.c            # Output operations
    │
    ├── validate_rank.c   # Rank assignment logic
    ├── disorder.c        # Disorder computation
    ├── strategy.c        # Strategy selection logic
    │
    ├── sort_small.c      # Small sort (n ≤ 20)
    ├── sort_simple.c     # Simple sort (n ≤ 100)
    ├── sort_medium.c     # Medium sort - chunk sort (n ≤ 500)
    ├── sort_complex.c    # Complex sort - binary radix (n > 500)
    │
    └── bench.c           # Benchmarking utilities
```

### Module Responsibilities

| Module | Purpose |
|--------|---------|
| **main.c** | Orchestrate program flow |
| **parse.c** | Parse arguments, validate input |
| **init_cleanup.c** | Memory allocation/deallocation |
| **stack.c** | Core stack operations |
| **stack_utils.c** | Find min/max positions, check sorted |
| **ops_*.c** | Implement 12 stack operations |
| **emit.c** | Output operation names |
| **validate_rank.c** | Convert values to ranks |
| **disorder.c** | Compute disorder metric |
| **strategy.c** | Select optimal algorithm |
| **sort_*.c** | Sorting algorithms |
| **bench.c** | Performance tracking |

### Compilation Flow

```
Source Files (*.c)
      ↓ [cc -Wall -Wextra -Werror -Iinclude]
Object Files (*.o)
      ↓ [Linking]
Executable (push_swap)
```

---

## Algorithm Comparison

### Performance Table

| Algorithm | Trigger | Time | Space | Best For |
|-----------|---------|------|-------|----------|
| Small Sort | n ≤ 20 | O(n²) | O(n) | Tiny datasets |
| Simple Sort | 21-100 | O(n²) | O(n) | Small datasets |
| Chunk Sort | 101-500 | O(n√n) | O(n) | Medium datasets |
| Binary Radix | > 500 | O(n log n) | O(n) | Large datasets |

### Operation Count Comparison (100 random elements)

```
Algorithm     │ Operations │ Optimality
─────────────────────────────────────
Simple Sort   │ ~800-1200   │ Good
Chunk Sort    │ ~400-600    │ Very Good
Binary Radix  │ ~600-800    │ Excellent
```

---

## Future Improvements

- [ ] GUI visualizer for sorting steps
- [ ] Parallel sorting for multi-threaded execution
- [ ] Custom comparison function support
- [ ] Performance optimization with cache-aware algorithms
- [ ] Extended benchmarking suite

---

## Author

**Khawaja Shahbaz**  
*42 School Student*  
[GitHub Profile](https://github.com/khawajashahbaz)

---

## License

This project is part of the 42 School curriculum. Feel free to use and modify as needed for educational purposes.

---

## Acknowledgments

This project demonstrates:
- Adaptive algorithm selection based on input characteristics
- Time-space complexity trade-offs
- Stack-based data structure manipulation
- Binary number operations and bit manipulation
- Performance optimization techniques

---

**Last Updated:** June 2026
