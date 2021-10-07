#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

// Create pointer for FILE type object
FILE *sourceFile;

int main(int argc, char *argv[])
{
    // Check if source file path is provided in args
    if (argc < 2)
    {
        fprintf(stderr, "Error occured %s", argv[0]);
        return 1;
    }

    // Creating bf source file buffer
    char file_buff[3000] = {0};
    char bf_buff[30000] = {0};
    char *bf_pointer = bf_buff;

    // Open bf source file
    sourceFile = fopen(argv[1], "r");

    // Reading and loading file to buff
    if (sourceFile != NULL)
    {
        //Create file read byte buffer
        int char_buff = 0, buff_counter = 0;

        //Read source file
        do
        {
            // Read char from file
            char_buff = fgetc(sourceFile);

            // Put readed char to file buffor
            if (!(char_buff == -1 || char_buff == 10 || char_buff == 13))
            {
                file_buff[buff_counter] = char_buff;
            }
            else
            {
                buff_counter--;
            }

            // Increment buff conuter and throw error if overflow occurs
            buff_counter++;
            if (buff_counter >= sizeof(file_buff))
            {
                fprintf(stdout, "Error occured: file buffer overflow!");
                return 1;
            }
        } while (char_buff != EOF);

        // Close source file
        fclose(sourceFile);
    }
    else
    {
        fprintf(stderr, "Error occured: can't open file!");
    }

    for (int i = 0; i < sizeof(file_buff); i++)
    {
        // Increment pointer
        if (file_buff[i] == '>')
        {
            bf_pointer += 1;
        }
        // Decrement pointer
        else if (file_buff[i] == '<')
        {
            bf_pointer -= 1;
        }
        else if (file_buff[i] == '+')
        {
            *bf_pointer += 1;
        }
        else if (file_buff[i] == '-')
        {
            *bf_pointer -= 1;
        }
        else if (file_buff[i] == '.')
        {
            printf("%c", *bf_pointer);
        }
        else if (file_buff[i] == ',')
        {
            *bf_pointer = getchar();
            while (getchar() != '\n')
                ;
        }
        else if (file_buff[i] == '[')
        {
            if ((*bf_pointer) == 0)
            {
                int iteration_level = 0;

                do
                {
                    i++;
                } while (file_buff[i] != ']');
            }
        }
        else if (file_buff[i] == ']')
        {
            int iteration_level = 0;

            do
            {
                i--;
            } while (file_buff[i] != '[');
            i--;
        }
        // End of program
        else if (file_buff[i] == 0)
        {
            printf("\n");
            return 0;
        }
        // Error in src file
        else
        {
            fprintf(stderr, "Error occured: error in source file! | %d | %d \n", i, (int)file_buff[i]);
        }
    }

    return 0;
}