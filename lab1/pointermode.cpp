#define _CRT_SECURE_NO_WARNINGS
#include "pointermode.h"

using namespace std;

char* enter_filename() {
    char* filename = new char[123];
    cout << "Enter the name of the file: ";
    cin >> filename;
    return filename;
}

void generate_input(const char* filename) {
    FILE* fp = fopen(filename, "a");

    if (fp == NULL) {
        std::cout << "Error. File cannot be read" << std::endl;
    }
    else {
        std::cout << "Enter the text: ";
        std::cin.ignore();

        char* text = new char[2048];
        while (true) {
            std::cin.getline(text, 2047);
            if (text[0] == '\n' || text[0] == '\0') break;
            fprintf(fp, "%s\n", text);
        }

        delete[] text;
        fclose(fp);
    }

}

void read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char line;

    if ((fp = fopen(filename, "r")) == NULL) {
        std::cout << "Unfortunately this file cannot be read" << std::endl;
    }
    while ((line = fgetc(fp)) != EOF) {
        std::cout << line;
    }

    fclose(fp);
}

int countstrings(const char* filename) {
    int counter = 0;
    FILE* fp = fopen(filename, "r");
    char c;
    do {
        c = fgetc(fp);
        if (c == '\n') {
            counter++;
        }
    } while (c != EOF);

    fclose(fp);
    return counter;
}

void deleteOddStrings(const char* filename) {
    FILE* file = fopen(filename, "r");
    FILE* output = fopen("outputtemp.txt", "w");

    char buffer[2048];
    int del = 0;
    char c;
    int len = 0;
    int i, st = 0;
    int row = countstrings(filename);

    if (file == NULL || output == NULL)
    {
        printf("Error opening file(s)\n");
    }

    do {
        fgets(buffer, 2048, file);
        if (del % 2 != 0) {
            fputs(buffer, output);
        }

        del++;
    } while (del < row);

    fclose(file);
    fclose(output);
}

void strngs(const char* filename, const char* outname) {
    FILE* fp = fopen(filename, "r");
    FILE* output = fopen(outname, "w");

    char c;
    int len = 0;
    char buffer[2048];
    int i, st = 0;
    int row = countstrings(filename);

    do {

        char a[2048] = { 0 };
        char b[2048] = { 0 };

        char u[100];
        char o[100];
        fgets(buffer, 2048, fp);
        len = strlen(buffer);
        int k = 0;
        int g = 0;

        for (i = 0; i <= len; i++) {
            c = buffer[i];

            if (i % 2 == 0) {
                int y = 0;
                if (c == '\n') {
                    u[y] = c;
                    y++;
                }
                else {
                    b[k] = c;
                    k++;
                }

            }
            else {
                int p = 0;
                if (c == '\n') {
                    o[p] = c;
                    p++;
                }
                else {
                    a[g] = c;
                    g++;
                }
            }
        }

        int arr1Len = strlen(b);
        int arr2Len = strlen(a);
        char result[2048] = {0};
        int n = arr1Len + arr2Len;

        strcpy(result, b);
        strcat(result, a);

        int f, odd_words_count = 0;
        int word_len = 0;
        bool in_word = false;

        for (f = 0; f < n; f++) {
            if (result[f] != ' ') {
                in_word = true;
                word_len++;
            }
            else {
                if (in_word && word_len % 2 != 0) {
                    odd_words_count++;
                }
                in_word = false;
                word_len = 0;
            }
        }
        if (in_word && word_len % 2 != 0) {
            odd_words_count++;
        }

        fprintf(output, "%s,", result);
        fprintf(output, " %d\n", odd_words_count);

        for (int u = 0; u < len; u++) {
            result[u] = '\0';
            a[u] = '\0';
            b[u] = '\0';
        }

        st++;
    } while (st < row);


    fclose(fp);
    fclose(output);
}

void pointermode(const char* filename) {

    generate_input(filename);

    cout << "\nInput file:\n";
    read_file(filename);

    deleteOddStrings(filename);

    const char* temp = "outputtemp.txt";
    const char* outfile = "output.txt";
    strngs(temp, outfile);

    cout << "\nOutput file:\n";
    read_file(outfile);

}
