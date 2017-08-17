const int m[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

int luhn_digit(const char* data, unsigned long length) {
  if (!length || *data == '\0') return 0;

  int d = 0;
  int c;

  do {
    c = *data++ - 48;
    if (c < 0 || c > 9) return -1;
    d += ((length & 1) ? c : m[c]);
  } while(--length);

  return (d - (d/10)*10);
}
