# Git & GitHub — Practical Reference

A structured guide to version control, everyday Git commands, collaboration on GitHub, and recommended workflows.

## 1. Git and GitHub: The Difference

### Git
Git is a distributed version control system that records changes to source code. It helps developers:
- Maintain a history of changes.
- Collaborate while managing changes from different contributors.
- Create branches for independent development.
- Merge work from separate branches.
- Recover earlier versions of files and projects.

### GitHub
GitHub is a web-based platform for hosting Git repositories. It adds:
- Remote repository hosting.
- A browser-based repository interface.
- Pull Requests and Issues for collaboration.
- Project-management tools.
- CI/CD integration.
- Documentation hosting through GitHub Pages.

**In short:** Git is the version control system; GitHub hosts Git repositories and provides collaboration tools.

## 2. Git's Basic Workflow

```text
Working Directory --git add--> Staging Area --git commit--> Local Repository
                                                              |
                                                           git push
                                                              |
                                                              v
                                                       Remote Repository
```

- **Working Directory:** Where files are created and edited.
- **Staging Area:** Where changes are selected for the next commit.
- **Local Repository:** Where committed history is stored on your machine.
- **Remote Repository:** A repository hosted on a service such as GitHub or GitLab.

A **local repository** lives on your computer; a **remote repository** lives on a hosting server.

### Three states of files
1. **Modified:** A tracked file has changed but is not staged.
2. **Staged:** The change is selected for the next commit.
3. **Committed:** The change is saved in the local repository's history.

## 3. Configure Git

```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
git config --list
git config --global core.editor "vim"
```

These commands set the identity associated with commits, display configuration, and select the default editor.

## 4. Start Working with a Repository

```bash
git init
git clone https://github.com/user/repo.git
git clone -b branch-name https://github.com/user/repo.git
```

`git init` initializes a repository in the current directory. `git clone` copies an existing repository, while the `-b` option selects a branch to clone.

## 5. Make and Save Changes

### Check status and stage files

```bash
git status
git add filename.txt
git add .
git add *.java
```

`git status` reports the state of the working directory and staging area. `git add` selects changes for the next commit.

### Commit changes

```bash
git commit -m "Commit message"
git commit
git commit -am "Message"
```

The first command creates a commit with a message. `git commit` opens the configured editor for a detailed message. `git commit -am` stages and commits changes to already tracked files; it does not automatically include new, untracked files.

## 6. Examine History and Differences

### Commit history

```bash
git log
git log --oneline
git log --graph --oneline --all
git log -n 5
git log -p
git log --author="Name"
```

These show the full history, a compact history, a graph of all branches, a limited number of commits, commit patches, or commits by an author.

### Compare changes

```bash
git diff
git diff --staged
git diff commit1 commit2
git diff filename.txt
```

- `git diff` shows unstaged changes.
- `git diff --staged` shows staged changes.
- Comparing two commits displays the differences between them.
- Supplying a filename limits the comparison to that file.

## 7. Branch-Based Development

Branches let developers work on separate versions of a project without immediately changing the main line of development.

```bash
git branch
git branch feature-branch
git checkout feature-branch
git checkout -b new-feature
git branch -m new-name
git branch -d branch-name
git branch -D branch-name
```

| Command | Purpose |
|---|---|
| `git branch` | List local branches. |
| `git branch feature-branch` | Create a branch. |
| `git checkout feature-branch` | Switch branches. |
| `git checkout -b new-feature` | Create a branch and switch to it. |
| `git branch -m new-name` | Rename the current branch. |
| `git branch -d branch-name` | Delete a merged branch. |
| `git branch -D branch-name` | Force-delete a branch, even if unmerged. |

## 8. Merge Branches and Handle Conflicts

To merge another branch into the branch currently checked out:

```bash
git merge feature-branch
```

If Git cannot combine changes automatically, it reports a merge conflict. Inspect the affected files, edit them to keep the intended final content, remove conflict markers, and stage the resolved files:

```bash
git status
git add resolved-file.txt
git merge --continue
```

To cancel a merge and return to the state before it began:

```bash
git merge --abort
```

## 9. Work with Remote Repositories

### Manage remote connections

```bash
git remote add origin https://github.com/user/repo.git
git remote -v
git remote remove origin
git remote rename old-name new-name
```

### Fetch, pull, and push

```bash
git fetch origin
git pull origin main
git push origin main
git push -u origin feature-branch
git push origin --delete branch-name
```

- `git fetch` downloads remote updates without merging them into the current branch.
- `git pull` fetches remote changes and integrates them into the current branch.
- `git push` uploads local commits to the remote repository.
- `git push -u` publishes a new branch and sets its upstream.
- The final command deletes a branch from the remote repository.

## 10. Undo or Reverse Changes

```bash
git checkout -- filename.txt
git reset HEAD filename.txt
git reset --soft HEAD~1
git reset --hard HEAD~1
git revert commit-hash
```

| Command | Effect |
|---|---|
| `git checkout -- filename.txt` | Discards unstaged changes in the named file. |
| `git reset HEAD filename.txt` | Unstages a file but keeps its working-directory changes. |
| `git reset --soft HEAD~1` | Moves back one commit while keeping changes staged. |
| `git reset --hard HEAD~1` | Moves back one commit and discards affected staged and working-tree changes. |
| `git revert commit-hash` | Creates a new commit that reverses a previous commit. |

**Caution:** `git reset --hard` can permanently discard uncommitted work.

## 11. Temporarily Put Work Aside with Stash

Stash saves uncommitted changes temporarily so you can switch tasks and restore them later.

```bash
git stash
git stash save "Work in progress"
git stash list
git stash apply
git stash apply stash@{0}
git stash pop
git stash drop stash@{0}
git stash clear
```

`git stash list` displays saved stashes. `apply` restores a stash but keeps it in the list; `pop` restores the latest stash and removes it if successfully applied. `drop` removes one stash, while `clear` removes all stashes.

## 12. Mark Releases with Tags

```bash
git tag v1.0.0
git tag -a v1.0.0 -m "Version 1.0.0"
git tag
git push origin --tags
git tag -d v1.0.0
git push origin --delete v1.0.0
```

The first tag command creates a lightweight tag. The annotated form stores a message and additional tag metadata. Tags can be listed, pushed, and deleted locally or remotely.

## 13. GitHub Collaboration Tools

### Pull Requests

A Pull Request proposes merging changes from one branch or repository into another. A typical contribution process is:
1. Fork the repository.
2. Clone your fork locally.
3. Create a feature branch.
4. Make changes and commit them.
5. Push the branch to your fork.
6. Open a Pull Request on GitHub.
7. Participate in review and discussion.
8. Merge after approval.

### Issues

Issues help teams track bugs and feature requests, assign work, organize tasks with labels and milestones, and connect discussions to Pull Requests.

### GitHub CLI

```bash
gh auth login
gh repo create project-name
gh repo clone user/repo
gh pr create
gh pr list
gh issue create
gh issue list
```

The GitHub CLI (`gh`) provides terminal access to authentication, repositories, Pull Requests, and Issues.

## 14. Common Branching Models

### Git Flow

```text
master (production)
  └── develop
      ├── feature/new-feature
      ├── feature/another-feature
      ├── release/1.0
      └── hotfix/urgent-fix
```

- `master`: Production-ready code.
- `develop`: Integration branch.
- `feature/*`: New feature development.
- `release/*`: Release preparation.
- `hotfix/*`: Urgent production fixes.

### GitHub Flow

A simpler process:
1. Create a branch from `main`.
2. Make changes and commit them.
3. Open a Pull Request.
4. Review and discuss the changes.
5. Merge into `main`.
6. Deploy.

## 15. Good Repository Habits

### Commit message style

Use a short summary (about 50 characters or fewer), with a longer explanation when needed. Wrap detailed text at around 72 characters. Explain **what** changed and **why**, and use the imperative mood.

Good examples:
- `Add user authentication system`
- `Fix memory leak in image processor`
- `Update documentation for API v2`

Avoid unclear messages such as `Fixed stuff`, `asdfgh`, or `Made changes`.

### Example project layout

```text
project/
├── .gitignore
├── README.md
├── LICENSE
├── .github/
│   └── workflows/
├── docs/
├── src/
└── tests/
```

### Example `.gitignore`

```gitignore
# Compiled files
*.o
*.pyc
*.class

# Build directories
build/
dist/
target/

# Dependencies
node_modules/
venv/

# IDE files
.vscode/
.idea/
*.swp

# OS files
.DS_Store
Thumbs.db

# Sensitive files
.env
secrets.txt
```

## 16. Frequently Used Workflows

### Start a feature

```bash
git checkout main
git pull origin main
git checkout -b feature/new-feature

# Make changes
git add .
git commit -m "Implement new feature"
git push -u origin feature/new-feature

# Create a Pull Request on GitHub
```

### Update a feature branch

```bash
git checkout main
git pull origin main
git checkout feature/my-feature
git merge main

# Resolve conflicts if any
git push origin feature/my-feature
```

### Resolve a merge conflict

```bash
git status
# Edit the conflicted files and remove conflict markers
git add resolved-file.txt
git commit -m "Resolve merge conflicts"
```

After editing a conflicted file, keep the intended final code, remove the conflict markers, stage the resolved file, and commit.

## 17. Common Mistakes to Avoid

- Committing passwords, API keys, or other sensitive data.
- Adding large binary files unnecessarily.
- Using unclear commit messages.
- Doing all development directly on `main`.
- Forgetting to pull recent changes before pushing.
- Committing files that still contain conflict markers.
- Force-pushing to shared branches and potentially overwriting others' work.

## 18. Git Aliases

Aliases provide shorter names for frequently used commands:

```bash
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global alias.visual 'log --oneline --graph --all'
```

For example, `git st` runs `git status` after the alias is configured.

## 19. Key Takeaways

- Git records changes and maintains a version history.
- Branching supports parallel development.
- Small, focused commits make history easier to understand.
- Pull Requests enable code review.
- Remote repositories make collaboration possible.
- `.gitignore` prevents unwanted files from being tracked.
- Clear commit messages make project history more useful.
- GitHub adds hosting and collaboration features around Git.

## 20. Further Resources

- [Official Git Documentation](https://git-scm.com/doc)
- [GitHub Guides](https://guides.github.com/)
- [Pro Git Book](https://git-scm.com/book)
- [GitHub Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)
