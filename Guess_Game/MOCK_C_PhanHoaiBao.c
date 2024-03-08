#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define NUM_DIGITS 4

// Structure to store player information
struct Player
{
    char max_name[50];
    int correct_guesses;
    int total_guesses;
    float lucky_ratio;
};

// Function prototypes
void playGame(struct Player *player);
void printLuckyRatioHistory(struct Player players[], int num_players);

int main()
{
    printf("\t\t\t\t=================================================\n");
    printf("\t\t\t\t|\tWelcome to number guesting game !!!\t|\n");
    printf("\t\t\t\t=================================================\n\n");

    struct Player players[MAX_PLAYERS] = {0};
    int num_players = 0;

    printf("Please enter your name: ");
    fgets(players[num_players].max_name, sizeof(players[num_players].max_name), stdin);
    strtok(players[num_players].max_name, "\n"); // Remove newline character
    ++num_players;

    while (1)
    {
        playGame(&players[num_players - 1]);

        // Print lucky ratio history after each game
        printf("\nLucky Ratio History:\n");
        printLuckyRatioHistory(players, num_players);

        // Ask if the player wants to play again
        char choice;
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline character

        if ((choice == 'Y') && (choice == 'y'))
        {
            break;
        }
        else
        {
            printf("\n\t\t\t\t\t\tTHANK YOU FOR PLAYED GAME !!!\n\n\n");
            break;
        }

        // If there's space for more players, ask for another player's name
        if (num_players < MAX_PLAYERS)
        {
            printf("\nPlease enter the next player's name: ");
            fgets(players[num_players].max_name, sizeof(players[num_players].max_name), stdin);
            strtok(players[num_players].max_name, "\n"); // Remove newline character
            ++num_players;
        }
    }

    return 0;
}

// Function to play the number guessing game
void playGame(struct Player *player)
{
    srand(time(NULL));
    int magic_number[NUM_DIGITS];
    int guess[NUM_DIGITS];
    int i, j, matched;
    player->correct_guesses = 0;
    player->total_guesses = 0;

    // Generate magic number
    for (i = 0; i < NUM_DIGITS; ++i)
    {
        magic_number[i] = rand() % 10;
    }

    printf("\nWelcome, %s! Let's play the game!\n", player->max_name);

    // Main game loop
    while (1)
    {
        printf("Enter your guess (4 digits): ");
        for (i = 0; i < NUM_DIGITS; ++i)
        {
            scanf("%1d", &guess[i]);
        }
        getchar(); // Consume newline character

        player->total_guesses++;

        // Check if the guess matches the magic number
        matched = 0;
        printf("Result: ");
        for (i = 0; i < NUM_DIGITS; ++i)
        {
            if (guess[i] == magic_number[i])
            {
                printf("%d", guess[i]);
                ++matched;
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");

        if (matched == NUM_DIGITS)
        {
            player->correct_guesses++;
            printf("Congratulations, %s! You guessed the number correctly!\n", player->max_name);
            break;
        }
        else
        {
            // Do nothing!
        }
    }

    // Calculate lucky ratio
    player->lucky_ratio = (float)player->correct_guesses / player->total_guesses;
    printf("Your lucky ratio: %.2f (%d/%d)\n", player->lucky_ratio, player->correct_guesses, player->total_guesses);
}

// Function to print lucky ratio history of players
void printLuckyRatioHistory(struct Player players[], int num_players)
{
    // Sort players by lucky ratio (bubble sort)
    for (int i = 0; i < num_players - 1; ++i)
    {
        for (int j = 0; j < num_players - i - 1; ++j)
        {
            if (players[j].lucky_ratio < players[j + 1].lucky_ratio)
            {
                struct Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Print lucky ratio history
    for (int i = 0; i < num_players && i < MAX_PLAYERS; ++i)
    {
        printf("%d. %s: %.2f\n", i + 1, players[i].max_name, players[i].lucky_ratio);
    }
}
