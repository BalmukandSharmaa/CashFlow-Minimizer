# Cash Flow Minimizer 💸

## Introduction

This project helps simplify money transactions between friends or groups.

During trips or events, people often spend money for each other. After many transactions, it becomes confusing to track who should pay whom.

This program minimizes unnecessary payments and finds the minimum number of transactions needed to settle all balances.

---

# Problem Statement

Transactions are given in this format:

```txt
Person A owes Person B amount X
```

The goal is to:

* Settle everyone's balance
* Keep the total money correct
* Minimize the number of transactions

---

# Example

## Input

```txt
Tom pays Jerry 1000
Jerry pays Spike 1000
Spike pays Tom 500
```

## Net Balance

```txt
Tom   = -500
Jerry = 0
Spike = +500
```

Jerry is already settled.

So instead of:

```txt
Tom -> Jerry -> Spike
```

We directly do:

```txt
Tom pays Spike 500
```

---

# Approach

## Step 1 — Calculate Net Balance

For every transaction:

* Sender loses money
* Receiver gains money

Example:

```txt
Alice pays Bob 1000
```

Balance becomes:

```txt
Alice = -1000
Bob   = +1000
```

---

## Step 2 — Separate People

* Negative balance → Person needs to pay
* Positive balance → Person should receive

---

## Step 3 — Minimize Transactions

We directly match debtors with creditors using a greedy approach.

At every step:

```txt
settledAmount = min(debt, credit)
```

This removes unnecessary middle transactions.

---

# Time Complexity

```txt
O(N + P)
```

Where:

* N = number of transactions
* P = number of unique people

---

# Space Complexity

```txt
O(P)
```

---

# Technologies Used

* C++
* STL
* Hash Maps
* Greedy Algorithm

---

# Project Structure

```txt
CashFlow-Minimizer/
│
├── main.cpp
├── README.md

```

---

# How to Run

## Compile

```bash
g++ main.cpp -o app
```

## Run

```bash
./app
```

---

# Sample Output

```txt
Optimized Transactions:

Tom pays Spike ₹500
```

---

# Author

Balmukand Sharma
B.Tech CSE | Full Stack Developer
