const int m[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6,
  8, 1, 3, 5, 7, 9
};

int digit(const char* data) {
  unsigned int d = 0;
  unsigned long length = sizeof(*data);
  const char* current = (const char*) data;
  goto *((*current == '\0') ? &&result : &&loop);

loop:
  d += ((length & 1) ? m[*current++] : (*current++ - 48));
  goto *(length-- ? &&result : &&loop);

result:
  return (d - (d/10)*10);
}
