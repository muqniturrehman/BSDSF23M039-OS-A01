# 📄 REPORT.md  

## Student Info  
**Name:** Your Name  
**Roll No:** BSDSF23M039  
**Course:** Operating Systems  
**Assignment:** OS-A01  

---

## Feature-1: Project Scaffolding & Version Control  

**Q: Explain your initial project setup and Git workflow.**  
- I created a GitHub repository named `BSDSF23M039-OS-A01`.  
- Cloned it locally and set up the required folder hierarchy (`src/`, `include/`, `lib/`, `bin/`, `obj/`, `REPORT.md`).  
- Used Git to stage, commit, and push changes.  
- This ensures a professional base project layout with clean version control from the start.  

---

## Feature-2: Multi-file Project using Make Utility  

**Q: Explain the linking rule in this part’s Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?**  
- `$(TARGET): $(OBJECTS)` means the final executable (target) depends on compiled object files.  
- The rule tells `make` to link all objects together into a single binary.  
- When linking against a library, the rule would instead use `-L` (library path) and `-l` (library name), pulling precompiled code from a `.a` or `.so` file instead of directly from `.o` files.  

**Q: What is a git tag and why is it useful? What’s the difference between a simple and an annotated tag?**  
- A git tag marks a specific commit as a “version.”  
- Useful for versioning stable builds and creating releases.  
- **Simple tag**: just a pointer to a commit.  
- **Annotated tag**: contains metadata (author, date, message) and is preferred for releases.  

**Q: What is the purpose of creating a GitHub Release and attaching binaries?**  
- A release is a packaged checkpoint of the project.  
- Attaching binaries (like `bin/client`) allows others to run the program without building from source.  

---

## Feature-3: Creating and Using a Static Library  

**Q: Compare the Makefile from Part 2 and Part 3. What are the key differences?**  
- Part 2 directly compiled all `.c` files into the executable.  
- Part 3 first compiled `.c` files into `.o`, then archived them into a static library (`libmyutils.a`) using `ar`.  
- The executable (`client_static`) was linked against the `.a` instead of individual `.o` files.  

**Q: What is the purpose of the `ar` command? Why is `ranlib` often used after it?**  
- `ar` creates an archive `.a` file from object files (static library).  
- `ranlib` builds an index of the library’s symbols for faster linking (often integrated in `ar rcs`).  

**Q: When running `nm` on `client_static`, are symbols like `mystrlen` present? What does this tell you?**  
- Yes, the function symbols appear inside the final binary.  
- This proves that **static linking copies code from the library into the executable**.  

---

## Feature-4: Creating and Using a Dynamic Library  

**Q: What is Position-Independent Code (-fPIC) and why required for shared libraries?**  
- PIC means the code can run correctly regardless of where it is loaded in memory.  
- Required for `.so` files because the dynamic loader may map them at different addresses for different processes.  

**Q: Why is `client_dynamic` smaller than `client_static`?**  
- `client_static` includes full copies of all library code.  
- `client_dynamic` only stores references; actual code stays in `.so` and is loaded at runtime.  
- Hence the binary is smaller.  

**Q: What is LD_LIBRARY_PATH? Why did we set it?**  
- An environment variable telling the loader where to look for `.so` files beyond default system paths.  
- We set it so the loader can find our `lib/libmyutils.so`.  
- This shows the dynamic loader does not scan project directories automatically.  

---

## Feature-5: Creating and Accessing Man Pages  

**Q: Why are man pages important?**  
- They provide standard, accessible documentation for users and developers.  
- Following Linux conventions (section 1 for executables, section 3 for library functions) ensures consistency and professionalism.  

**Q: What does the `install` target in Makefile do?**  
- Copies the built executable into `/usr/local/bin` so it can run from anywhere as `client`.  
- Copies and compresses man pages into `/usr/local/share/man` so they are accessible via `man client` or `man 3 mygrep`.  
- Updates the man database (`mandb`) if available.  

---

## Final Submission  

**Q: What did you finalize in your REPORT.md file?**  
- Answered all report questions for Features 1–5 clearly.  
- Explained the workflow, tools, and concepts.  

**Q: What Git workflow did you follow at the end?**  
- Each feature was developed on its own branch (`multifile-build`, `static-build`, `dynamic-build`, `man-pages`).  
- Merged them back into `main` after completion.  
- Created annotated tags for each release (`v0.1.1-multifile`, `v0.2.1-static`, `v0.3.1-dynamic`, `v0.4.1-final`).  
- Pushed all branches and tags to GitHub for grading.  

---

## 📌 Reflection  

By completing this assignment, I practiced the **full professional C workflow**:  
- Writing modular code in `.c` + `.h` files.  
- Building executables with `make`.  
- Creating and linking against static and dynamic libraries.  
- Debugging and analyzing binaries with `nm`, `ar`, `ldd`.  
- Writing proper Linux man pages.  
- Using Git/GitHub workflow with branches, tags, and releases.  

This gave me a hands-on understanding of how real-world projects are built, documented, versioned, and released.  
