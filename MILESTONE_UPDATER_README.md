# GitHub Milestone Updater

A Python script to push all milestones in a GitHub repository by 1 week.

## 🚀 Quick Start

### Prerequisites

1. **Python 3.6+** installed
2. **GitHub Personal Access Token** with `repo` permissions
3. **Repository access** (owner or collaborator)

### Installation

1. **Install dependencies:**
   ```bash
   pip install -r requirements.txt
   ```

2. **Create GitHub Personal Access Token:**
   - Go to GitHub Settings → Developer settings → Personal access tokens
   - Generate new token with `repo` scope
   - Copy the token (you'll need it for the script)

### Usage

#### Method 1: Python Script (Cross-platform)
```bash
# Dry run (see what would be updated)
python update_milestones.py owner repo token --dry-run

# Actually update milestones
python update_milestones.py owner repo token
```

#### Method 2: Batch File (Windows)
```bash
# Dry run
update_milestones.bat owner repo token --dry-run

# Actually update milestones
update_milestones.bat owner repo token
```

### Examples

```bash
# For repository: https://github.com/octocat/my-project
python update_milestones.py octocat my-project ghp_xxxxxxxxxxxxxxxx

# Dry run first to see changes
python update_milestones.py octocat my-project ghp_xxxxxxxxxxxxxxxx --dry-run
```

## 📋 Parameters

- **owner**: GitHub username or organization name
- **repo**: Repository name
- **token**: GitHub Personal Access Token
- **--dry-run**: (Optional) Show what would be updated without making changes

## 🔧 How It Works

1. **Fetches all milestones** from the specified repository
2. **Calculates new due dates** by adding 7 days to current due dates
3. **Updates each milestone** via GitHub API
4. **Reports success/failure** for each milestone

## 📊 Sample Output

```
Fetching milestones for octocat/my-project...
Found 3 milestones:

  Sprint 1:
    Current due: 2024-01-15
    New due: 2024-01-22
    ✅ Updated successfully

  Sprint 2:
    Current due: 2024-01-29
    New due: 2024-02-05
    ✅ Updated successfully

  Release v1.0:
    Current due: 2024-02-12
    New due: 2024-02-19
    ✅ Updated successfully

All milestones updated successfully!
```

## 🛠️ Troubleshooting

### Common Issues

**"Error fetching milestones: 404"**
- Check repository name and owner
- Verify you have access to the repository
- Ensure token has `repo` permissions

**"Error fetching milestones: 401"**
- Invalid or expired token
- Token doesn't have required permissions
- Generate a new token with `repo` scope

**"No milestones found"**
- Repository has no milestones
- All milestones are already closed
- Check repository settings

### Manual Token Creation

1. Go to [GitHub Settings](https://github.com/settings/tokens)
2. Click "Generate new token (classic)"
3. Select scopes:
   - ✅ `repo` (Full control of private repositories)
4. Click "Generate token"
5. Copy the token immediately (it won't be shown again)

## 🔒 Security Notes

- **Never commit your token** to version control
- **Use environment variables** in production
- **Rotate tokens regularly** for security
- **Use minimal required permissions**

## 📝 Advanced Usage

### Environment Variables
```bash
# Set token as environment variable
export GITHUB_TOKEN=ghp_xxxxxxxxxxxxxxxx
python update_milestones.py owner repo $GITHUB_TOKEN
```

### Custom Date Range
To modify the script for different time periods, edit the `timedelta(days=7)` line in `update_milestones.py`:

```python
# Push by 2 weeks
new_due = current_due + timedelta(days=14)

# Push by 1 month
new_due = current_due + timedelta(days=30)
```

## 🤝 Contributing

Feel free to:
- Add support for different time periods
- Improve error handling
- Add support for filtering milestones
- Create GUI version

## 📄 License

This tool is provided as-is for personal and organizational use.
