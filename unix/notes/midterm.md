# Intro to Shell Scripting
- `$`num: this is how you access command line arguments
    - the dollar sign indicates command line arg and the number is the index of the arg you wish to use
    - `*`: using the asterik means it will use all arguments over than 0
- `shift`: moves all of the args over by one
    - arg 0 dissapears and arg 1 takes it's place, arg 2 becomes args 1 etc.
- `#`: comment
- conditionals look like this

```bash
if [ test ]
then
    command
elif [ test ]
    then
        command
    else
        command
else
    command
fi
```

- `$#`: is the number of arguments
- `-ge`: is $\ge$
- so a test like this means if the number of arguments is greater than or equal to

```bash
if [ $# -ge 2 ]
then
    commands
else
    commands
fi
```

- case

```bash
case value in
    pattern1 ) commands;;
    pattern2 ) commands;;
    *) commands
esac
```

- here pattern is a string regex expression
- `read`: it's simply input used like this
    - if more args then asked for, the remaining are all assigned to the last var.
    - is less args then required, remaining vars will be null
    - optioanlly use \n and \c

```bash
echo "Missing var1 and var 2. Enter them: "
read var1 var2
```

- `|`: or, can be used in case

- `while`:

```bash
while [ test ]
do
    commands
done
```

- `until`: just a negated while. that is while goes until test is false. until goes until test is true

```bash
until [ test ]
do
    commands
done
```

- `for`: for-each

```bash
for var in str1 str2 str3
do
    commands
done
```

- `=`: is equality
