#include <cs50.h>
#include <stdio.h>
#include <string.h>
/*
Only the functions except the main is written by me and everything else is provided as part of the course
implements the tideman algorithm for the ranked voting

*/
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(pair);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();

    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] == preferences[j][i])
            {
                continue;
            }
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
            }
            else
            {
                pairs[k].winner = j;
                pairs[k].loser = i;
            }
            k += 1;
        }
    }
    pair_count = k;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int large_pos = i;
        pair temp;
        for (int j = i + 1; j < pair_count;
             j++) // using selection sort to reverse sort the winner loser pair based on strength
        {
            if ((preferences[pairs[j].winner][pairs[j].loser] -
                 preferences[pairs[j].loser][pairs[j].winner]) >
                (preferences[pairs[large_pos].winner][pairs[large_pos].loser] -
                 preferences[pairs[large_pos].loser]
                            [pairs[large_pos].winner])) // computes the strength and find which is
                                                        // smaller
            {
                large_pos = j;
            }
        }
        if (large_pos != i)
        {
            temp = pairs[i];
            pairs[i] = pairs[large_pos];
            pairs[large_pos] = temp;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!check_cycle(pairs[i]))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                if (j == candidate_count - 1) // it means that the entire coloumn was false and this
                                              // is the source of graph
                {
                    printf("%s\n", candidates[i]);
                    return;
                }
            }
            else
            {
                break;
            }
        }
    }
    return;
}

// check for any cycles

bool check_cycle(pair p) // uses stack to find if a cycle will form if a the pair p is added to the
                         // graph. true means cycle will be formed so don't add that edge.
{
    int candidate_store[9];
    int initial_point = p.winner;
    candidate_store[0] = p.loser;
    int top_pos = 1;
    int current_point;
    while (top_pos != 0)
    {
        current_point = candidate_store[top_pos - 1];
        top_pos -= 1;
        for (int i = 0; i < candidate_count; i++)
        {
            if (i == current_point)
                continue;
            if (locked[current_point][i] == true)
            {
                if (i == initial_point)
                {
                    return true;
                }
                candidate_store[top_pos] = i;
                top_pos += 1;
            }
        }
    }
    return false;
}
