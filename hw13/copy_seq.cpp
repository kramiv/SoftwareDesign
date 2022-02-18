//look up examples
void copy_seq(char *s, char *&t) {
    t = s;
}

int main() {
    char a[] = "hi";
    int k = a[3];
    char b[k];
    copy_seq(a, b);
}
