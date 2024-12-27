//declaración struct
struct Reader {   
char name[26]; 
int code; 
};


void p_new();
void p_add();
void p_vote();
void  p_clean();
int p_show (struct Reader *tab_r, int numero);
int p_init (struct Reader *tab_r, int *numero);

