# 🎓 SCHOOL ADMINISTRATION SYSTEM

### *Efficient Student Record Management using Binary Search Tree (C Programming)*

## 👥 Team Members

* C. Karthik Varma
* P. Siva Kumar Reddy

---

## 📌 Project Overview

This project is a **School Administration System** implemented in **C programming** using a **Binary Search Tree (BST)**. It manages student records efficiently with dynamic memory allocation and provides multiple operations such as insertion, deletion, searching, updating, and analysis of student data.

---

## ❗ Problem Statement

To design and implement a system that efficiently manages student records, allowing:

* Storage of student details
* Fast searching and retrieval
* Dynamic updates and deletions
* Analytical operations like finding toppers and filtering students

---

## 🌳 Data Structure Used

### Binary Search Tree (BST)

* Each node represents a student
* Left subtree → IDs smaller than root
* Right subtree → IDs greater than root

### Why BST?

* Efficient search, insert, delete → **O(log n)** (average case)
* Maintains sorted order of records
* Suitable for dynamic data

---

## ⚙️ Features / Operations
```
✔ Add Student
✔ Display All Students (Inorder Traversal)
✔ Search Student by ID
✔ Update Student Details
✔ Delete Student
✔ Count Total Students
✔ Find Topper (Highest Marks) 🏆
✔ Display Students Above Given Marks 🎯
✔ Automatic Grade Calculation (A/B/C/D/F)
✔ Memory Management using `malloc()` and `free()`
```

---

## 🧠 Algorithm Explanation

### 🔹 Insertion

* Compare ID with root
* Insert into left/right subtree recursively

### 🔹 Deletion

* Case 1: No child → Delete node
* Case 2: One child → Replace node
* Case 3: Two children → Replace with inorder successor

### 🔹 Searching

* Traverse BST based on ID comparison

### 🔹 Topper Finding

* Traverse entire tree
* Track node with maximum marks

### 🔹 Filtering (Above Marks)

* Inorder traversal
* Print students with marks > threshold

---

## 🛠️ Compilation & Execution

> 📦 **Compile**

```bash
gcc school_admin.c -o school_admin
```

> ▶️ **Run**

```bash
./school_admin
```

---

## 🖥️ Sample Output
1. Menu
"C:\Users\KARTHIK\Pictures\Screenshots\Screenshot 2026-04-06 120400.png"
2. Add Student  
3. Display All Students  
4. Search Student  
5. Update Student  
6. Delete Student  
7. Count Students  
8. Find Topper  
9. Students Above Marks  
0. Exit  



## 🚀 Conclusion

This project demonstrates:

* Efficient data handling using **BST**
* Use of **dynamic memory allocation**
* Implementation of **real-world CRUD operations**
* Clean modular programming in C

---

## 📎 Notes

* Memory is safely managed using `freeTree()`
* Program avoids memory leaks
* Easily extendable (file handling, login system, etc.)

---

## 📖 Project Summary
⭐ A simple and efficient system to manage student records using BST with fast operations, clear structure, and proper memory handling.
