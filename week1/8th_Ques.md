# git clone vs git fetch vs git pull
 
A quick reference for understanding what each command actually does, how they relate to each other, and when to reach for each one.
 
# TABLE
 
| Command | What it does | Changes your working files? | Typical use case |
|---|---|---|---|
| `git clone` | Downloads an entire repository (all branches, history, tags) and sets up a local copy | Yes — creates the whole project on disk | First time getting a repo onto your machine |
| `git fetch` | Downloads new commits/branches/tags from a remote, but doesn't touch your current branch | No | Checking what's new on the remote before deciding what to do |
| `git pull` | Runs `git fetch` **and then** merges (or rebases) those changes into your current branch | Yes — updates your working files | Getting your current branch up to date with the remote |
