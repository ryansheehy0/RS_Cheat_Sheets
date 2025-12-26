[Home](../README.md#tools)

# Git
Git can be thought of as a database of commits.

A **commit** is a snapshot of the entire project made of a pointer to this snapshot, metadata(who created it, when it was created, and the commit message), and a pointer backwards to the parent commit. This creates a chain of commits.

Git comrpresses files and if a file doesn't change between commits, it's only stored once.

- Useful links:
	- [Git Will Finally Make Sense After This](https://youtu.be/Ala6PHlYjmw?si=e8KEPPQ2OAivoP1E)

<!-- TOC -->

- [Config](#config)
- [Status](#status)
- [Branches](#branches)
- [Merge](#merge)
- [Rebase](#rebase)
- [Reset and revert](#reset-and-revert)
- [Log](#log)
- [Remote](#remote)
	- [Local repo setup](#local-repo-setup)
	- [Fetch and pull](#fetch-and-pull)
	- [Pull requests](#pull-requests)
	- [Setting up ssh with GitHub](#setting-up-ssh-with-github)
- [Workflow](#workflow)
- [Worktrees](#worktrees)

<!-- /TOC -->

## [Config](#git)

| Config commands                          | Description                                         |
|------------------------------------------|-----------------------------------------------------|
| `git config list`                        | Lists out all of your configs.                      |
| `git config set <section>.<key> <value>` | Sets the key for that section.                      |
| `git config get <section>.<key>`         | Gets the value for that section and key.            |
| `git config unset <section>.<key>`       | Removes the key from that section.                  |
| `git config remove-section <section>`    | Removes a section and all the keys in that section. |

- Git config allows multiple entries for the same key, so you need to unset it before setting the new one to rename it.
- Keys sets on the `--local` level override keys set on the `--global` level.
	- If you don't specify, the default is `--local`
	- You specify it after the command: `git config set --global`
- Common keys
	- `user.name`
	- `user.email`
	- `init.defaultBranch`

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
| `git rm --cached <file/folder>`   | Unstages a file/folder.                |

- You can list files and folders in a `.gitignore` file to prevent them from being staged.
	- `*` matches any number of characters except `/`. Ex: `*.txt` ignores any txt files.
	- Lines that start with `#` are comments.
	- `/` anchors the patter to the directory containing the .gitignore and not any subdirectories.
	- You can negate a pattern by prefixing it with `!`

## [Branches](#git)
A **branch** is a named pointer to a commit. Committing to a branch updates it to point to the new commit.

| Branch commands                     | Description                                                    |
|-------------------------------------|----------------------------------------------------------------|
| `git branch`                        | List all branches. * is your current branch.                   |
| `git branch -m <oldname> <newname>` | Rename a branch.                                               |
| `git branch <name>`                 | Creates a new branch pointing to your current commit.          |
| `git branch <name> <commitHas>`     | Creates a new branch pointing to the commit hash.              |
| `git branch -d <name>`              | Deletes a branch.                                              |
| `git switch <branch>`               | Switches to a branch.                                          |
| `git switch -c <name>`              | Creates a new branch at the current commit and switches to it. |

- GitHub's default branch is main.
- The old version of the `switch` command is `checkout`.

## [Merge](#git)
A **merge commit** combines changes from two branches into a single commit that has two parent commits.

```
Before:
A - B - C  main(current branch)
   \
    D - E  branch

After:
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
A - B     main(current branch)

After:
            branch
A - B - C   main(current branch)
```

## [Rebase](#git)
**Rebase** moves the commits from one branch onto the tip of another branch.

- This allows a future merge to be a fast-forward merge, if no new commits were added to the target branch.
- When to use rebase?
	- Merge is useful when you want to preserve the true history of the project, but it can create a lot of merge commits.
	- Rebase is useful for simplifying the commit history.
	- You should never rebase a branch that others may have already pulled because it will change their history.
		- You should only rebase for private branches where no one else has based work on it.

```
Before:
A - B - C   main
   \
    D - E   branch(current branch)

After:
A - B - C         main
         \
          D - E   branch(current branch)
```

- What the rebase command does:
	1. Find the latest commit from the specified branch(main).
	2. Replays each commit from your current branch(branch) onto the end of the specified branch(main).
	3. Updates your current branch(branch) to point to the last replayed commit and doesn't change the specified branch(main).

| Command               | Description                                           |
|-----------------------|-------------------------------------------------------|
| `git rebase <branch>` | Rebases the current branch onto the specified branch. |

```
Example with a merge:

Before:
A - B - C - E - F - G   main
          \   /
            D - H - I   branch(current branch)

After:
A - B - C - E - F - G         main
          \   /      \
            D         H - I   branch(current branch)
```

## [Reset and revert](#git)
These commands are used to undo commits.

- `git reset`
	- All options move the branch to the commit.
	- Mainly used for private branches that aren't shared with anyone.
	- `git reset --soft <commitHash>`
		- Keeps the changes from the reset commits and stages them.
	- `git reset --mixed <commitHash>`
		- Keeps the changes from the reset commits, but doesn't stage them.
		- The default option.
		- Can be used to remove all staged files.
	- `git reset --hard <commitHash>`
		- Discards the changes. Makes your working directory and staging area match the specified commit.
		- Warning: All changes are lost forever.
- `git revert <commitHash>`
	- Creates a new commit that reverts all the changes of an old commit.
	- Mainly used for public branches where you don't want to break other people's history.

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

- You can also specify a remote location and a branch in that remote location: `git log <locationName>/<branch>`
- `git reflog` shows everywhere the head has pointed to, which is useful for reversing resets or rebases.
	- You can recover work by creating a branch to a orphaned commit if it's still there.

## [Remote](#git)

### [Local repo setup](#git)

| Commands                                | Description                                                        |
|-----------------------------------------|--------------------------------------------------------------------|
| `git clone <https/ssh>`                 | Copies an existing remote repo to your machine and initializes it. |
| `git init`                              | Initializes a new empty local repo.                                |
| `git remote -v`                         | Shows list of locations and their urls.                            |
| `git remote add <location> <https/ssh>` | Adds a location.                                                   |
| `git remote remove <location>`          | Removes a loction.                                                 |

- `origin` is the most common location name for the default remote repository.

### [Fetch and pull](#git)

| Commands                                | Description                                                                        |
|-----------------------------------------|------------------------------------------------------------------------------------|
| `git fetch <location>`                  | Updates metadata(trees/folders and blobs/files). Doesn't update working directory. |
| `git fetch`                             | By defualt it fetches from origin.                                                 |
| `git merge <location>/<branch>`         | Merges the remote location's branch onto your current branch.                      |
| `git push <location> <branch>`          | Sends local changes to any remote location.                                        |
| `git pull <location> <branch>`          | Fetches, then merges what was pulled into your current branch.                     |
| `git pull --rebase <location> <branch>` | Fetches, then rebases your changes ontop of what was pulled.                       |

- You should use `git pull --rebase` instead of `git pull` to prevent excessive merge commits.
	- If there's a conflict, you can do `git rebase --abort` and pull normally.
	- https://youtu.be/xN1-2p06Urc?si=ARehzgXvVYUYDHQU
- You can also push a local branch to a remote branch with a different name: `git push <location> <localBranch>:<remoteBranch>`
	- You can also delete a remote branch: `git push <location> :<remoteBranch>`

### [Pull requests](#git)
**Pull requests** are a way to request merging changes from one branch into another on GitHub.

1. Pull requests tab
2. New pull request
3. Set your branches so that the compare branch gets merged into the base branch.

### [Setting up ssh with GitHub](#git)
1. `ssh-keygen -t ed25519 -C <githubEmail>`
    - Used to generate a public and private key pair.
        - Private key is in: .ssh/id_ed25519
        - Public key is in: .ssh/id_ed25519.pub
    - Note: ed25519 an elliptic curve type of encryption, but this type of encryption may change in the future.
    - You usually create one ssh key per computer/device.
1. `eval "$(ssh-agent -s)"`
    - Starts the ssh-agent on your computer which makes it so that you don't have to re-enter you password each time you use git.
    - The `eval` command evaluates the output of `ssh-agent -s` and sets the necessary environment variables in the current shell session.
1. inside file ~/.ssh/config
    ```
    Host *
        AddKeysToAgent yes
        IdentityFile ~/.ssh/id_ed25519
    ```
    - `Host *` means that the variables are being applied to all the hosts.
    - `AddKeysToAgent yes` means the private keys will be automatically added to the ssh-agent when you connect to a remote host.
    - `IdentityFile ~/.shh/id_ed25519` sets the default private key for all SSH connections.
    - These settings make is so that you don't need to run `ssh-add ~/.ssh/id_ed25519` with a new terminal session.
1. Go to github settings -> SSH and GPG keys -> New SSH key
1. Paste the contents of id_ed25519.pub into github and press Add Key
1. To test if it worked run: `ssh -T git@github.com` and you should see Successfully Authenticated
    - If this doesn't work then you may need to run `eval "$(ssh-agent -s)"` in order to start the ssh-agent
1. To use with SSH make sure your github repo locations are SSHs(they starts with git@github.com)

## [Workflow](#git)
- Solo workflow
	- Stay on main branch.
	- Make changes.
	- `git add -A`
	- `git commit -m "Message"`
	- `git push origin main`
- Team workflow
	- Update main branch: `git pull --rebase origin main`
	- Create a new branch for your changes: `git switch -c <branch>`
	- Make changes.
	- `git add -A`
	- `git commit -m "message"`
	- `git push origin <branch>`
	- Once you're done with your changes open a pull request on GitHub.
	- Ask a team member to review pull requet.
	- Once approved, click the Merge button.
	- Delete feature branch.

## [Worktrees](#git)
https://youtu.be/ntM7utSjeVU?si=zyk8xC9Pii2EDW4z