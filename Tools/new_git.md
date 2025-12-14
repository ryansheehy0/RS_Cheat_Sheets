[Home](../README.md#tools)

# Git
Git can be thought of as a database of commits.

A **commit** is a snapshot of the entire project made of a point to this snapshot, metadata(who created it, when it was created, and the commit message), and pointer backwards to the parent commit. This creates a chain of commits.

- Useful links:
	- [Git Will Finally Make Sense After This](https://youtu.be/Ala6PHlYjmw?si=e8KEPPQ2OAivoP1E)
	- [Never* use git pull](https://youtu.be/xN1-2p06Urc?si=87JsMOu5509BmQV_)

<!-- TOC -->

- [Config](#config)
- [Branches](#branches)
- [Head](#head)
- [File states](#file-states)
- [Revert](#revert)
- [Combining branches](#combining-branches)
- [History](#history)
- [Other](#other)

<!-- /TOC -->

## [Config](#git)
You can set your identity at both the global level and the repository level.

| Config commands                                          | Description                  |
|----------------------------------------------------------|------------------------------|
| `git config list`                                        | List out all of your configs |
| `git config set --global user.name "username"`           | Set your global username     |
| `git config set --global user.email "email@example.com"` | Set your global email        |
| `git config set --global init.defaultBranch master`      | Set default branch           |

## [Branches](#git)
A **branch** is a pointer to a specific commit and when you commit to a branch, the branch points to the new commit.

| Branch commands | Description |
|-----------------|-------------|
|                 |             |

- **Reset** - Moves branch
	- **--soft** - Moves branch only and doesn't change your staging area or repository.
		- Want to combine a lot of commits into 1.
	- **--mixed** - (Default)Moves branch and staging area reset.
		- Changes still exist in your files, but unstaged.
	- **--hard** - Moves everything
		- Resets staging area and working directory.
		- Uncommited work gone.
		- Want to completely abandon work and start fresh.

## [Head](#git)
The **head** is a pointer to a branch that tracks your current location.

The head can be in a **detatched state** if it points directly to a commit, instead of a branch. This can be dangerous because any commits in this state are orphaned and will eventually be deleted.

| Head commands           |                               |
|-------------------------|-------------------------------|
| `git checkout <branch>` | Moves the head to the branch. |

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
| `git commit --amend -m "message"` | Change the last commit message.                  |

| Pushed commands                | Description                             |
|--------------------------------|-----------------------------------------|
| `git push <location> <branch>` | Sends local commits to the remote repo. |

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

## [History](#git)
- **git reflog** - Shows everywhere head has pointed recently
	- Can recover your work if you made a mistake. `git branch newBranch hash` for creating a branch to your old work.
	- Expire around 30 days for orphaned commits.
- **git log** - Shows history of the commits in a repository
	- Who made the commit, when the commit was made, and the commit message.
- `git cat-file -p <hash>`
	- The tree is a snapshot of the directory structure for that commit, pointing to blobs for files and other trees for subdirectories.
	- **tree** - Gits way of storing a directory
	- **blob** - Gits way of storing a file
	- You can also put the tree or block hash instead of the commit hash.

## Other
- **Porcelain** - High level commands
	- status, add, commit, push, pull, log
- **Plumbing** - Low level commands
	- apply, commit-tree, hash-object
- Repository - Represents a single prokect.
	- .git - Hidden directory where git stores all of its internal tracking and versioning info