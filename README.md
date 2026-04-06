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
<img width="692" height="471" alt="Screenshot 2026-04-06 120400" src="https://github.com/user-attachments/assets/961deca8-7fd4-415a-8195-0d00a0c1ab2d" />

2. Add Student  
<img width="659" height="642" alt="Screenshot 2026-04-06 120522" src="https://github.com/user-attachments/assets/3e0c8094-6ae2-471c-aaee-ec52c97d57d6" />

3. Display All Students  
<img width="788" height="1021" alt="Screenshot 2026-04-06 120741" src="https://github.com/user-attachments/assets/f3b69ff5-93bf-47ba-b5ed-a7d69941e918" />

4. Search Student
  <img width="732" height="739" alt="Screenshot 2026-04-06 120802" src="https://github.com/user-attachments/assets/e06afb31-37ff-47fd-b544-7aa849495c04" />

5. Update Student
    <img width="767" height="653" alt="Screenshot 2026-04-06 120830" src="https://github.com/user-attachments/assets/b0a3c41c-9088-4fee-879e-bd54772762c2" />

6. Delete Student
  <img width="816" height="520" alt="Screenshot 2026-04-06 120855" src="https://github.com/user-attachments/assets/b9a2e9bc-e778-4592-8de4-58b8086ac36c" />

7. Count Students
  <img width="746" height="506" alt="Screenshot 2026-04-06 120907" src="https://github.com/user-attachments/assets/5d71f922-f66f-49f9-a438-e917b6ae83d4" />

8. Find Topper
 <img width="950" height="787" alt="Screenshot 2026-04-06 120928" src="https://github.com/user-attachments/assets/4f378314-2dae-4acb-8ca5-9f4187a68fbe" />

9. Students Above Marks
<img width="830" height="807" alt="Screenshot 2026-04-06 120948" src="https://github.com/user-attachments/assets/6e5e4f8c-2a29-4d13-ae23-bfb7dcc26c9a" />

0. Exit
<img width="715" height="541" alt="Screenshot 2026-04-06 121000" src="https://github.com/user-attachments/assets/a916720d-93cd-4cea-b60a-02efe74706e9" />



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
