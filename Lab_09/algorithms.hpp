int isSubstring(char* string, char* sub) {
    while (*sub != '\0') {
        if (!*string) return 1;
        if (*(string) == *(sub)) {
            string++;
            sub++;
        }
        else {
            *string++;
            continue;
        }
    }
    return 0;
}

int CountWords(char* mes) {
    int count = 1;
    for (int i = 0; i < MAX; i++) if (mes[i] == ' ') count++;
    return count;
}
