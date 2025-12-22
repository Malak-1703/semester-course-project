# semester-course-project

### Module Assignments

- **Adam**
  - `src/array_list.c`
  - `src/linked_list.c`

- **Malak**
  - `src/stack.c`

- **Marwa**
  - `src/queue.c`
  - `src/priority_queue.c`

- **Hamza**
  - `src/search.c`

- **Yassine**
  - `src/sort.c`
  - `src/tree.c`

- **Haytam**
  - `src/graph.c`

### Responsibility Rules

- Each member is responsible for:
  - Correct implementation of assigned modules
  - Memory safety and correctness
  - Compliance with function contracts defined in header files
- No member may modify another module’s public interface without team approval
- Integration is performed only after all modules respect their documented behavior

### Oral Defense Note

During the oral defense, each team member must be able to:
- Explain the design choices of their assigned data structures
- Justify algorithmic complexity
- Describe how their module interacts with the rest of the system

### Design Rule

All behavioral rules and module responsibilities are defined in the `.h` files.  
Each `.c` file must strictly follow the contract described in its corresponding header.

---

## Core Data Structure

### LoginRecord

`LoginRecord` is the **central data model** shared across all modules.

```c
typedef struct {
    char timestamp[20];
    char username[32];
    char ip[16];
    int success;  // 1 = success, 0 = failure
} LoginRecord;
