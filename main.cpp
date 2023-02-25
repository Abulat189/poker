#include <bits/stdc++.h>

using namespace std;

#pragma execution_character_set("utf-8")

enum suits {
  hearts = 0, //
  diamonds = 1, //
  clover = 2, //
  spades = 3 //
};

struct card {
  int suit;
  int value;
  //get char value of card, remember a card can be ten
  char get_value() {
    switch (value) {
      case 1:
        return 'A';
      case 10:
        return 'T';
      case 11:
        return 'J';
      case 12:
        return 'Q';
      case 13:
        return 'K';
      default:
        return value + '0';
    }
  }

  char char_value;
  
  //print card
  void print() {
    char_value = get_value();
    switch (suit) {
      case hearts:
        cout << char_value << "♥";
        break;
      case diamonds:
        cout << char_value << "♦";
        break;
      case clover:
        cout << char_value << "♣";
        break;
      case spades:
        cout << char_value << "♠";
        break;
    }
  }

  int hash() {
    return suit * 13 + value;
  }
};

struct player {
  vector<card> cards;
  vector<card> center;

  multiset<card> all;

  void printcenter() {
    for (int i = 0; i < center.size(); i++) {
      center[i].print();
      cout << " ";
    }
    cout << endl;
  }

  int score;
  
  int check() {
    for(int i = 0; i < cards.size(); i++){
      all.insert(cards[i]);
    }
    for(int i = 0; i < center.size(); i++){
      all.insert(center[i]);
    }

    //write a snippet to check if there are three same elements in the vector all
    //if there are three same elements, then the player has a three of a kind
    for(int i = 1; i <= 13; i++){
      int count = 0;
      for(auto it = all.begin(); it != all.end(); it++){
        if(it->value == i){
          count++;
        }
      }
      if(count == 3){
        cout << "Three of a kind" << endl;
        return 1;
      }
    }
    



    
    //check for royal flush
    //check for straight flush
    //check for four of a kind
    //check for full house
    //check for flush
    //check for straight
    //check for three of a kind
    //check for two pair
    //check for one pair
    //check for high card
    return 0;
  }

  //print cards and center
  void print() {
    for (int i = 0; i < cards.size(); i++) {
      cards[i].print();
      cout << " ";
    }
    for (int i = 0; i < center.size(); i++) {
      center[i].print();
      cout << " ";
    }
    cout << endl;
  }
};

vector<card> create_deck(){
  vector<card> deck;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 13; j++) {
      card c;
      c.suit = i;
      c.value = j;
      deck.push_back(c);
    }
  }
  return deck;
}

vector<player> deal(vector<card> deck, int player_count) {
  vector<player> players;
  for (int i = 0; i < player_count; i++) {
    player p;
    p.cards.push_back(deck[i * 2]);
    p.cards.push_back(deck[i * 2 + 1]);
    players.push_back(p);
  }
  return players;


}

int main() {
  srand (time(NULL));

  //get number of players
  int player_count;
  cin >> player_count;
  vector<player> players;

  //create a vector with all cards in a deck
  vector<card> deck = create_deck();

  //shuffle the deck
  random_shuffle(deck.begin(), deck.end());

  //deal cards to players
  players = deal(deck, player_count);

  //output the cards of each player

  for (int i = 0; i < player_count; i++) {
    cout << "Player " << i + 1 << ": ";
    for (int j = 0; j < 2; j++) {
      players[i].cards[j].print();
      cout << " ";
    }
    cout << endl;
  }

  while(true){
    //add three cards to the center
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < player_count; j++) {
        players[j].center.push_back(deck[player_count * 2 + i]);
      }
    }
    players[0].printcenter();
    //check if any player has a winning hand
    for (int i = 0; i < player_count; i++) {
      if(players[i].check()) {
        players[i].print();
        return 0;
      }
    }
    //if no player has a winning hand, add one card to the center
    for (int i = 0; i < player_count; i++) {
      players[i].center.push_back(deck[player_count * 2 + 3]);
    }  
  }

  
  
  return 0;
}