# 0x1D. C - Binary trees

## Learning Objectives

### General

* What is a binary tree
* What is the difference between a binary tree and a Binary Search Tree
* What is the possible gain in terms of time complexity compared to linked lists
* What are the depth, the height, the size of a binary tree
* What are the different traversal methods to go through a binary tree
* What is a complete, a full, a perfect, a balanced binary tree

## Requirements

### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using _gcc_, using the options _-Wall -Werror -Wextra -pedantic -std=gnu89_
* All your files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called binary_trees.h
* Don’t forget to push your header file
* All your header files should be include guarded

### GitHub

* There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

### More Info

#### Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

* Basic Binary Tree
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
```

* Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```

* AVL Tree
```
typedef struct binary_tree_s avl_t;
```

* Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```

Note: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.
Print function

To match the examples in the tasks, you are given [this function](https://github.com/holbertonschool/0x1C.c)

This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction

# Tasks

## Mandatory tasks

* [Task 0](https://github.com/IMickisz/binary_trees/blob/main/0-binary_tree_node.c) : New node
<details>
<summary markdown="span">More</summary>

 Write a function that creates a binary tree node
 * Prototype: <font color="red">binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);</font>
 * Where <font color="red">parent</font> is a pointer to the parent node of the node to create
 * And <font color="red">value</font> is the value to put in the new node
 * When created, a node does not have any child
 * Your function must return a pointer to the new node, or <font color="red">NULL</font> on failure

    <details>
    <summary markdown="span">Exemple</summary>
    
        alex@/tmp/binary_trees$ cat 0-main.c
        #include <stdlib.h>
        #include "binary_trees.h"
        
        /**
         * main - Entry point
         *
         * Return: Always 0 (Success)
         */
        int main(void)
        {
            binary_tree_t *root;
        
            root = binary_tree_node(NULL, 98);
        
            root->left = binary_tree_node(root, 12);
            root->left->left = binary_tree_node(root->left, 6);
            root->left->right = binary_tree_node(root->left, 16);
        
            root->right = binary_tree_node(root, 402);
            root->right->left = binary_tree_node(root->right, 256);
            root->right->right = binary_tree_node(root->right, 512);
        
            binary_tree_print(root);
            return (0);
        }
        alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
        alex@/tmp/binary_trees$ ./0-node
               .-------(098)-------.
          .--(012)--.         .--(402)--.
        (006)     (016)     (256)     (512)
        alex@/tmp/binary_trees$
    </details>
</details>


* [Task 1](https://github.com/IMickisz/binary_trees/blob/main/1-binary_tree_insert_left.c) : Insert left
<details>
<summary markdown="span">More</summary>

 Write a function that inserts a node as the left-child of another node

 * Prototype: <font color="red">binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);</font>
 * Where <font color="red">parent</font> is a pointer to the node to insert the left-child in
 * And <font color="red">value</font> is the value to store in the new node
 * Your function must return a pointer to the created node, or <font color="red">NULL</font> on failure or if <font color="red">parent</font> is <font color="red">NULL</font>
 * If <font color="red">parent</font> already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.
    
    <details>
    <summary markdown="span">Exemple</summary>
    
        alex@/tmp/binary_trees$ cat 1-main.c 
        #include <stdlib.h>
        #include <stdio.h>
        #include "binary_trees.h"
        
        /**
         * main - Entry point
         *
         * Return: Always 0 (Success)
         */
        int main(void)
        {
            binary_tree_t *root;

            root = binary_tree_node(NULL, 98);
            root->left = binary_tree_node(root, 12);
            root->right = binary_tree_node(root, 402);
            binary_tree_print(root);
            printf("\n");
            binary_tree_insert_left(root->right, 128);
            binary_tree_insert_left(root, 54);
            binary_tree_print(root);
            return (0);
        }
        alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
        alex@/tmp/binary_trees$ ./1-left
          .--(098)--.
        (012)     (402)
        
               .--(098)-------.
          .--(054)       .--(402)
        (012)          (128)                                            
        alex@/tmp/binary_trees$
    </details>
</details>


* [Task 2](https://github.com/IMickisz/binary_trees/blob/main/2-binary_tree_insert_right.c) : Insert right
<details>
<summary markdown="span">More</summary>
    
 Write a function that inserts a node as the right-child of another node

 * Prototype: <font color="red">binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);></font>
 * Where <font color="red">parent</font> is a pointer to the node to insert the right-child in
 * And <font color="red">value</font> is the value to store in the new node
 * Your function must return a pointer to the created node, or <font color="red">NULL</font> on failure or if parent is NULL
 * If <font color="red">parent</font> already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.
    <details>
    <summary markdown="span">Exemple</summary>
    
        alex@/tmp/binary_trees$ cat 1-main.c 
        #include <stdlib.h>
        #include <stdio.h>
        #include "binary_trees.h"
        
        /**
         * main - Entry point
         *
         * Return: Always 0 (Success)
         */
        int main(void)
        {
            binary_tree_t *root;
        
            root = binary_tree_node(NULL, 98);
            root->left = binary_tree_node(root, 12);
            root->right = binary_tree_node(root, 402);
            binary_tree_print(root);
            printf("\n");
            binary_tree_insert_left(root->right, 128);
            binary_tree_insert_left(root, 54);
            binary_tree_print(root);
            return (0);
        }
        alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
        alex@/tmp/binary_trees$ ./1-left
          .--(098)--.
        (012)     (402)
        
               .--(098)-------.
          .--(054)       .--(402)
        (012)          (128)                                            
        alex@/tmp/binary_trees$
    </details>
</details>


* [Task 3](https://github.com/IMickisz/binary_trees/blob/main/3-binary_tree_delete.c) : <details>
<summary markdown="span">More</summary>

 Write a function that deletes an entire binary tree

 * Prototype: <font color="red">void binary_tree_delete(binary_tree_t *tree);</font>
 * Where <font color="red">tree</font> is a pointer to the root node of the tree to delete
 * If <font color="red">tree</font> is <font color="red">NULL</font>, do nothing
    <details>
    <summary markdown="span">Exemple</summary>
    
        alex@/tmp/binary_trees$ cat 3-main.c 
        #include <stdlib.h>
        #include <stdio.h>
        #include "binary_trees.h"
        
        /**
         * main - Entry point
         *
         * Return: Always 0 (Success)
         */
        int main(void)
        {
            binary_tree_t *root;
        
            root = binary_tree_node(NULL, 98);
            root->left = binary_tree_node(root, 12);
            root->right = binary_tree_node(root, 402);
            binary_tree_insert_right(root->left, 54);
            binary_tree_insert_right(root, 128);
            binary_tree_print(root);
            binary_tree_delete(root);
            return (0);
        }
        alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
        alex@/tmp/binary_trees$ valgrind ./3-del
        ==13264== Memcheck, a memory error detector
        ==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
        ==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
        ==13264== Command: ./3-del
        ==13264== 
          .-------(098)--.
        (012)--.       (128)--.
             (054)          (402)
        ==13264== 
        ==13264== HEAP SUMMARY:
        ==13264==     in use at exit: 0 bytes in 0 blocks
        ==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
        ==13264== 
        ==13264== All heap blocks were freed -- no leaks are possible
        ==13264== 
        ==13264== For counts of detected and suppressed errors, rerun with: -v
        ==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
        alex@/tmp/binary_trees$
    </details>
</details>


* [Task 4](https://github.com/IMickisz/binary_trees/blob/main/4-binary_tree_is_leaf.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 5](https://github.com/IMickisz/binary_trees/blob/main/5-binary_tree_is_root.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 6](https://github.com/IMickisz/binary_trees/blob/main/6-binary_tree_preorder.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 7](https://github.com/IMickisz/binary_trees/blob/main/7-binary_tree_inorder.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 8](https://github.com/IMickisz/binary_trees/blob/main/8-binary_tree_postorder.c) : 
<details>
<summary markdown="span">More</summary>
    
    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 9](https://github.com/IMickisz/binary_trees/blob/main/9-binary_tree_height.c) :
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 10](https://github.com/IMickisz/binary_trees/blob/main/10-binary_tree_depth.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 11](https://github.com/IMickisz/binary_trees/blob/main/11-binary_tree_size.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 12](https://github.com/IMickisz/binary_trees/blob/main/12-binary_tree_leaves.c) : 
<details>
<summary markdown="span">More</summary>
    
    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 13](https://github.com/IMickisz/binary_trees/blob/main/13-binary_tree_nodes.c) : 
<details>
<summary markdown="span">More</summary>
    
    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 14](https://github.com/IMickisz/binary_trees/blob/main/14-binary_tree_balance.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 15](https://github.com/IMickisz/binary_trees/blob/main/15-binary_tree_is_full.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 16](https://github.com/IMickisz/binary_trees/blob/main/16-binary_tree_is_perfect.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 17](https://github.com/IMickisz/binary_trees/blob/main/17-binary_tree_sibling.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>


* [Task 18](https://github.com/IMickisz/binary_trees/blob/main/18-binary_tree_uncle.c) : 
<details>
<summary markdown="span">More</summary>

    <details>
    <summary markdown="span">Exemple</summary>
    
    </details>
</details>

## Advanced tasks

* [Task ]() : 
```
```
