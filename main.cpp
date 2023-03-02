#include <iostream>


using namespace std;

string getCardNotation();
string extractCardNumber(string card_notation);
string extractCardSuit(string card_notation);
void displayCard(string number, string suit);

int main(){
    string card_notation = "";
    string card_number = "";
    string card_suit = "";
    string doItAgain = "";
    do {

        // get the card notation from the user
        card_notation = getCardNotation();

        // extract card number
        card_number = extractCardNumber(card_notation);

        // figure out the card suit
        card_suit = extractCardSuit(card_notation);

        // Display the full card name to the user
        displayCard(card_number, card_suit);

        cout << "Would you like to enter another card (Y/N):";
        cin >> doItAgain;

    } while (doItAgain == "Y" || doItAgain == "y");
    return 0;
}
/**
 * Collects the card notation from the User
 * @return The card notation such as "5H" or "6D"
 */
string getCardNotation() {
    string card_notation;
    cout << "Please enter the card notation: ";
    cin >> card_notation;
    return card_notation;
}

/**
 * Returns a card number as a word based on the card notation
 * @param card_notation notation for the card such as "5H" or "6D"
 * @return a word number like Ten, Five or King
 */
string extractCardNumber(string card_notation) {
    string card_number = "";
    char number = card_notation[0];

    switch (number) {
        case '1':
            // the only time the first char is '1' is when
            // the number is 10
            card_number = "Ten";
            break;
        case '2':
            card_number = "Two";
            break;
        case '3':
            card_number = "Three";
            break;
        case '4':
            card_number = "Four";
            break;
        case '5':
            card_number = "Five";
            break;
        case '6':
            card_number = "Six";
            break;
        case '7':
            card_number = "Seven";
            break;
        case '8':
            card_number = "Eight";
            break;
        case '9':
            card_number = "Nine";
            break;
        case 'j':
        case 'J':
            card_number = "Jack";
            break;
        case 'q':
        case 'Q':
            card_number = "Queen";
            break;
        case 'k':
        case 'K':
            card_number = "King";
            break;
        case 'a':
        case 'A':
            card_number = "Ace";
            break;
        default:
            card_number = "Error";
    }

    return card_number;
}

/**
 * Returns the card suit name such at "Diamond" or "Heart"
 * @param card_notation  notation for the card such as "5H" or "6D"
 * @return card suit name
 */
string extractCardSuit(string card_notation) {
    string suit = "";
    char suit_notation;
    if (card_notation.length() == 2) {
        suit_notation = card_notation[1];
    } else if (card_notation.length() == 3) {
        suit_notation = card_notation[2];
    } else {
        return "Error";
    }

    switch (suit_notation) {
        case 'D':
        case 'd':
            suit = "Diamonds";
            break;
        case 'S':
        case 's':
            suit = "Spades";
            break;
        case 'H':
        case 'h':
            suit = "Hearts";
            break;
        case 'C':
        case 'c':
            suit = "Clubs";
            break;
        default:
            suit = "Error";
    }

    return suit;
}

/**
 * Displays the full card name such as "Three of Clubs"
 * @param number number name
 * @param suit  number suit
 */
void displayCard(string number, string suit) {
    // Error Checking
    if (number == "Error" || suit == "Error") {
        cout << "Error That is not a Valid Card Notation!" << endl;
        return;
    }

    cout << number << " of " << suit << endl;

}
