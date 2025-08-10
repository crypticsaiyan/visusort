# VisuSort - Sorting Algorithm Visualizer

<div align="center">

```
██╗   ██╗██╗███████╗██╗   ██╗███████╗ ██████╗ ██████╗ ████████╗
██║   ██║██║██╔════╝██║   ██║██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝
██║   ██║██║███████╗██║   ██║███████╗██║   ██║██████╔╝   ██║   
╚██╗ ██╔╝██║╚════██║██║   ██║╚════██║██║   ██║██╔══██╗   ██║   
 ╚████╔╝ ██║███████║╚██████╔╝███████║╚██████╔╝██║  ██║   ██║   
  ╚═══╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝
```

*A terminal-based interactive sorting algorithm visualizer written in C++*

</div>

## 🎯 Supported Sorting Algorithms

- Selection Sort
- Insertion Sort
- Bubble Sort
- Quick Sort
- Merge Sort
- Heap Sort
- Counting Sort

## 💡 Prerequisites

- C++ compiler with C++20 support (g++, clang++)
- Python 3.x (for the interactive menu)
- Linux/Unix-like environment (or WSL on Windows)

## 🛠️ Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/crypticsaiyan/visusort.git
   cd visusort
   ```

2. **Build the project:**
   ```bash
   # Using the installation script (recommended)
   chmod +x installation.sh
   ./installation.sh
   
   # Or manually
   g++ -O3 -DNDEBUG -march=native -s $(find . -name "*.cpp") -o main
   ```

## 📚 Usage

### Method 1: Interactive Python Menu (Recommended)

```bash
python3 visusort.py
```


### Method 2: Direct Command Line

```bash
./main <algorithm> <display_theory>
```

**Parameters:**
- `<algorithm>`: One of `selection`, `insertion`, `bubble`, `quick`, `merge`, `heap`, `counting`
- `<display_theory>`: `1` to show theory, `0` to skip

**Examples:**
```bash
# Run bubble sort with theory explanations
./main bubble 1

# Run quick sort without theory
./main quick 0

# Run merge sort with theory
./main merge 1
```

**Example Session:**
```
Enter the length of test array: 5
Enter the values separated by spaces: 64 34 25 12 22
```

## 🎨 Visual Elements

- **`^`**: Current element being processed
- **`*`**: Element being compared
- **Red highlighting**: Elements being swapped
- **Green highlight**: Element(s) currently being compared
- **Blue highlight**: Element(s) actively being processed or manipulated
- **Yellow highlight**: Element(s) that are sorted and in their final position
- **Comparison counter**: Real-time count of comparisons made

**Note:** The visual elements may vary slightly based on the terminal emulator used.

## 📝 License



## 📊 Performance Notes

- **Small Arrays (< 20 elements)**: All algorithms perform similarly
- **Medium Arrays (20-100 elements)**: O(n log n) algorithms show clear advantages
- **Large Arrays (> 100 elements)**: Performance differences become very apparent
- **Counting Sort**: Excellent for arrays with small range of values

---

<div align="center">

**Made with ❤️ by crypticsaiyan**

[Report Bug](https://github.com/crypticsaiyan/visusort/issues) · [Request Feature](https://github.com/crypticsaiyan/visusort/issues)

</div>
