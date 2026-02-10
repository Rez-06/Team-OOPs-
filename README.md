# 🎮 XOR Gaming Cafe & Restaurant Management System (C++)

A complete **console-based Restaurant + Gaming Zone Management System** written in **C++ using Object-Oriented Programming (OOP)** concepts and file handling.  
This project simulates the real-world operations of a gaming café that includes a food service, kitchen workflow, game rentals, and financial register management.

---

## 📌 Features Overview

### 🔐 Authentication System
- Login / Sign Up / Forgot Password
- Role-based access:
  - **Admin**
  - **Chef**
  - **Customer**

---

## 🍔 Restaurant Management

### 📋 Food Menu
- Add, update, delete food items
- Each food item contains:
  - Name
  - Price
  - Recipe
  - Required ingredients & quantity
- Menu items are stored in **binary files**
- **Customer only sees food that is available based on inventory**

###  Inventory Management
- Add new ingredients
- Refill or update stock
- Automatic stock deduction when orders are placed
- Prevents ordering when ingredients are insufficient

###  Order System
- Customers can place food orders
- Inventory is validated and deducted
- Orders are pushed to the **Kitchen Queue**
- Fake transaction loading screen using `chrono`

###  Kitchen Queue (Chef)
- View pending orders
- View recipes of ordered food
- Confirm and complete orders

---

##  Game Zone Management

###  Game Catalogue
- Admin can add or remove games
- Each game includes:
  - Name
  - Genre
  - Description
  - Release Date

### 🎧 Rental System
- Supports **PlayStation 1–4**
- 1–4 controllers supported
- Pricing rules:
  - 2 controllers:
    - 1 hour → 150 BDT
    - 30 minutes → 100 BDT
  - Extra controller:
    - +50 BDT (1 hour)
    - +30 BDT (30 minutes)
- Customers choose time slots
- If all slots are booked → **Unavailable shown**
- Admin can update prices and slot count
- Rental goes through transaction screen

---

##  Register & Transaction System

- Central register for **all money flow**
- Tracks:
  - Food purchases
  - Game rentals
  - Cash-outs
- Features:
  - Total cash in register
  - Best-selling food item
  - Most rented game
  - Total income (Cafe + Game Zone)
- Admin-only **cash-out** feature with description
- All transactions stored in files with timestamps

---

##  Technologies Used

- **C++**
- Object-Oriented Programming (OOP)
- File Handling (`.txt` / `.dat`)
- STL (`vector`, `queue`, `map`)
- `chrono` for fake loading screens
- Console-based UI

---

##  Project Structure

├── main.cpp
├── login.h / login.cpp
├── passcode.h / passcode.cpp
├── admin.h / admin.cpp
├── chef.h / chef.cpp
├── customer.h / customer.cpp
├── food_menu.h / food_menu.cpp
├── inventory.h / inventory.cpp
├── order.h / order.cpp
├── kitchen_queue.h / kitchen_queue.cpp
├── game_catalogue.h / game_catalogue.cpp
├── rental.h / rental.cpp
├── register.h / register.cpp


---

##  How to Run

1. Clone the repository
2. Open in **Code::Blocks / GCC**
3. Compile all `.cpp` files
4. Run `main.cpp`

---

##  Author

Developed as an **academic OOP project** demonstrating real-world system design using C++.



