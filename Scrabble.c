#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    //  Compute and return score for string
    int p = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //converts letter to lowercase if it is uppercase
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        //converts letter in ASCII format to points in the new format
        if (word[i] >= 97 && word[i] <= 122)
        {
            int f = word[i] - 97;
            word[i] = POINTS[f];
        }
        //Ignores non-letters from counting toward the total score
        else
        {
            word[i] = 0;
        }
        p += word[i];
    }
    //returns the total score
    return p;
}

