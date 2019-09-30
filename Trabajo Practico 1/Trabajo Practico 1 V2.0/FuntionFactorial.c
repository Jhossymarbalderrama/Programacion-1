int funtionFactorial(int n){
    int i;
    int fact=1;

    for(i=1; i<=n; i++)
        fact = fact * i;

    return fact;
}
