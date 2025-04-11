[Home](../README.md)

# Git Cheat Sheet
A version control system that manages changes to files.

<!-- TOC -->

- [Cloning and Initializing](#cloning-and-initializing)
- [Committing](#committing)
	- [Resetting Commits](#resetting-commits)
	- [Reverting Commits](#reverting-commits)
	- [Commit Logs](#commit-logs)
- [Pushing](#pushing)
- [Pulling](#pulling)
- [Branches](#branches)
- [Stashing](#stashing)
- [Setting Personal Access Tokens](#setting-personal-access-tokens)
- [First push](#first-push)
	- [SSH](#ssh)
	- [HTTPS](#https)
- [Rebasing](#rebasing)
- [Pull Requests](#pull-requests)
	- [When your branch says behind main](#when-your-branch-says-behind-main)
- [Setting up with SSH](#setting-up-with-ssh)
- [Adding a warning when pushing to main/master from another branch](#adding-a-warning-when-pushing-to-mainmaster-from-another-branch)
- [Git Ignore](#git-ignore)

<!-- /TOC -->

## [Cloning and Initializing](#git-cheat-sheet)

|                   |                                             |
|-------------------|---------------------------------------------|
| git clone {https} | Pulls github repository and initializes it. |
| git init          | Creates .git file to allow for pushing.     |

## [Committing](#git-cheat-sheet)

|                                            |                                                                                                                                                                                                                                                  |
|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| git status                                 | Shows all files that were updated, created, or deleted and if the files are untracked, tracked, or staged. Tracked meaning Git tracks versioning of the file and staged meaning the file is ready to be committed. All staged files are tracked. |
| git add {File}                             | Tells git to track and stage the file so it can be committed.                                                                                                                                                                                    |
| git add -A                                 | Tracks and stages all the files and folders listed in status.                                                                                                                                                                                    |
| git commit -m ”{Title}” -m ”{Description}” | Commits staged files. It is recommended to have your Title be in the present tense. Ex: "Adds some stuff"                                                                                                                                      |

### [Resetting Commits](#git-cheat-sheet)

|                               |                                                                       |
|-------------------------------|-----------------------------------------------------------------------|
| git reset -hard {commit hash} | Resets to commit specified and deletes any commits after that commit. |
| git reset {commit hash}       | Resets to commit specified and unstages changes.                      |
| git reset -soft {commit hash} | Resets to commit specified, but leaves files staged.                  |

### [Reverting Commits](#git-cheat-sheet)

|                          |                                                                                                                            |
|--------------------------|----------------------------------------------------------------------------------------------------------------------------|
| git revert {commit hash} | Makes a new commit that undos the changes from the commit hash. Does the opposite of the changes made in that commit hash. |

### [Commit Logs](#git-cheat-sheet)

|                  |                                                            |
|------------------|------------------------------------------------------------|
| git log          | Lists commit history. This can tell you the commit hashes. |
| git log {branch} | Lists commit history for that branch.                      |

## [Pushing](#git-cheat-sheet)

|                                   |                                                         |
|-----------------------------------|---------------------------------------------------------|
| git push {location} {branch}      | Pushes commits to the branch at the specified location. |
| git remote -v                     | Shows locations you can push to.                        |
| git remote add {location} {https} | Adds a location you can push to.                        |
| git remote remove {location}      | Removes a location you can push to.

## [Pulling](#git-cheat-sheet)

|                               |                                                                                                                |
|-------------------------------|----------------------------------------------------------------------------------------------------------------|
| git pull {location} {branch}  | Pulls changes made from location’s branch. Pulling is the same as fetching and merging.                        |
| git fetch {location}          | The metadata in the local repo is updated, but not files are downloaded.                                       |
| git fetch                     | Fetches all the branches.                                                                                      |
| git merge {location}/{branch} | Incorporate the changes from fetch into the specified branch. This downloads the changes from the remote repo. |

## [Branches](#git-cheat-sheet)

|                          |                                              |
|--------------------------|----------------------------------------------|
| git checkout -b {branch} | Creates a new branch.                        |
| git branch               | Shows all branches. * is for current branch. |
| git checkout {branch}    | Switches branch.                             |
| git branch -d {branch}   | Deletes branch.                              |

## [Stashing](#git-cheat-sheet)

|                        |                                                                                      |
|------------------------|--------------------------------------------------------------------------------------|
| git stash              | Saves changes to a temporary storage area.                                           |
| git stash list         | Lists all the stashes.                                                               |
| git stash pop          | Restore changes from the stash to your current directory and removes the last stash. |
| git stash apply        | Restore changes from the stash to your current directory and keeps the last stash.   |
| git stash drop         | Removes the last stash.                                                              |
| git stash drop {index} | Removes the stash at the index.                                                      |

## [Setting Personal Access Tokens](#git-cheat-sheet)

Settings $\rightarrow$ Developer settings $\rightarrow$ Personal access tokens $\rightarrow$ Generate new tokens

- Make sure to check repo box so you have access to public and private repositories
- After a certain time period the token expires and needs to be regenerated and reset

|                                                                                                                         |                                     |
|-------------------------------------------------------------------------------------------------------------------------|-------------------------------------|
| git remote set-url {location} https://{username}:{personal access token}@github.com/{owner's username}/{repository}.git | Gives permissions for the location. |

## [First push](#git-cheat-sheet)
Recommended {location} is `origin` and {branch} is `master`.

1. git init
2. git add -A
3. git commit -m "{Title}" -m "{Description}"

### [SSH](#git-cheat-sheet)
This is recommended over HTTPS.

4. git remote add {location} {ssh}
5. git push {location} {branch}

### [HTTPS](#git-cheat-sheet)

4. git remote add {location} {https}
5. git remote set-url {location} https://{username}:{personal access token}@github.com/{owner's username}/{repository}.git
6. git push {location} {branch}

## [Rebasing](#git-cheat-sheet)

|                     |                                                                                    |
|---------------------|------------------------------------------------------------------------------------|
| git rebase {branch} | Takes the commits from current branch and puts them ontop of the specified branch. |

## [Pull Requests](#git-cheat-sheet)
- A pull request is a request to make changes to a branch from another branch.
- A merge is the combining changes from one branch to another.

|                       |                                                                                                                                                                         |
|-----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Create a merge commit | Combines the changes from the source branch and the target branch and makes a commit to the target branch with the changes. Preserves the history.                      |
| Squash and merge      | Combines all the changes from the source branch and makes a commit to the target branch with the changes. This removes the source branch. Doesn't preserve the history. |
| Rebase and merge      | Commits all the previous commits in the source branch and adds them to the target branch. This removes the source branch. Preserves the history.                        |

### [When your branch says behind main](#git-cheat-sheet)
- This means that there are new commits in the main branch that aren't in your branch.
1. Ensure your changes are committed
    - git status
    - git add -A
    - git commit -m "{Title}" -m "{Description}"
1. Switch to the main branch
    - git checkout main
1. Pull from main
    - git pull {location} main
1. Switch to your branch
    - git checkout {your branch}
1. Merge changes from main into your branch
    - git merge main
1. Resolve any conflicts
    - Git will tell you which files. If 2 or more people changed the same file then there will be conflicts..
    - Inside the conflicting files

```
<<<<<<< HEAD
// Your changes in the current branch
=======
// Changes from the branch you are merging with
>>>>>>> branch-name
```

<ol start="7">
    <li>Once resolved commit and push your update</li>
    <ul>
        <li>git add -A</li>
        <li>git commit -m "{Title}" -m "{Description}"</li>
        <ul>
            <li>It is recommended to make the Title something like "Merged main into {your branch}"</li>
        </ul>
        <li>git push {location} {your branch}</li>
    </ul>
    <li>It should now say ahead of main</li>
    <ul>
        <li>This means that your branch has additional commits compared to the main branch.</li>
    </ul>
</ol>

## [Setting up with SSH](#git-cheat-sheet)
1. `ssh-keygen -t ed25519 -C {github email}`
    - Used to generate a public and private key pair.
        - Private key is in: .ssh/id_ed25519 (Don't share with anyone)
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
    - `IdentifyFile ~/.shh/id_ed25519` sets the default private key for all SSH connections.
    - These settings make is so that you don't need to run `ssh-add ~/.ssh/id_ed25519` with a new terminal session.
1. Go to github settings -> SSH and GPG keys -> New SSH key
1. Paste the contents of id_ed25519.pub into github and press Add Key
1. To test if it worked run: `ssh -T git@github.com` and you should see Successfully Authenticated
    - If this doesn't work then you may need to run `eval "$(ssh-agent -s)"` in order to start the ssh-agent
1. To use with SSH make sure your github repo locations are SSHs(they starts with git@github.com)

## [Adding a warning when pushing to main/master from another branch](#git-cheat-sheet)
- Put this code inside .git/hooks/pre-push
    - Not pre-push.sample

```
#!/bin/bash

current_branch=$(git symbolic-ref --short HEAD)

while read local_ref local_oid remote_ref remote_oid
do
	if [[ "$current_branch" != "main" && "$current_branch" != "master" ]]; then
		if [[ $remote_ref =~ master || $remote_ref =~ main ]]; then
			read -p "You're about to push to main/master. Are you sure? [y/n] " -n 1 -r < /dev/tty
    	    echo
			if [[ $REPLY != "y" || $REPLY != "Y" ]]; then
				exit 1
			fi
		fi
	fi
done

exit 0
```

- Make it executable with `chmod +x ./.git/hooks/pre-push`

## [Git Ignore](#git-cheat-sheet)
A file called `.gitignore` which is used to ignore folders or files when pushed to github.

Git ignores use regexes.

This simply doesn't push the folder called "Folder", the file called "file", and any files that start with regex. that are in the Regex folders.

```
#titles
Folder
file
Regex/regex.*
```

- Often times different passwords or api keys are stored in the `.env` file and this should always be in the `.gitignore` for security reasons.