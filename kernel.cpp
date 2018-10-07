// ThanOS
// Copyright Benjamin Kyd (c) 2018

int kernel_main(void) {
    const char* str = "Your mother gay lol";
    char* videoMemoryPtr = (char*)0xb8000; // Video memory start

    unsigned int i = 0;
    unsigned int j = 0;

    while (j < 80 * 25 * 2) {
        videoMemoryPtr[j] = ' ';
        videoMemoryPtr[j+1] = 0x07;
        j += 2;
    }

    j = 0;

    while(str[j] != '\0') {
        videoMemoryPtr[i] = str[j];
        videoMemoryPtr[i+1] = 0x07;
        j++;
        i += 2;
    }

    return 1;
}
