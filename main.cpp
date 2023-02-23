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
  char char_value;
  
  int get_value() {
    switch (char_value) {
      case 'A':
        return 1;
      case 'J':
        return 11;
      case 'Q':
        return 12;
      case 'K':
        return 13;
      default:
        return char_value - '0';
    }
  }

  int value = get_value();
  
  void print() {
    switch (suit) {
      case hearts:
        cout << "♥";
        break;
      case diamonds:
        cout << "♦";
        break;
      case clover:
        cout << "♣";
        break;
      case spades:
        cout << "♠";
        break;
    }
    cout << value;
  }
};

int main() {
  int player_count;
  cin >> player_count;
  vector<vector<card>> player;

  //create a vector with all cards in a deck
  vector<card> deck;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 13; j++) {
      card c;
      c.suit = i;
      c.value = j;
      deck.push_back(c);
    }
  }
  
  //shuffle the deck
  random_shuffle(deck.begin(), deck.end());

  //deal cards to players
  for (int i = 0; i < player_count; i++) {
    vector<card> p;
    for (int j = 0; j < 2; j++) {
      p.push_back(deck.back());
      deck.pop_back();
    }
    player.push_back(p);
  }

  //output the cards of each player
  for (int i = 0; i < player_count; i++) {
    cout << "Player " << i + 1 << ": ";
    for (int j = 0; j < 2; j++) {
      player[i][j].print();
      cout << " ";
    }
    cout << endl;
  }
  
  return 0;
}