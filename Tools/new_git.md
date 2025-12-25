[Home](../README.md#tools)

# Git
Git can be thought of as a database of commits.

A **commit** is a snapshot of the entire project made of a pointer to this snapshot, metadata(who created it, when it was created, and the commit message), and a pointer backwards to the parent commit. This creates a chain of commits.

- Useful links:
	- [Git Will Finally Make Sense After This](https://youtu.be/Ala6PHlYjmw?si=e8KEPPQ2OAivoP1E)
	- [Never* use git pull](https://youtu.be/xN1-2p06Urc?si=87JsMOu5509BmQV_)

<!-- TOC -->

- [Config](#config)
- [Status](#status)
- [Branches](#branches)
- [Merge](#merge)
- [Log](#log)
- [History](#history)
- [Revert](#revert)
- [Combining branches](#combining-branches)
- [Other](#other)

<!-- /TOC -->

## [Config](#git)

| Config commands                          | Description                                         |
|------------------------------------------|-----------------------------------------------------|
| `git config list`                        | Lists out all of your configs.                      |
| `git config set <section>.<key> <value>` | Sets the key for that section.                      |
| `git config get <section>.<key>`         | Gets the value for that section and key.            |
| `git config unset <section>.<key>`       | Removes the key from that section.                  |
| `git config remove-section <section>`    | Removes a section and all the keys in that section. |

- Keys sets on the `--local` level override keys set on the `--global` level.
	- If you don't specify, the default is `--local`
	- You specify it after the command: `git config set --global`
- Common keys
	- `user.name`
	- `user.email`
	- `init.defaultBranch`
- Git config allows you to have multiple keys with the same name.

## [Status](#git)
- **Untracted** - Files not yet tracked by git.
- **Staged** - Files marked for includsion in the next commit.
- **Committed** - Files saved in the local repos's history.

| Status commands                   | Description                            |
|-----------------------------------|----------------------------------------|
| `git status`                      | Shows current state of your files.     |
| `git add <file/folder>`           | Stages a file or folder                |
| `git add -A`                      | Stages all changes                     |
| `git commit -m "message"`         | Commits staged changes with a message. |
| `git commit --amend -m "message"` | Change the last commit message.        |

## [Branches](#git)
A **branch** is a named pointer to a commit. Committing to a branch updates it to point to the new commit.

| Branch commands                     | Description                                                    |
|-------------------------------------|----------------------------------------------------------------|
| `git branch`                        | List all branches. * is your current branch.                   |
| `git branch -m <oldname> <newname>` | Rename a branch.                                               |
| `git branch <name>`                 | Creates a new branch pointing to your current commit.          |
| `git branch -d <name>`              | Deletes a branch.                                              |
| `git switch <branch>`               | Switches to a branch.                                          |
| `git switch -c <name>`              | Creates a new branch at the current commit and switches to it. |

- GitHub's default branch is main.
- The old version of the `switch` command is `checkout`.

## [Merge](#git)
A **merge commit** combines changes from two branches into a single commit that has two parent commits.

```
Example:

A - B - C - F  main(current branch)
   \     /
    D - E      branch
```

- What the merge command does:
	1. Finds the **merge base**/**best common ancestor** - the commit closest to both branches.
		- `A` in this example.
	2. Adds the changes from main starting from the merge base, into a new commit.
	3. Adds the changes from the other branch starting from the merge base.
	4. Creates a new commit with two parents.
		- `F` in this example.

| Merge commands       | Description                                                                  |
|----------------------|------------------------------------------------------------------------------|
| `git merge <branch>` | Creates a merge commit on your current branch from the branch you specified. |

- **Faster forward merge** - Sometimes git doesn't need to create a new merge commit.

```
Before:
      C   branch
     /
A - B     main

After:
            branch
A - B - C   main
```

## [Log](#git)
`git log` shows the history of commits.

| Flags              | Description                          |
|--------------------|--------------------------------------|
| `--oneline`        | Condensed view of commits.           |
| `--graph`          | Draws lines for the path.            |
| `--decorate`       | Give branch and tag information.     |
| `--all`            | Commits reachable from all branches. |
| `--parents`        | Gives parent commit.                 |
| `--author <regex>` | Searches for author.                 |

```
git log --oneline --graph --decorate --all
```

# Other
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

## [History](#git)
- `git reflog` - Shows everywhere head has pointed recently
	- Can recover your work if you made a mistake. `git branch newBranch hash` for creating a branch to your old work.
	- Expire around 30 days for orphaned commits.
- `git cat-file -p <hash>`
	- The tree is a snapshot of the directory structure for that commit, pointing to blobs for files and other trees for subdirectories.
	- **tree** - Gits way of storing a directory
	- **blob** - Gits way of storing a file
	- You can also put the tree or block hash instead of the commit hash.



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

## Other
- **Porcelain** - High level commands
	- status, add, commit, push, pull, log
- **Plumbing** - Low level commands
	- apply, commit-tree, hash-object
- Repository - Represents a single prokect.
	- .git - Hidden directory where git stores all of its internal tracking and versioning info
- Commits
	- Git compresses and packs files
	- If a file doesn't change between commits, git will only store it once.

- **Reset** - Moves branch
	- **--soft** - Moves branch only and doesn't change your staging area or repository.
		- Want to combine a lot of commits into 1.
	- **--mixed** - (Default)Moves branch and staging area reset.
		- Changes still exist in your files, but unstaged.
	- **--hard** - Moves everything
		- Resets staging area and working directory.
		- Uncommited work gone.
		- Want to completely abandon work and start fresh.

The **head** is a pointer to a branch that tracks your current location.

The head can be in a **detatched state** if it points directly to a commit, instead of a branch. This can be dangerous because any commits in this state are orphaned and will eventually be deleted.

- `.git/refs/heads` is a folder holding files of your different branches with the hash of the commit the branch is pointing to.

1. Update repo to the latest code
	- git fetch or git pull

| Pushed commands                | Description                             |
|--------------------------------|-----------------------------------------|
| `git push <location> <branch>` | Sends local commits to the remote repo. |

- **Pushed** - Commits sent to a remote repository for sharing or backup.