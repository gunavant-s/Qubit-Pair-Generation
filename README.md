# Quantum State Pair Generator

This C++ program generates and prints pairs of binary numbers representing states in a quantum system with a specific target qubit. It demonstrates how to manipulate binary representations of quantum states and is useful for understanding quantum algorithms and operations.

---

## Code Explanation

### Key Components

1. **`printBinary` Function**:
   - Converts an integer `num` into a binary string of length `bits`.
   - Uses `std::bitset<16>` for binary conversion and truncates the result to the specified number of bits.
   - Prints the binary string and the original integer.

2. **`main` Function**:
   - Simulates a quantum system with `N` qubits and a target qubit `t`.
   - Computes pairs of states (`i0` and `i1`) where the target qubit is toggled (`0` or `1`).
   - Prints the binary representations of each pair.

---

## How It Works

### Input Parameters
- `N`: Total number of qubits (e.g., `N = 6`).
- `t`: Target qubit (0-indexed, e.g., `t = 2`).

### Key Steps
1. **Calculate Number of Pairs**:
   - The number of pairs is `pairs = 1 << (N-1)` (e.g., for `N = 6`, `pairs = 32`).

2. **Generate Pairs**:
   - For each `idx` from `0` to `pairs-1`:
     - Compute `base = (idx & ~((1 << t) - 1)) << 1 | (idx & ((1 << t) - 1))`.
     - Compute `i0 = base` (target qubit is `0`).
     - Compute `i1 = base | (1 << t)` (target qubit is `1`).

3. **Output**:
   - Print the binary representations of `i0` and `i1` for each pair.

---

### Example Output

For `N = 6` and `t = 2`, the output looks like this:

```
N = 6 qubits, target = 2
Number of pairs: 32

Pair  0: 000000 (0) and 000100 (4)
Pair  1: 000001 (1) and 000101 (5)
Pair  2: 000010 (2) and 000110 (6)
Pair  3: 000011 (3) and 000111 (7)
Pair  4: 001000 (8) and 001100 (12)
Pair  5: 001001 (9) and 001101 (13)
Pair  6: 001010 (10) and 001110 (14)
Pair  7: 001011 (11) and 001111 (15)
Pair  8: 010000 (16) and 010100 (20)
Pair  9: 010001 (17) and 010101 (21)
Pair 10: 010010 (18) and 010110 (22)
Pair 11: 010011 (19) and 010111 (23)
Pair 12: 011000 (24) and 011100 (28)
Pair 13: 011001 (25) and 011101 (29)
Pair 14: 011010 (26) and 011110 (30)
Pair 15: 011011 (27) and 011111 (31)
Pair 16: 100000 (32) and 100100 (36)
Pair 17: 100001 (33) and 100101 (37)
Pair 18: 100010 (34) and 100110 (38)
Pair 19: 100011 (35) and 100111 (39)
Pair 20: 101000 (40) and 101100 (44)
Pair 21: 101001 (41) and 101101 (45)
Pair 22: 101010 (42) and 101110 (46)
Pair 23: 101011 (43) and 101111 (47)
Pair 24: 110000 (48) and 110100 (52)
Pair 25: 110001 (49) and 110101 (53)
Pair 26: 110010 (50) and 110110 (54)
Pair 27: 110011 (51) and 110111 (55)
Pair 28: 111000 (56) and 111100 (60)
Pair 29: 111001 (57) and 111101 (61)
Pair 30: 111010 (58) and 111110 (62)
Pair 31: 111011 (59) and 111111 (63)
```

---

## Explanation of `base` Calculation

The expression `base = (idx & ~((1 << t) - 1)) << 1 | (idx & ((1 << t) - 1))` is used to construct the `base` state by manipulating the bits of `idx` to account for the target qubit `t`.

### Breakdown:
1. **`(1 << t)`**:
   - Creates a bitmask with a `1` at the position of the target qubit `t`.
   - Example: For `t = 2`, `(1 << 2) = 0b100`.

2. **`((1 << t) - 1)`**:
   - Creates a bitmask with `1`s in all positions **below** the target qubit.
   - Example: For `t = 2`, `(1 << 2) - 1 = 0b011`.

3. **`~(1 << t) - 1`**:
   - Flips all bits in the bitmask.
   - Example: For `t = 2`, `~(0b011) = 0b111...11100`.

4. **`idx & ~((1 << t) - 1)`**:
   - Clears the bits **below** the target qubit in `idx`.
   - Example: For `idx = 5` (`0b101`), `idx & ~((1 << 2) - 1) = 0b100`.

5. **`(idx & ~((1 << t) - 1)) << 1`**:
   - Shifts the result left by `1` to make space for the target qubit.
   - Example: `0b100 << 1 = 0b1000`.

6. **`idx & ((1 << t) - 1)`**:
   - Extracts the bits **below** the target qubit in `idx`.
   - Example: For `idx = 5` (`0b101`), `idx & ((1 << 2) - 1) = 0b001`.

7. **Combine Results**:
   - Combines the shifted bits with the lower bits using the `|` (OR) operator.
   - Example: `0b1000 | 0b001 = 0b1001`.
