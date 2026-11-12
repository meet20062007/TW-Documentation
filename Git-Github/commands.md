# Git Command Handbook

A categorized handbook of commonly used Git commands, with examples for configuration, repositories, commits, branches, collaboration, recovery, and maintenance.

## 1. Getting Git Ready

### Set your identity
```bash
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
```

### Inspect configuration
```bash
git config --list
git config user.name
git config --global --list
```

### Choose an editor
```bash
git config --global core.editor "code --wait"
git config --global core.editor "vim"
```

### Define shortcuts
```bash
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.lg "log --oneline --graph --all"
```

### Remove a setting
```bash
git config --global --unset user.name
```

## 2. Starting or Copying a Repository

### Create a repository
```bash
git init
git init project-name
```

### Copy an existing repository
```bash
git clone <url>
git clone <url> <directory-name>
git clone -b <branch> <url>
```

### Make a shallow clone
```bash
git clone --depth 1 <url>
```

## 3. Inspecting Repository State and History

### Check the working tree
```bash
git status
git status -s                 # Short format
git status -sb                # Short format with branch information
```

### Browse commit history
```bash
git log
git log --oneline
git log --oneline --graph --all
git log -n 5                  # Most recent 5 commits
git log --since="2 weeks ago"
git log --author="Name"
git log --grep="keyword"
git log -p                    # Include patches
git log --stat                # Include change statistics
```

### Inspect a commit
```bash
git show <commit-hash>
git show HEAD
git show HEAD~2
```

### See who changed each line
```bash
git blame <file>
```

## 4. Preparing and Saving Changes

### Stage files
```bash
git add <file>
git add .                     # Stage all changes
git add *.txt                 # Stage txt files
git add src/                  # Stage files in a directory
```

### Stage selected parts interactively
```bash
git add -p
```

### Remove files from the staging area
```bash
git reset HEAD <file>
git restore --staged <file>
```

### Create or update commits
```bash
git commit -m "Message"
git commit                    # Open the configured editor
git commit -am "Message"     # Commit changes to tracked files
git commit --amend            # Modify the latest commit
git commit --amend -m "New message"
```

## 5. Working with Branches

### Display branches
```bash
git branch                    # Local branches
git branch -a                 # Local and remote-tracking branches
git branch -r                 # Remote-tracking branches
```

### Create a branch
```bash
git branch <branch-name>
git branch <branch-name> <commit-hash>
```

### Move between branches
```bash
git checkout <branch-name>
git switch <branch-name>
```

### Create and switch in one step
```bash
git checkout -b <branch-name>
git switch -c <branch-name>
```

### Rename or remove a branch
```bash
git branch -m <old> <new>
git branch -m <new>           # Rename the current branch
git branch -d <branch-name>
git branch -D <branch-name>   # Force deletion
```

### Compare branches
```bash
git diff <branch1>..<branch2>
git log <branch1>..<branch2>
```

## 6. Combining Branch Histories

### Merge another branch
```bash
git merge <branch-name>
git merge --no-ff <branch>    # Create a merge commit instead of fast-forwarding
git merge --squash <branch>   # Combine changes for one commit
```

### Cancel a merge
```bash
git merge --abort
```

### Open a merge tool
```bash
git mergetool
```

## 7. Working with Remotes

### Register and inspect remotes
```bash
git remote add <name> <url>
git remote add origin https://github.com/user/repo.git
git remote
git remote -v
git remote show origin
```

### Remove or rename a remote
```bash
git remote remove <name>
git remote rename <old> <new>
```

### Download remote updates
```bash
git fetch
git fetch origin
git fetch origin <branch>
```

### Bring remote changes into your branch
```bash
git pull
git pull origin main
git pull --rebase             # Rebase instead of merging
```

### Send local changes to a remote
```bash
git push
git push origin main
git push -u origin main       # Set upstream tracking
 git push --all                # Push all branches
git push --tags               # Push tags
 git push origin --delete <branch>  # Delete a remote branch
```

### Force push (use with care)
```bash
git push --force              # Dangerous on shared branches
git push --force-with-lease   # Safer alternative
```

## 8. Comparing Changes

```bash
git diff                      # Unstaged changes
git diff --staged             # Staged changes
git diff --cached             # Another form for staged changes
git diff <commit1> <commit2>  # Compare commits
git diff <branch1>..<branch2> # Compare branches
git diff <file>               # Changes in one file
git diff HEAD <file>          # File compared with HEAD
git diff --stat               # Summary of changed files
```

## 9. Undoing Work and Correcting Commits

### Discard edits in the working directory
```bash
git checkout -- <file>
git restore <file>
```

### Discard all working-directory edits
```bash
git checkout .
git restore .
```

### Unstage a file
```bash
git reset HEAD <file>
git restore --staged <file>
```

### Move the current branch pointer back
```bash
git reset --soft HEAD~1       # Keep changes staged
git reset --mixed HEAD~1      # Keep changes unstaged
git reset --hard HEAD~1       # Discard changes
git reset --hard <commit>     # Reset to a chosen commit
```

### Undo a commit with a new commit
```bash
git revert <commit-hash>
git revert HEAD
```

## 10. Temporarily Shelving Work with Stash

```bash
git stash
git stash save "Message"
git stash -u                  # Include untracked files
git stash list
git stash apply               # Apply the latest stash
git stash apply stash@{0}     # Apply a specific stash
git stash pop                 # Apply and remove the stash
git stash show
git stash show -p              # Show the patch
git stash drop stash@{0}
git stash clear                # Remove all stashes
```

## 11. Marking Releases with Tags

### List tags
```bash
git tag
git tag -l "v1.*"
```

### Create tags
```bash
git tag v1.0.0                # Lightweight tag
git tag -a v1.0.0 -m "Version 1.0.0"  # Annotated tag
git tag -a v1.0.0 <commit> -m "Message"
```

### Inspect, publish, and delete tags
```bash
git show v1.0.0
git push origin v1.0.0
git push origin --tags
git tag -d v1.0.0             # Delete locally
git push origin --delete v1.0.0  # Delete remotely
```

## 12. Finding Text and Commits

### Search tracked files
```bash
git grep "search-term"
git grep -n "search-term"     # Include line numbers
git grep -c "search-term"     # Count matches
```

### Search commit history
```bash
git log -S "search-term"      # Commits that add/remove the term
git log --grep="search-term"  # Search commit messages
```

## 13. Removing Untracked Files

```bash
git clean -n                 # Preview what would be removed
git clean -f                 # Remove untracked files
git clean -fd                # Also remove untracked directories
git clean -fdx               # Also remove ignored files
```

## 14. Rewriting History with Rebase

```bash
git rebase <branch>
git rebase main
git rebase -i HEAD~3          # Interactive rebase of the last 3 commits
git rebase --continue
git rebase --abort
git rebase --skip
```

## 15. Applying Existing Commits Elsewhere

```bash
git cherry-pick <commit-hash>
git cherry-pick <commit1> <commit2>
git cherry-pick <commit1>..<commit2>
```

## 16. Using Submodules

```bash
git submodule add <url> <path>
git submodule init
git submodule update
git clone --recursive <url>
```

## 17. Repository Inspection and Maintenance

### Inspect files and file history
```bash
git log --follow <file>
git blame <file>
git ls-tree -r <commit> --name-only
git show <commit>:<file>
```

### Explore repository metadata
```bash
git reflog
git reflog show HEAD
git describe
git describe --tags
git shortlog
git shortlog -sn              # Summary by author
git count-objects -v
```

### Archive the current commit
```bash
git archive --format=zip HEAD > project.zip
```

### Maintenance and object cleanup
```bash
git gc
git prune
git gc --aggressive
```

### Calculate repository object sizes
```bash
git rev-list --objects --all | git cat-file --batch-check='%(objecttype) %(objectname) %(objectsize) %(rest)' | sort -k3 -n
```

## 18. Resolving Merge Conflicts

After a merge conflict:
```bash
git status                    # Identify conflicted files
# Edit the files manually and remove conflict markers
git add <resolved-file>
git commit
```

Choose one side of a conflicted file:
```bash
git checkout --theirs <file>
git checkout --ours <file>
```

You can also launch a merge tool:
```bash
git mergetool
```

## 19. Troubleshooting and Recovery

### Leave detached HEAD state
```bash
git checkout main
```

### Recover a deleted branch
```bash
git reflog
git checkout -b <branch> <commit-hash>
```

### Undo staging before committing
```bash
git reset
```

### Recover a lost commit
```bash
git reflog
git cherry-pick <commit-hash>
```

### Correct the latest commit message
```bash
git commit --amend -m "Correct message"
```

### Stop tracking a file but keep it on disk
```bash
git rm --cached <file>
```

## 20. Safety Checks and Useful Workflows

### Check operations before applying them
```bash
git push --dry-run
git fetch --dry-run
git fsck
git remote -v
git ls-remote
```

### Common multi-command workflows

Undo the latest commit while retaining its changes:
```bash
git reset --soft HEAD~1
```

Add a forgotten file to the latest commit without changing its message:
```bash
git add forgotten-file
git commit --amend --no-edit
```

Bring a fork's main branch up to date with its upstream:
```bash
git fetch upstream
git checkout main
git merge upstream/main
```

Create a branch from the latest stash:
```bash
git stash branch <branch-name>
```

List commits that are not yet in the remote-tracking main branch:
```bash
git log origin/main..HEAD
```

Delete every local branch other than `main`:
```bash
git branch | grep -v "main" | xargs git branch -D
```

## 21. Quick Syntax Reference

### HEAD and parent references

| Reference | Meaning |
|---|---|
| `HEAD` | Current commit |
| `HEAD~1` | One commit before HEAD |
| `HEAD~2` | Two commits before HEAD |
| `HEAD^` | First parent of HEAD |
| `HEAD^^` | Grandparent of HEAD |

### Commit ranges

| Syntax | Meaning |
|---|---|
| `<commit1>..<commit2>` | Commits reachable from the second endpoint but not the first |
| `<commit1>...<commit2>` | Symmetric difference between the two endpoints |

### Common names

| Name | Meaning |
|---|---|
| `main` | A branch name |
| `origin/main` | Remote-tracking branch |
| `@` | Shorthand for `HEAD` |

## 22. Getting More Help

For full documentation on a command, use any of these forms:
```bash
git help <command>
git <command> --help
man git-<command>
```

---

This handbook collects commonly used Git commands by task. Check a command's help page for its full options and behavior before using destructive operations.
