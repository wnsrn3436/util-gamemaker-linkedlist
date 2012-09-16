typedef struct _LIST {
    struct _LIST *next, *back;
    struct _DATA *first, *last;
    double index;
    double size;
} LIST;

typedef struct _DATA {
    struct _DATA *next, *back;
    double data;
} DATA;

double list_create();
double list_set_index(double index);
void list_destroy();
void list_data_clear();
void list_data_add(double data);
double list_data_set_read_pos(double pos);
double list_data_get_read_pos();
double list_data_get_size();
double list_data_get_data();
double list_data_get_data_delete();
void list_data_delete();
void list_data_replace(double data);
void list_data_insert(double data);
