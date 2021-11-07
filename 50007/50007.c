int count(int length[3]) {
     return 36*length[0] + 12*length[1] + length[2];
}
void init(int length[3]) {
    length[0] = length[1] = length[2] = 0;
    return;
}
void add(int length[3], int i) {
    int amount = count(length) + i;
    length[0] = amount/36;    amount %= 36;
    length[1] = amount/12;    amount %= 12;
    length[2] = amount;
    return;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    init(lengthc);
    add(lengthc, count(lengtha) + count(lengthb));
    return;
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    init(lengthc);
    add(lengthc, count(lengtha) - count(lengthb));
    return;
}
