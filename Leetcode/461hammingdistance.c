int hammingDistance(int x, int y) {
    int number=x;
    int numbertwo=y;
    int difference=0;
    int value=0;
    for (int i=0;i<31;i++){
        if ((number & 1<<i) == (numbertwo & 1<< i)) {
        }else{
            value++;
            difference=(value>difference?value:difference);
        }

    }
    return difference;
     
}
