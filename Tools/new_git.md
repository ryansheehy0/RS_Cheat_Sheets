[Home](../README.md#tools)

# Git
To Do
	- Organize into categories.
	- Draw diagrams of examples.

- Git is a database of commits.
- **Commit** - Snapshot of your entire project at one moment in time.
	- Pointer to your snapshot
	- Metadata - Who created it, when, and commit message.
	- Pointer backwards to the parent commit
		- Creates a chain of commits.
- **Merge commit** - A commit with two or more parents.
- **Branches** - A pointer to a specific commit.
	- When you commit to a branch, it moves the branch pointer to that new commit.
- **Head** - A pointer to a branch that tracks your current location.
	- **Detatched head state** - The head points directly to a commit, instead of a branch.
		- When you commit in this state, the commits are orphaned and git's garbage collector can remove them once the head moves away.
- Area where you code can live
	- **Working direcctory** - The folder with your code locally on your computer.
	- **Staging area** - Files that are to be added to your commit.
		- `git add` - file moves into staging area
		- Lets you controll which changes go into a commit.
	- **Repository** - Where commits are stored.
		- `git commit` - moves changes from the staging area into the local repository
	- **Remote repository** - Online database of your commits and other people's commits.
		- `git push` moves what's in your repository to the remote repository.
		- Ex: GitHub, GitLab, or Bitbucket.
- **Checkout** - Moves head
- **Reset** - Moves branch
	- **--soft** - Moves branch only and doesn't change your staging area or repository.
		- Want to combine a lot of commits into 1.
	- **--mixed** - (Default)Moves branch and staging area reset.
		- Changes still exist in your files, but unstaged.
	- **--hard** - Moves everything
		- Resets staging area and working directory.
		- Uncommited work gone.
		- Want to completely abandon work and start fresh.
- **Revert** - Creates a new commit that does the opposite of an old commit.
	- Safe. History is preserved.
- You have a feature branch, but main has continied to receive comits. How to integrate?
	- **Merge** - Create a commit with two parents.
	- **Rebase** - Take your commits in the feature branch and create new commits that have the same changes and add them to main.
		- The old commits orphanged because the feature branch was moved to point to the same commit as main.
		- Can be a problem for people who've based work on the featured branch because those commits had their history altered.
		- Most useful when your branch hasn't made it to the remote repository yet and you want to add your features to main.
- **git reflog** - Shows everywhere head has pointed recently
	- Can recover your work if you made a mistake. `git branch newBranch hash` for creating a branch to your old work.
	- Expire around 30 days for orphaned commits.