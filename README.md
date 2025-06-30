# 🔐 Cryptarithmetic Puzzle Solver using Branch and Bound

A **Cryptarithmetic Puzzle Solver** developed in C++ that uses the **Branch and Bound** technique to solve puzzles like `SEND + MORE = MONEY`. This solver is efficient, uses pruning strategies, and demonstrates the application of combinatorial optimization.

---

## 📌 Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [How It Works](#how-it-works)
- [Demo](#demo)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Sample Input/Output](#sample-inputoutput)
- [Project Structure](#project-structure)
- [License](#license)

---

## 📖 About the Project

Cryptarithmetic puzzles are mathematical puzzles in which the digits are replaced by letters. The goal is to find the unique digit each letter represents such that the arithmetic equation holds true.

This project demonstrates how to use **Branch and Bound** with backtracking to efficiently find a solution to such puzzles.

---

## ✨ Features

- Solves any valid cryptarithmetic addition puzzle (with unique letter mapping).
- Implements **Branch and Bound** to prune unfeasible paths.
- Ensures:
  - No duplicate digits
  - No leading zeroes
- Clean and modular C++ code
- Easy to adapt and extend

---

## 🧠 How It Works

1. Extract all unique characters.
2. Use permutations of digits (0–9) of length equal to number of unique letters.
3. Use **Branch and Bound** to:
   - Eliminate permutations early if they violate constraints.
   - Skip paths with leading zeroes.
4. Substitute the digits in the equation.
5. Check if the arithmetic expression evaluates correctly.

---
