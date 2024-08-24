#include "mesa.h"

struct Mesa find_mesa(FILE* in, unsigned int *numbers, unsigned int count, unsigned int *length, unsigned int *height )
{
    // Reads in the length and the height
    fscanf(in, "%u", length);
    fscanf(in, "%u", height);

    // Variable declarations and initializations
    unsigned int length_counter = 1;
    unsigned int mass = 1;
    struct Mesa result;
    result.valid = false;

    // For loop to iterate through the length of the array
    for (unsigned int i = 0; i < count; i++)
    {
        // Conditional that checks if all Mesa requirements are met
        if (numbers[i] >= *height && length_counter >= *length)
        {
            // First time a mesa is found - creates a mesa
            if (!(result.valid))
            {
                result.start = i - length_counter + 1;
                result.end = i;
                result.height = numbers[i];
                result.weight = length_counter * numbers[i];
                result.valid = true;
                mass = length_counter * numbers[i];
            }

            // If a new mesa has a larger mass than previous one - creates a new mesa
            else if (length_counter * numbers[i] > mass)
            {
                result.start = i - length_counter + 1;
                result.end = i;
                result.height = numbers[i];
                result.weight = length_counter * numbers[i];
                result.valid = true;
                mass = length_counter * numbers[i];
            }
        }

        // If the number to the right is not the same - reset length_counter
        if (i != count - 1 && numbers[i] != numbers[i + 1])
        {
            length_counter = 1;
        }

        // Increment length_counter
        else
        {
            length_counter++;
        }
    }

    return result;
}

void display_mesa( FILE* out, struct Mesa m )
{
    // Output and formatting of Mesa fields
    fprintf(out, "\n%s", "Start\t\tEnd\t\tHeight\t\tWeight\n");
    fprintf(out, "%d", m.start);
    fprintf(out, "%s", "\t\t");
    fprintf(out, "%d", m.end);
    fprintf(out, "%s", "\t\t");
    fprintf(out, "%d", m.height);
    fprintf(out, "%s", "\t\t");
    fprintf(out, "%d\n\n", m.weight);

}

