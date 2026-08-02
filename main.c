#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    int i, participantCount, startingPrice, minBudget, maxBudget, userBudget, currentBid, userStatus = 1, userParticipation = 1, auctionRound, participantDecision, bidAmount, highestBidder;
    char item[50];
    
    // Defines the name of the item to be auctioned
    printf("Enter the name of the item to be auctioned: ");
    scanf("%49[^\n]", item);
    
    // Defines the starting bid price of the item
    printf("Set the starting bid price of the item: ");
    scanf("%d", &startingPrice);
    
    // Defines the value range the budget can take
    maxBudget = startingPrice + 100000;
    minBudget = startingPrice + 5000;
    
    // Determines how many people will participate in the auction (excluding the user)
    printf("Specify the number of participants in the auction: ");
    scanf("%d", &participantCount);
    
    // Determines the user's budget
    userBudget = rand() % (maxBudget - minBudget + 1) + minBudget;
    
    int participantBudget[participantCount + 1];

    // Determines the budgets of the participants
    for(i = 1; i <= participantCount; i++) {
        participantBudget[i] = rand() % (maxBudget - minBudget + 1) + minBudget;
        // printf("Participant %d   Participant budget: %d\n", i, participantBudget[i]);
    }
    
    // Clears previous outputs
    system("cls");
    
    currentBid = startingPrice;
    bidAmount = 1000;    
    
    // Auction start
    printf("Auctioned item: %s", item);
    printf("\nStarting bid: %d", startingPrice);
    printf("\nYour Budget: %d", userBudget);
    
    for(auctionRound = 1; auctionRound >= 0; auctionRound++) {
    
        int activeParticipants = 0;
        
        if(userStatus == 1 && userBudget >= currentBid + bidAmount) {
            activeParticipants++;
        }
        
        for(i = 1; i <= participantCount; i++) {
            if(participantBudget[i] >= currentBid + bidAmount && highestBidder != i) {
                activeParticipants++;
            }
        }
        
        if(activeParticipants == 0) {
            printf("\n\nNo one can bid!");
            printf("\nAuction ended!");
            if(highestBidder == -1) {
                printf("\nAuction rounds: %d", auctionRound - 1);
                printf("\nCongratulations, you won the auction!");
                printf("\nFinal bid price: %d", currentBid);
            }
            else if(highestBidder > 0) {
                printf("\nAuction rounds: %d", auctionRound - 1);
                printf("\nParticipant %d won the auction!", highestBidder);
                printf("\nFinal bid price: %d", currentBid);
            } 
            else {
                printf("\nNo one bid, there is no winner!");
            }
            break;
        }
        
        printf("\n\n\nRound %d", auctionRound);
        int auctionStatus = 0;
        
        if(userStatus == 1 && userBudget >= currentBid + bidAmount){
            userParticipation = 1;
            if(userParticipation == 1) {
                // User makes a choice
                int choice;
                printf("\nMake your choice:\n1)Place Bid (%d)   2)Pass   3)Withdraw from Auction", bidAmount);
                printf("\nYour choice: ");
                scanf("%d", &choice);
                
                // Changes based on choice
                if(choice == 1) {
                	printf("Bid amount: ");
                	scanf("%d",bidAmount);
                    currentBid = currentBid + bidAmount;
                    printf("You placed a bid!");
                    printf("\nNew Bid: %d", currentBid);
                    highestBidder = -1;
                    auctionStatus = 1;
                }
                else if(choice == 2) {
                    printf("You passed the round!");
                    currentBid = currentBid;
                    printf("\nBid did not change: %d", currentBid);
                }
                else if(choice == 3) {
                    printf("\nYou withdrew from the auction, you will not participate in the next rounds!");
                    userStatus = 0;
                }
                else {
                    printf("\nInvalid action, skipping round!");
                    currentBid = currentBid;
                    printf("\nBid did not change: %d", currentBid);
                }
            }
        }
        else if (userBudget < currentBid) {
            printf("\nYou don't have enough money to bid!");
            userStatus = 0;
        }
        else {
            userParticipation = 0;
            printf("\nYou withdrew, waiting for other participants' bids!");
        }
    
        for(i = 1; i <= participantCount; i++) {
            if(participantBudget[i] >= currentBid + bidAmount && highestBidder != i) {
                participantDecision = (rand() % 20) + 1;
                if(participantDecision == 1) {
                    printf("\nParticipant %d withdrew from the auction!", i);
                    printf("\nBid did not change: %d", currentBid);
                    participantBudget[i] = 0;
                }
                else if(participantDecision != 1 && participantDecision <= 5){
                    printf("\nParticipant %d passed!", i);
                    printf("\nBid did not change: %d", currentBid);
                }
                else {
                    printf("\nParticipant %d increased the price!", i);
                    currentBid = currentBid + bidAmount;
                    printf("\nNew bid: %d", currentBid);
                    highestBidder = i;
                    auctionStatus = 1;
                }
            }
        }
        
        if(auctionStatus == 0) {
            printf("\n\nNo one bid this round!");
            printf("\nAuction ended!");
            if(highestBidder == -1) {
                printf("\nAuction rounds: %d", auctionRound);
                printf("\nCongratulations, you won the auction!");
                printf("\nFinal bid price: %d", currentBid);
            }
            else if(highestBidder > 0) {
                printf("\nAuction rounds: %d", auctionRound);
                printf("\nParticipant %d won the auction!", highestBidder);
                printf("\nFinal bid price: %d", currentBid);
            } 
            else {
                printf("\nNo one bid, there is no winner!");
            }
            break;
        }
    }
    return 0;
}

