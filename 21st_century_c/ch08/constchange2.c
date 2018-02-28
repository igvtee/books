/* Compile with:
CFLAGS="-g -Wall" CC=c99 make constchange
*/
//No const in the header this time...
void set_elmt(int *a, int *b){
    a[0] = 3;
}

int main(){
    int a[10] = {};
    int const *b = a;
    set_elmt(a, (int *)b); //...so add a type-cast to the call.
}
