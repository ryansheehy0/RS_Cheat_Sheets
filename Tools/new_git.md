[Home](../README.md#tools)

# Git
Git can be thought of as a database of commits.

- Useful links:
	- [Git Will Finally Make Sense After This](https://youtu.be/Ala6PHlYjmw?si=e8KEPPQ2OAivoP1E)
	- [Never* use git pull](https://youtu.be/xN1-2p06Urc?si=87JsMOu5509BmQV_)

<!-- TOC -->

- [Config](#config)
- [Commits](#commits)
- [Branches](#branches)
- [Head](#head)
- [File states](#file-states)
- [Reset](#reset)
- [Revert](#revert)
- [Combining branches](#combining-branches)
- [Reflog](#reflog)
- [Other](#other)

<!-- /TOC -->

## [Config](#git)
You can set your identity at both the global level and the repository level.

| Command                                                  | Description                  |
|----------------------------------------------------------|------------------------------|
| `git config list`                                        | List out all of your configs |
| `git config set --global user.name "username"`           | Set your global username     |
| `git config set --global user.email "email@example.com"` | Set your global email        |
| `git config set --global init.defaultBranch master`      | Set default branch           |

## [Commits](#git)
A **commit** is a snapshot of your entire project. It's made of three parts:

- Pointer to your snapshot.
- Metadata: Who created it, when it was created, and the commit message.
- Pointer backwards to the parent commit.

This creates a chain of commits:
[Image]()

| Command | Description |
|---------|-------------|
|         |             |

## [Branches](#git)
A **branch** is a pointer to a specific commit and when you commit to a branch, the branch points to the new commit.
A **

- **Branches** - A pointer to a specific commit.
	- When you commit to a branch, it moves the branch pointer to that new commit.

## [Head](#git)

- **Head** - A pointer to a branch that tracks your current location.
	- **Detatched head state** - The head points directly to a commit, instead of a branch.
		- When you commit in this state, the commits are orphaned and git's garbage collector can remove them once the head moves away.

- **Checkout** - Moves head

## [File states](#git)
- **Untracted** - Files not yet tracked by git.
- **Staged** - Files marked for includsion in the next commit.
- **Committed** - Files saved in the local repos's history.
- **Pushed** - Commits sent to a remote repository for sharing or backup.
- `git status` - Shows current state of your files.

| Staging commands | Description         |
|------------------|---------------------|
| `git add <file>` | Stages a file       |
| `git add -A`     | Stages all changes  |

| Committing commands               | Description                                      |
|-----------------------------------|--------------------------------------------------|
| `git commit -m "message"`         | Commits staged changes with a message.           |
| `git commit -am "message"`        | Stages all changes and commits them in one step. |
| `git commit --amend -m "message"` | Change the last commit message.                  |

| Pushed commands                | Description                             |
|--------------------------------|-----------------------------------------|
| `git push <location> <branch>` | Sends local commits to the remote repo. |

## [Reset](#git)
- **Reset** - Moves branch
	- **--soft** - Moves branch only and doesn't change your staging area or repository.
		- Want to combine a lot of commits into 1.
	- **--mixed** - (Default)Moves branch and staging area reset.
		- Changes still exist in your files, but unstaged.
	- **--hard** - Moves everything
		- Resets staging area and working directory.
		- Uncommited work gone.
		- Want to completely abandon work and start fresh.

## [Revert](#git)
- **Revert** - Creates a new commit that does the opposite of an old commit.
	- Safe. History is preserved.

## [Combining branches](#git)
- You have a feature branch, but main has continied to receive comits. How to integrate?
	- **Merge** - Create a commit with two parents.
	- **Rebase** - Take your commits in the feature branch and create new commits that have the same changes and add them to main.
		- The old commits orphanged because the feature branch was moved to point to the same commit as main.
		- Can be a problem for people who've based work on the featured branch because those commits had their history altered.
		- Most useful when your branch hasn't made it to the remote repository yet and you want to add your features to main.

- **Merge commit** - A commit with two or more parents.
- Merge conflicts?
- Pushing, but someone has already pushed.

## [Reflog](#git)
- **git reflog** - Shows everywhere head has pointed recently
	- Can recover your work if you made a mistake. `git branch newBranch hash` for creating a branch to your old work.
	- Expire around 30 days for orphaned commits.

## Other
- **Porcelain** - High level commands
	- status, add, commit, push, pull, log
- **Plumbing** - Low level commands
	- apply, commit-tree, hash-object
- Repository - Represents a single prokect.
	- .git - Hidden directory where git stores all of its internal tracking and versioning info