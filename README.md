# Cash Flow Minimizer 💸

## Introduction

This project simplifies money transactions between people by reducing unnecessary payments.

It calculates the final balance of each person and finds the minimum number of transactions required to settle all debts.

---

# Problem Statement

Transactions are given in this format:

```txt
Person A owes Person B amount X
```

The goal is to:

* Settle everyone's balance
* Keep the money transfer correct
* Minimize the number of transactions

---

# Example

## Input

```txt
Tom pays Jerry 1000
Jerry pays Spike 1000
Spike pays Tom 500
```

## Output

```txt
Tom pays Spike 500
```

---

# Approach

## Step 1

Calculate the net balance of every person.

* Negative balance → needs to pay
* Positive balance → should receive

## Step 2

Match debtors and creditors directly using a greedy approach.

This removes unnecessary intermediate transactions.

---

# Time Complexity

```txt
O(N + P)
```

Where:

* N = number of transactions
* P = number of people

---

# Technologies Used

* C++
* STL
* Hash Maps
* Greedy Algorithm

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

# Author

Balmukand Sharma
