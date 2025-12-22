# semester-course-project

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
