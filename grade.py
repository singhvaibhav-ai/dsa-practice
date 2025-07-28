import numpy as np

def assign_relative_grade(mark, avg, std, max_marks, top_score, x_p=1.0, x_f=1.0):
    threshold_o = min(avg + 1.5 * std, max_marks)
    if mark == top_score:
        return "O"
    elif mark > threshold_o:
        return "O"
    elif mark >= avg - 1.5 * std:
        return "E"
    elif mark >= max(avg - x_p * std, 40):
        return "P"
    elif mark < max(avg - x_f * std, 40):
        return "F"
    else:
        return "Other"

def assign_absolute_grade(mark):
    if mark >= 90:
        return "O"
    elif mark >= 80:
        return "A"
    elif mark >= 70:
        return "B"
    elif mark >= 60:
        return "C"
    elif mark >= 50:
        return "D"
    elif mark >= 40:
        return "P"
    else:
        return "F"

def calculate_grades(students, mode):
    grades = {}
    if mode == "1":
        marks_array = np.array(list(students.values()))
        avg = np.mean(marks_array)
        std = np.std(marks_array)
        top_score = max(marks_array)
        max_marks = 100
        for name, mark in students.items():
            grades[name] = assign_relative_grade(mark, avg, std, max_marks, top_score)
    else:
        for name, mark in students.items():
            grades[name] = assign_absolute_grade(mark)
    return grades

# --- Main loop ---
students = {}

# Step 1: Enter data
while True:
    try:
        n = int(input("Enter number of students: "))
        break
    except:
        print("Invalid input. Try again.")

for _ in range(n):
    name = input("Enter student name or roll number: ")
    while True:
        try:
            marks = float(input(f"Enter marks for {name}: "))
            break
        except:
            print("Invalid marks. Try again.")
    students[name] = marks

# Step 2: Choose grading mode
while True:
    print("\nSelect grading mode:")
    print("1. Relative Grading")
    print("2. Absolute Grading")
    grading_choice = input("Enter 1 or 2: ")
    if grading_choice in ["1", "2"]:
        break
    else:
        print("Invalid choice. Try again.")

# Main menu loop
while True:
    grades = calculate_grades(students, grading_choice)

    print("\n--- Main Menu ---")
    print("1. View grades of all students (rank-wise)")
    print("2. View grade of a specific student")
    print("3. Edit student marks")
    print("4. Edit student name/roll number")
    print("5. Change grading mode (relative/absolute)")
    print("6. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        sorted_students = sorted(students.items(), key=lambda x: x[1], reverse=True)
        print("\nGrades (Rank-wise):")
        for name, mark in sorted_students:
            print(f"{name} (Marks: {mark}) → Grade: {grades[name]}")
    
    elif choice == "2":
        while True:
            query = input("Enter student name/roll (or 'back' to return): ")
            if query.lower() == "back":
                break
            elif query in grades:
                print(f"{query}'s Grade: {grades[query]}")
            else:
                print("Student not found.")

    elif choice == "3":
        name = input("Enter student name/roll to edit marks: ")
        if name in students:
            while True:
                try:
                    new_marks = float(input(f"Enter new marks for {name}: "))
                    students[name] = new_marks
                    print("Marks updated.")
                    break
                except:
                    print("Invalid input. Try again.")
        else:
            print("Student not found.")

    elif choice == "4":
        old_name = input("Enter current student name/roll: ")
        if old_name in students:
            new_name = input("Enter new name/roll: ")
            students[new_name] = students.pop(old_name)
            print("Name/roll updated.")
        else:
            print("Student not found.")

    elif choice == "5":
        while True:
            print("\nSelect new grading mode:")
            print("1. Relative Grading")
            print("2. Absolute Grading")
            new_mode = input("Enter 1 or 2: ")
            if new_mode in ["1", "2"]:
                grading_choice = new_mode
                print("Grading mode updated.")
                break
            else:
                print("Invalid choice. Try again.")

    elif choice == "6":
        print("Exiting. Have a nice day!")
        break

    else:
        print("Invalid choice. Try again.")
