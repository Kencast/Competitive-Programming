
int busq(int inf, int sup, int num, int array[]){
    int m=(inf+sup)/2;
    while(inf+1<sup){
        if(array[m]>num) sup=m;
        else inf=m;
        m=(inf+sup)/2;
    }
    //array[inf]<=num
    return inf; //retorna el indice
}