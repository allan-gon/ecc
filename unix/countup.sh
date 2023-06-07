is_even() {
    if [ "$(($1 % 2))" -eq 0 ]; then
        return 0
    else
        return 1
    fi
}

is_number() {
    if [[ $1 =~ ^[0-9]+$ ]]; then
        return 0
    else
        return 1
    fi
}

bad_args() {
    echo "Usage: countup [-o -e] number"
    exit 1
}

count_up() {
    current=1

    if [ "$2" == "even"  ]; then
        current=2
    fi

    while [ $current -le $1 ]; do
        echo -n "$current "

        if [ "$2" == "all" ]; then
            current=$((current + 1))
        else
            current=$((current + 2))
        fi
    done
}

if [ $# -eq 1 ]; then
    if is_number "$1"; then
        flag="all"
        count_up "$1" "$flag"
    else
        bad_args
    fi
elif [ $# -eq 2 ]; then
    if [ "$1" = "-e" ]; then
        flag="even"
    elif [ "$1" = "-o" ]; then
        flag="odd"
    else
        echo "Invalid Option $1"
        exit 1
    fi

    if ! is_number "$2"; then
        bad_args
    fi

    count_up "$2" "$flag"
else
    bad_args
fi
