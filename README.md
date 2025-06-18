<h1>🍨 Stock Management System (Ice‑Cream Parlor)</h1>
A tiny C++ console application that lets you manage the inventory of a fictional ice‑cream shop—complete with a login prompt, flavor CRUD, and simple file persistence.

✨ Features
Capability	Details
Secure login	Checks the username (A, B, or C) plus a hard‑coded password (pass123).
Add flavors	Store up to MAX_FLAVORS (default = 10). Persists additions to flavors.txt.
Remove flavors	Delete a flavor by name; array items are automatically compacted.
View inventory	Lists each flavor and its remaining quantity.
Light persistence	Every successful addFlavor appends a line of the form name‑quantity to flavors.txt.

🏗️ Build & Run
### Prerequisites

C++17‑capable compiler (e.g. g++ 10+ or clang 12+)


# Build
g++ -std=c++17 -Wall -Wextra -o ice_parlor main.cpp

# Run
./ice_parlor
Windows: replace the last line with ice_parlor.exe.

🚀 Quick Demo
text
Copy code
Welcome To AI Ice-Cream Parlor

Enter username: A
Enter password: pass123

            || ACCESS GRANTED ||
Welcome A

Please choose an option:
1. Add Flavor
2. Remove Flavor
3. View Available Flavors
4. Exit
Enter your choice: 1
Enter flavor name: Strawberry
Enter quantity: 30
Strawberry flavor added successfully.
⚙️ Configuration
Macro / Variable	Purpose	Default
MAX_FLAVORS	Array capacity	 10
validUsers	Whitelisted usernames	 {"A","B","C"}
Password	Hard‑coded string inside login()	 pass123
flavors.txt	Append‑only log of added flavors	 —

Feel free to tweak these in main.cpp.

📂 Project Structure
bash
Copy code
│
├── main.cpp      # All application logic
└── README.md     # You are here
🛣️ Roadmap / Ideas
✅ Replace C‑style strings with std::string

✅ Swap raw array for std::vector<Flavor>

⏳ Refactor persistence into CSV or JSON

⏳ Unit tests (Catch2 / GoogleTest)

⏳ Password hashing & user management


Author: Mayank Kumar Gupta  •  🌐 Portfolio  •  ✉️ mg258087@gmail.com
