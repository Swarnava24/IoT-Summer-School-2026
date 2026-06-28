# What is a `.gitignore` file?
 
A `.gitignore` file tells Git which files or folders to **ignore** — i.e., not track, stage, or commit. It's used for files that don't belong in version control, such as compiled output, OS-generated files, IDE settings, and temporary/build files. This keeps the repository clean and avoids committing machine-specific or auto-generated content.
 
## `.gitignore` for an Arduino project
 
```gitignore
# Compiled output files
*.hex
*.elf
 
# OS-specific files
.DS_Store
Thumbs.db
 
# IDE config folders
.vscode/
build/
```
