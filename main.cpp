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
};

struct player {
  vector<card> cards;
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


//create a deal function that deals to a vector of players
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
  
  return 0;
}