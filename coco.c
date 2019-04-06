// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by YOUR-NAME-HERE (z5258152)
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


// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);

void store_values(int array_length, int array[]);
int prime_finder(int array_length, int general_array[], int prime_array[]);
void largest_play_no_win(int cards_played[], int legal_cards[], int legal_cards_length, int number_cards_played);
void coco_numbers(int number_cards_in_hand, int hand[], int cards_played[], int number_cards_played);
void divisible_numbers(int legal_cards[], int hand[], int number_cards_in_hand);

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE


// You should not need to change this main function

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
    
    
    while ( i > 0 && d  < 3){
        
        if (cards_in_hand[i] == DOUGLAS){
            
            i = i - 1;
        }
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
    
    if (number_cards_played > 0){
        
        int cards_played[number_cards_played];
        store_values(number_cards_played, cards_played);
        
        int prime_played[1];
        int prime_played_length = 0;
        prime_played_length = prime_finder(1, cards_played, prime_played);
        
        if (prime_played_game == 0 && prime_played_length == 1){
            prime_played_game = 1;
        }
        
        if (prime_played_length == 1 && primes_hand_length > 0){
            
            largest_play_no_win(cards_played, primes_hand, primes_hand_length, number_cards_played);
        }
        else if (prime_played_length == 1 && primes_hand_length <= 0){
        
            printf("%d\n", hand[number_cards_in_hand - 1]);
        }
        else if (prime_played_length == 0){
        
            coco_numbers(number_cards_in_hand, hand, cards_played, number_cards_played);
        }
        
    }
    else if (number_cards_played == 0){
        
        if (prime_played_game == 1){
            printf("%d\n", hand[0]);
        }
        else if(prime_played_game == 0){
        
            int legal_cards[number_cards_in_hand];
            divisible_numbers(legal_cards, hand, number_cards_in_hand);
        }
    }
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF

    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY


}

// ADD YOUR FUNCTIONS HERE

// Function to store values in hand into an array
void store_values(int array_length, int array[]){

    int i = 0;
    
    while (i< array_length){
        
        scanf("%d", &array[i]);
        

        i++;
    } 
}

// Function used to find primes and store them into an array
int prime_finder(int array_length, int general_array[], int prime_array[]){
    
    int i = 0;
    int d = 0;
    
    while (i < array_length){
        
        int prime = 1;
        int counter = 2;
        
        while (counter < general_array[i]){
        
            if (general_array[i] % counter == 0){
                
                prime = 0;
                
                // Exit loop if values is not array
                counter = general_array[i];
            }
            counter++;
        }   
        
        if (prime == 1){
        
            prime_array[d] = general_array[i];
            d++;
        }
        i++;
    }
    
    return d;
}

void largest_play_no_win(int cards_played[], int legal_cards[], int legal_cards_length, int number_cards_played){
    
    int i = legal_cards_length - 1;
    int card_printed = 0;
    int d = 0;
    
    while (i >= 0){
    
        d = 0;
        
        while (d < number_cards_played){
            if (legal_cards[i] < cards_played[d]){
            
                printf("%d\n", legal_cards[i]);
                card_printed = 1;
                
                // Exit loop condition
                i = -1;
                d = number_cards_played;
            }
            d++;
        }
        i = i - 1; 
    }
    
    if (card_printed == 0){
    
        printf("%d\n", legal_cards[0]);
    }
}

void coco_numbers(int number_cards_in_hand, int hand[], int cards_played[], int number_cards_played){

    int i = 0;
    int d = 0;
    int coco_cards[number_cards_in_hand];
    int douglas_index = -1;
    
    while (i < number_cards_in_hand){
    
        int counter = 2;
    
        while (counter < hand[i]){
        
            if ( hand[i] % counter == 0 && cards_played[0] % counter == 0){
            
                coco_cards[d] = hand[i];
                
                if (coco_cards[d] == DOUGLAS){
                    douglas_index = d;
                }
                
                d++;   
                counter = hand[i]; 
                
                
            }
            counter++;
        }
            
        i++;
    }

    
    i = 0;
    while (i < number_cards_played){
        if ( d > 0 && douglas_index > 0 && cards_played[i] > DOUGLAS){
            i = number_cards_played;
            printf("%d\n", coco_cards[douglas_index]);
            douglas_index = -1;
        }
        
        else if ( d > 0){
    
            largest_play_no_win(cards_played, coco_cards, d, number_cards_played);
            i = number_cards_played;
        }
        
        else {
            printf("%d\n", hand[number_cards_in_hand - 1]);
            i = number_cards_played;
        }
    i++;
    }
}


void divisible_numbers(int legal_cards[], int hand[], int number_cards_in_hand){
    
    int i = 0;
    int d = 0;
    
    while (i < number_cards_in_hand){
    
        int counter = 2;
        
        while (counter < hand[i]){
            
            if ( hand[i] % counter == 0){
            
                counter = hand[i];
                legal_cards[d] = hand[i];
                
                d++;
            }
            counter++;
        }
        i++;
    }
    if (d > 0){
        printf("%d\n", legal_cards[0]);
    }
    else{
        printf("%d\n", hand[0]);
    }
}
