roll() {
    num1=$((1 + RANDOM % 6))
    num2=$((1 + RANDOM % 6))
    sum=$((num1 + num2))
    echo "$num1 $num2 $sum"
}

craps() {
    play_again="Y"

    while [[ $play_again == "Y" ]]; do
        sum_array=()
        echo -e "WELCOME TO THE CRAP TABLE!\n"
        read -r num1 num2 sum <<<"$(roll)"
        sum_array+=($sum)
        echo -e "YOUR FIRST ROLL IS $num1 AND $num2 = $sum\n"

        if [[ $sum -eq 7 || $sum -eq 11 ]]; then
            echo -e "YOU WIN!\n"
        elif [[ $sum -eq 2 || $sum -eq 3 || $sum -eq 12 ]]; then
            echo -e "YOU LOSE!"
        else
            while true; do
                echo -e "PRESS ENTER TO TRY FOR ${sum_array[-1]} AGAIN?\n"
                read _
                read -r num1 num2 sum <<<"$(roll)"

                echo -e "YOU ROLLED $num1 AND $num2 = $sum\n"
                if [[ $sum -eq 7 ]]; then
                    echo "YOU LOSE!"
                    rolls=$(
                        IFS=", "
                        echo "${sum_array[*]}"
                    )
                    echo "YOUR ROLLS WERE $rolls"
                    break
                elif [[ $sum -eq ${sum_array[-1]} ]]; then
                    echo "YOU WIN!"
                    rolls=$(
                        IFS=", "
                        echo "${sum_array[*]}"
                    )
                    echo -e "YOUR ROLLS WERE ${rolls}\n"
                    break
                else
                    sum_array+=($sum)
                fi
            done
        fi

        echo -n "WANT TO PLAY AGAIN? "
        read play_again
        clear
    done
}

gen_prize_cost() {
    case $1 in
    1)
        echo $((200 + RANDOM % 500))
        ;;
    2)
        echo $((600 + RANDOM % 900))
        ;;
    3)
        echo $((5000 + RANDOM % 15000))
        ;;
    esac
}

guessing_game() {
    play_again="Y"
    options="GUESSING GAME PRIZES\n\n1. COLOR TV\n2. REFRIGERATOR\n3. AUTO\nENTER YOUR CHOICE (1,2,3)?"
    prizes=("COLOR TV" "REFRIGERATOR" "AUTO")
    while [[ $play_again == "Y" ]]; do
        echo -e -n "$options "
        read choice

        if [[ $choice -eq 1 || $choice -eq 2 || $choice -eq 3 ]]; then
            prize_cost=$(gen_prize_cost "$choice")
            echo "Generated: $prize_cost"
            guessed=false
            first=true
            start_time=$(date +%s)

            echo "YOU HAVE ONE MINUTE TO GUESS THE PRICE OF THE PRIZE"
            while [[ $(($(date +%s) - start_time)) -lt 60 && $guessed == false ]]; do
                if [ $first == true ]; then
                    # no validataion of the guess
                    # but that owns me when comparing
                    echo -n "WHAT IS YOUR FIRST GUESS? "
                    read guess
                    first=false
                elif [ $guess -eq $prize_cost ]; then
                    guessed=true
                elif [[ $guess -lt $prize_cost ]]; then
                    echo -n "GUESS HIGHER? "
                    read guess
                else
                    echo -n "GUESS LOWER? "
                    read guess
                fi
            done

            if [ $guessed == true ]; then
                idx=$((choice - 1))
                echo -e "\nTHAT IS CORRECT! YOU WIN THE ${prizes[idx]}!\n"
            else
                echo "SORRY, YOU HAVE RUN OUT OF GUESSES!"
                echo -e "THE PRICE WAS ${prize_cost}\n"
            fi
        else
            echo "Invalid choice: $choice"
        fi
        echo -n "WANT TO PLAY AGAIN? "
        read play_again
    done
}

# constants used for deck creation
declare -A values=(
    ["2"]=2
    ["3"]=3
    ["4"]=4
    ["5"]=5
    ["6"]=6
    ["7"]=7
    ["8"]=8
    ["9"]=9
    ["10"]=10
    ["J"]=10
    ["Q"]=10
    ["K"]=10
    ["A"]=11
)
suits=("Hearts" "Diamonds" "Clubs" "Spades")

gen_deck() {
    for suit in "${suits[@]}"; do
        for value in "${!values[@]}"; do
            deck+=("$value of $suit")
        done
    done
    shuffle_deck
}

shuffle_deck() {
    local currentIndex=${#deck[@]}
    local temp_val
    local rand_idx

    # While there remain elements to shuffle
    while [ $currentIndex -gt 0 ]; do
        # Pick a remaining element
        rand_idx=$((RANDOM % currentIndex))
        currentIndex=$((currentIndex - 1))

        # Swap it with the current element
        temp_val=${deck[$currentIndex]}
        deck[$currentIndex]=${deck[$rand_idx]}
        deck[$rand_idx]=$temp_val
    done
}

deal() {
    local -n deck_ref=$1
    local -n hand_ref=$2
    # pretend like this func wont be called with bad $3
    # or with empty deck
    for _ in $(seq 1 $3); do
        local card=${deck_ref[-1]}
        hand_ref+=("$card")
        unset "deck_ref[-1]"
    done
}

won() {
    local hand=("$@")
    hand_value=0
    for card in "${hand[@]}"; do
        read -r face _ <<<"$card"
        card_val="${values[$face]}"
        hand_val=$((hand_val + card_val))
    done

    if [ $hand_val -eq 21 ]; then
        return 0
    else
        return 1
    fi
}

black_jack() {
    # this function remains unfinished
    play_again="Y"

    while [[ $play_again == "Y" ]]; do
        dealer_hand=()
        player_hand=()
        deck=()
        gen_deck
        deal deck player_hand 2
        deal deck dealer_hand 2
        echo -e "WELCOME TO THE BLACK JACK TABLE!\n"
        # on the initial deal, aces are worth 11
        # not implementing
        echo -n "WANT TO PLAY AGAIN? "
        read play_again
    done
}

main_menu="COMPUTER GAMES MENU\n1. CRAPS (9)\n2. GUESSING GAME (9)\n3. BLACKJACK (7)\n4. EXIT\nENTER YOUR CHOICE (1, 2, 3, OR 4)?"

while true; do
    echo -e -n "$main_menu "
    read game_choice
    clear

    case $game_choice in
    1) craps ;;
    2) guessing_game ;;
    3) black_jack ;;
    4) break ;;
    *)
        echo "Invalid choice: ${game_choice}"
        read -p "Press any key to return to menu " _
        ;;
    esac
    clear
done
