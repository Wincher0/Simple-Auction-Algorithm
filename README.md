# Simple-Auction-Algorithm
Auction Algorithm in C

A C-based console application that simulates a dynamic auction environment. A user competes against automated participants featuring randomized financial constraints and probabilistic decision-making.

How It Works

Setup: Define the asset name, starting price, and the number of automated participants. The system assigns randomized budgets to all entities.

Bidding Rounds: In each round, you can choose to:

1 - Place Bid (Increases the current price)

2 - Pass (Skip the round but stay active)

3 - Withdraw (Exit the auction permanently)

Automated Logic: Non-user participants independently evaluate their hidden budgets to bid, pass, or drop out.

Resolution: The simulation terminates when no active participant places a higher bid, declaring the highest bidder as the winner.
