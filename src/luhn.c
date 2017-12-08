const int m[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

int luhn_digit(const char* data) {
  if (*data == '\0') return 0;

  int d = 0;
  int t = 0;
  unsigned int c;

  do {
    c = *data++ - 48;
    if (c > 9) return -1;
    d += ((t & 1) ? c : m[c]);
    t ^= 1;
  } while(*data);

  d = (10 - (d%10));
  return (d == 10) ? 0 : d;
}

int luhn_valid(const char* data) {
  return luhn_digit(data) == 0;
}
