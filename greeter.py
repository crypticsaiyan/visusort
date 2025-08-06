import os
import subprocess
import sys
import termios
import tty

options = ["Selection Sort", "Insertion Sort", "Bubble Sort", "Quick Sort", "Merge Sort", "Heap Sort"]
selected = 0
mapping = {
    "Selection Sort": "selection",
    "Insertion Sort": "insertion",
    "Bubble Sort": "bubble",
    "Quick Sort": "quick",
    "Merge Sort": "merge",
    "Heap Sort": "heap"
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
    print("██╗   ██╗██╗███████╗██╗   ██╗███████╗ ██████╗ ██████╗ ████████╗")
    print("██║   ██║██║██╔════╝██║   ██║██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝")
    print("██║   ██║██║███████╗██║   ██║███████╗██║   ██║██████╔╝   ██║   ")
    print("╚██╗ ██╔╝██║╚════██║██║   ██║╚════██║██║   ██║██╔══██╗   ██║   ")
    print(" ╚████╔╝ ██║███████║╚██████╔╝███████║╚██████╔╝██║  ██║   ██║   ")
    print("  ╚═══╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝")
    print("\nUse ↑/↓ arrow keys to move, Enter to select:\n")
    for i, option in enumerate(options):
        marker = "[x] " if i == selected else "[ ] "
        print(f"{marker}{option}")
    print("\nPress 'q' to quit")

while True:
    print_menu()
    key = get_key()

    if key == '\033[A':  # Up arrow
        selected = (selected - 1) % len(options)
    elif key == '\033[B':  # Down arrow
        selected = (selected + 1) % len(options)
    elif key == "\r" or key == "\n":  # Enter key
        clear()
        print("\033[?25h", end="", flush=True)  # Show cursor
        subprocess.run(["./main", mapping[options[selected]]])
        print("\nPress any key to return to menu...")
        get_key()
    elif key.lower() == "q":
        clear()
        print("\033[?25h", end="", flush=True)  # Show cursor before exit
        print("Goodbye!")
        break
