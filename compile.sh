#!/bin/bash

# Compile all programs
echo "=== Compiling DSA Assignment Programs ==="
echo ""

cd /workspaces/dsa_assignment

echo "Compiling prog_1.c (Balanced Parentheses)..."
gcc -o prog_1 prog_1.c
if [ $? -eq 0 ]; then echo "✓ prog_1 compiled successfully"; else echo "✗ prog_1 compilation failed"; fi

echo "Compiling prog_2.c (Infix to Postfix)..."
gcc -o prog_2 prog_2.c -lm
if [ $? -eq 0 ]; then echo "✓ prog_2 compiled successfully"; else echo "✗ prog_2 compilation failed"; fi

echo "Compiling prog_3.c (Linked List Reverse)..."
gcc -o prog_3 prog_3.c
if [ $? -eq 0 ]; then echo "✓ prog_3 compiled successfully"; else echo "✗ prog_3 compilation failed"; fi

echo "Compiling prog_4.c (Doubly Linked List)..."
gcc -o prog_4 prog_4.c
if [ $? -eq 0 ]; then echo "✓ prog_4 compiled successfully"; else echo "✗ prog_4 compilation failed"; fi

echo "Compiling prog_5.c (Graph BFS/DFS)..."
gcc -o prog_5 prog_5.c
if [ $? -eq 0 ]; then echo "✓ prog_5 compiled successfully"; else echo "✗ prog_5 compilation failed"; fi

echo "Compiling prog_6.c (Min/Max Heap)..."
gcc -o prog_6 prog_6.c
if [ $? -eq 0 ]; then echo "✓ prog_6 compiled successfully"; else echo "✗ prog_6 compilation failed"; fi

echo "Compiling prog_7.c (Dijkstra's Algorithm)..."
gcc -o prog_7 prog_7.c
if [ $? -eq 0 ]; then echo "✓ prog_7 compiled successfully"; else echo "✗ prog_7 compilation failed"; fi

echo "Compiling prog_8.c (Sorting Algorithms)..."
gcc -o prog_8 prog_8.c
if [ $? -eq 0 ]; then echo "✓ prog_8 compiled successfully"; else echo "✗ prog_8 compilation failed"; fi

echo ""
echo "=== Compilation Complete ==="
echo ""
echo "Executable files created:"
ls -la prog_* | grep -v ".c" | grep -v ".md"
