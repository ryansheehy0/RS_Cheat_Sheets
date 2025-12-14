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
- [Areas where your code can live](#areas-where-your-code-can-live)
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
- `git commit -am "message"` - Stages all tracked and modied files and commits them in one step.

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

## [Areas where your code can live](#git)
- **Working direcctory** - The folder with your code locally on your computer.
- **Staging area** - Files that are to be added to your commit.
	- `git add` - file moves into staging area
	- Lets you controll which changes go into a commit.
- **Repository** - Where commits are stored.
	- `git commit` - moves changes from the staging area into the local repository
- **Remote repository** - Online database of your commits and other people's commits.
	- `git push` moves what's in your repository to the remote repository.
	- Ex: GitHub, GitLab, or Bitbucket.

- Files can be in one of several states
	- `untracked` - Not being tracked by git
	- `staged` - Marked for inclusion in the next commit
	- `committed` - Saved to the repository's history
	- `git status` - Shows current state of yoru repo

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