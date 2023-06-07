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

    for _ in $(seq 1 $3); do
        local card=${deck_ref[-1]}
        hand_ref+=("$card")
        unset "deck_ref[-1]"
    done
}

# Shuffle the deck
deck=()
gen_deck

player_hand=()

deal deck player_hand 2

# echo "${#player_hand[@]}"
# echo "${#deck[@]}"

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

won "${player_hand[@]}"
