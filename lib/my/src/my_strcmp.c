/*
** EPITECH PROJECT, 2020
** strcmp
** File description:
** compares arrays
*/

int compare_numbers(char  const *s1 , char  const *s2, int bigger_number)
{
    int mesure_one = 0;
    int mesure_two = 0;

    while (s1[mesure_one] != '\0') {
        mesure_one++;
    }
    mesure_one--;
    while (s2[mesure_two] != '\0') {
        mesure_two++;
    }
    mesure_two--;

    if (mesure_one > mesure_two) {
        bigger_number = mesure_one;
        return (bigger_number);
    } else {
        bigger_number = mesure_two;
        return (bigger_number);
    }
}

int  my_strcmp(char  const *s1 , char  const *s2)
{
    int position = 0;
    int ret = 0;
    int bigger_number = 0;

    bigger_number = compare_numbers(s1, s2, bigger_number);

    while (position <= bigger_number) {
        if (s1[position] != s2[position]) {
            ret = s1[position] - s2[position];
            return (ret);
        }
        position++;
    }
    return (ret);
}
