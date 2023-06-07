valid_number() {
    if [[ $1 =~ ^[0-9]{3}-[0-9]{4}$ ]]; then
        return 0
    else
        return 1
    fi
}

add_entry() {
    echo "Enter name to add"
    read name
    echo "Enter phone number to add"
    read number

    if valid_number $number; then
        echo "$name:$number" >>$1
    else
        echo "Invalid number: $number must be of the form ddd-dddd"
    fi
}

delete_entry() {
    echo "Enter name to delete:"
    read name
    mapfile -t result_array < <(grep -n -e "$name" "$1")
    if [ ${#result_array[@]} -eq 0 ]; then
        echo "That name isn't present in the file..."
    else
        for result in "${result_array[@]}"; do
            echo $result
        done

        echo -n "Which line will be deleted? "
        read line

        found=false
        for result in "${result_array[@]}"; do
            line_num="${result%%:*}"
            content="${result#*:}"
            if [ $line_num == $line ]; then
                found=true
                break
            fi
        done

        if $found; then
            sed -i "${line}d" "$1"
            echo "$content has been deleted!"
        else
            echo "Invalid line number: $line"
        fi
    fi
}

list() {
    list_menu="1) list entry\n2) list file"
    echo -e $list_menu
    echo -n "What is your choice? "
    read choice

    case $choice in
    1)
        echo -n "Enter name to list: "
        read name
        readarray -t result < <(grep "$name" "$1")
        for line in "${result[@]}"; do
            echo "$line"
        done
        ;;
    2)
        echo "Use the following commands to navigate through the file:"
        echo "Spacebar: Scroll down one page"
        echo "Enter: Scroll down one line"
        echo "B: Scroll up one page"
        echo "Q: Exit"
        echo "Press enter to start viewing"
        read _

        less $1
        ;;
    *) echo "Invalid choice: $choice" ;;
    esac
}

edit_entry() {
    echo -n "Enter name to change: "
    read name

    mapfile -t result_array < <(grep -n -e "$name" "$1")
    if [ ${#result_array[@]} -eq 0 ]; then
        echo "That name isn't present in the file..."
    else
        for result in "${result_array[@]}"; do
            echo $result
        done

        echo -n "Which line will be changed? "
        read line

        found=false
        for result in "${result_array[@]}"; do
            line_num="${result%%:*}"
            content="${result#*:}"
            if [ $line_num == $line ]; then
                found=true
                break
            fi
        done

        if $found; then
            echo "1) change name"
            echo "2) change number"
            echo "Please make a choice? "
            read name_or_number
            case $name_or_number in
            1)
                echo -n "What is the new name? "
                read name

                for result in "${result_array[@]}"; do
                    IFS=":" read -r line_number old_name phone_number <<<"$result"
                    if [ $line_number == $line ]; then
                        sed -i "${line}s/$old_name/$name/" "$1"
                        echo "The new entry is $name:$phone_number"
                        break
                    fi

                done

                ;;
            2)
                echo -n "What is the new number? "
                read new_phone_number

                if valid_number $new_phone_number; then
                    for result in "${result_array[@]}"; do
                        IFS=":" read -r line_number name old_phone_number <<<"$result"
                        if [ $line_number == $line ]; then
                            sed -i "${line}s/$old_phone_number/$new_phone_number/" "$1"
                            echo "The new entry is $name:$new_phone_number"
                            break
                        fi

                    done
                else
                    echo "Invalud number: $new_phone_number"
                fi
                ;;
            *) echo "Invalid choice: $name_or_number" ;;
            esac
        else
            echo "Invalid line number: $line"
        fi
    fi
}

menu="Phone book system\n1) add an entry\n2) delete an entry\n3) list file or entry\n4) change entry\n5) exit system"
continue="y"

echo -n "What is the name of your phonebook? "
read file

while true; do
    echo -e $menu
    echo -n "What is your choice? "
    read choice
    case $choice in
    1)
        while [[ $continue == "y" ]]; do
            add_entry $file
            echo -n "Would you like to add another? (y/n) "
            read continue
        done
        continue="y"
        ;;
    2)
        while [[ $continue == "y" ]]; do
            delete_entry $file
            echo -n "Would you like to delete another? (y/n) "
            read continue
        done
        continue="y"
        ;;
    3) list $file ;;
    4)
        while [[ $continue == "y" ]]; do
            edit_entry $file
            echo -n "Would you like to change another? (y/n) "
            read continue
        done
        continue="y"
        ;;
    5) exit 0 ;;
    *) echo "Invalid choice: $choice" ;;
    esac
    echo "Press Enter for main menu"
    read _
done
