void putchar(char c) {
    volatile char *video = (volatile char *) 0xB8000;  // Video memory address
    *video = c;
}

void clear_screen() {
    const char *str = "                          "; // Blank line for clearing
    for (int i = 0; i < 25; i++) {  // 25 lines on the screen
        for (int j = 0; j < 80; j++) {  // 80 columns
            putchar(' ');  // Fill with spaces
        }
    }
}

void print_string(const char *str) {
    while (*str) {
        putchar(*str);
        str++;
    }
}

char getchar() {
    volatile unsigned short *port = (unsigned short *) 0x60;  // Keyboard input port
    return *port;  // Get the character from the keyboard
}

int atoi(const char *str) {
    int num = 0;
    while (*str >= '0' && *str <= '9') {
        num = num * 10 + (*str - '0');  // Convert char to integer
        str++;
    }
    return num;
}

void get_input(char *buffer, int max_length) {
    int i = 0;
    char c;
    while (i < max_length - 1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';  // Null terminate the string
}

void number_guessing_game() {
    int number = 42;  // Let's set the target number to 42
    char input[10];
    int guess;
    
    clear_screen();
    print_string("Welcome to the Number Guessing Game!\n");
    print_string("Guess the number (between 1 and 100): ");
    
    while (1) {
        get_input(input, 10);
        guess = atoi(input);
        
        if (guess > number) {
            print_string("Too high! Try again: ");
        } else if (guess < number) {
            print_string("Too low! Try again: ");
        } else {
            print_string("You guessed it right! The number was 42.\n");
            break;
        }
    }
}

void main() {
    clear_screen();
    print_string("Welcome to MishoOS!\n");

    number_guessing_game();
}
