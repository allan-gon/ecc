sum_up() {
    sum=0
    for arg in "$@"; do
        sum=$((sum + arg))
    done
    # echo so can catch value outside of func
    echo $sum
}

are_all_nums() {
    for arg in "$@"; do
        # at least one character is not a digit
        if [[ ! $arg =~ ^[0-9]+$ ]]; then
            return 1
        fi
    done
    return 0
}

ouput_and_save() {
    # output the sum
    sum=$(sum_up $@)
    echo "The sum of the given $# is $sum."
    # save to file
    echo "$@:$sum" >>addall.hst
}

# if they pass in no args throw error
if [ $# -eq 0 ]; then
    echo "Usage: addall [-h] number-list"
    exit 1
# if the enter all numbers
elif are_all_nums $@; then
    ouput_and_save $@
elif [ $1 == "-h" ]; then
    # could need error checking here because size isn't gauranteed
    # but examples do
    lines=$2
    shift 2
    if [ $# -gt 0 ]; then
        ouput_and_save $@
    fi
    # output last n lines
    tail -n "$lines" "addall.hst"
else
    echo "Invalid Option $1"
fi


