# LeetCode Practice

This repository contains my LeetCode practice solutions in C++.

## 🚀 Quick Start

### Automated Setup (Recommended)

1. **Generate new problem file:**
   ```bash
   .\new_problem.bat 1234_Problem_Name
   ```

2. **Add test cases to `input.txt`**

3. **Press `Ctrl + Alt + N` to run**

### Manual Setup

1. **Use VS Code snippets:**
   - Type `lc` for string input problems
   - Type `lcv` for vector input problems

2. **Or copy from `template.cpp`**

## 📁 File Structure

- `*.cpp` - LeetCode solutions
- `input.txt` - Test cases (one per line)
- `output.txt` - Program output
- `template.cpp` - Template for new problems
- `run_cpp.bat` - Compilation and execution script
- `new_problem.bat` - Problem file generator

## ⚙️ Configuration

The following files are configured for automation but excluded from git:
- `.vscode/settings.json` - Code Runner configuration
- `.vscode/tasks.json` - Build tasks
- `.vscode/cpp.code-snippets` - VS Code snippets
- `template.cpp` - Problem template
- `run_cpp.bat` - Execution script
- `new_problem.bat` - File generator

## 🎯 Usage Examples

### String Input Problem
```cpp
// Generated with: .\new_problem.bat 2264_Largest_3_Same_Digit_Number_In_A_String
class Solution {
public:
    string largestGoodInteger(string num) {
        // Your solution here
    }
};
```

### Vector Input Problem
```cpp
// Use 'lcv' snippet in VS Code
class Solution {
public:
    int twoSum(vector<int>& nums, int target) {
        // Your solution here
    }
};
```

## 🔧 Requirements

- MinGW (g++ compiler)
- VS Code with Code Runner extension
- Windows PowerShell

## 📝 Notes

- All solutions automatically read from `input.txt`
- Output is written to `output.txt`
- Use `Ctrl + Alt + N` to run any C++ file
- Configuration files are gitignored for personal use
