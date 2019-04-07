// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by ABDUL-KANJ (z5258152)
// on 29/03/19
//

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

#define DOUGLAS              42



void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);

void store_values(int array_length, int array[]);
int prime_finder(int array_length, int general_array[], int prime_array[]);
void largest_play_no_win(int cards_played[], int legal_cards[], int legal_cards_length, int number_cards_played);
void coco_numbers(int number_cards_in_hand, int hand[], int cards_played[], int number_cards_played);
void divisible_numbers(int legal_cards[], int hand[], int number_cards_in_hand);



int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Master Shredder");

}

void choose_discards() {
    
    int i = N_CARDS_INITIAL_HAND - 1;
    
    //Array storing card values in Players hand
    int cards_in_hand[N_CARDS_INITIAL_HAND];
    
    int cards_discard_index[3];
    int d = 0;
    
    store_values(N_CARDS_INITIAL_HAND, cards_in_hand);
    
    // loop used to ensure only three cards are discarded
    while ( i > 0 && d  < 3){
        
        // Statement to ensure the Douglas is kept in hand
        if (cards_in_hand[i] == DOUGLAS){
            
            i = i - 1;
        }
        // Discard largest card otherwise
        else{
        
            printf("%d ", cards_in_hand[i]);
            i = i - 1;
            d++;
        }
    }
    // Prints cards we are going to discard
    printf("\n");
}


void choose_card_to_play(void) {

    int number_cards_in_hand = 0;
    scanf("%d", &number_cards_in_hand);

    int number_cards_played = 0;
    scanf("%d", &number_cards_played);
    
    int table_position = 0;
    scanf("%d", &table_position);
    
    int hand[number_cards_in_hand];
    store_values(number_cards_in_hand, hand);

    int primes_hand[number_cards_in_hand];
    int primes_hand_length = 0;
    primes_hand_length = prime_finder(number_cards_in_hand, hand, primes_hand); 
    
    int prime_played_game = 0;
    
    // If we are not the first player follow through this IF statement
    if (number_cards_played > 0){
        
        int cards_played[number_cards_played];
        store_values(number_cards_played, cards_played);
        
        int prime_played[1];
        int prime_played_length = 0;
        prime_played_length = prime_finder(1, cards_played, prime_played);
        
        // If there has been a prime played 
        if (prime_played_game == 0 && prime_played_length == 1){
            prime_played_game = 1;
        }
        
        // Statement to play primes if we have primes in hand and a prime has been played
        if (prime_played_length == 1 && primes_hand_length > 0){
            
            largest_play_no_win(cards_played, primes_hand, primes_hand_length, number_cards_played);
        }
        
        // If a prime has been played and 0 primes in hand, play largest number in hand
        else if (prime_played_length == 1 && primes_hand_length <= 0){
        
            printf("%d\n", hand[number_cards_in_hand - 1]);
        }
        // If not a prime played first, play a coco number
        else if (prime_played_length == 0){
        
            coco_numbers(number_cards_in_hand, hand, cards_played, number_cards_played);
        }
        
    }
    // If we are the first player follow the following statements
    else if (number_cards_played == 0){
        
        // If prime has been played in previous round, play lowest card in hand
        if (prime_played_game == 1){
            printf("%d\n", hand[0]);
        }
        // If no prime has been played in previous round yet, play the lowest legal number
        else if(prime_played_game == 0){
        
            int legal_cards[number_cards_in_hand];
            divisible_numbers(legal_cards, hand, number_cards_in_hand);
        }
    }

}


// Function to store values in hand into an array
void store_values(int array_length, int array[]){

    int i = 0;
    
    // Loop used to go through all inputs and store them in an array
    while (i< array_length){
        
        scanf("%d", &array[i]);
        

        i++;
    } 
}

// Function used to find primes and store them into an array
int prime_finder(int array_length, int general_array[], int prime_array[]){
    
    int i = 0;
    int d = 0;
    
    // Loop used to go through array
    while (i < array_length){
        
        int prime = 1;
        int counter = 2;
        
        // Loop used to check whether prime or composite
        while (counter < general_array[i]){
        
            // If statement used to signify that the values are not prime
            if (general_array[i] % counter == 0){
                
                prime = 0;
                
                // Exit loop if values is not array
                counter = general_array[i];
            }
            counter++;
        }   
        
        // Statement used to store value if they are prime
        if (prime == 1){
        
            prime_array[d] = general_array[i];
            d++;
        }
        i++;
    }
    
    return d;
}

// Function to play the Largest card possible without winning the round
void largest_play_no_win(int cards_played[], int legal_cards[], int legal_cards_length, int number_cards_played){
    
    int i = legal_cards_length - 1;
    int card_printed = 0;
    int d = 0;
    
    // Loop used to go through all legal cards starting from largest value
    while (i >= 0){
    
        d = 0;
        
        // Loop used to go through all cards played during round and compare
        while (d < number_cards_played){
        
            if (legal_cards[i] < cards_played[d]){
            
                printf("%d\n", legal_cards[i]);
                card_printed = 1;
                
                // Exit loop conditions
                i = -1;
                d = number_cards_played;
            }
            d++;
        }
        i = i - 1; 
    }
    
    // If no card printed during the comparison Loop, play the smallest legal card
    if (card_printed == 0){
    
        printf("%d\n", legal_cards[0]);
    }
}

// Function to check which cards in hand are cocomoposite with the first card played for the round
void coco_numbers(int number_cards_in_hand, int hand[], int cards_played[], int number_cards_played){

    int i = 0;
    int d = 0;
    int coco_cards[number_cards_in_hand];
    int douglas_index = -1;
    
    // Main loop used to go through each card in hand
    while (i < number_cards_in_hand){
    
        int counter = 2;
        
        // Loop to test all possible common divisors
        while (counter < hand[i]){
        
            // If condition to ensure that the divisor is common to both cards
            if ( hand[i] % counter == 0 && cards_played[0] % counter == 0){
            
                coco_cards[d] = hand[i];
                
                // Stores index of the Douglas if it is a coco number with the first card played
                if (coco_cards[d] == DOUGLAS){
                    douglas_index = d;
                }
                d++;   
                
                // Exit condition to prevent unnecessary/repeated storing of the same card value 
                counter = hand[i]; 
            }
            counter++;
        }
        i++;
    }
    
    i = 0;
    
    
    int card_printed = 0;
    
    // Loop used to check whether card values played for the round are > than the Douglas
    while (i < number_cards_played){
     
        if ( d > 0 && douglas_index > 0 && cards_played[i] > DOUGLAS){
     
            i = number_cards_played;
            printf("%d\n", coco_cards[douglas_index]);
            
            // Unallocates variable storing douglas index to prevent incorrect use 
            douglas_index = -1;
            // Variable card_printed set to true
            card_printed = 1;
        }
    i++;
    }
    
    // If douglas is not played/unplayable use largest_playable_no_win function to decide card to play
    if ( d > 0 && card_printed != 1){
    
        largest_play_no_win(cards_played, coco_cards, d, number_cards_played);
        card_printed = 1;
    }
        
    // If no cards printed at all, play largest card in hand
    else if (card_printed != 1){
        printf("%d\n", hand[number_cards_in_hand - 1]);
        card_printed = 1;
    }

}

// Function to check which cards in hand are non-prime when playing first card / No prime played
void divisible_numbers(int legal_cards[], int hand[], int number_cards_in_hand){
    
    int i = 0;
    int d = 0;
    
    // Main Loop to store the composite numbers
    while (i < number_cards_in_hand){
    
        int counter = 2;
        
        // Loop used to go through all possible divisors
        while (counter < hand[i]){
            
            // If Loop to test whether divisible by the divisor
            if ( hand[i] % counter == 0){
            
                counter = hand[i];
                legal_cards[d] = hand[i];
                
                d++;
            }
            counter++;
        }
        i++;
    }
    
    // Plays the lowest legal card if any composite numbers in hand
    if (d > 0){
     
        printf("%d\n", legal_cards[0]);
    }
    
    // Plays lowest card value in hand if no composite numbers
    else{
     
        printf("%d\n", hand[0]);
    }
}
