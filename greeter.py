import os
import subprocess
import sys
import termios
import tty

options = ["Selection Sort", "Insertion Sort", "Bubble Sort", "Quick Sort", "Merge Sort", "Heap Sort", "Counting Sort"]
selected = 0
display_theory = False  # Checkbox state for displaying theory
mapping = {
    "Selection Sort": "selection",
    "Insertion Sort": "insertion",
    "Bubble Sort": "bubble",
    "Quick Sort": "quick",
    "Merge Sort": "merge",
    "Heap Sort": "heap",
    "Counting Sort": "counting",
}

def clear():
    print("\033[2J\033[1;1H\033[3J\033[?25l", end="", flush=True)  # Clear screen and hide cursor

def get_key():
    """Get a single key press without requiring Enter"""
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(1)
        # Handle arrow keys (they come as escape sequences)
        if key == '\033':  # ESC sequence
            key += sys.stdin.read(2)  # Read the next two characters
        return key
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

def print_menu():
    clear()
    print("\033[1;34m██╗   ██╗██╗███████╗██╗   ██╗███████╗ ██████╗ ██████╗ ████████╗")
    print("██║   ██║██║██╔════╝██║   ██║██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝")
    print("██║   ██║██║███████╗██║   ██║███████╗██║   ██║██████╔╝   ██║   ")
    print("╚██╗ ██╔╝██║╚════██║██║   ██║╚════██║██║   ██║██╔══██╗   ██║   ")
    print(" ╚████╔╝ ██║███████║╚██████╔╝███████║╚██████╔╝██║  ██║   ██║   ")
    print("  ╚═══╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝\033[0m")
    print("\nUse ↑/↓ arrow keys to move, Enter to select:\n")
    
    # Display theory checkbox
    if selected == -1:
        checkbox = "\033[1;34m[x] " if display_theory else "\033[1;34m[ ] "
        print(f"{checkbox}Display Theory\033[0m")
    else:
        checkbox = "[x] " if display_theory else "[ ] "
        print(f"{checkbox}Display Theory")
    
    print()  # Empty line for separation
    
    for i, option in enumerate(options):
        if i == selected:
            marker = "\033[1;34m[x] "  # Bold blue
            print(f"{marker}{option}\033[0m")  # Reset formatting after
        else:
            marker = "[ ] "
            print(f"{marker}{option}")
    print("\nPress 'q' to quit")

while True:
    print_menu()
    key = get_key()

    if key == '\033[A':  # Up arrow
        if selected == -1:
            selected = len(options) - 1
        elif selected == 0:
            selected = -1
        else:
            selected = selected - 1
    elif key == '\033[B':  # Down arrow
        if selected == -1:
            selected = 0
        elif selected == len(options) - 1:
            selected = -1
        else:
            selected = selected + 1
    elif key == "\r" or key == "\n":  # Enter key
        if selected == -1:
            # Toggle display theory checkbox
            display_theory = not display_theory
        else:
            # Run the selected sorting algorithm
            clear()
            print("\033[?25h", end="", flush=True)  # Show cursor
            theory_arg = "1" if display_theory else "0"
            subprocess.run(["./main", mapping[options[selected]], theory_arg])
            get_key()
    elif key.lower() == "q":
        clear()
        print("\033[?25h", end="", flush=True)  # Show cursor before exit
        print("Goodbye!")
        break
