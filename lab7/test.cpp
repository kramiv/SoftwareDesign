int main() {
    int test(int i) {//index of an element of the array elt
        if (i < (size - 1)) {
            if (i > 0) {
                return elt[i];
            }
        }
        if (i < 0) {
            return elt[0];
            std::cerr << "warning: i out of range of array elt. too small" << '\n';
        }
        if (i > (size - 1)) {
            return elt[(size - 1)];
            std::cerr << "warning: i out of range of array elt. too big" << '\n';
        }

    }
}