const int m[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

int digit(const char* data) {
  unsigned int d = 0;
  char c;
  unsigned long length = sizeof(*data);
  goto *((*data == '\0') ? &&result : &&loop);

loop:
  c = *data++;
  if (c < '0' || c > '9') {
    return -1;
  }
  d += ((length & 1) ? m[c - 48] : (c - 48));
  goto *(--length ? &&loop : &&result);

result:
  return (d - (d/10)*10);
}
