ssh -oHostKeyAlgorithms=+ssh-rsa agongora@acad-centos1.elcamino.edu
- password: C$40Stud3nt

# Commands
- `logname`: shows your username
- `hostname`: shows the name of the host

- only missing last part of lab

- `>`: write mode
- `>>`: append mode
- better echo redirect is cat redirect

```
ping -c 5 10.129.99.100 > lab16.out
scp -r agongora@acad-centos1:. agongora@10.129.7.222:.

mkdir cpgms

sftp agongora@acad-centos1
get /usr/cs40/game2.tar .

get game2.tar /path/to/local/destination/directory/
exit
tar -xf game2.tar
gcc tictacux.c -l curses
mv a.out tictac
./tictac

hostname >> lab16.out
logname >> lab16.out
ls –R >> lab16.out
```