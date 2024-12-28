//declaración struct
struct Reader {   
char name[26]; 
int code; 
};

struct Book {   
char author[26]; 
char title[26]; 
int votes; 
int points; 
int signature; 
};


void p_new();
void p_add();
void p_vote();
void  p_clean();
int p_show (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b);
int p_init (struct Reader *tab_r, int *n_r, struct Book *tab_b, int *n_b);
void p_fin(struct Reader *tab_r, int *n_r, struct Book *tab_b,  int *n_b);
