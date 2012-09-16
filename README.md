# Linked List for GameMaker

A doubly linked list module written in C++ to be used like GameMaker's `ds_list`. GameMaker can only pass doubles and strings to and from an external DLL, so the list handles and the stored values are all doubles. Creating a list returns a number, and later calls pick a list by that number, which is the same way `ds_list` is used. It consists of the list module and a console test that exercises it.

<p>
  <img src="docs/screenshots/screenshot-1.png" width="480" alt="Console test output">
</p>


## How to use

Running the test program from Releases prints the results of create, add, clear, read and delete, replace, and insert, switching between two lists as it goes. To build the source, open `LIST.dev` in wxDev-C++ or use `Makefile.win`.

The functions in `list.h` are used like this.

```cpp
double a = list_create();        // make a list and get its number
list_set_index(a);               // pick the list that later calls apply to
list_data_add(1); list_data_add(2); list_data_add(3);

list_data_set_read_pos(1);       // move the read cursor to the second value
list_data_insert(100);           // insert after the cursor: 1, 2, 100, 3
list_data_get_data();            // return the value at the cursor and step forward
list_destroy();                  // remove the picked list entirely
```


## How it works

**It is a list of lists.** Each list (`LIST`) owns a doubly linked list of value nodes (`DATA`), and the lists themselves are also doubly linked. Both are circular in the forward direction, with the last node's `next` pointing at the first, while the first node's `back` points at itself. `list_create` appends a new `LIST` to the ring and returns an increasing number. `list_set_index` walks the ring until the number matches and makes that the current list.

```cpp
typedef struct _LIST {
    struct _LIST *next, *back;      // links between lists
    struct _DATA *first, *last;     // value nodes of this list
    double index;
    double size;
} LIST;
```

**State is held as a current list and a read cursor.** Instead of passing a list number to every function, calls apply to whatever `list_set_index` picked. Inside it there is one read cursor. `list_data_get_data` returns the value at the cursor and steps forward, and delete, replace, and insert all happen at the cursor. When the cursor passes the end it wraps around, since the ring is circular.

**Everything is a double.** GameMaker's `external_define` only exchanges doubles and strings, so handles, sizes, positions, and stored values are all doubles, ready to be moved into a DLL later.


## Files

| Path | Contents |
|---|---|
| `source/list.h`, `source/list.cpp` | The linked list module |
| `source/main.cpp` | Console test |
| `source/LIST.dev`, `source/Makefile.win` | wxDev-C++ project and MinGW makefile |
| `docs/screenshots/` | Screenshots |
| Releases | Console test program |


## License

zlib. See [LICENSE](LICENSE).
