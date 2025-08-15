# LeetCode Practice

This repository contains my LeetCode practice solutions in C++ with an automated setup for efficient problem-solving.

## 🚀 Quick Start

### Method 1: Automated File Generation (Recommended)

1. **Generate new problem file:**
   ```bash
   .\new_problem.bat 1234_Problem_Name
   ```

2. **Add test cases to `input.txt`:**
   ```
   3
   test_case_1
   test_case_2
   test_case_3
   ```

3. **Press `Ctrl + Alt + N` to run**

### Method 2: VS Code Snippets

1. **Create new `.cpp` file**
2. **Type snippet prefix:**
   - `lc` - String input problems
   - `lcv` - Vector input problems
   - `lcm` - Multiple input types
3. **Press Tab to expand**
4. **Replace placeholders** (`$1`, `$2`) with your function

### Method 3: Template Copy

1. **Copy `template.cpp`** to your new file
2. **Rename** and modify as needed

## 📁 File Structure

```
LeetCode/
├── *.cpp                    # LeetCode solutions
├── input.txt               # Test cases (first line = count)
├── output.txt              # Program output
├── template.cpp            # Template for new problems
├── run_cpp.bat            # Compilation and execution script
├── new_problem.bat        # Problem file generator
├── .vscode/               # VS Code configuration
│   ├── settings.json      # Code Runner settings
│   ├── tasks.json         # Build tasks
│   └── cpp.code-snippets  # VS Code snippets
└── .gitignore             # Git ignore rules
```

## ⚙️ Configuration Files

The following files are configured for automation but excluded from git:
- `.vscode/settings.json` - Code Runner configuration
- `.vscode/tasks.json` - Build tasks
- `.vscode/cpp.code-snippets` - VS Code snippets
- `template.cpp` - Problem template
- `run_cpp.bat` - Execution script
- `new_problem.bat` - File generator
- `input.txt` - Test data
- `output.txt` - Program output

## 🎯 Usage Examples

### Input Format
```
3
6777133339
2300019
42352338
```
- **First line**: Number of test cases
- **Following lines**: Test case inputs

### Example 1: String Input Problem
```cpp
// Generated with: .\new_problem.bat 2264_Largest_3_Same_Digit_Number_In_A_String
class Solution {
public:
    string largestGoodInteger(string num) {
        int i = 0;
        string retStr = "";

        while (i < num.length() - 2) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string current = num.substr(i, 3);
                if (retStr.empty() || current > retStr) {
                    retStr = current;
                }
                i += 3;
            } else {
                i++;
            }
        }

        return retStr;
    }
};
```

### Example 2: Vector Input Problem
```cpp
// Use 'lcv' snippet in VS Code
class Solution {
public:
    int twoSum(vector<int>& nums, int target) {
        // Your solution here
        return 0;
    }
};
```

### Example 3: Multiple Input Types
```cpp
// Use 'lcm' snippet in VS Code
class Solution {
public:
    string someFunction(string str, int num) {
        // Your solution here
        return str + to_string(num);
    }
};
```

## 🔧 Setup Requirements

### Prerequisites
- **MinGW** (g++ compiler) - [Download here](https://sourceforge.net/projects/mingw/)
- **VS Code** with Code Runner extension
- **Windows PowerShell**

### Installation Steps
1. **Install MinGW** and add to PATH
2. **Install VS Code** and Code Runner extension
3. **Clone this repository**
4. **Test setup**: Run `.\new_problem.bat test` and `Ctrl + Alt + N`

## 🛠️ Troubleshooting

### Common Issues

**"g++ not found"**
```bash
# Add MinGW to PATH or use full path
C:\MinGW\bin\g++.exe -o program.exe program.cpp
```

**"Code Runner not working"**
- Check if Code Runner extension is installed
- Verify `.vscode/settings.json` exists
- Try running in terminal: `.\run_cpp.bat filename.cpp`

**"Input not reading correctly"**
- Ensure first line in `input.txt` is the test case count
- Check for extra spaces or newlines
- Verify `cin.ignore()` is called after reading count

### Manual Compilation
```bash
# Compile
g++ -o program.exe program.cpp

# Run with input/output redirection
program.exe < input.txt > output.txt
```

## 📝 Best Practices

### File Naming
- Use format: `1234_Problem_Name.cpp`
- Example: `0001_TwoSum.cpp`, `2264_Largest_3_Same_Digit_Number_In_A_String.cpp`

### Input Format
- Always start with test case count
- One test case per line
- Use consistent formatting

### Code Structure
- Keep Solution class clean
- Use meaningful variable names
- Add comments for complex logic

## 🎯 Workflow Summary

1. **Generate** new file: `.\new_problem.bat problem_name`
2. **Open** in VS Code
3. **Replace** `yourFunction` with actual function name
4. **Implement** your solution
5. **Add** test cases to `input.txt`
6. **Run**: `Ctrl + Alt + N`
7. **Check** `output.txt` for results

## 📊 Current Solutions

This repository contains solutions for various LeetCode problems including:
- Array manipulation
- String processing
- Dynamic programming
- Graph algorithms
- And more...

## 🤝 Contributing

Feel free to:
- Add new solutions
- Improve existing code
- Suggest enhancements to the automation setup

## 📄 License

This project is for personal learning and practice purposes.

---

**Happy Coding! 🚀**
