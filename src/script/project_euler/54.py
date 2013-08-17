def check_royal_flush(p1_cards, p2_cards):
    # Check if p1 has a royal flush
    sdhc = [set([110, 111, 112, 113, 114]), set([210, 211, 212, 213, 214]), set([310, 311, 312, 313, 314]), set([410, 411, 412, 413, 414])]
    for rf in sdhc:
        if rf.issubset(p1_cards):
            return 1
    for rf in sdhc:
        if rf.issubset(p2_cards):
            return 2
    return 0

def check_straight(p1_cards, p2_cards):
    p1_vals = []
    p2_vals = []
    for card in p1_cards:
        p1_vals.append(card - (card / 100 * 100))
    for card in p2_cards:
        p2_vals.append(card - (card / 100 * 100))
    return check_straight_flush(p1_vals, p2_vals)

def check_straight_flush(p1_cards, p2_cards):
    list1 = list(p1_cards)
    list2 = list(p2_cards)

    list1.sort()
    list2.sort()

    p1_has_straight_flush = -1
    p2_has_straight_flush = -1

    if (list1[4] == list1[3] + 1 == list1[2] + 2 == list1[1] + 3 == list1[0] + 4):
        p1_has_straight_flush = list1[4]
    if (list2[4] == list2[3] + 1 == list2[2] + 2 == list2[1] + 3 == list2[0] + 4):
        p2_has_straight_flush = list2[4]

    if p1_has_straight_flush > p2_has_straight_flush:
        return 1
    elif p1_has_straight_flush < p2_has_straight_flush:
        return 2

    return 0

def check_full_house(p1_cards, p2_cards):
    p1_values = set()
    p2_values = set()
    p1_card_count = [0] * 15
    p2_card_count = [0] * 15

    for card in p1_cards:
        p1_values.add(card - (card / 100 * 100))
        p1_card_count[card - (card / 100 * 100)] += 1

    for card in p2_cards:
        p2_values.add(card - (card / 100 * 100))
        p2_card_count[card - (card / 100 * 100)] += 1
    p1_3card = -1
    p1_2card = -1
    for i, val in enumerate(p1_card_count):
        if val == 3:
            p1_3card = i
        if val == 2:
            p1_2card = i

    p2_3card = -1
    p2_2card = -1

    for i, val in enumerate(p2_card_count):
        if val == 3:
            p2_3card = i
        if val == 2:
            p2_2card = i
    if p1_3card != -1 and p1_2card != -1:
        # p1 has a full house
        if p2_3card != -1 and p2_2card != -1:
            # p2 has a full house
            if p1_3card > p2_3card:
                return 1
            else:
                return 2
        else:
            return 1
    elif p2_3card != -1 and p2_2card != -1:
        return 2
    
    return 0


def check_three_of_kind(p1_cards, p2_cards):

    p1_values = set()
    p2_values = set()
    p1_card_count = [0] * 15
    p2_card_count = [0] * 15

    for card in p1_cards:
        p1_values.add(card - (card / 100 * 100))
        p1_card_count[card - (card / 100 * 100)] += 1

    for card in p2_cards:
        p2_values.add(card - (card / 100 * 100))
        p2_card_count[card - (card / 100 * 100)] += 1
        
    p1_3card = -1

    for i, val in enumerate(p1_card_count):
        if val == 3:
            p1_3card = i

    p2_3card = -1

    for i, val in enumerate(p2_card_count):
        if val == 3:
            p2_3card = i
    if p1_3card != -1:
        # p1 has a three of a kind
        if p2_3card != -1:
            # p2 has three of a kind
            if p1_3card > p2_3card:
                return 1
            else:
                return 2
        else:
            return 1
    elif p2_3card != -1:
        return 2
    
    return 0

def check_one_pair(p1_cards, p2_cards):

    p1_values = set()
    p2_values = set()
    p1_card_count = [0] * 15
    p2_card_count = [0] * 15

    for card in p1_cards:
        p1_values.add(card - (card / 100 * 100))
        p1_card_count[card - (card / 100 * 100)] += 1

    for card in p2_cards:
        p2_values.add(card - (card / 100 * 100))
        p2_card_count[card - (card / 100 * 100)] += 1
        
    p1_2card = -1

    for i, val in enumerate(p1_card_count):
        if val == 2:
            p1_2card = i

    p2_2card = -1

    for i, val in enumerate(p2_card_count):
        if val == 2:
            p2_2card = i
    if p1_2card != -1:
        # p1 has a three of a kind
        if p2_2card != -1:
            # p2 has three of a kind
            if p1_2card > p2_2card:
                return 1
            else:
                return 2
        else:
            return 1
    elif p2_2card != -1:
        return 2
    
    return 0

def check_flush(p1_cards, p2_cards):
    p1_suits = set()
    p2_suits = set()
    p1_high_card = -1
    p2_high_card = -1
    for card in p1_cards:
        p1_suits.add(card / 100)
        card_val =  card - (card / 100 * 100)
        if card_val > p1_high_card:
            p1_high_card = card_val
    for card in p2_cards:
        p2_suits.add(card / 100)        
        card_val =  card - (card / 100 * 100)
        if card_val > p2_high_card:
            p2_high_card = card_val

    if len(p1_suits) == 1:
        if len(p2_suits) == 1:
            if p1_high_card > p2_high_card:
                return 1
            else:
                return 2
        else:
            return 1
    elif len(p2_suits) == 1:
        return 2
    return 0

def check_two_pairs(p1_cards, p2_cards):
    p1_values = set()
    p2_values = set()
    p1_card_count = [0] * 15
    p2_card_count = [0] * 15

    for card in p1_cards:
        p1_values.add(card - (card / 100 * 100))
        p1_card_count[card - (card / 100 * 100)] += 1

    for card in p2_cards:
        p2_values.add(card - (card / 100 * 100))
        p2_card_count[card - (card / 100 * 100)] += 1
    p1_2card_1 = -1
    p1_2card_2 = -1
    for i, val in enumerate(p1_card_count):
        if val == 2:
            if p1_2card_1 != -1:
                p1_2card_2 = i
            else:
                p1_2card_1 = i

    p2_2card_1 = -1
    p2_2card_2 = -1

    for i, val in enumerate(p2_card_count):
        if val == 2:
            if p2_2card_1 != -1:
               p2_2card_2 = i
            else:
               p2_2card_1 = i

    if p1_2card_1 != -1 and p1_2card_2 != -1:
        # p1 has two pairs
        p1_max = max(p1_2card_1, p1_2card_2)
        if p2_2card_1 != -1 and p2_2card_2 != -1:
            # p2 has two pairs
            p2_max = max(p2_2card_1, p2_2card_2)
            if p1_max > p2_max:
                return 1
            else:
                return 2
        else:
            return 1
    elif p2_2card_1 != -1 and p2_2card_2 != -1:
        return 2
    
    return 0

def check_four_of_a_kind(p1_cards, p2_cards):
    p1_values = set()
    p2_values = set()
    p1_card_count = [0] * 15
    p2_card_count = [0] * 15

    for card in p1_cards:
        p1_values.add(card - (card / 100 * 100))
        p1_card_count[card - (card / 100 * 100)] += 1

    for card in p2_cards:
        p2_values.add(card - (card / 100 * 100))
        p2_card_count[card - (card / 100 * 100)] += 1

    i = 0
    fok_p1 = -1
    for count in p1_card_count:
        if count == 4:
            fok_p1 = i
        i = i + 1
    i = 0
    fok_p2 = -1
    for count in p2_card_count:
        if count == 4:
            fok_p2 = i
            break
        i = i + 1
    
    if fok_p1 != -1:
        # p1 has four of a kind
        if fok_p2 != -1:
            # p2 also has four of a kind. Check who has the higher value
            if fok_p1 > fok_p2:
                return 1
            else:
                return 2
        else:
            return 1
    elif fok_p2 != -1:
        # p1 does not have four of a kind and p2 does
        return 2
    # Both don't have four of a kind
    return 0

def get_highest_card(p1_cards, p2_cards):
    p1_list = []
    p2_list = []

    for card in p1_cards:
        p1_list.append(card - (card / 100 * 100))
    for card in p2_cards:
        p2_list.append(card - (card / 100 * 100))
        
    p1_list.sort()
    p2_list.sort()

    p1_highest = p1_list[4]
    p2_highest = p2_list[4]

    if p1_highest > p2_highest:
        return 1
    else :
        return 2

def get_result(p1_cards, p2_cards):
    rf = check_royal_flush(p1_cards, p2_cards)
    # rf = i means player i has a royal flush
    if rf == 1:
        # Player 1 has won
       print "RF "
       return True
    elif rf == 2:
        # Player 2 has won
        print "RF "
        return False
    sf = check_straight_flush(p1_cards, p2_cards)
    # sf = i means player i has a straight flush    
    if sf == 1:
        # Player 1 has won
       print "SF "
       return True
    elif sf == 2:
        # Player 2 has won
        print "SF "
        return False

    fok = check_four_of_a_kind(p1_cards, p2_cards)
    # fok = i means player i has four of a kind
    if fok == 1:
        # Player 1 has won
       print "FOK "        
       return True
    elif fok == 2:
        # Player 2 has won
        print "FOK "        
        return False

    
    fh = check_full_house(p1_cards, p2_cards)
    if fh == 1:
        print "FH "                
        return True
    elif fh == 2:
        print "FH "                
        return False
    

    flush  = check_flush(p1_cards, p2_cards)
    if flush == 1:
        print "Flush "                
        return True
    elif flush == 2:
        print "Flush "                
        return False

    straight = check_straight(p1_cards, p2_cards)
    if straight == 1:
        print "Straight "                
        return True
    elif straight == 2:
        print "Straight "                
        return False

    tok = check_three_of_kind(p1_cards, p2_cards)
    if tok == 1:
        print "TOK "                
        return True
    elif tok == 2:
        print "TOK "                
        return False

    tp = check_two_pairs(p1_cards, p2_cards)
    if tp == 1:
        print "TP "                
        return True
    elif tp == 2:
        print "TP "                
        return False

    
    op = check_one_pair(p1_cards, p2_cards)
    if op == 1:
        print "OP "                
        return True
    elif op == 2:
        print "OP "                
        return False
    
    high_card = get_highest_card(p1_cards, p2_cards)
    if high_card == 1:
        print "HC "                
        return True
    elif high_card == 2:
        print "HC "                
        return False

    
    print "Should not reach here"
    return False
def get_card_number(value, suit):
    if value == 'J':
        num_val = 11
    elif value == 'Q':
       num_val = 12
    elif value == 'K':
        num_val = 13
    elif value == 'A':
        num_val = 14
    elif value == 'T':
        num_val = 10
    else:
        num_val = int(value)
    if suit == 'S':
        num_suit = 100
    elif suit == 'D':
        num_suit = 200
    elif suit == 'H':
        num_suit = 300
    elif suit == 'C':
        num_suit = 400
        
    return num_suit + num_val

def main():
    count = 0
    inp_file = open('poker.txt', 'r')
    for line in inp_file:
        list_of_cards = line.split(' ')
        list_of_cards[9] = list_of_cards[9].split('\n')[0]

        player_1_cards = set()
        for card in list_of_cards[0:5]:
            card_number = get_card_number(card[0:len(card) - 1], card[len(card) - 1])
            player_1_cards.add(card_number)

        player_2_cards = set()
        for card in list_of_cards[5:10]:
            card_number = get_card_number(card[0 : len(card) - 1], card[len(card) - 1])
            player_2_cards.add(card_number)

        player_1_wins = get_result(player_1_cards, player_2_cards)
        if player_1_wins:
            print "Won"
            count = count + 1
        else:
            print "Lost"
    print "Player 1 won ", count, " times"
if __name__ == '__main__':
    main()
