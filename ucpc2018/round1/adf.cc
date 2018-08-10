void rotate(char dest[4][4], char src[4][4]) {
  int i, j;
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      dest[j][3-i]=src[i][j];
    }
  }
}
