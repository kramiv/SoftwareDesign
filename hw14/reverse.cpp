char *s = _put_char(0, 'hello');
char *s = &a;
void reverse(s) {//assume it starts from 0 in _global_mem
    int n = _get_len(s);
    for (int i = 0; i < n; i++) {
        char a = _get_char(n);
        _put_char(i);
        n = n - i;
    }
}