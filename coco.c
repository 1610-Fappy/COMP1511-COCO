// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by YOUR-NAME-HERE (z5258152)
// on INSERT-DATE-HERE
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


// IF YOU NEED MORE #defines ADD THEM HERE

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


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

    // Prints the Players name

    printf("Master Shredder");

}

void choose_discards() {
    
    // Counter used to initialise values into array of cards in hand
    int i = 0;
    //Array storing card values in Players hand
    int cards_in_hand[N_CARDS_INITIAL_HAND];
    
    // Loop used to store intial card values into array
    while (i < N_CARDS_INITIAL_HAND){
        
        // Storing Value into array
        scanf("%d", &cards_in_hand[i]);
        
        //Increments counter by 1
        i++;
    }
    
    /* Loop used to test that values are correctly stored in Array
    
    i = 0;
    while (i < N_CARDS_INITIAL_HAND){
        
        // Printing Values out
        printf("%d ", cards_in_hand[i]);
        
        //increment counter by 1
        i++;
    }
    
    */
    
    // Prints cards we are going to discard
    printf("%d %d %d\n", cards_in_hand[9], cards_in_hand[8], cards_in_hand[7]);
    

}


void choose_card_to_play(void) {
    
    // Variable to store number of cards currently in hand (1-10)
    int number_cards_in_hand = 0;
    
    // scanf used to receive how many cards in hand from referee
    scanf("%d", &number_cards_in_hand);
    
    // How many cards have been played in the round so far (0-3)
    int number_cards_played = 0;
    
    // scanf used to receive number of cards played from referee
    scanf("%d", &number_cards_played);
    
    // Array to store values of cards played this round (Added 1 for case where we are in first position)
    int cards_played[number_cards_played + 1];
    
    // Counter used in loop to store card values played this round
    int counter = 0;
    
    // Table Position (0-3)
    int table_position = 0;
    
    // scanf used to receive table position from referee
    scanf("%d", &table_position);
   
    // Counter used to initialise values into array of cards in hand
    int i = 0;
    
    //Array storing card values in Players hand
    int cards_in_hand[number_cards_in_hand];
    
    
    // Loop used to store intial card values into cards_in_hand[] array
    while (i < number_cards_in_hand){
        
        // Storing Value into array
        scanf("%d", &cards_in_hand[i]);
        
        //Increments counter by 1
        i++;
    }
    
    // Counter used within array as condition to exit once all values are stored
    i = 0;
    
    // Loop used to store cards played in the round so far
    while ( i < number_cards_played){
    
        //Used to store the values into the array
        scanf("%d", &cards_played[i]);
        
        i++;
    }
    // Loop used to check if values are stored in array correctly
    
    /*
    i = 0;
    while (i < number_cards_in_hand){
        
        // Printing Values out
        printf("%d ", cards_in_hand[i]);
        
        //increment counter by 1
        i++;
    }
    */
    
    i = 0;
    
    // Variable used as a boolean to indicate whether the first card value played was a prime number
    int prime_number = 0;
    
    // Used to increment the index for where the values are stored in the array for legal_cocomposite_hand[]
    int d = 0;
    
    // Initialise array to store cards in hand which are playable 
    int legal_cocomposite_number[10];
    
    if (number_cards_played > 0) {
        while (i < number_cards_in_hand){
            
            // Variable used to store the lowest number when comparing first card value played and card in hand to be tested
            int lowest_number = 0;
        
            //Counter used to go through all possible factors
            counter = 2;
            
            // IF statement to test for lowest card value to limit the factors which it loops through until
            if (cards_in_hand[i] < cards_played[0]){
            
                // Assigns the lowest card value to the current card value that we are trying to test for cocomposicy
                lowest_number = cards_in_hand[i];
            
            }
            else{
                
                // Assigns the lowest card value to the first card played
                lowest_number = cards_played[0];
            
            }
        
            //Loop used to go through all possible factors between 2 and the first number played
            while (counter < lowest_number){
            
                //Testing condition for whether the number is cocomposite with the original number played
                if (cards_played[0] % counter == 0 && cards_in_hand[i] % counter == 0){
            
                    //Assigning the cocomposite number into the array cards_in_hand[]
                    legal_cocomposite_number[d] = cards_in_hand[i];
                    d++;
                
                    //Used to exit loop once we find that the number is cocomposite and continue to test other numbers
                    counter = cards_played[0];
                }
                
                // Incrementing counter to continue trying to find factors
                counter++;
        
            }   
        
            i++;
    
        }
        
        if (d > 0){
    
            printf("%d\n", legal_cocomposite_number[0]);
        }
        else {
            printf("%d\n", cards_in_hand[number_cards_in_hand - 1]);
 
        }    
    }
    else if (number_cards_played == 0){
        printf("%d\n", cards_in_hand[number_cards_in_hand - 1]);
    }
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF

    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF

    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY

 

}

// ADD YOUR FUNCTIONS HERE

